/*Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element. */

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int first = -1 , second = -1 ;
        for (int num : arr) {
            if (num > first) {
                second = first;
                first = num;
            } else if(num < first && num > second) {
                second = num;
            }
        }
        return second;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cout<< "Enter number of test cases: ";
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
