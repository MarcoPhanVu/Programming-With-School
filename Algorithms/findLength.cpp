#include <iostream>

// int findLength(int arr[]) {
//     return sizeof(arr) / sizeof(int);
// }

int main() {
    int arr1[10];
    int arr2[10] = {22, 55, 33, 11, 66, 77, 24, 99, 44, 88};
    std::cout << "Len of arr1 = " << sizeof(arr1) / sizeof(int) << "\n"; // = 10
    std::cout << "Len of arr2 = " << sizeof(arr2) / sizeof(int) << "\n"; // = 10
    return 0;
}