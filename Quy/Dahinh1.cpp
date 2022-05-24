#include <iostream>
using namespace std;

class HCN {
	double dai, rong;
public:
	double getDai() { return dai; }
	void setDai(double d) { dai = d; }
	double getRong() { return rong; }
	void setRong(double d) { rong = d; }

	HCN(double _dai = 0, double _rong = 0) {
		dai = _dai;
		rong = _rong;
	}
	HCN(const HCN& h) {
		dai = h.dai;
		rong = h.rong;
	}
	~HCN(){}
	//Nhap-Xuat
	friend istream& operator >> (istream& is, HCN& s) {
		is >> s.dai >> s.rong;
		return is;
	}
	friend ostream& operator << (ostream& os, HCN s) {
		os << s.getCV();
		return os;
	}
	//Ham bo tro
	/*virtual double getCV() {
		return (dai + rong) * 2;
	}*/
	double getCV() {
		return (dai + rong) * 2;
	}
};
class HV : public HCN {
	double canh;
public:
	double getCanh() { return canh; }
	void setCanh(double d) { canh = d; }

	HV(double _canh = 0) {
		canh = _canh;
	}
	HV(const HV& v) {
		canh = v.canh;
	}
	~HV(){}

	friend istream& operator >> (istream& is, HV& s) {
		is >> s.canh;
		return is;
	}
	friend ostream& operator << (ostream& os, HV s) {
		os << s.getCV();
		return os;
	}
	double getCV() {
		return canh * 4;
	}
};

int main() {
	/*HCN x;
	cin >> x;
	cout << x.getCV();*/
	char s;
	while (cin >> s) {
		HCN* x;
		if (s == 'a') {
			double canh;
			cin >> canh;
			x = new HV(canh);
			cout << x->getCV() << endl;
		}
		else if (s == 'b') {
			double dai, rong;
			cin >> dai >> rong;
			x = new HCN(dai, rong);
			cout << x->getCV() << endl;
		}
	}
}