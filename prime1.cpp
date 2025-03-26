#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n1, n2;
    cout << "Enter the number of elements in first list: ";
    cin >> n1;
    int arr1[n1];
    cout << "Enter elements of first list: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    
    cout << "Enter the number of elements in second list: ";
    cin >> n2;
    int arr2[n2];
    cout << "Enter elements of second list: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }
    
    int n = n1 + n2;
    int mergedArr[n];
    for (int i = 0; i < n1; i++) {
        mergedArr[i] = arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        mergedArr[n1 + i] = arr2[i];
    }
    
    mergeSort(mergedArr, 0, n - 1);
    cout << "Sorted merged list: ";
    printArray(mergedArr, n);
    
    return 0;
}
