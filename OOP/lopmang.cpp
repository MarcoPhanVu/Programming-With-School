#include <iostream>
// #include <cmath>

// using namespace std;

//class LOPMANG

class ArrayClass {
    private:
        int s; //size of array
        int arr[100]; //array
    public:
        //Constructor
        ArrayClass(int newS = 0, int newArr[] = new int [0]) { 
            //return 0 if there is no parameters/arguments passed in it
            //if a parameters/arguments is an array ->  newArr[] = new int [0]
            s = newS;
            for (int i = 0; i < s; i++) {
                arr[i] = newArr[i];
            }
        }

        //Copy Constructor
        ArrayClass(const ArrayClass& anArray) {
            s = anArray.s;
            for (int i = 0; i < s; i++) {
                arr[i] = anArray.arr[i];
            }
        }
        ~ArrayClass() {}

        int getSize() {
            return s;
        }

        void setSize(int newSize) {
            s = newSize;
        }

        // if class has arra -> overload index("[]") operator
        int& operator [] (int index){
            return arr[index];
        }

        int getValAt(int index) {
            return arr[index];
        }

        void setValAt(int index, int value) {
            arr[index] = value;
        }

        friend std::istream& operator >> (std::istream& is, ArrayClass& arrClass) {
            while (is >> arrClass[arrClass.s]) { //cin new element without knowing the true size of the array
                arrClass.s++;
            }
            return is;
        }

        friend std::ostream& operator << (std::ostream& os, ArrayClass arrClass) {
            for (int i = 0; i < arrClass.s; i++) {
                os << arrClass[i] << " ";
            }
            std::cout << "\n";
            return os;
        }

        void hasVal(int val) {
            for (int i = 0; i < s; i++) {
                if (arr[i] == val) {
                    std::cout << "TRUE\n";
                    return;
                }
            }
            std::cout << "FALSE\n";
        }

        void ascendSort() {
            
        }      
};

void swap(int &a, int &b) {
    a += b;
    b = a - b;
    a = a - b;
}




int main() {
    int x;
    std::cin >> x;
}

