#include<iostream>
#include<climits>

using namespace std;

int main () {
    int n ;
    cout << "Enter thenumber of vertices : ";
    cin >> n ;
    int cost [n][n];

    cout << "Enter the cost adjacency matrix (use 0 for no edge) : " << endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j  = 0 ; j < n ; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0) {
                cost[i][j] = INT_MAX;
            }
        }
    }
    int selected[n];
    for (int i = 0 ; i < n ; i++) {
        selected[i] = 0 ;
    }

    selected[0] = 1 ;
    int edge_count = 0 ;
    int min_cost = 0 ;

    cout << " Edges in the MST: " << endl;
    while (edge_count < n-1 ) {
        int min = INT_MAX;
        int x = 0 , y = 0 ;

        for (int i = 0 ; i < n ; i++) {
            if (selected[i]) {
                for (int j = 0 ; j < n ; j++) {
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        x = i ;
                        y = j;
                    }
                }
            }
        }
        cout << "Edge" << edge_count + 1 <<  ": (" << x << " - " << y << ") cost = "  << cost[x][y] << endl;
        min_cost += cost[x][y];
        selected[y] = 1 ;
        edge_count++;
    }
    cout << "Minimum Cost of Spanning Tree: " << min_cost << endl;
    return 0;
}