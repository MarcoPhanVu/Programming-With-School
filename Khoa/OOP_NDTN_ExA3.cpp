#include <iostream>
using namespace std;

class ARRINT1 {
    int n;
    int a[100];
public:
    // get - set
    int getN () { return n; }
    void setN (int _n) { n = _n; }
    // ktao - huy
    ARRINT1 () {
        n = 1;
        a[0] = 0;
    }
    ARRINT1 (int len, int m[]) {
        n = len;
        for (int i = 0; i < n; i++)
            a[i] = m[i];
    }
    ARRINT1 (const ARRINT1 &m) {
        n = m.n;
        for (int i = 0; i < n; i++)
            a[i] = m.a[i];
    }
    ~ARRINT1 () {};
    // nhap - xuat
    friend istream & operator >> (istream &in, ARRINT1 &m) {
        for (int i = m.n - 1; i >= 0; i--)
            in >> m.a[i];
        return in;
    }
    friend ostream & operator << (ostream &out, ARRINT1 m) {
        out << m.n << ": ";
        for (int i = 0; i < m.n; i++)
            out << m.a[i];
        return out;
    }
    // ham khac
    ARRINT1 operator + (ARRINT1 m) {
        ARRINT1 t;
        if (n==m.n) {
            t.n = n;
            for (int i = 0; i < n; i++)
                t.a[i] = a[i] + m.a[i];
        }
        else if (n > m.n) {
            t.n = n;
            for (int i = 0; i < n; i++) {
                if (i < m.n)
                    t.a[i] = a[i] + m.a[i];
                else
                    t.a[i] = a[i];
            }
        }
        else {
            t.n = m.n;
            for (int i = 0; i < m.n; i++) {
                if (i < n)
                    t.a[i] = a[i] + m.a[i];
                else
                    t.a[i] = m.a[i];
            }
        }
        for (int i = 0; i < t.n; i++)
            if (t.a[i] >= 10)
                t.a[i] -= 10;
        return t;
    }
};

int main () {
    int tp, tq;
    cin >> tp >> tq;
    ARRINT1 p, q;
    p.setN(tp);
    q.setN(tq);
    cin >> p >> q;
    cout << p+q;
}