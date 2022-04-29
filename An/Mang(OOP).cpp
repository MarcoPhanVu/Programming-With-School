#include <iostream>
using namespace std;

class MANG{
    int a[100], n;
public:
    void setN(int k);
    int getN();
    int& operator[] (int index);
    MANG(int _a[]=new int[1], int _n=1);
    MANG(const MANG &m);
    ~MANG();
    friend istream& operator >> (istream &is, MANG &m);
    friend ostream& operator << (ostream &os, MANG m);
    int findValue(int x);
    void sortValue(bool f=true);
};
void swap(int &a, int &b);

int main(){
    int x;
    cin >> x;
    MANG m;
    cout << m.getN() << endl;
    if(m.findValue(x)==-1) cout << "FALSE" << endl;
    else cout << "TRUE" << endl;
    MANG m1=m;
    m1.sortValue();
    cout << m1;
    m[0]++;
    m.sortValue(false);
    cout << m;
    return 0;
}

void swap(int &a, int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}
void MANG:: setN(int k) {n=k;}
int MANG:: getN() {return n;}
int& MANG:: operator[](int index) {return a[index];}
MANG:: MANG(int _a[], int _n){
    n=_n;
    for(int i=0; i<n; i++) a[i] = _a[i];
}
MANG:: MANG(const MANG &m){
    n=m.n;
    for(int i=0; i<n; i++) a[i] = m.a[i];
}
MANG:: ~MANG(){n=0;}
istream& operator >> (istream &is, MANG &m){
    m.n=0;
    while(is >> m[m.n]) {m.n++;}
    return is;
}
ostream& operator << (ostream &os, MANG m){
    for(int i=0; i<m.n; i++) os << m[i] << " ";
    os << endl;
    return os;
}
int MANG:: findValue(int x){
    for(int i=0; i<n; i++) if(a[i]==x) return i;
    return -1;
}
void MANG:: sortValue(bool f){
    for(int i=0; i<n-1; i++){
        for(int j=i+1;j<n;j++){
            if(a[i] > a[j]&& f) swap(a[i],a[j]);
            if(a[i] < a[j]&& !f) swap(a[i],a[j]);
        }
    }
}