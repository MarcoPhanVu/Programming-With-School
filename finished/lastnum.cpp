#include <iostream>

using namespace std;

long long sum(long long n) {
    if (n < 10) {
        return n;
    }

    long nSum = 0;
    
    while (n > 0) {
        nSum += n%10;
        n /= 10;
    }
    
    return sum(nSum);
}

int main() {
    long long n;
    cin >> n;
    cout << sum(n);
}