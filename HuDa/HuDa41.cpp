#include<iostream>

using namespace std;

int main() {
    int i = 0; //for counting
    int arr[1000];
    int totalProfit = 0;

    while (cin >> arr[i]) {
        if (arr[i] == 0) {
            break;
        }
        
        cin >> arr[i + 1];
        totalProfit += arr[i] - arr[i + 1];
        i += 2;
    }
    
    cout << "Total profit: " << totalProfit;

}
