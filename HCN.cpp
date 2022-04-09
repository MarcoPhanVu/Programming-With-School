#include <iostream>
#include <iomanip>

using namespace std;

struct rect {
    float x, y;
    
    void operator = (rect otherRect) {
        x = otherRect.x;
        y = otherRect.y;
    }
};

istream& operator >> (istream& cin, rect& rect) {
    cin >> rect.x >> rect.y;
    return cin;
}

ostream& operator << (ostream& cout, rect rect) {
    cout << "[HCN] " << rect.x << "," << rect.y << "\n";
}

float perimeter(rect a) {
    return (a.x + a.y) * 2;
}

bool operator < (rect a, rect b) {
    return perimeter(a) < perimeter(b);
}

bool operator > (rect a, rect b) {
    return !(a < b);
}

bool operator == (rect a, rect b) {
    return ((perimeter(a) == perimeter(b)) && a.x == b.x);
}

bool operator != (rect a, rect b) {
    return !(a==b);
}
	
float operator + (rect rect, float x) {
    return perimeter(rect) + x;
}

int main() {
    rect a, b;
    cin >> a >> b;
    cout << a << b;
    if (a < b) {
        cout << "true";
        return 0;
    }
    cout << "false";
}