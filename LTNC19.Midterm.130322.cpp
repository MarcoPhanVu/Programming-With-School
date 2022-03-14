#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

struct SoLaMa {
    string chara;
    int val;
};

istream& operator >> (istream &in, SoLaMa &n) {
	in >> n.chara;
    string romanianNum[10] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
    for (int i = 0; i < 10; i++) {
        if (romanianNum[i] == n.chara) {
            n.val = i + 1;
            break;
        }
    }
	return in;
}

ostream& operator << (ostream &out, SoLaMa n) {
    out << n.val;
    return out;
}

bool operator < (SoLaMa n0, SoLaMa n1) {
    return (n0.val < n1.val);
}

bool operator > (SoLaMa n0, SoLaMa n1) {
    return !(n0 < n1);
}

SoLaMa operator + (SoLaMa n0, SoLaMa n1) {
    SoLaMa sum;
    sum.chara = n0.chara + n1.chara;
    sum.val = n0.val + n1.val;
    return sum;
}

int main() {
    SoLaMa a, b, c;
    cin >> a >> b;
    c = a + b;
    cout << a << "\n" << b << "\n" << c << "\n";
    if (a < b) {
        cout << "true";
        return 0;
    }

    cout << "false";

    return 0;
}