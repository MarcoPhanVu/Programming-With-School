#include<iostream>

using namespace std;

int main() {
    int i = 0; //for counting
    int arr[1000];
    int totalPrice = 0, basePrice = 50, bedroomPrice = 17, bathroomPrice = 12.5, carInGarage = 6;

    while (cin >> arr[i]) {
        if (arr[i] == 0) {
            break;
        }
        
        cin >> arr[i + 1] /*bathroom*/ >> arr[i + 2] /*car*/;
        totalPrice += basePrice + arr[i] * bedroomPrice + arr[i + 1] * bathroomPrice + arr[i + 2] * carInGarage;
        i += 3;
    }
    
    cout << "Total price: " << totalPrice * 1000; //lười ghi số 0 vl

}
