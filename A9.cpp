//============================================================================
// Name        : 
// Author      : 
// Course      : 
// Section     : 
// Date        : 11/25/2023
//============================================================================

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

string convertDeptAbbr(vector<string> abbrs, vector<string> fullNames, string abbr) {
	string value = "";

	for (int i = 0; i < abbrs.size(); i++) {
		if (abbrs[i] == abbr) value = fullNames[i];
	}

	return value;
}

int main() {
	cout << "---PART ONE---" << endl;

	array<int, 5> arr;
	float sum1;
	string input1;
	int count = 0;
	bool error = false;

	cout << "Enter a list of temperatures" << endl;
	getline(cin, input1);

	while (input1 != "stop" && !error) {
		arr[count] = stoi(input1);

		count++;

		cout << "Enter a temperature" << endl;
		getline(cin, input1);

		try {
			arr.at(count);
		} catch (out_of_range) {
			error = true;
			cout << "Error: number of arguments must be less than or equal to 5" << endl;
		}
	}

	if (!error) {
		for (int i = 0; i < count; i++) {
			sum1 = sum1 + arr[i];

			cout << "You entered " << arr[i] << " as temperature #" << i + 1 << endl;
		}

		cout << "The average temperature was " << sum1 / count << endl;
	}
	cout << "---PART TWO---" << endl;

	ifstream file;

	file.open("a9data.txt");

	if (!file.is_open()) {
		cout << "Failed to open file" << endl;

		return 0;
	}

	string record;
	string input2;
	vector<string> abbrs;
	vector<string> fullNames;

	getline(file, record);

	while (!file.eof()) {
		abbrs.push_back(record.substr(0, 5));
		fullNames.push_back(record.substr(5, 25));

		getline(file, record);
	}

	cout << "Enter abbreviation" << endl;
	getline(cin, input2);

	while (input2 != "stop") {
		string conversion = convertDeptAbbr(abbrs, fullNames, input2);

		if (conversion.length() == 0) {
			cout << "Error: Invalid abbreviation entered" << endl;
		} else {
			cout
				<< "Abbreviation entered: " << input2 << "\n"
				<< "Full name: " << conversion << endl;
		}

		cout << "Enter abbreviation" << endl;
		getline(cin, input2);
	}

	cout << "Program ended" << endl;

	return 0;
}
