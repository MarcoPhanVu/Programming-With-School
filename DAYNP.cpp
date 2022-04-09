#include <iostream>
#include <string>

using namespace std;

string Binary(string bin) {
    string temp = bin;
    int i = bin.length();
    if (bin[i] == '1' && bin[i - 1] == '1') {

    }
}

int main() {
    int n;
    cin >> n;
    string res = "";
    for (int i = 0; i < n; i++) {
        res += "0";
    }
    cout << "res= " << res;
    Binary(res);
    return 0;
}