#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

struct PhanSo
{
	int a, b;
};

istream& operator >> (istream& in, PhanSo& p);
ostream& operator << (ostream& out, PhanSo p);
bool operator == (const PhanSo& p1, const PhanSo& p2);
bool operator < (const PhanSo& p1, const PhanSo& p2);
bool operator > (const PhanSo& p1, const PhanSo& p2);
PhanSo operator + (PhanSo p1, PhanSo p2);

template<typename T>
struct Mang
{
	int n;
	T a[100];
	T& operator [] (int i)
	{
		return a[i];
	}
};

template<typename T>
istream& operator >> (istream& in, Mang<T>& a);
template<typename T>
ostream& operator << (ostream& out, Mang<T>& a);
template <typename T>
Mang<T> operator + (Mang<T> a, Mang<T> b);

template<typename T>
T tongPhanTu (Mang<T> a);
template<typename T>
T phanTuMax (Mang<T> a);
template<typename T>
void Sapxep(Mang<T>& a, char c);

int UCLN(int a, int b);
void rutGon(PhanSo& p);
template <typename T>
void xuatChanLe(Mang<T> a, int n);

int main()
{
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	char c;
	infile >> c;
	if (c == 'I')
	{
		Mang<int> a1, a2, sa;
		infile >> a1;
		infile >> a2;
		Mang<int>tam_a1=a1, tam_a2=a2;
		outfile << a1 << endl;
		outfile << "MAX 1 = " << phanTuMax(a1) << endl;
		outfile << "SUM 1 = " << tongPhanTu(a1) << endl;
		Sapxep(a1, '<');
		xuatChanLe(a1, 2);
		xuatChanLe(a1, 1);
		outfile << endl;
		outfile << a2 << endl;
		outfile << "MAX 2 = " << phanTuMax(a2) << endl;
		outfile << "SUM 2 = " << tongPhanTu(a2) << endl;
		Sapxep(a2, '>');
		xuatChanLe(a2, 1);
		xuatChanLe(a2, 2);
		outfile << endl;
		sa = tam_a1 + tam_a2;
		outfile << sa;
	}
	if (c == 'F')
	{
		Mang<PhanSo> p1, p2, sp;
		infile >> p1;
		infile >> p2;
		Mang<PhanSo> tam_p1 = p1, tam_p2 = p2;
		for (int i = 0; i < p1.n; i++) rutGon(p1[i]);
		outfile << p1 << endl;
		outfile << "MAX 1 = " << phanTuMax(p1) << endl;
		outfile << "SUM 1 = " << tongPhanTu(p1) << endl;
		Sapxep(p1,'<');
		outfile << p1 << endl;
		for (int i = 0; i < p2.n; i++) rutGon(p2[i]);
		outfile << p2 << endl;
		outfile << "MAX 2 = " << phanTuMax(p2) << endl;
		outfile << "SUM 2 = " << tongPhanTu(p2) << endl;
		Sapxep(p2,'>');
		outfile << p2 << endl;
		sp = tam_p1 + tam_p2;
		outfile << sp;
	}
	infile.close();
	outfile.close();
	return 0;
}

istream& operator >> (istream& in, PhanSo& p)
{
	char c;
	in >> p.a >> c >> p.b;
	return in;
}

ostream& operator << (ostream& out, PhanSo p)
{
	out << p.a << "/" << p.b;
	return out;
}

PhanSo operator + (PhanSo p1, PhanSo p2)
{
	PhanSo p;
	p.a = p1.a * p2.b + p2.a * p1.b;
	p.b = p1.b * p2.b;
	rutGon(p);
	return p;
}

int UCLN(int a, int b)
{
    while (a != b)
    {
        if (a > b) a -= b;
        if (b > a) b -= a;
    }
    return a;
}

void rutGon(PhanSo& p)
{
    int uc = UCLN(p.a, p.b);
    p.a = p.a / uc;
    p.b = p.b / uc;
}

bool operator == (const PhanSo& p1, const PhanSo& p2)
{
	return (p1.a * p2.b == p2.a * p1.b);
}
bool operator < (const PhanSo& p1, const PhanSo& p2)
{
	return (p1.a * p2.b < p2.a * p1.b);
}
bool operator > (const PhanSo& p1, const PhanSo& p2)
{
	return (p1.a * p2.b > p2.a * p1.b);
}

template<typename T>
istream& operator >> (istream& in, Mang<T>& a)
{
	in >> a.n;
	for (int i = 0; i < a.n; i++)
	{
		in >> a[i];
	}
	return in;
}

template<typename T>
ostream& operator << (ostream& out, Mang<T>& a)
{
	for (int i = 0; i < a.n; i++)
	{
		out << a[i] << " ";
	}
	return out;
}

template<typename T>
T tongPhanTu (Mang<T> a)
{
	T s = a[0];
	for (int i = 1; i < a.n; i++)
	{
		s = s + a[i];
	}
	return s;
}

template<typename T>
T phanTuMax(Mang<T> a)
{
	T max = a[0];
	for (int i = 1; i < a.n; i++)
	{
		if (max < a[i]) max = a[i];
	}
	return max;
}

template <typename T>
void Sapxep(Mang<T>& a, char c)
{
	if (c == '>')
	{
		for (int i = 0; i < a.n; i++)
		{
			for (int j = i + 1; j < a.n; j++)
			{
				if (a[i] < a[j])
				{
					T tam = a[i];
					a[i] = a[j];
					a[j] = tam;
				}
			}
		}
	}
	else if (c == '<')
	{
		for (int i = 0; i < a.n; i++)
		{
			for (int j = i + 1; j < a.n; j++)
			{
				if (a[i] > a[j])
				{
					T tam = a[i];
					a[i] = a[j];
					a[j] = tam;
				}
			}
		}
	}
}

template <typename T>
void xuatChanLe(Mang<T> a, int n)
{
	if (n == 1)
	{
		for (int i = 0; i < a.n; i++)
		{
			if (a[i] % 2 != 0) cout << a[i] << " ";
		}
	}
	else if (n == 2)
	{
		for (int i = 0; i < a.n; i++)
		{
			if (a[i] % 2 == 0) cout << a[i] << " ";
		}
	}
}

template <typename T>
Mang<T> operator + (Mang<T> a, Mang<T> b)
{
	Mang<T> tong;
	if (a.n > b.n)
	{
		tong = a;
		for (int i = 0; i < b.n; i++) tong[i] = tong[i] + b[i];
	}
	else if (a.n == b.n)
	{
		tong = a;
		for (int i = 0; i < b.n; i++) tong[i] = tong[i] + b[i];
	}
	else
	{
		tong = b;
		for (int i = 0; i < a.n; i++) tong[i] = tong[i] + a[i];
	}
	return tong;
}