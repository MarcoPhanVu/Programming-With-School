#include <iostream>
#include <string>

using namespace std;
class Khach{
    string ten;
    int tgian, smay, dgia;
public:
    Khach(string _ten=" ", int _tgian=0, int _smay=0, int _dgia=0): ten(_ten), tgian(_tgian), smay(_smay), dgia(_dgia) {}
    Khach(const Khach &k): ten(k.ten), tgian(k.tgian), smay(k.smay), dgia(k.dgia) {}
    int getTgian() {return tgian;}
    void Dgiav(int a, int b){dgia=a*b;}
    void Dgiatx(int a, int b, int c){dgia=a*b-a*c;}
    void Dgiaktx(int a, int b, int c, int d){dgia=a*b+c*d;}
    virtual void Input(){}
    void Input1(){
        getline(cin,ten);
        cin>>tgian>>smay;
    }
    void Output(int &i, string &info){
        cout<<i<<". Loai khach: "<<info<<endl;
        cout<<"Ho Ten: "<<ten<<endl;
        cout<<"Thoi gian su dung: "<<tgian<<endl;
        cout<<"So may: "<<smay<<endl;
        cout<<"So tien phai tra: "<<dgia<<endl<<endl;
    }
    virtual void Dongia(int &gia, int &giak){}
};
class KhachVIP: public Khach{ 
public:
    KhachVIP(string _ten=" ", int _tgian=0, int _smay=0, int _dgia=0): Khach(_ten, _tgian, _smay, _dgia) {}
    KhachVIP(const KhachVIP &k): Khach(k) {}
    void Dongia(int &gia, int &giak){
        if(getTgian()>=4) Dgiav(gia,4);
        else Dgiav(giak,getTgian());
    }
    void Input(){
      Input1();
    }
};
class KhachTX: public Khach{
    int hskm;
public:
    KhachTX(string _ten=" ", int _tgian=0, int _smay=0, int _dgia=0, int _hskm=0): Khach(_ten, _tgian, _smay, _dgia), hskm(_hskm) {}
    KhachTX(const KhachTX &k): Khach(k), hskm(k.hskm) {}
    void Input(){
        Input1();
        cin>>hskm;
    }
    void Dongia(int &gia, int &giadl){
        Dgiatx(getTgian(), gia, hskm);
    }
};
class KhachKTX: public Khach{
    int dungluong;
public:
    KhachKTX(string _ten=" ", int _tgian=0, int _smay=0, int _dgia=0, int _dungluong=0): Khach(_ten, _tgian, _smay, _dgia), dungluong(_dungluong) {}
    KhachKTX(const KhachKTX &k): Khach(k), dungluong(k.dungluong) {}
    void Input(){
        Input1();
        cin>>dungluong;
    }
    void Dongia(int &gia, int &giak){
        Dgiaktx(getTgian(), gia, dungluong, giak);
    }
};
int main(){
    int n, t, tv, tdl, i=1;
    string info;
    cin>>n>>t>>tv>>tdl;
    Khach *p;
    KhachVIP v;
    KhachTX tx;
    KhachKTX ktx;
    while (n--){
        cin.ignore();
        getline(cin, info);
        if(info=="VIP") p = &v;
        else if(info=="TX") p = &tx;
        else if(info=="KTX") p = &ktx;
        p->Input();
        if(info=="VIP") p->Dongia(tv,t);
        else if(info=="TX") p->Dongia(t,tdl);
        else if(info=="KTX") p->Dongia(t,tdl);
        p->Output(i,info);
        i++;
    }
}