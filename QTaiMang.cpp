#include <iostream>

using namespace std;

struct arr {
    int a[100];
    int n;
    
    int& operator [] (int i){
        return a[i];
    }
    
    void operator = (arr b){
        n = b.n;
        
        for (int i = 0; i < n; i++){
            a[i] = b[i];
        }
    }
    
};

istream& operator >> (istream& in, arr& arr){
    in >> arr.n;
    for (int i = 0; i < arr.n; i++) {
        in >> arr[i];
    }
    return in;
}

ostream& operator << (ostream& out, arr& arr) {
    for (int i = 0; i < arr.n; i++){
        out<< arr[i] << " ";
    }
    return out;
}

arr operator + (arr a, arr b){
    int temp = (a.n < b.n) ? a.n : b.n; 
    arr c = (a.n <= b.n)? b : a;
    // to prevent combining unallocated elements of smaller array
    for (int i = 0; i < temp; i++) {
        if (temp == a.n) { //sum the other array( not the same size)
            c[i] += a[i];
        }
        else {
            c[i] += b[i];
        }
    }
    return c;
}

bool operator == (arr a, arr b){
    if (a.n != b.n) {
        return false;
    }

    for (int i=0; i < a.n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool operator != (arr a, arr b){
    return !(a == b);
}

int main() {
    arr a, b, c;
    cin >> a >> b;
    
    c = a + b;
    
    cout << c;

    return 0;
}