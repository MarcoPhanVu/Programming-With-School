#include <iostream>

using namespace std;

int findMin(int arr[], int min, int index, int arrLen) {
    if (arr[index] < min) {
        min = arr[index];
    }
    
    if (index == arrLen - 1) { //end when reached the end of the array
        return min;
    }
    
    return findMin(arr, min, index + 1, arrLen);
}

int main()
{
    int array[10] = {10, 5, 7, -2, 9, 6, 3, 2, 1, 4};
    
    for (int i = 0; i < 10; ++i) {
        cout << "arr[" << i << "]= " << array[i] << "\n";
    }
    
    cout << findMin(array, array[10], 0, 10);
    return 0;
}