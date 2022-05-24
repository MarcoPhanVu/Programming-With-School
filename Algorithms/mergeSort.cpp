#include <iostream>
#include <fstream>

// ASCENDING
void mergeArray(int a[], int l, int m, int r) {
	int tempArr[100];
	int i = l;
	int j = m + 1;
	int count = l;

	while (i <= m && j <= r) { //gradually compare elements and sort them into a temporary array
		if (a[i] > a[j]) {
			tempArr[count] = a[j];
			++j;
			++count;
		} else {
			tempArr[count] = a[i];
			++i;
			++count;
		}
	}

	while (i <= m) { // put the excess elements into the temp arra(before mid + 1)
		tempArr[count] = a[i];
			++i;
			++count;
	}

	while (j <= r) { // put the excess elements into the temp arra(after mid)
		tempArr[count] = a[j];
			++j;
			++count;
	}

	for (i = l; i < count; i++) { // insert elements from temp arr to main arr
		a[i] = tempArr[i];
	}
}

void mergeSort(int array[], int leftPointer, int rightPointer) {
	if (leftPointer < rightPointer) {
		int middlePoint = (leftPointer + rightPointer)/2;

		mergeSort(array, leftPointer, middlePoint);
		mergeSort(array, middlePoint + 1, rightPointer);

		mergeArray(array, leftPointer, middlePoint, rightPointer);
	}

	return;
}

// DESCENDING 
void mergeArrayDesc(int a[], int l, int m, int r) { //same as ascending, just flipping some variables and symbols
	int tempArr[100];
	int i = l;
	int j = m + 1;
	int count = l;

	while (i <= m && j <= r) {
		if (a[i] > a[j]) {
			tempArr[count] = a[i];
			++count;
			++i;
		} else {
			tempArr[count] = a[j];
			++count;
			++j;
		}
	}

	while (i <= m) {
		tempArr[count] = a[i];
			++i;
			++count;
	}

	while (j <= r) {
		tempArr[count] = a[j];
			++j;
			++count;
	}

	for (i = l; i < count; i++) {
		a[i] = tempArr[i];
	}
}

void mergeSortDesc(int array[], int leftPointer, int rightPointer) {
	if (leftPointer < rightPointer) {
		int middlePoint = (leftPointer + rightPointer)/2;

		mergeSortDesc(array, leftPointer, middlePoint);
		mergeSortDesc(array, middlePoint + 1, rightPointer);

		mergeArrayDesc(array, leftPointer, middlePoint, rightPointer);
	}

	return;
}

int main() {
	int ascendArr[10] = {22, 55, 33, 11, 66, 77, 24, 99, 44, 88};
	int descendArr[10] = {22, 55, 33, 11, 66, 77, 24, 99, 44, 88};

	mergeSort(ascendArr, 0, 10);
	std::cout << "Ascending Array: ";
	for (int i = 0; i < 10; ++i) { // insert elements from temp arr to main arr
		std::cout << ascendArr[i] << " ";
	}

	std::cout << "\n";

	mergeSortDesc(descendArr, 0, 10);
	std::cout << "Descending Array: ";
	for (int i = 0; i < 10; ++i) {
		std::cout << descendArr[i] << " ";
	}
	
	return 0;
}