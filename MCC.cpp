#include<iostream>
using namespace std;

int main () {
    int coin[5] = {1, 2, 5, 10, 20};
    int n = 5;
    int amount;
    
    cout << "Enter the amount: ";
    cin >> amount;

    int originalAmount = amount; // store the original amount for display later
    int count = 0;
    int usedCoins[100];  // assuming max 100 coins
    int idx = 0;

    // To find out the minimum number of coins and store which coins are used
    for (int i = n - 1; i >= 0; i--) {
        while (amount >= coin[i]) {
            amount -= coin[i];
            usedCoins[idx++] = coin[i];  // store coin used
            count++;
        }
    }

    cout << "The minimum number of coins required for amount " << originalAmount << " is: " << count << endl;

    // Display which coins were used
    cout << "The coins used are: ";
    for (int i = 0; i < idx; i++) {
        cout << usedCoins[i] << " ";
    }
    cout << endl;

    return 0;
}
