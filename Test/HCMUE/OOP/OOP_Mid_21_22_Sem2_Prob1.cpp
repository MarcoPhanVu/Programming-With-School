#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;

class Stock {
    private:
        string code;
        int amount;
        float value[100];
    public:
        Stock (string _code = "", int _amount = 0, float _value[] = new float[0]) {
            code = _code;
            for (int i = 0; i < amount; i++) {
                value[i] = _value[i];
            }
        }

        Stock (const Stock &s) {
            code = s.code;
            amount = s.amount;
            for (int i = 0; i < s.amount; i++)
			    value[i] = s.value[i];
        }
        ~Stock() {}

        float& operator[](int index) {
            return value[index];
        }

        friend istream& operator >> (istream& is, Stock& s) {
            is >> s.code;
            is >> s.amount;
            int count = 0;

            // while (count < s.amount) {
            //     is >> s.value[count];
            //     ++count;
		    // }

            for (int i = 0; i < s.amount; ++i) {
                is >> s.value[i];
            }

		    return is;
        }

        float getOpenValue() {
            return value[0];
        }

        float getCloseValue() {
            return value[amount - 1];
        }

        float getDiff() {
            return (-1 * (getOpenValue() - getCloseValue()));
        }
        
        float getPerDiff() {
            return (getDiff()/getOpenValue() * 100);
        }

        friend ostream& operator << (ostream& os, Stock s) {
            os << s.code << "|"; 
            os << setprecision(2) << fixed << s.getOpenValue() << "|";
            os << setprecision(2) << fixed << s.getCloseValue() << "|";
            os << setprecision(2) << fixed << s.getDiff() << "|";
            os << setprecision(2) << fixed << s.getPerDiff() << "\n";
            return os;
        }
};

int main() {
    int a; //amount of Stocks
    cin >> a;
    // Stock arr[a]; //arr of Stocks

    // Using For loop will not be able to end the loop somehow?
    // So better using while loop and print out the result asap

    // for (int i = 0; i < a; ++i) { 
    //     cin >> arr[i];
    //     cout << arr[i];
    // }

    Stock s;
    while ( a-- ) {
        cin >> s;
        cout << s;
    }
    
    return 0;
}