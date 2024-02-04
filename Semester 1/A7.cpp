//============================================================================
// Name        : 
// Author      : 
// Course      : 
// Section     : 
// Date        : 10/26/2023
//============================================================================

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

string getGeneration(int age) {
	if (age >= 78) {
		return "Silent";
	} else if (age >= 59 && age <= 77) {
		return "Baby boomer";
	} else if (age >= 43 && age <= 58) {
		return "Gen X";
	} else if (age >= 27 && age <= 42) {
		return "Millennial";
	} else if (age >= 4 && age <= 26) {
		return "Gen Z";
	} else {
		return "Alpha";
	}
}

string getGenre(char genre) {
	if (genre == 'C') {
		return "Comedy";
	} else if (genre == 'R') {
		return "Rom-com";
	} else if (genre == 'A') {
		return "Action";
	} else if (genre == 'S') {
		return "Sci-fi";
	} else if (genre == 'H') {
		return "Horror";
	} else if (genre == 'D') {
		return "Drama";
	} else {
		return "UNKNOWN_GENRE";
	}
}

int main() {
	cout << "---PART ONE---" << endl;

	int arr0[5];
	float sum0;
	string input0;

	cout << "Enter five temperatures greater than zero\n";

	for (int i = 0; i < 5; i++) {
		cout << "Enter temperature #" << i + 1 << endl;
		getline(cin, input0);

		int num = stoi(input0);

		if (num <= 0) {
			cout << "Error: Number must be greater than zero\n";
			i--;
		} else {
			arr0[i] = num;
		}
	}

	for (int i = 0; i < 5; i++) {
		sum0 = sum0 + arr0[i];

		cout << "You entered " << arr0[i] << " as temperature #" << i + 1 << endl;
	}

	cout << "The average temperature was " << sum0 / 5 << endl;

	cout << "---PART TWO---" << endl;

	int arr1[100];
	float sum1;
	string input1;
	int count = 0;

	cout << "Enter a list of temperatures" << endl;
	getline(cin, input1);

	while (input1 != "stop") {
		arr1[count] = stoi(input1);

		count++;

		cout << "Enter a temperature" << endl;
		getline(cin, input1);
	}

	for (int i = 0; i < count; i++) {
		sum1 = sum1 + arr1[i];

		cout << "You entered " << arr1[i] << " as temperature #" << i + 1 << endl;
	}

	cout << "The average temperature was " << sum1 / count << endl;

	cout << "---PART THREE---" << endl;

	ifstream file;

	file.open("A6F23data.txt");

	if (!file.is_open()) {
		cout << "Failed to open file" << endl;

		return 0;
	}

	string genreArr[100];
	string nameArr[100];
	int ratingArr[100];
	string record;
	bool isFirstRecord = true;
	int ratingCount = 0;
	int ratingTotal = 0;

	getline(file, record);

	while (!file.eof()) {
		if (isFirstRecord) {
			cout
				<< "Rater: " << record.substr(0, 10) << record.substr(10, 15) << endl
				<< "Age of rater: " << record.substr(25, 2) << "   " << getGeneration(stoi(record.substr(25, 2)))
				<< endl << endl;

			isFirstRecord = false;
		} else {
			nameArr[ratingCount] = record.substr(0, 20);
			genreArr[ratingCount] = getGenre(record.substr(20, 1)[0]);
			ratingArr[ratingCount] = stoi(record.substr(21, 1));

			ratingTotal = ratingTotal + stoi(record.substr(21, 1));

			ratingCount++;
		}

		getline(file, record);
	}

	file.close();

	for (int i = 0; i < ratingCount; i++) cout << "Movie: " << left << setw(20) << nameArr[i] << genreArr[i] << endl << "Rating: " << ratingArr[i] << endl << endl;

	cout << "Average rating: " << ratingTotal / ratingCount << endl;
	return 0;
}
