#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    cin >> x >> y;
    int a[x][y];

    for (int i = 0; i < x; i++) { //Input
        for (int j = 0; j < y; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < x; i++) { //swap rows
        if (a[i][0] > a[i + 1][0]) {
            for (int j = 0; j < y; j++) {
                swap(a[i][j], a[i + 1][j]);
            }
        }
    }

    for (int i = 0; i < x; i++) { //swap inline
        // odd -> ascend
        if (i%2 != 0) {
            for (int j = 0; j < y; j++) {
                if (a[i][j] > a[i][j + 1]) {
                    swap(a[i][j], a[i][j + 1]);
                }
            }
        }
        
        // even -> descend
        else {
            for (int j = y; j > 0; j--) {
                if (a[i][j] < a[i][j + 1]) {
                    swap(a[i][j], a[i][j + 1]);
                }
            }
        }
    }

    for (int i = 0; i < x; i++) { //Output
        for (int j = 0; j < y; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

}