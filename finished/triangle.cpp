#include <iostream>
#include <cmath>

using namespace std;

struct point {
    int a, b;
    
    void operator = (point otherPoint) {
        a = otherPoint.a;
        b = otherPoint.b;
    }
};

struct triangle {
    point a, b, c;
    
    void operator = (triangle Tri) {
        a = Tri.a;
        b = Tri.b;
        c = Tri.c;
    }
};

istream& operator >> (istream& in, point& p) {
    in >> p.a >> p.b;
    return in;
}

ostream& operator << (ostream& out, point& p) { // p stands for Equation
    out << "(" << p.a << "," << p.b << ")";
    return out;
}

istream& operator >> (istream& in, triangle& t) {
    in >> t.a >> t.b >> t.c;
    return in;
}

ostream& operator << (ostream& out, triangle& t) { // p stands for Equation
    out << t.a << t.b << t.c;
    return out;
}

bool operator == (point pA, point pB) {
    if (pA.a == pB.a && pA.b == pB.b) {
        return true;
    }
    return false;
}

bool operator != (point pA, point pB) {
    return !(pA == pB);
}

// XÉT CÁC ĐIỂM TRÙNG -> LỖI CÁC TEST CASES 5, 6
// bool operator == (triangle t0, triangle t1) {
//     if (t0.a == t1.a && t0.b == t1.b && t0.c == t1.c) {
//         return true;
//     }
//     return false;
// }

float length(point p0, point p1) {
    float len, x, y;
    // x = float(p0.a) - float(p1.a);
    // y = float(p0.b) - float(p1.b);
    x = p0.a - p1.a;
    y = p0.b - p1.b;
    len = sqrt(x * x + y * y);
    return len;
}

float perimeter(triangle t) {
    return length(t.a, t.b) + length(t.c, t.b) + length(t.a, t.c); 
}

bool operator < (triangle t0, triangle t1) {
    if (perimeter(t0) < perimeter(t1)) {
        return true;
    }
    return false;
}

float operator + (triangle t0, triangle t1) {
    return perimeter(t0) + perimeter(t1);
}


// XÉT CHU VI TAM GIÁC -> ĐỦ TEST CASE
bool operator == (triangle t0, triangle t1) {
    if (perimeter(t0) == perimeter(t1)) {
        return true;
    }
    return false;
}

int main() {
    triangle t0, t1;
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