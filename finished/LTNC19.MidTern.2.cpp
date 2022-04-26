#include <iostream>
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

template <typename val>
struct array{
    int size;
    val a[100];
    val& operator [](int i) {
        return a[i];
    }
};

template <typename val>
istream& operator >> (istream &is, array<val>& a){
    while(is >> a[a.size] ){
        a.size++;
    }
    return is;
}

template <typename val>
val findMax(array<val> a) {
    val max = a[0];
    for (int i = 1; i < a.size; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

int getSum(array<int> a) {
    int sum = a[0];
    for (int i = 1; i < a.size; i++) {
        sum += a[i];
    }
    return sum;
}

int getSum(array<SoLaMa> a) { //havent overload Romanian Numbers succesfully
    SoLaMa sum = a[0];
    sum.val = a[0].val;
    for (int i = 1; i < a.size; i++) {
        sum.val = sum.val + a[i].val;
    }
    return sum.val;
}

template <typename val>
ostream& operator << (ostream &os, array<val>& a) {
    cout << findMax(a) << "\n";
    cout << getSum(a);
}

int main() {
    char type;
    cin >> type;

    array<int> arrINT;
    array<SoLaMa> arrRN;

    if (type == 'N'){
        cin >> arrINT;
        cout << arrINT;
    }
    if (type=='L')
    {
        cin >> arrRN;
        cout << arrRN;
    }
}