// Write a program to perform Bubble sort for any given list of numbers.

#include<iostream>
using namespace std;

void bubble(int arr[] , int n) {
    for (int i = 0 ; i < n-1 ; i++ ) {
        for (int j = 0 ; j < n-i-1 ; j++ ) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main () {
    cout << "Enter the size of the array : " << endl;
    int n ;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : " << endl;
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    bubble(arr , n);
    cout << "The sorted array is : " << endl;
    for (int i = 0 ; i < n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0 ;
}