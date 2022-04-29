#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class DIEM {
private:
	int n;
	double a[1000];
public:
	// Get - Set
	int getN() { return n; }
	void setN(int _n) { n = _n; }
	double& operator [](int index) {
		return a[index];
	}
	// Hàm ktao - hủy
	/*DIEM() {
		n = 1;
		a[0] = 0;
	}*/
	DIEM(double _a[0] = new double [1], int _n = 0) {
		n = _n;
		for (int i = 0; i < n; i++) {
			a[i] = _a[i];
		}
	}
	DIEM(const DIEM& p) {
		n = p.n;
		for (int i = 0; i < n; i++) {
			a[i] = p.a[i];
		}
	}
	~DIEM() { n = 0; }
	// Nhập Xuất
	friend istream& operator >> (istream& is, DIEM& p) {
		p.n = 0;
		while (is >> p.a[p.n]) {
			p.n++;
		}
		return is;
	}
	friend ostream& operator << (ostream& os, DIEM p) {
		for (int i = 0; i < p.n; i++) {
			os << p.a[i];
		}
		return os;
	}
	// Hỗ trợ
	double getDTB() {
		double dtb = 0;
		for (int i = 0; i < n; i++) {
			dtb = dtb + a[i];
		}
		return dtb / n;
	}
	bool operator < (DIEM d) {
		return getDTB() < d.getDTB();
	}
}; // Lớp Điểm
class SinhVien {
private:
	string hoten;
	string mssv;
	DIEM d;
public:	
	string getHoTen() { return hoten; }
	string getMSSV() { return mssv; }
	DIEM getd() { return d; }
	void setHoTen(string _hoten) {
		hoten = _hoten;
	}
	void setMSSV(string _mssv) {
		mssv = _mssv;
	}
	void setd(DIEM _d) {
		d = _d;
	}

	/*SinhVien() {
		hoten = "name";
		mssv = "mssv";
	}*/
	SinhVien(string _hoten = "name", string _mssv = "mssv", DIEM _d = DIEM()) {
		hoten = _hoten;
		mssv = _mssv;
		d = _d;
	}
	SinhVien(const SinhVien& s) {
		hoten = s.hoten;
		mssv = s.mssv;
		d = s.d;
	}
	~SinhVien() {	}

	friend istream& operator >> (istream& is, SinhVien& p) {
		getline(is, p.hoten);
		getline(is, p.mssv);
		is >> p.d;
		return is;
	}
	friend ostream& operator << (ostream& os, SinhVien p) {
		os << "Ho Ten: " << p.hoten << endl;
		os << "Ma Sinh Vien: " << p.mssv << endl;
		os << "DTB: " << fixed << setprecision(1) << p.d.getDTB();
		return os;
	}
	double DTB() {
		return d.getDTB();
	}
	bool operator < (SinhVien sv) {
		return DTB() < d.getDTB();
	}
};
class MangSinhVien {
	int slpt;
	SinhVien s[100];
public:
	//get - set
	int getM()							{ return slpt; }
	void setM(int _slpt)				{ slpt = _slpt; }
	SinhVien& operator [] (int index)	{ return s[index]; }
	//ktao - huy
	MangSinhVien(SinhVien _s[] = new SinhVien[0], int _slpt = 0) {
		slpt = _slpt;
		for (int i = 0; i < slpt; i++) {
			s[i] = _s[i];
		}
	}
	MangSinhVien(const MangSinhVien& q) {
		slpt = q.slpt;
		for (int i = 0; i < slpt; i++) {
			s[i] = q.s[i];
		}
	}
	~MangSinhVien() { slpt = 0; }
	//ham ho tro
	friend istream& operator >> (istream& is, MangSinhVien& p) {
		is >> p.slpt;
		for (int i = 0; i < p.slpt; i++) {
			cin.ignore();
			cin.clear();
			is >> p.s[i];		// ???
		}
		return is;
	}
	friend ostream& operator << (ostream& os, MangSinhVien p) {
		for (int i = 0; i < p.slpt; i++) {
			os << p.s[i] << endl;
		}
		return os;
	}
	double getDTBSV() {
		double tong = 0;
		for (int i = 0; i < slpt; i++) {
			tong = tong + s[i].DTB();
		}
		return tong / slpt;
	}
	int getDTBLonNhat() {
		int imax = 0;
		for (int i = 1; i < slpt; i++) {
			if (s[i].DTB() > s[imax].DTB())
				imax = i;
		}
		return imax;
	}


};
int main() {
	MangSinhVien q;
	cin >> q;
	cout << q;
	cout << q.getDTBSV();
	cout << q[q.getDTBLonNhat()];

}