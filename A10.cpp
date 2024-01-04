//============================================================================
// Name        : 
// Author      : 
// Course      : 
// Section     : 
// Date        : 12/01/2023
//============================================================================

#include <iostream>
#include <fstream>
#include <cmath>
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

struct Movie {
	string name;
	string genre;
	int rating;
};

int main() {
	ifstream file;

	file.open("A10F23data.txt");

	if (!file.is_open()) {
		cout << "Failed to open file" << endl;

		return 0;
	}

	string record;
	bool isFirstRecord = true;
	int ratingCount = 0;
	int ratingTotal = 0;
	Movie movieArr[100];
	string infoText;

	getline(file, record);

	while (!file.eof()) {
		if (isFirstRecord) {
			infoText =
					"Rater: " + record.substr(0, 10) + record.substr(10, 15)
					+ "\nAge of rater: " + record.substr(25, 2) + "   " + getGeneration(stoi(record.substr(25, 2)));

			isFirstRecord = false;
		} else {
			movieArr[ratingCount].name = record.substr(0, 20);
			movieArr[ratingCount].genre = getGenre(record.substr(20, 1)[0]);
			movieArr[ratingCount].rating = stoi(record.substr(21, 1));

			ratingTotal = ratingTotal + stoi(record.substr(21, 1));

			ratingCount++;
		}

		getline(file, record);
	}

	file.close();

	cout << infoText + "\nNumber of movies rated: " << ratingCount << endl << endl;

	for (int i = 0; i < ratingCount; i++) cout << "Movie: " << left << setw(20) << movieArr[i].name << movieArr[i].genre << endl << "Rating: " << movieArr[i].rating << endl << endl;

	cout << "Average rating: " << ratingTotal / ratingCount << endl;
	return 0;
}
