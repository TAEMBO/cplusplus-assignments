//============================================================================
// Name        : 
// Author      : 
// Course      : 
// Section     : 
// Date        : 9/11/2023
//============================================================================

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	cout << "Part One - Interest Calculations" << endl << endl; // Part 1

	float princ;
	float rate;

	rand();

	cout << "Enter principal" << endl;
	cin >> princ;

	cout << "Enter interest rate" << endl;
	cin >> rate;

	float compAmtAn = princ * (rate / 100);
	float compAmtDl = princ * pow( (1 + (rate / 100) / 365), 365) - princ;

	cout
		<< setprecision(2) << fixed
		<< left << setw(31) << "For a loan of                $ " << right << setw(10) << princ << endl
		<< left << setw(31) << "With a rate of" << right << setw(10) << rate << " %" << endl
		<< left << setw(31) << "Interest compounded annually $ " << right << setw(10) << compAmtAn << endl
		<< left << setw(31) << "YE labance                   $ " << right << setw(10) << princ + compAmtAn << endl
		<< left << setw(31) << "Interest compounded daily    $ " << right << setw(10) << compAmtDl << endl
		<< left << setw(31) << "YE balance                   $ " << right << setw(10) << princ + compAmtDl << endl;

	cout << endl << "Part Two - Screen size calculation" << endl << endl; // Part 2

	float height;
	float width;

	cout << "Enter screen height in inches" << endl;
	cin >> height;

	cout << "Enter screen width in inches" << endl;
	cin >> width;

	float size = pow(height, 2) + pow(width, 2);

	cout << "Screen size is " << setprecision(1) << fixed << sqrt(size) << " inches" << endl;

	cout << endl << "Part Three - Travel mileage calculations" << endl << endl; // Part 3

	float cost;
	float miles;

	cout << "Enter cost of a tank of gas" << endl;
	cin >> cost;

	cout << "Enter amount of miles driven on said tank of gas" << endl;
	cin >> miles;

	cout
		<< setprecision(2) << fixed
		<< left << setw(15) << "Cost of gas   $" << right << setw(10) << cost << endl
		<< left << setw(15) << "Miles driven" << right << setw(10) << miles << endl
		<< left << setw(15) << "Cost per mile $" << right << setw(10) << cost / miles << endl;

	cout << endl << "Part Four - Las Vegas dice game" << endl << endl; // Part 4

	srand(time(0));

	int dice0 = (rand() % 6) + 1;
	int dice1 = (rand() % 6) + 1;
	int total = dice0 + dice1;

	cout
		<< "Dice one: " << dice0 << endl
		<< "Dice two: " << dice1 << endl
		<< "Total: " << total << endl;

	if (total == 2 || total == 3 || total == 12) {
		cout << "You lost" << endl;
	} else if (total == 7 || total == 11) {
		cout << "You win" << endl;
	} else {
		int dice2 = (rand() % 6) + 1;
		int dice3 = (rand() % 6) + 1;

		cout
			<< "Dice three: " << dice2 << endl
			<< "Dice four: " << dice3 << endl;

		if ((dice2 + dice3) == total) {
			cout << "You win" << endl;
		} else {
			cout << "You lose" << endl;
		}

	}




	return 0;
}
