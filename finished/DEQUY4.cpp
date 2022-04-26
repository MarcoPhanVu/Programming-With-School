#include <iostream>
#include <cmath>

using namespace std;

int exponential(int x, int n) {
    if (n == 0) {
        return 1;
    }
    return exponential(x, n - 1) + pow(x, n);
}

int main() {
    int x, n;
    cin >> n >> x;
    cout << exponential(x, n);
}