//============================================================================
// Name        : 
// Author      : 
// Course      : 
// Section     : 
// Date        : 9/6/2023
//============================================================================

#include <iostream>
using namespace std;

int main() {
	// Variables will be separated with an appending "_#" to denote which part they pertain to
	// if duplicate variable names arise

	// ---Part 1---
	int days_0;
	float hours_0;

	cout << "Ender number of days have you worked last week" << endl;
	cin >> days_0; // Collect the amount of days

	cout << "Enter number of hours have you worked last week" << endl;
	cin >> hours_0; // Collect the amount of hours

	float avg_0 = hours_0 / days_0;

	cout << "You averaged " << avg_0 << " hours of work each day" << endl;

	// ---Part 2---
	float f_0;

	cout << "Enter a in fahrenheit to convert to centigrade (number)" << endl;
	cin >> f_0; // Collect the number in fahrenheit

	float c_0 = (f_0 - 32) * 5 / 9; // Perform formula to calculate centigrade

	cout << f_0 << " fahrenheit is " << c_0 << " centigrade" << endl;

	// ---Part 3---
	string id;
	string item0;
	float cost0;
	string item1;
	float cost1;
	string item2;
	float cost2;

	cout << "Enter your ID" << endl;
	cin >> id; // Collect ID

	cout << "Enter item #1's name" << endl;
	cin >> item0; // Collect first item's name
	cout << "Enter item #1's cost" << endl;
	cin >> cost0; // Collect first item's cost

	cout << "Enter item #2's name" << endl;
	cin >> item1; // Collect second item's name
	cout << "Enter item #2's cost" << endl;
	cin >> cost1; // Collect second item's cost

	cout << "Enter item #3's name" << endl;
	cin >> item2; // Collect third item's name
	cout << "Enter item #3's cost" << endl;
	cin >> cost2; // Collect third item's cost

	float taxRate = 0.0925;
	float subtotal = cost0 + cost1 + cost2;
	float tax = subtotal * taxRate;
	float total = subtotal + tax;

	cout
		<< "----------------Receipt for " << id << "------------------" << "\n"
		<< item0 << ": $" << cost0 << "\n"
		<< item1 << ": $" << cost1 << "\n"
		<< item2 << ": $" << cost2 << "\n"
		<< "Subtotal: $" << subtotal << "\n"
		<< "Tax: $" << tax << "\n"
		<< "Total: $" << total << "\n"
		<< "-------------------------------------------------------" << endl;



	return 0;
}
