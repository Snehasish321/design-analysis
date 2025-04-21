#include<iostream>
#include<queue>

using namespace std;

int main () {
    priority_queue<int> pq;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    cout << "The elements in descending order are: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;   
    return 0;
}