#include <iostream>

using namespace std;

struct BacNhat {  // eqn stands for Equation
    int a, b;
    
    void operator = (BacNhat otherFunc) {
        a = otherFunc.a;
        b = otherFunc.b;
    }
};

struct BacHai {
    int a, b, c;
    
    void operator = (BacHai otherFunc) {
        a = otherFunc.a;
        b = otherFunc.b;
        c = otherFunc.c;
    }
};

istream& operator >> (istream& in, BacNhat& eqn){
    in >> eqn.a >> eqn.b;
    return in;
}

istream& operator >> (istream& in, BacHai& eqn){
    in >> eqn.a >> eqn.b >> eqn.c;
    return in;
}

ostream& operator << (ostream& out, BacNhat& eqn){
    out << eqn.a << "x+" << eqn.b;
    return out;
}

ostream& operator << (ostream& out, BacHai& eqn){
    out << eqn.a << "x^2+" << eqn.b << "x+" << eqn.c;
    return out;
}

BacNhat operator + (BacNhat funcA, BacNhat funcB) {
    BacNhat sum = funcA;
    sum.a = funcA.a + funcB.a;
    sum.b = funcA.b + funcB.b;
    return sum;
}

BacHai operator + (BacHai funcA, BacHai funcB) {
    BacHai sum;
    sum.a = funcA.a + funcB.a;
    sum.b = funcA.b + funcB.b;
    sum.c = funcA.c + funcB.c;
    return sum;
}

BacHai operator * (BacNhat funcA, BacNhat funcB) {
    BacHai c;
    c.a = funcA.a * funcB.a;
    c.b = funcA.a * funcB.b + funcB.a * funcA.b;
    c.c = funcA.b * funcB.b;
    return c;
}

int tinhGiaTri(BacNhat func, int x) {
    return func.a * x + func.b;
}

int tinhGiaTri(BacHai func, int x) {
    return func.a * x * x + func.b * x + func.c;
}

bool operator == (BacNhat funcA, BacNhat funcB) {
    if (funcA.a + funcA.b == funcB.a + funcB.b) {
        return true;
    }
    return false;
}

bool operator == (BacHai funcA, BacHai funcB) {
    if (funcA.a + funcA.b + funcA.c == funcB.a + funcB.b + funcB.c) {
        return true;
    }
    return false;
}


int main() {
    BacHai a, b, sumAB, e;
    BacNhat c, d;
    int x;
    cin >> a >> b >> c >> d >> x;

    sumAB = a + b;
    e = c * d;

    cout << a << "\n";
    cout << tinhGiaTri(a, x) << "\n";
    cout << b << "\n";
    cout << tinhGiaTri(b, x) << "\n";
    cout << sumAB << "\n";
    cout << tinhGiaTri(sumAB, x) << "\n";
    cout << "(" << c << ")*(" << d << ")" << "=" << e << "\n";
    cout << tinhGiaTri(e, x) << "\n";
    
    if ((a == b) && (a == e)) {
        cout << "TRUE3";
        return 0;
    }

    if (a == e) {
        cout << "TRUE1";
        return 0;
    }

    if (b == e) {
        cout << "TRUE2";
        return 0;
    }

    cout << "FALSE";
    return 0;
}