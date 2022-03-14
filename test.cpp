#include <iostream>
using namespace std;
struct SoLaMa
{
    string chu;
    int so;
};
istream& operator >> (istream& in, SoLaMa& a);
ostream& operator << (ostream& out,  SoLaMa a);
int operator + (SoLaMa  a, SoLaMa  b);
string operator < (SoLaMa a, SoLaMa b);
int main() {
    SoLaMaa;
    cin>>a;
    cout<<a<<endl;
    return 0;
}
istream& operator >> (istream &in, SoLaMa &a)
{
	in >> a.chu;
   	if(a.chu=="I")a.so=1;
    if(a.chu=="II")a.so=2;
    if(a.chu=="III")a.so=3; 
    if(a.chu=="IV")a.so=4; 
    if(a.chu=="V")a.so=5; 
    if(a.chu=="VI")a.so=6; 
    if(a.chu=="VII")a.so=7; 
    if(a.chu=="VIII")a.so=8;
    if(a.chu=="IX")a.so=9;
    if(a.chu=="X")a.so=10;
	return in;
}

ostream& operator << (ostream &out, SoLaMa a)
{
    out << a.so;
    return out;
}
string operator < (SoLaMa a, SoLaMa b) return (a.so<b.so);
int operator + (SoLaMa  a, SoLaMa  b) return (a.so+b.so);