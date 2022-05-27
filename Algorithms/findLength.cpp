#include <iostream>


int main() {
    int arr1[10];
    int arr2[10] = {22, 55, 33, 11, 66, 77, 24, 99, 44, 88};
    int arr3[8] = {22, 11, 66, 77, 24, 99, 44, 88};
    int arr4[5] = {22, 11, 77, 24, 99};
    std::cout << "Len of arr1 = " << sizeof(arr1) / sizeof(int) << "\n"; // = 10
    std::cout << "Len of arr2 = " << sizeof(arr2) / sizeof(int) << "\n"; // = 10
    std::cout << "Len of arr3 = " << sizeof(arr3) / sizeof(int) << "\n"; // = 8
    std::cout << "Len of arr4 = " << sizeof(arr4) / sizeof(int) << "\n\n"; // = 5
    return 0;
}