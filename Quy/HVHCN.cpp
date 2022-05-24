#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class HCN {
	double dai, rong;
public:
	HCN(double x = 0, double y = 0) {
		//cout << "HCN duoc tao" << endl;
		dai = x;
		rong = y;
	}
	HCN(const HCN& h) {
		//cout << "HCN duoc tao" << endl;
		dai = h.dai;
		rong = h.rong;
	}
	~HCN() {
		//cout << "HCN duoc huy" << endl; 
	}
	void Set(double x, double y) {
		dai = x;
		rong = y;
	}

	friend istream& operator >>(istream& is, HCN& h) {
		is >> h.dai >> h.rong;
		return is;
	}
	friend ostream& operator <<(ostream& os, HCN h) {
		
		return os;
	}

	double DT() {
		return dai * rong;
	}
	double CV() {
		return (dai + rong) * 2;
	}
	double getDai() {
		return dai;
	}
};

class HV :public HCN {
	double canh;
public:
	HV(double _canh = 0) {
		//cout << "HV duoc tao" << endl;
		canh = _canh;						HCN::Set(canh, canh);			//HThoi::Set(canh, 90);
	}
	HV(const HV& h) {
		//cout << "HV duoc tao" << endl;
		canh = h.canh;						HCN::Set(canh, canh);			//HThoi::Set(canh, 90);
	}
	~HV() {
		//cout << "HV duoc huy" << endl; 
	}
	void Set(double _canh) {
		canh = _canh;						HCN::Set(canh, canh);			//HThoi::Set(canh, 90);
	}

	friend istream& operator >>(istream& is, HV& h) {
		is >> h.canh;
		h.HCN::Set(h.canh, h.canh);				//C1: goi ham toi doi tuong
		//h = HV(h.canh);						//C2: khoi tao doi tuong
		return is;
	}
	friend ostream& operator <<(ostream& os, HV h) {

		return os;
	}
	/*double DT() {
		return canh * canh;
	}*/
	/*double DT() {
		return HThoi::DT;
	}*/
};

int main() {
	string q;
	cin >> q;
	//cout << q;
	int n = 0;
	double maxCV;
	if (q == "HCN") {
		HCN h[100];
		while (cin >> h[n]) {
			n++;
		}
		maxCV = h[0].CV();
		for (int i = 0; i < n; i++) {
			if (h[i].CV() > h[0].CV()) {
				maxCV = h[i].CV();
			}
		}
	}
	else {
		HV h[100];
		while (cin >> h[n]) {
			n++;
		}
		maxCV = h[0].CV();
		for (int i = 0; i < n; i++) {
			if (h[i].CV() > h[0].CV()) {
				maxCV = h[i].CV();
			}
		}
	}
}


//#include <iostream>
//#include <cmath>
//using namespace std;
//
//class HCN {
//	double dai, rong;
//public:
//	HCN(double x = 0, double y = 0) {
//		cout << "HCN duoc tao" << endl;
//		dai = x;
//		rong = y;
//	}
//	HCN(const HCN& h) {
//		cout << "HCN duoc tao" << endl;
//		dai = h.dai;
//		rong = h.rong;
//	}
//	~HCN() { cout << "HCN duoc huy" << endl; }
//	void Set(double x, double y) {
//		dai = x;
//		rong = y;
//	}
//	double DT() {
//		return dai * rong;
//	}
//	double CV() {
//		return (dai + rong) * 2;
//	}
//	double getDai() {
//		return dai;
//	}
//};
//class HThoi {
//	double canh, goc;
//public:
//	HThoi(double _canh = 0, double _goc = 0) {
//		cout << "HThoi duoc tao" << endl;
//		canh = _canh;
//		goc = _goc;
//	}
//	HThoi(const HThoi& h) {
//		cout << "HThoi duoc coyp" << endl;
//		canh = h.canh;
//		goc = h.goc;
//	}
//	~HThoi() { cout << "HThoi duoc huy" << endl; }
//	void Set(double _canh, double _goc) {
//		canh = _canh;
//		goc = _goc;
//	}
//	double DT() {
//		return canh * canh* sin(goc * 3.14 / 180);
//	}
//};
//class HV :public HCN, public HThoi {
//	double canh;
//public:
//	HV(double _canh = 0) {
//		cout << "HV duoc tao" << endl;
//		canh = _canh;						HCN::Set(canh, canh);			//HThoi::Set(canh, 90);
//	}
//	HV(const HV& h) {
//		cout << "HV duoc tao" << endl;
//		canh = h.canh;						HCN::Set(canh, canh);			//HThoi::Set(canh, 90);
//	}
//	~HV() { cout << "HV duoc huy" << endl; }
//	void Set(double _canh) {
//		canh = _canh;						HCN::Set(canh, canh);			//HThoi::Set(canh, 90);
//	}
//	/*double DT() {
//		return canh * canh;
//	}*/
//	/*double DT() {
//		return HThoi::DT;
//	}*/
//};
//
//class TG {
//	double a, b, c;
//public:
//	TG(double _a = 0, double _b = 0, double _c = 0) {
//		a = _a;
//		b = _b;
//		c = _c;
//	}
//	TG(const TG& t) {
//		a = t.a;
//		b = t.b;
//		c = t.c;
//	}
//	~TG(){}
//
//	void Set(double _a = 0, double _b = 0, double _c = 0) {
//		a = _a;
//		b = _b;
//		c = _c;
//	}
//
//	double getCV() { return a + b + c; }
//	double getDT() {
//		double p = getCV() / 2;
//		return sqrt(p * (p - a) * (p - b) * (p - c));
//	}
//};
//class TGDeu :public TG {
//	double a;
//public:
//	TGDeu(double _a = 0) { 
//		a = _a;					TG::Set(a, a, a);
//	}	
//	TGDeu(const TGDeu& t) {
//		a = t.a;				TG::Set(a, a, a);
//	}
//	~TGDeu() { }
//
//};
//
//int main() {
//	//HCN hcn = HCN(2, 4);
//	//HV hv = HV(3);
//	//cout << hv.DT() << endl;
//	//cout<<hv.Set()<<endl;
//	//TG t = TG(3, 4, 5);
//	//cout << t.getCV() << endl;
//	//cout << t.getDT() << endl;
//}