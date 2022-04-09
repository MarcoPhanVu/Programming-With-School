#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Fraction { //numerator and denominator
	int nu, de;
	void operator = (Fraction f1) {
		nu = f1.nu;
		de = f1.de;
	}
	void operator = (int x) {
		nu = x;
		de = 1;
	}
	void operator = (float n) {
	    nu = n * 1000;
	    de = 1000;
	}
	
};

istream& operator >> (istream& in, Fraction& f) {
	in >> f.nu >> f.de;
	return in;
}

ostream& operator << (ostream& out, Fraction f) {
    out << f.nu << "/"<< f.de << "\n";
    return out;
}

Fraction shorten(Fraction f) {
	int x = __gcd(f.nu, f.de); //from <algorithm> library
	f.nu /= x;
	f.de /= x;
	return f;
}

bool operator == (Fraction f1, Fraction f2) {
    return (f1.nu * f2.de == f2.nu * f1.de);
}

bool operator != (Fraction f1, Fraction f2) {
    return !(f1 == f2); //Fract == Fract has been declared up there
}

Fraction operator + (Fraction f1, Fraction f2) { //must return the shorten version
    Fraction fSum;
    fSum.nu = f1.nu * f2.de + f2.nu * f1.de;
    fSum.de = f1.de * f2.de;
    return shorten(fSum);
}

Fraction operator += (Fraction f1, Fraction f2) { //must return the shorten version
    Fraction fSum;
    fSum.nu = f1.nu * f2.de + f2.nu * f1.de;
    fSum.de = f1.de * f2.de;
    return shorten(fSum);
}

Fraction operator - (Fraction f1, Fraction f2) {
    Fraction fMinus;
    fMinus.nu = f1.nu * f2.de - f2.nu * f1.de;
    fMinus.de = f1.de * f2.de;
    return shorten(fMinus);
}

Fraction operator * (Fraction f1, Fraction f2) {
    Fraction fMul;
    fMul.nu = f1.nu * f2.nu;
    fMul.de = f1.de * f2.de;
    return shorten(fMul);
}

Fraction operator / (Fraction f1, Fraction f2) {
    Fraction fDiv;
    fDiv.nu = f1.nu * f2.de;
    fDiv.de = f1.de * f2.nu;
    return shorten(fDiv);
}

float getVal(Fraction f) {
    float res = float(f.nu) / float(f.de);
    return res; 
}

Fraction findLarger(Fraction f1, Fraction f2) {
    // cout << "val of F1: " << f1.nu << "/" << f1.de << " = " << getVal(f1) << "\n";
    // cout << "val of F2: " << f2.nu << "/" << f2.de << " = " << getVal(f2) << "\n";
    if (getVal(f1) < getVal(f2)) {
        return f2;
    }
    else {
        return f1;
    }
}

Fraction findSmoller(Fraction f1, Fraction f2) {
    // cout << "val of F1: " << f1.nu << "/" << f1.de << " = " << getVal(f1) << "\n";
    // cout << "val of F2: " << f2.nu << "/" << f2.de << " = " << getVal(f2) << "\n";
    if (getVal(f1) > getVal(f2)) {
        return f2;
    }
    else {
        return f1;
    }
}

int main() {
	float a[10];
	Fraction x;
	
	int count = 0; 

	while (cin >> a[count]){
	    count++;
	}
	
	if (count == 1) {
	    x = a[0];
	    cout << shorten(x);
	    return 0;
	} else {
	    x.nu = a[0];
	    x.de = a[1];
	    cout << shorten(x);
	    cout << fixed << setprecision(4) << getVal(x);
	}
	
	return 0;
}