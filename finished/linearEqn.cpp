#include <iostream>

using namespace std;

struct linearFunc {
    int a, b;
    
    void operator = (linearFunc otherFunc) {
        a = otherFunc.a;
        b = otherFunc.b;
    }
};

istream& operator >> (istream& in, linearFunc& eqn){ // eqn stands for Equation
    in >> eqn.a >> eqn.b;
    return in;
}

ostream& operator << (ostream& out, linearFunc& eqn){ // eqn stands for Equation
    out << eqn.a << "x+" << eqn.b;
    return out;
}

linearFunc operator + (linearFunc funcA, linearFunc funcB) {
    linearFunc sum = funcA;
    sum.a = funcA.a + funcB.a;
    sum.b = funcA.b + funcB.b;
    return sum;
}

int solve(linearFunc func, int x) {
    return func.a * x + func.b;
}

bool operator == (linearFunc funcA, linearFunc funcB) {
    if (funcA.a + funcA.b == funcB.a + funcB.b) {
        return true;
    }
    return false;
}


int main() {
    linearFunc a, b, c;
    int x;
    cin >> a >> b >> x;
    c = a + b;

    cout << a << "\n";
    cout << b << "\n";
    cout << a << "+" << b << "=" << c << "\n";

    cout << solve(a, x) << "\n";
    cout << solve(b, x) << "\n";

    if (a == b) {
        cout << "TRUE";
    } else {
        cout << "FALSE";
    }
    
    return 0;
}