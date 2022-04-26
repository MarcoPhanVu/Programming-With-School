#include <iostream>
#include <cmath>
using namespace std;

bool isSoCPhuong(int num)
{
    int i = sqrt(num);
    if (i*i == num) {
        return true;
    }
    return false
}

int main() {
    int n, res = 0;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (isSoCPhuong(arr[i])) {
            res += arr[i]
        }
    }

    cout << res;

}


