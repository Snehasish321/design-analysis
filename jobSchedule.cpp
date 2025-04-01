#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);
    int n = jobs.size();
    vector<int> slots(n, -1);
    vector<bool> filled(n, false);
    int totalProfit = 0;
    
    for (auto job : jobs) {
        for (int j = min(n, job.deadline) - 1; j >= 0; j--) {
            if (!filled[j]) {
                slots[j] = job.id;
                filled[j] = true;
                totalProfit += job.profit;
                break;
            }
        }
    }
    
    cout << "Scheduled jobs: ";
    for (int i = 0; i < n; i++) {
        if (slots[i] != -1)
            cout << (char)slots[i] << " ";
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    vector<Job> jobs = {{'A', 2, 100}, {'B', 1, 50}, {'C', 2, 10}, {'D', 1, 20}, {'E', 3, 30}};
    jobScheduling(jobs);
    return 0;
}
