//============================================================================
// Name        : 
// Author      : 
// Course      : 
// Section     : 
// Date        : 11/12/2023
//============================================================================

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void roll(int (&arr)[11]) {
	int roll0 = (rand() % 6) + 1;
	int roll1 = (rand() % 6) + 1;
	int total = roll0 + roll1;

	arr[total - 2]++;

}

string convertDeptAbbr(string abbr) {
	string value = "";
	string table[12][2] = {
		{"ART  ", "Art"},
		{"BIOS ", "Biological Sciences"},
		{"COMM ", "Communications Studies"},
		{"COMSC", "Computer Science"},
		{"ENGR ", "Engineering"},
		{"FIN  ", "Finance"},
		{"MATH ", "Mathematical Sciences"},
		{"PHYS ", "Physical Education"},
		{"PHYSC", "Physics"},
		{"POLS ", "Political Science"},
		{"PSYC ", "Psychology"},
		{"REST ", "Culinary Arts"},
	};

	for (int i = 0; i < 12; i++) {
		if (table[i][0] == abbr) value = table[i][1];
	}

	return value;
}

void testDept ()
{
	string tests [4] = {"ART  ", "COMSC", "ART", "REST "};
	string r;
	for (int i = 0; i<4; i++)
	{
		r = convertDeptAbbr (tests [i]);
		if (r.length() == 0)
		{
			cout << "Department " << tests [i] << " not found" << endl;
		}
		else
		{
			cout << "Department " << tests [i] << " is " << r << endl;
		}
	}
}

int main() {
	srand(time(0));

	int arr[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	string input;

	cout << "Enter a number of rolls" << endl;

	getline(cin, input);

	float limit = stoi(input);

	for (int i = 0; i < limit; i++) roll(arr);

	for (int i = 0; i < 11; i++) cout << "roll " << setw(2) << right << i + 2 << " occurrences " << setw(7) << right << arr[i] << "  " << setw(5) << right << setprecision(2) << fixed << arr[i] / limit * 100 << " %" << endl;

	testDept();

	return 0;
}
