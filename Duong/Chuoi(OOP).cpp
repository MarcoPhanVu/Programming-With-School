#include<iostream>
#include<string>
using namespace std;

class Chuoi{
  string str;
  string nsx;
public:
    string Getstr(){
        return str;
    }
    void Setstr(string _str){
        str=_str;
    }
    Chuoi(string _Chuoi = " ",string _NSX=" "){ // hàm mặc định
        str= _Chuoi;
        nsx=_NSX;
    }
    
    Chuoi(const Chuoi &a ){
        str=a.str;
    }
    ~Chuoi(){}
    friend istream& operator >> (istream& is, Chuoi& a){
        getline(is,a.str);
        return is;
    }
    friend ostream& operator << (ostream& os, Chuoi a){
        os<<a.str<<endl;
        return os;
    }
    int getLength(){
        return str.size();
    }
    void UpperCase(){
        for(int i=0;i < str.size();i++){
            str[i]=toupper(str[i]);
        }
    }
    
};

int main(){
    Chuoi a,b;
    cin>>a>>b;
    cout<<a;
    cout<<b;
    if (a.getLength() < b.getLength()){
        cout<<"No"<<endl;
        b.UpperCase();
        cout<<b;
    }
    else {
        cout<<"YES"<<endl;
        a.UpperCase();
        cout<<a;
    }
    
    
    
}