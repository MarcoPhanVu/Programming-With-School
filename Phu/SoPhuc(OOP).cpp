#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Sophuc{
    private:
    int r,v;
    public:
    int getR () {return r;}
    void setR (int _r) {r=_r;}
    int getV () {return v;}
    void setV (int _v) {v=_v;}
    Sophuc (int _r=0, int _v=0){
        r=_r;
        v=_v;
    }
    Sophuc (const Sophuc &sp){
        r=sp.r;
        v=sp.v;
    }
    friend istream &operator>>(istream &in, Sophuc &sp){
        in>>sp.r>>sp.v;
        return in;
    }
    friend ostream &operator<<(ostream &out, Sophuc &sp){
        out<<"{";
        if(sp.r!=0) out<<sp.r;
        if(sp.v==1) out<<"+i";
        else if(sp.v==-1) out<<"-i";
        else if(sp.v>0) out<<"+"<<sp.v<<"i";
        else if(sp.v<0) out<<sp.v<<"i";
        out<<"}"<<" ";
        return out;
    }
    Sophuc operator+(Sophuc &sp){
    	Sophuc tong;
    	tong.r=r+sp.r;
    	tong.v=v+sp.v;
    	return tong;
    }
    Sophuc operator-(Sophuc &sp){
    	Sophuc hieu;
    	hieu.r=r-sp.r;
    	hieu.v=v-sp.v;
    	return hieu;
    }
    double modun(){
        double c;
        c=sqrt(r*r+v*v);
        return c;
    }
};
class Mangsp{
    private:
    int n; Sophuc s[10];
    public:
    void setN (int _n) {n=_n;}
    int getN () {return n;}
    Sophuc &operator[](int index) {return s[index];}
    Mangsp (int _n=0, Sophuc _s[0]=new Sophuc[0]){
        n=_n;
        for (int i=0; i<n; i++) s[i]=_s[i];
    }
    Mangsp (const Mangsp &m){
        n=m.n;
        for (int i=0; i<n; i++) s[i]=m.s[i];
    }
    friend istream &operator>>(istream &in, Mangsp &m){
        while (in>>m[m.n]) m.n++;
        return in;
    }
    friend ostream &operator<<(ostream &out, Mangsp &m){
        for (int i=0; i<m.n; i++){
            out<<m[i];
        }
        out<<endl;
        for (int i=0; i<m.n; i++){
            out<<setprecision(2)<<fixed<<m[i].modun();
            out<<" ";
        }
        out<<endl;
        Sophuc tong=m[0];
        for (int i=1; i<m.n; i++){
            tong=tong+m[i];
        }
        out<<tong;
        return out;
    }
    
};
int main(){
    Mangsp m;
    cin>>m;
    cout<<m;
}