#include <iostream>
using namespace std;
struct SoLaMa
{
    string chu;
    int so;
};
istream& operator >> (istream &in, SoLaMa &n)
ostream& operator << (ostream &out, SoLaMa n)
bool operator < (SoLaMa n1, SoLaMa n2)
SoLaMa operator + (SoLaMa n1, SoLaMa n2)
int main()
{
    SoLaMa a, b;
    cin>>a>>b;
    cout<<a<<endln;
    cout<<b<<endln;
    cout<<a+b<<endln;
    if (a<b) cout<<"true";
    else cout<<"false";
    return 0;
}
istream& operator >>(istream &in, SoLaMa &n)
{
	in>>n.chu;
   	if(n.chu=="I") n.so=1;
    if(n.chu=="II") n.so=2;
    if(n.chu=="III")n.so=3; 
    if(n.chu=="IV")n.so=4; 
    if(n.chu=="V")n.so=5; 
    if(n.chu=="VI") n.so=6; 
    if(n.chu=="VII")n.so=7; 
    if(n.chu=="VIII") n.so=8;
    if(n.chu=="IX")n.so=9;
    if(n.chu=="X")n.so=10;
	return in;
}
ostream& operator << (ostream &out, SoLaMa n)
{
    out<<n.so;
    return out;
}
bool operator < (SoLaMa n2, SoLaMa n2) return (n2.so < n2.so);
SoLaMa operator + (SoLaMa n2, SoLaMa n2)
{
    SoLaMa tong;
    tong.chu = n2.chu + n2.chu;
    tong.so = n2.so + n2.so;
    return tong;
}