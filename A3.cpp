//============================================================================
// Name        : 
// Author      : 
// Course      : 
// Section     : 
// Date        : 9/22/2023
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout << "Part 1" << endl << endl;

	int counter_0 = 1;

	while (counter_0 <= 10) {
		if (counter_0 != 7) {
			cout << "Square of " << counter_0 << ": " << counter_0 * counter_0 << endl;
			cout << "Square root: " << sqrt(counter_0) << endl << endl;
		}
		counter_0++;
	}

	cout << "Part 2" << endl << endl;

	int counter_1 = 10;
	int sum_0 = 0;

	while (counter_1 <= 20) {
		sum_0 = sum_0 + counter_1;
		counter_1++;
	}

	cout << "Sum: " << sum_0 << endl;

	cout << endl << "Part 3" << endl << endl;

	int lower;
	int upper;
	int sum_1 = 0;

	cout << "Enter integer for lower bound" << endl;
	cin >> lower;

	cout << "Enter integer for upper bound" << endl;
	cin >> upper;

	cout
		<< "Lower bound: " << lower << endl
		<< "Upper bound: " << upper << endl;

	while (lower <= upper) {
		sum_1 = sum_1 + lower;
		lower++;
	}

	cout << "Sum: " << sum_1 << endl;

	cout << endl << "Part 4" << endl << endl;

	string name_0;

	cout << "Enter a name that is either Dagny, Hank, or Francisco" << endl;
	cin >> name_0;

	while (name_0 != "Dagny" && name_0 != "Hank" && name_0 != "Francisco") {
		cout << "Invalid name; Enter a name that is either Dagny, Hank, or Francisco" << endl;
		cin >> name_0;
	}

	cout << "Success" << endl;

	cout << endl << "Part 5" << endl << endl;

	int num;

	cout << "Enter a number" << endl;
	cin >> num;

	while (num > 0) {
		if (num == 1) {
			cout << "Abigail" << endl;
		} else if (num == 2) {
			cout << "Bobby" << endl;
		} else if (num == 3) {
			cout << "Charmaine" << endl;
		} else {
			cout << "Error; ";
		}

		cout << "Enter a number" << endl;
		cin >> num;
	}

	cout << endl << "Part 6" << endl << endl;

	string name_1;

	cout << "Enter a name" << endl;
	cin >> name_1;

	while (name_1 != "Frank" && name_1 != "Betty") {
		cout << "Error; Enter a name" << endl;
		cin >> name_1;
	}

	cout << "You did well" << endl;



	return 0;
}
