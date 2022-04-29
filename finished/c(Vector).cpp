// mã bài: Vector

#include <iostream>
#include <cmath>

using namespace std;

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

void sumNotPrime(int num) {
    int sum = 0, ext = 0;
    while (num > 0) {

        ext = num%10;
        
        if (!isPrime(ext)) {
            sum += ext;
        }
        
        num /= 10;
    }
    
    cout << sum;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (isPrime(a[i])) {
            // cout << "a[" << i << "]= ";
            sumNotPrime(a[i]);
        } else {
            cout << -1;
        }
        cout << "\n";
    }
    
}