#include <iostream>
#include <string>
using namespace std;

void printBoard(string str, int showed) {
    string line = "++++++++++++++++++++++"; //22
    int front = 20 - showed;
    int back = 0;
    cout << line << "\n";
    cout << "+";
    
    for (int i = 0; i < front; front++) {//blank space before
        if (front <= 0) {
            break;
        }
        cout << "+";
    }
    
    for (int i = 0; i < showed; i++) {
        cout << str[i];
    }
    
    int subtract = 20 - showed - front;


    for (back = 0; back < subtract; back++) { //blank space after
        if (subtract <= 0) {
            break;
        }
        cout << "+";
    }
    
    // cout << "f= " << front;
    cout << "+\n";
    cout << line << "\n";
}

int main() {
    string input;
    cin >> input;
    
    for (int i = 0; i <= input.length() + 20; i++) {
        printBoard(input, i);
    }
    
    return 0;
}