#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    string pos, nev;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            nev += to_string(a[i]) + " ";
        } else {
            pos += to_string(a[i]) + " ";
        }
    }
    cout << nev << "\n" << pos;
}