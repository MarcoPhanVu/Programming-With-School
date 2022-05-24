#include <iostream>
using namespace std;
int main()
{
    int a[100], n = 0;
    //  while (cin >> n) {n++;} // cin mãi mãi và đ bao giờ ngừng =)))

    // Thay vào đó, ông nên
    while (cin >> a[n]) {
        if (a[n] == 0) {
            --n; // để giảm cái count xuống -> không nhận số 0
            break; //Để ngưng cái while loop này
        }
        ++n;
    }

    
    int max = a[0];
    for (int i = 0; i < n; i++){
        if (a[i] > max && a[i] != 0) {max = a[i];}
    }
    
    int min = a[0];
    for (int i = 0; i < n; i++){
        if (a[i] < min && a[i] != 0) {min = a[i];}
    }
    cout << "max is: " << max << endl;
    cout << "min is: " << min << endl;
    return 0;
}