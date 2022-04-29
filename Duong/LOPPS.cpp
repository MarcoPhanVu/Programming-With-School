#include<iostream>
#include<algorithm>//thu vien giai thuat
using namespace std;
class PhanSo{
    int tu, mau;
public:
    void Settu(int _tu){//ham gan
        tu=_tu;
    }
    int Gettu(){//ham lay
        return tu;
    }
    void Setmau(int _mau){
        mau=_mau;
    }
    int Getmau(){//ham lay
        return mau;
    }
    PhanSo (int _tu=0, int _mau=1){// khoi tao co tham so
        tu=_tu;
        mau=_mau;
    }
    // PhanSo (){// khai bao mac dinh khong tham so 
    //     tu=0;
    //     mau=1;
    // }
    
    PhanSo( const PhanSo & p){
        tu=p.tu; 
        mau=p.mau;
    }   //ham sao chep
        // sau p. thi lay ten cua PhanSo
    ~PhanSo(){}
    friend istream& operator >> (istream& is, PhanSo&p){
        is>>p.tu>>p.mau;
        return is;
    }
    friend ostream& operator << (ostream& os, PhanSo p){
        os<<p.tu<<"/"<<p.mau;
        return os;
    }
    PhanSo nghichDao(PhanSo p){
        PhanSo kq = p;
        kq.tu=kq.tu+kq.mau;
        kq.mau=kq.tu-kq.mau;
        kq.tu=kq.tu-kq.mau;
        return kq;
    }
    PhanSo rutGon(){//khong thay doi phan so ban dau
        int kq;
        kq= __gcd(tu, mau);
        tu=tu/kq;
        mau=mau/kq;
        return *this;
    }
    PhanSo operator + (PhanSo p){
        PhanSo kq;
        kq.tu= tu*p.mau + mau*p.tu;
        kq.mau= p.mau*mau;
        return kq;
    }
    PhanSo operator - (PhanSo p){
        PhanSo kq;
        kq.tu= tu*p.mau - mau*p.tu;
        kq.mau= p.mau*mau;
        return kq;
    }
    PhanSo operator * (PhanSo p){
        PhanSo kq;
        kq.tu=tu*p.tu;
        kq.mau=mau*p.mau;
        return kq;
    }
    PhanSo operator / (PhanSo p){
          PhanSo kq;
        kq.tu=tu*p.mau;
        kq.mau=mau*p.tu;
        return kq;
    }
    bool operator == (PhanSo p){
        return (tu*p.mau == mau*p.tu);
    }
    PhanSo operator + (int k){
        tu=tu+k;
        mau=mau+k;
        return *this;
    }

};
int main(){
    PhanSo p;
    int k;
    cin>>p;
    cin>>k;
    PhanSo p1 = p;
    cout<< p.Gettu()<<endl;
    cout<< p.Getmau()<<endl;
    cout<<p.nghichDao(p)<<endl;
    cout<<p.rutGon()<<endl;
    p1=p1+k;
    cout<<p1<<endl;
    PhanSo p2=p*p1;
    cout<<p2.rutGon();
}