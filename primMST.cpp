#include <iostream>
#include <climits> // for INT_MAX
using namespace std;

int main() {
    int n;

    // Input number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    int cost[n][n];

    // Input adjacency matrix (graph represented as cost matrix)
    cout << "Enter the cost adjacency matrix (use 0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0) {
                cost[i][j] = INT_MAX; // No direct edge
            }
        }
    }

    int selected[n]; // keeps track of selected vertices
    for (int i = 0; i < n; i++) {
        selected[i] = 0;
    }

    selected[0] = 1; // Start from the first vertex
    int edge_count = 0;
    int min_cost = 0;

    cout << "\nEdges in the Minimum Spanning Tree:\n";

    while (edge_count < n - 1) {
        int min = INT_MAX;
        int x = 0, y = 0;

        // Find the minimum cost edge from selected to unselected vertex
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << "Edge " << edge_count + 1 << ": (" << x << " - " << y << ") cost = " << cost[x][y] << endl;
        min_cost += cost[x][y];
        selected[y] = 1;
        edge_count++;
    }

    cout << "\nMinimum Cost of Spanning Tree: " << min_cost << endl;

    return 0;
}
