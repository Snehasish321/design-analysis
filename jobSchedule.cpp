#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

// Comparison function to sort jobs by profit (descending)
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    // Input: list of jobs
    Job jobs[] = {
        {'A', 2, 100},
        {'B', 1, 50},
        {'C', 2, 10},
        {'D', 1, 20},
        {'E', 3, 30}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]); // number of jobs

    // Sort jobs in decreasing order of profit
    sort(jobs, jobs + n, compare);

    int slots[100];      // stores job IDs for each time slot
    bool filled[100];    // marks if a slot is already filled

    // Initialize slots
    for (int i = 0; i < n; i++) {
        filled[i] = false;
        slots[i] = -1;
    }

    int totalProfit = 0;

    // Assign jobs to slots
    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!filled[j]) {
                slots[j] = i;  // store the index of the job
                filled[j] = true;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Output scheduled jobs
    cout << "Scheduled jobs: ";
    for (int i = 0; i < n; i++) {
        if (slots[i] != -1) {
            cout << jobs[slots[i]].id << " ";
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;

    return 0;
}
