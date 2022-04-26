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
            nev += (a[i]) + " ";
        } else {
            pos += (a[i]) + " ";
        }
    }
    cout << nev << "\n" << pos;
}