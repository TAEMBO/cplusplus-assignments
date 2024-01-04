//============================================================================
// Name        : 
// Author      : 
// Course      : 
// Section     : 
// Date        : 9/26/2023
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout << "Part 1" << endl << endl;

	int counter_0 = 1;

	for (int i = 0; i <= 10; i++) {
		if (counter_0 != 7) {
			cout << "Square of " << counter_0 << ": " << counter_0 * counter_0 << endl;
			cout << "Square root: " << sqrt(counter_0) << endl << endl;
		}
		counter_0++;
	}

	cout << "Part 2" << endl << endl;

	string s0;
	string s1;

	cout << "Enter integer for lower bound" << endl;
	getline(cin, s0);

	cout << "Enter integer for upper bound" << endl;
	getline(cin, s1);

	int lower = stoi(s0);
	int upper = stoi(s1);
	int sum_1 = 0;

	cout
		<< "Lower bound: " << lower << endl
		<< "Upper bound: " << upper << endl;

	for (int i = lower; i <= upper; i++) sum_1 = sum_1 + i;

	cout << "Sum: " << sum_1 << endl;

	cout << "Part 3" << endl << endl;

	int counter_1 = 0;
	int sum = 0;
	string input;
	int number;

	cout << "Enter a list of integers. Type \"STOP\" to finish your list" << endl;
	getline(cin, input);

	while (input != "STOP") {
		number = stoi(input);

		counter_1++;

		sum = sum + number;
		getline(cin, input);
	}

	cout << "Average: " << sum / counter_1 << endl;

	cout << "Part 4" << endl << endl;

	string input_1;
	int total = 0;
	int adaCount = 0;
	int bobCount = 0;
	int calCount = 0;

	cout << "Enter a list of names. Type \"STOP\" to finish your list" << endl;
	getline(cin, input_1);


	while (input_1 != "STOP") {
		if (input_1.length() != 0) total++;

		if (input_1 == "Ada") {
			adaCount++;
		} else if (input_1 == "Bob") {
			bobCount++;
		} else if (input_1 == "Cal") {
			calCount++;
		}

		getline(cin, input_1);
	}

	cout
		<< "Total: " << total << endl
		<< "\"Ada\" count: " << adaCount << endl
		<< "\"Bob\" count: " << bobCount << endl
		<< "\"Cal\" count: " << calCount << endl;

	cout << "Part 5" << endl << endl;

	string input_2;
	int number_1;
	int sum_2;

	cout << "Enter a list of integers, ending your list with -1" << endl;
	getline(cin, input_2);
	number_1 = stoi(input_2);


	while (number_1 != -1) {
		sum_2 = 0;
		for (int i = 1; i <= number_1; i++) {
			sum_2 = sum_2 + number_1;
		}

		cout << "Square root: " << sum_2 << endl;
		getline(cin, input_2);
		number_1 = stoi(input_2);
	}

	cout << "Finish" << endl;

	return 0;
}
