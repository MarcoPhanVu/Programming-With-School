#include<iostream>
using namespace std;

class LopMang{
    int n;
    int a[100];
public:
    LopMang(int _n = 0, int _a[]=  new int [0]){
        n=_n;
        for(int i = 0;i < n; i++){
            a[i]=_a[i];
        } //mang thi phai la _a[]= new int [0]
    }
    LopMang (const LopMang& m ){
        n=m.n;
        for(int i = 0;i <= n; i++){
            a[i]=m.a[i];
        }
    }// them bien truyen vao (a.) truoc ten bien cua lop (LopMang)
    ~LopMang(){}
    int GetN(){
        return n;
    }
    void SetN(int _n){
        n = _n;
    }
    // co mang thi them operator cua index []
    int& operator [] (int index){
        return a[index];
    }
    LopMang Getphantu( int& i ){
        return a[i];
    }
    void Setphantu ( int i, int giatri){
        a[i]= giatri; 
    }
    
    friend istream& operator >> (istream& is, LopMang& p){
        while (is >> p[p.n]){
            p.n++;
        }
        return is;
    }
    friend ostream& operator << (ostream& os, LopMang p){
        for(int i = 0; i < p.n; i++){
            os << p[i] << " ";
 
        }
        cout << endl;
         return os;       
    }
    void timPT(int k){
        bool h = false;
        for (int i = 0 ; i < n;i++){
            if(k == a[i]){
                h =true;
                break;
            }
        } 
        if ( h == true) cout << "TRUE";
        else cout << "FALSE";
    }
    void sapXep(int c ){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (c == 0){
                    if(a[i] > a[j]){
                        swap(a[i], a[j]);
                    }
                }
                if (c == 1){
                    if(a[i] < a[j]){
                        swap(a[i], a[j]);
                    }
                }
            }
        }
    }
    void swap(int& a, int& b){
        a=a+b;
        b=a-b;
        a=a-b;
    }
};

int main(){
    LopMang p;
    int k;
    cin >> k;
    cin >> p;
    cout << p.GetN() << endl;
    p.timPT(k);
    cout << endl;
    LopMang p1=p;
    p1.sapXep(1);
    cout << p1 ;
    p[0]= p[0] + 1;
    p.sapXep(0);
    cout << p ;
}