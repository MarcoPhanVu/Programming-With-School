#include <iostream>
#include <cmath>

using namespace std;

long long factorial(int n) {
    while ( n > 1) {
        return factorial(n - 1) * n;
    }
}

double exponential(int n, int x) {
    if (n < 0) {
        return 1;
    }
    return exponential(n - 1, x) + (pow(x, n * 2 + 1))/factorial( n * 2 + 1);
}

int main() {
    int n, x;
    cin >> n >> x;
    cout << roundf(exponential(n, x) * 1000) / 1000;
    // cout << "\n5! = " << factorial(5);
    return 0;
}