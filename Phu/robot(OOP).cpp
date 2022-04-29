#include <iostream>
#include <string>
using namespace std;
class Robot {
    string Name, UserName;
    int EnergyLevel, LocationX, LocationY;
public:
    int x;
    int getE() {return EnergyLevel;}
    void E(int e) {EnergyLevel-=e;}
    Robot(string name="Robot", string username=" ", int energylevel=100, int x=0, int y=0): Name(name), UserName(username), EnergyLevel(energylevel), LocationX(x), LocationY(y) {}
    Robot(const Robot &r): Name(r.Name), UserName(r.UserName), EnergyLevel(r.EnergyLevel), LocationX(r.LocationX), LocationY(r.LocationY) {}
    void Charge(){ EnergyLevel+=10;}
    void buocdi(int &direction){
        switch (direction){
            case 0: LocationX-=1; break;
            case 1: LocationX+=1; break;
            case 2: LocationY+=1; break;
            case 3: LocationY-=1; break;
            }
    }
    virtual bool Move(int direction){
        if (EnergyLevel==0) return false;
        else buocdi(direction);
            EnergyLevel-=5;
        }
    void Input(){
        getline(cin, Name);
        getline(cin, UserName);
        cin>>EnergyLevel>>LocationX>>LocationY;
    }
    void Display(char &k){
        cout<<"{"<<k<<Name<<"} : {"<<UserName<<"}"<<endl;
        cout<<"("<<LocationX<<","<<LocationY<<")"<<endl;
        cout<<EnergyLevel<<endl;
    }
};
class AdaptiveRobot: public Robot {
public:
    AdaptiveRobot(string name="AdaptiveRobot", string username=" ", int energylevel=100, int x=0, int y=0)
    : Robot(name, username, energylevel, x, y) {}
    AdaptiveRobot(const AdaptiveRobot &r): Robot(r) {}
    bool Move(int direction){
        buocdi(direction);
    }
};
int main(){
    Robot r, *p;
    AdaptiveRobot ar;
    char k; int n; cin>>n;
    while (n--){
        int dem;
        bool c=true;
        int i=0;
        cin>>k;  if (k!='A') p=&r; else p=&ar;
        p->Input();
        if (k!='A') while (cin>>p->x){
                    if(p->x==4) p->Charge();
                    else if(p->x>=0 && p->x<=3) p->Move(p->x);
                    else if(p->x==-1) {c=false; break;}
                }
        else while (c==true){
            if (p->getE()<=20) dem=1;
            else if(p->getE()>=20 && p->getE()<=50) dem=2;
            else if(p->getE()>50) dem=3; 
            while (dem--){
                cin>>p->x;
                if(p->x==-1) {c=false; break;}
                else if(p->x>=0 && p->x<=3) p->Move(p->x);
                else if(p->x==4) p->Charge();
                switch (dem){
                    case 1: p->E(6); break;
                    case 2: p->E(9); break;
                    case 3: p->E(12); break;
                }
            }
        }
        p->Display(k);
    }
}