#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Greedy approach for Fractional Knapsack
struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);
    double finalValue = 0.0;
    for (auto& item : items) {
        if (W >= item.weight) {
            W -= item.weight;
            finalValue += item.value;
        } else {
            finalValue += item.value * ((double)W / item.weight);
            break;
        }
    }
    return finalValue;
}

// Dynamic Programming approach for 0/1 Knapsack
int knapsackDP(int W, vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (items[i - 1].weight <= w)
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main() {
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    
    cout << "Maximum value in Fractional Knapsack = " << fractionalKnapsack(W, items) << endl;
    cout << "Maximum value in 0/1 Knapsack = " << knapsackDP(W, items) << endl;
    
    return 0;
}
