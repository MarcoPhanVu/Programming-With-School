#include <iostream>
#include <cmath>

using namespace std;

class Vector {
	int x, y;
	int GetX() {
        return x; 
    }
	int GetY() {
        return y; 
    }
	void SetX(int a) { 
        x = a;
    }
	void SetY(int b) {
        y = b;
    }
public:
	Vector(int a = 0, int b = 0) { //Default constructor
		x = a;
		y = b;
	}
	Vector(const Vector& vector) { //Initial constructor
		x = vector.x;
		y = vector.y;
	}
	~Vector() {} //End of constructor

	friend istream& operator >>(istream& is, Vector& vector) {
		is >> vector.x >> vector.y;
		return is;
	}
	friend ostream& operator <<(ostream& os, Vector vector) {
		os << "(" << vector.x << "," << vector.y << ")";
		return os;
	}
	Vector operator +(Vector vector) {
		Vector c(x + vector.x, y + vector.y);
		return c;
	}
	Vector operator -(Vector vector) {
		Vector c(x - vector.x, y - vector.y);
		return c;
	}
	float operator *(Vector vector) {
	    float c = sqrt(pow(x+vector.x,2)+pow(y+vector.y,2));
	    return c;
	}
	void operator = (Vector vector) {
		x = vector.x;
		y = vector.y;
	}
	Vector operator -- () {
		x--;
		y--;
		return *this;
	}
	Vector operator ++ () {
		x++;
		y++;
		return *this;
	}
};

int main() {
	Vector v1,v2;
	cin >> v1 >> v2;
	cout << v1 * v2;
}