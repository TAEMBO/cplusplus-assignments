//============================================================================
// Name        : 
// Author      : 
// Course      : 
// Section     : 
// Date        : 10/16/2023
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

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
	ifstream file;

	file.open("A6F23data.txt");

	if (!file.is_open()) {
		cout << "Failed to open file" << endl;

		return 0;
	}

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
			ratingCount++;

			string movieName = record.substr(0, 20);
			string movieGenre = record.substr(20, 1);
			int movieRating = stoi(record.substr(21, 1));

			ratingTotal = ratingTotal + movieRating;

			cout
				<< "Movie: " << left << setw(20) << movieName << getGenre(movieGenre[0]) << endl
				<< "Rating: " << movieRating << endl << endl;


		}

		getline(file, record);
	}

	file.close();

	cout << "Average rating: " << ratingTotal / ratingCount << endl;

	return 0;
}
