#include<iostream>
using namespace std;

class Oopb1
{
	int len;
	int a[50];
public:
	Oopb1(int _len = 0, int _a[] = 0)
	{
		len = _len;
		for (int i = 0; i < len; i++)
			a[i] = _a[i];
	}
	Oopb1(const Oopb1 &p)
	{
		len = p.len;
		for (int i = 0; i < len; i++)
			a[i] = p.a[i];
	}
	~Oopb1() {}
	friend istream& operator >> (istream& is,Oopb1 &p)
	{
		for (int k = 0; k < p.len; k++)
		{
			is >> p[k];
		}
		return is;
	}
	friend ostream& operator << (ostream& os, Oopb1 p)
	{
		for (int i = 0; i < p.len; i++)
		{
			os << p.a[i] << " ";
		}
		return os;
	}
	friend Oopb1 operator + (Oopb1 c, Oopb1 b)
	{
		int out[50];
		if (c.len > b.len)
		{
			for (int i = 0; i < c.len; i++)
			{
				int out[50];
				for (int j = 0; j < c.len; j++)
				{
					out[j] = c.a[i] + b.a[i];
				}
			}
		}
		else
		{
			for (int i = 0; i < b.len; i++)
			{
				for (int j = 0; j < b.len; j++)
				{
					out[j] = c.a[i] + b.a[i];
				}
			}
		}
		return out[50];
	}
};

int main()
{
    int n;
	cout << "nhập số lượng dãy số bạn cần tính: "; 
	cin >> n;
    Oopb1 objArr[n]; //Số lượng Oopb1 m muốn nhập
    int len; //độ dài các mảng, reset mỗi khi lặp
    int lenArr[n]; //Độ dài mảng tương ứng với từng dãy Oob1 của m.
    
    for (int i = 0; i < n; ++i) {
        cin >> objArr[i].len; //nhập vào độ dài của cái Oob1
        cin >> objArr[i];
    }

	return 0;
}