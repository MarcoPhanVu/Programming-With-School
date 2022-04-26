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
        return 0;
    }
    return exponential(n - 1, x) + pow(-1, n) * (pow(x, n * 2 + 1))/factorial( n * 2 + 1);
}

int main() {
    int n, x;
    cin >> n >> x;
    cout << roundf(exponential(n, x) * 1000) / 1000;
    return 0;
}