#include <iostream>

using namespace std;

int main()
{
    int m[100], n = 0;
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    
    while (cin >> m[n]) {
        if (m[n] == 0) ++a;
        if (m[n] == 1) ++b;
        if (m[n] == 2) ++c;
        if (m[n] == 3) ++d;
        if (m[n] == 4) ++e;
        if (m[n] == 5) ++f;
        ++n;
    }

    cout << "n: " << n << "\n";
    cout << "0: " << a << endl;
    cout << "1: " << b << endl;
    cout << "2: " << c << endl;
    cout << "3: " << d << endl;
    cout << "4: " << e << endl;
    cout << "5: " << f << endl;

    return 0;
}