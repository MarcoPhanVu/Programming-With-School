#include <iostream>
using namespace std;
struct SoLaMa
{
  int n;
  string s;
  void operator = (SoLaMa sl)
  {
      n=sl.n;
  }
};
int GetN(string s)
{
    if(s=="I") return 1;
    if(s=="II") return 2;
    if(s=="III") return 3;
    if(s=="IV") return 4;
    if(s=="V") return 5;
    if(s=="VI") return 6;
    if(s=="VII") return 7;
    if(s=="VIII") return 8;
    if(s=="IX") return 9;
    if(s=="X") return 10;
    
}
istream& operator >> (istream& is,SoLaMa& l)
{
    is>>l.s;
    l.n=GetN(l.s);
    return is;
}
ostream& operator << (ostream& os,SoLaMa l)
{
    os<<l.n;
    return os;
}
bool operator < (SoLaMa mot,SoLaMa hai)
{
    return mot.n<hai.n;
}
int operator + (SoLaMa mot, SoLaMa hai)
{
    return mot.n+hai.n;
}

template<typename T>
struct Mang
{
    int n;
    T a[100];
    T& operator [](int i)
    {
        return a[i];
    }
};
template<typename T>
istream& operator >> (istream& is,Mang<T>& m)
{
    while(is>>m[m.n]){m.n++;}
    return is;
}
template<typename T>
ostream& operator <<(ostream& os,Mang<T> m)
{
    cout<<Timmax(m)<<endl;
    cout<<Tinhtong(m);
}
template<typename T>
T Timmax(Mang<T> m)
{
    T max=m[0];
    for(int i=0;i<m.n;i++)
    {
        if(max<m[i])
        {
            max=m[i];
        }
    }
    return max;
}
int Tinhtong(Mang<int> m)
{
    int sum=0;
    
    for(int i=0;i<m.n;i++)
    {
        sum+=m[i];
    }
    return sum;
}
int Tinhtong(Mang<SoLaMa> m)
{
    SoLaMa sum;
    sum.n=m[0].n;
    for(int i=1;i<m.n;i++)
    {
        sum.n=sum.n+m[i].n;
    }
    return sum.n;
}
int main()
{
    char s; cin>>s;
    Mang<int> m_in;
    Mang<SoLaMa> m_lm;
    if(s=='N')
    {
        cin>>m_in;
        cout<<m_in;
    }
    if(s=='L')
    {
        cin>>m_lm;
        cout<<m_lm;
    }
}