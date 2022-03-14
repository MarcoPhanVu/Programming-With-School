#include <iostream>

using namespace std;

struct linearEqn {  // eqn stands for Equation
    int a, b;
    
    void operator = (linearEqn otherFunc) {
        a = otherFunc.a;
        b = otherFunc.b;
    }
};

struct quadraticEqn {
    int a, b, c;
    
    void operator = (quadraticEqn otherFunc) {
        a = otherFunc.a;
        b = otherFunc.b;
        c = otherFunc.c;
    }
};

istream& operator >> (istream& in, linearEqn& eqn){
    in >> eqn.a >> eqn.b;
    return in;
}

istream& operator >> (istream& in, quadraticEqn& eqn){
    in >> eqn.a >> eqn.b >> eqn.c;
    return in;
}

ostream& operator << (ostream& out, linearEqn& eqn){
    out << eqn.a << "x+" << eqn.b;
    return out;
}

ostream& operator << (ostream& out, quadraticEqn& eqn){
    out << eqn.a << "x^2+" << eqn.b << "x+" << eqn.c;
    return out;
}

linearEqn operator + (linearEqn funcA, linearEqn funcB) {
    linearEqn sum = funcA;
    sum.a = funcA.a + funcB.a;
    sum.b = funcA.b + funcB.b;
    return sum;
}

quadraticEqn operator + (quadraticEqn funcA, quadraticEqn funcB) {
    quadraticEqn sum;
    sum.a = funcA.a + funcB.a;
    sum.b = funcA.b + funcB.b;
    sum.c = funcA.c + funcB.c;
    return sum;
}

quadraticEqn operator * (linearEqn funcA, linearEqn funcB) {
    quadraticEqn c;
    c.a = funcA.a * funcB.a;
    c.b = funcA.a * funcB.b + funcB.a * funcA.b;
    c.c = funcA.b * funcB.b;
    return c;
}

int solve(linearEqn func, int x) {
    return func.a * x + func.b;
}

int solve(quadraticEqn func, int x) {
    return func.a * x * x + func.b * x + func.c;
}

bool operator == (linearEqn funcA, linearEqn funcB) {
    if (funcA.a + funcA.b == funcB.a + funcB.b) {
        return true;
    }
    return false;
}

bool operator == (quadraticEqn funcA, quadraticEqn funcB) {
    if (funcA.a + funcA.b + funcA.c == funcB.a + funcB.b + funcB.c) {
        return true;
    }
    return false;
}


int main() {
    quadraticEqn a, b, sumAB, e;
    linearEqn c, d;
    int x;
    cin >> a >> b >> c >> d >> x;

    sumAB = a + b;
    e = c * d;

    cout << a << "\n";
    cout << solve(a, x) << "\n";
    cout << b << "\n";
    cout << solve(b, x) << "\n";
    cout << sumAB << "\n";
    cout << solve(sumAB, x) << "\n";
    cout << "(" << c << ")*(" << d << ")" << "=" << e << "\n";
    cout << solve(e, x) << "\n";
    
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