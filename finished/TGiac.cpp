#include <iostream>
#include <cmath>

using namespace std;

struct diem {
    int a, b;
    void operator = (diem otherdiem) {
        a = otherdiem.a;
        b = otherdiem.b;
    }
};

struct tamGiac {
    diem a, b, c;
    
    void operator = (tamGiac Tri) {
        a = Tri.a;
        b = Tri.b;
        c = Tri.c;
    }
};

istream& operator >> (istream& in, diem& p) {
    in >> p.a >> p.b;
    return in;
}

ostream& operator << (ostream& out, diem& p) { // p stands for Equation
    out << "(" << p.a << "," << p.b << ")";
    return out;
}

istream& operator >> (istream& in, tamGiac& t) {
    in >> t.a >> t.b >> t.c;
    return in;
}

ostream& operator << (ostream& out, tamGiac& t) { // p stands for Equation
    out << t.a << t.b << t.c;
    return out;
}

bool operator == (diem pA, diem pB) {
    if (pA.a == pB.a && pA.b == pB.b) {
        return true;
    }
    return false;
}

bool operator != (diem pA, diem pB) {
    return !(pA == pB);
}

// XÉT CÁC ĐIỂM TRÙNG -> LỖI CÁC TEST CASES 5, 6
// bool operator == (tamGiac t0, tamGiac t1) {
//     if (t0.a == t1.a && t0.b == t1.b && t0.c == t1.c) {
//         return true;
//     }
//     return false;
// }

float length(diem p0, diem p1) {
    float len, x, y;
    // x = float(p0.a) - float(p1.a);
    // y = float(p0.b) - float(p1.b);
    x = p0.a - p1.a;
    y = p0.b - p1.b;
    len = sqrt(x * x + y * y);
    return len;
}

float chuVi(tamGiac t) {
    return length(t.a, t.b) + length(t.c, t.b) + length(t.a, t.c); 
}

bool operator < (tamGiac t0, tamGiac t1) {
    if (chuVi(t0) < chuVi(t1)) {
        return true;
    }
    return false;
}

float operator + (tamGiac t0, tamGiac t1) {
    return chuVi(t0) + chuVi(t1);
}

// XÉT CHU VI TAM GIÁC -> ĐỦ TEST CASE
bool operator == (tamGiac t0, tamGiac t1) {
    if (chuVi(t0) == chuVi(t1)) {
        return true;
    }
    return false;
}

int main() {
    tamGiac t0, t1;
    cin >> t0 >> t1;
    cout << t0 << "\n" << t1 << "\n";

    if (t0 < t1) {
        cout << "TRUE" << "\n";
    } else {
        cout << "FALSE" << "\n";
    }

    if (t0 == t1) {
        cout << "TRUE";
        return 0;
    }
    cout << "FALSE";

    return 0;
}