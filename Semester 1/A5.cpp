//============================================================================
// Name        : 
// Author      : 
// Course      : 
// Section     : 
// Date        : 10/03/2023
//============================================================================

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int beans;

void showServices() {
	cout
		<< endl
		<< "Which service are you interested in?" << endl
		<< "A. Temperature conversion, F to C" << endl
		<< "B. Number guessing game" << endl
		<< "C. Temperature table, C to F" << endl
		<< "D. Draw a rectangle" << endl
		<< "E. Baby names voting" << endl
		<< "X. Exit" << endl;
}

void optionA() {
	string input;

	cout << "Enter a number in fahrenheit to convert to centigrade" << endl;
	getline(cin, input);

	float converted = (stof(input) - 32) * 5 / 9;

	cout << input << " fahrenheit is " << converted << " centigrade" << endl;
}

void optionB() {
	srand(time(0));

	int num = rand();
	int parsedGuess;
	int guessCount = 1;
	string guess;

	cout << "Random number generated, attempt to guess the number" << endl;
	getline(cin, guess);

	parsedGuess = stoi(guess);

	while (parsedGuess != num) {
		if (parsedGuess > num) {
			cout << "Guess was too high" << endl;
		} else {
			cout << "Guess was too low" << endl;
		}

		cout << "Incorrect guess, try again" << endl;
		getline(cin, guess);

		guessCount++;

		parsedGuess = stoi(guess);

	}

	cout << "Guessed correctly after " << guessCount << " attempts " << endl;

}

void optionC() {
	cout << "Centigrade    Fahrenheit" << endl;

	for (float i = 0; i <= 100; i++) {
		float converted = (i * 9 / 5) + 32;

		cout << right << setprecision(0) << setw(6) << i << right << setw(17) << setprecision(2) << fixed << converted << endl;
		i = i + 4;
	}
}

void optionD() {
	string heightInput;
	string lengthInput;
	string shape;

	cout << "Enter the height of the rectangle to draw" << endl;
	getline(cin, heightInput);

	cout << "Enter the length of the rectangle to draw" << endl;
	getline(cin, lengthInput);

	int parsedHeight = stoi(heightInput);
	int parsedLength = stoi(lengthInput);

	for (int i = 0; i < parsedHeight; i++) {
		for (int x = 0; x < parsedLength; x++) shape = shape + "*";

		shape = shape + "\n";
	}

	cout << endl << shape << endl;

}

void optionE() {
	int billCount = 0;
	int bobCount = 0;
	int jerryCount = 0;
	string input;
	string winner;

	cout << "Baby names voting" << endl;

	while (billCount < 3 && bobCount < 3 && jerryCount < 3) {
		cout << "Which do you like? bill, bob, jerry" << endl;
		getline(cin, input);

		if (input == "bill") {
			billCount++;
			cout << "Vote recorded" << endl;
		} else if (input == "bob") {
			bobCount++;
			cout << "Vote recorded" << endl;
		} else if (input == "jerry") {
			jerryCount++;
			cout << "Vote recorded" << endl;
		} else {
			cout << "Error: Invalid name entered" << endl;
		}

	}

	if (billCount == 3) {
		winner = "bill";
	} else if (bobCount == 3) {
		winner = "bob";
	} else {
		winner == "jerry";
	}

	cout
		<< "And the winner is abby with 3 votes!" << endl
		<< "Vote totals:" << endl
		<< "   bob   " << billCount << endl
		<< "   bill  " << bobCount << endl
		<< "   jerry " << jerryCount << endl;
}

int main() {
	string choice;

	showServices();
	getline(cin, choice);

	while (choice != "x" && choice != "X") {
		if (choice == "A" || choice == "a") {
			optionA();
		} else if (choice == "B" || choice == "b") {
			optionB();
		} else if (choice == "C" || choice == "c") {
			optionC();
		} else if (choice == "D" || choice == "d") {
			optionD();
		} else if (choice == "E" || choice == "e") {
			optionE();
		} else {
			cout << "Error: Invalid choice entered" << endl;
		}

		showServices();
		getline(cin, choice);
	}

	cout << "Thank you for playing" << endl;

	return 0;
}
