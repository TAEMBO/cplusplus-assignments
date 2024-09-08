#include <iostream>
#include <cmath>
using namespace std;

void createArray(int size, int* &arr) {
	arr = new int[size];
}

void fillArray(int size, int* &arr) {

	for (int i = 0; i < size; i++) arr[i] = rand() / 1000;
}

void displayArray(int size, int* &arr) {
	for (int i = 0; i < size; i += 10) {
		cout << "Set " << (i / 10) + 1 << ": ";

		for (int j = 0; j < 10; j++) cout << arr[i + j] << (arr[i + j] > 9 ? " " : "  ");

		cout << endl;
	}

	cout << endl;
}

void sortArray(int size, int* &arr) {
	for (int i = 1; i < size - 1; i++) {
		int min = i;

		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}

		if (min != i) {
			int temp = arr[min];

			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

bool hasElement(int size, int element, int* &arr) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == element) return true;
	}

	return false;
}

void mergeArrays(int sizes, int* &arr1, int* &arr2, int* &recArr) {
	int i = 0;

	for (int j = 0; j < sizes; j++) {
		if (!hasElement(sizes, arr1[j], recArr)) {
			recArr[i] = arr1[j];
			i++;
		}
	}

	for (int j = 0; j < sizes; j++) {
		if (!hasElement(sizes, arr2[j], recArr)) {
			recArr[i] = arr2[j];
			i++;
		}
	}

	sortArray(100, recArr);
}

void deleteArray(int* &arr) {
	delete[] arr;
}

int main() {
	int* arrPtr1;
	int* arrPtr2;
	int* arrPtr3;

	srand(time(0));

	createArray(50, arrPtr1);
	createArray(50, arrPtr2);
	createArray(100, arrPtr3);

	fillArray(50, arrPtr1);
	fillArray(50, arrPtr2);

	displayArray(50, arrPtr1);
	displayArray(50, arrPtr2);

	sortArray(50, arrPtr1);
	sortArray(50, arrPtr2);

	displayArray(50, arrPtr1);
	displayArray(50, arrPtr2);

	mergeArrays(50, arrPtr1, arrPtr2, arrPtr3);

	displayArray(100, arrPtr3);

	deleteArray(arrPtr1);
	deleteArray(arrPtr2);
	deleteArray(arrPtr3);
    
	return 0;
}
