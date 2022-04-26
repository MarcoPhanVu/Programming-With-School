#include <iostream>

using namespace std;

int Catalan(int n) {
    int sum = 0;
    if (n == 1 || n == 0) {
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        sum += Catalan(i) * Catalan(n - 1 - i);
    }
    return sum;
}

int main() {
    int arr[100], n = 0;
    while (cin >> arr[n]) {
        cout << Catalan(arr[n]) << "\n";
        n++;    
    }
    return 0;
}