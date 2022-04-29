#include <iostream>

void swap(int &a, int &b) {
    a += b;
    b = a - b;
    a = a - b;
}

long long factorial(int n) {
    while ( n > 1) {
        return factorial(n - 1) * n;
    }
}

bool isPrime(int num) { //Function to check if prime
    if (num == 1) {return false;}
    if (num == 2 || num == 3) {return true;}
    if (num%2 == 0) {return false;}
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num%i == 0) {
            return false;
        }
    }
    return true;
}

int UCLN(long a, long b) {
    while (a*b != 0) { 
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}