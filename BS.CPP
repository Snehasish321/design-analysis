#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return binarySearchRecursive(arr, left, mid - 1, key);
        else
            return binarySearchRecursive(arr, mid + 1, right, key);
    }
    return -1;
}

int binarySearchIterative(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main() {
    int n, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to search: ";
    cin >> key;
    
    int resultRecursive = binarySearchRecursive(arr, 0, n - 1, key);
    int resultIterative = binarySearchIterative(arr, n, key);
    
    if (resultRecursive != -1)
        cout << "Element found at index (Recursive): " << resultRecursive << endl;
    else
        cout << "Element not found (Recursive)." << endl;
    
    if (resultIterative != -1)
        cout << "Element found at index (Iterative): " << resultIterative << endl;
    else
        cout << "Element not found (Iterative)." << endl;
    
    return 0;
}
