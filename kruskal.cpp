#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edges.resize(E);
    }
};

class Subset {
public:
    int parent, rank;
};

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

void KruskalMST(Graph& graph) {
    vector<Edge> result;
    int e = 0, i = 0;
    sort(graph.edges.begin(), graph.edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });
    Subset* subsets = new Subset[graph.V];
    for (int v = 0; v < graph.V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < graph.V - 1 && i < graph.E) {
        Edge nextEdge = graph.edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        if (x != y) {
            result.push_back(nextEdge);
            Union(subsets, x, y);
            e++;
        }
    }
    cout << "Edge \tWeight\n";
    for (auto edge : result) {
        cout << edge.src << " - " << edge.dest << " \t" << edge.weight << "\n";
    }
    delete[] subsets;
}

int main() {
    int V = 5, E = 7;
    Graph graph(V, E);
    graph.edges = {{0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}};
    KruskalMST(graph);
    return 0;
}
