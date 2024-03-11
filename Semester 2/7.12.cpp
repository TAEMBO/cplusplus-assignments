#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    string input;
    string title;
    string col1header;
    string col2header;
    vector<string> dataStrings;
    vector<int> dataIntegers;

    cout << "Enter a title for the data:" << endl;

    getline(cin, title);

    cout << "You entered: " << title << endl << endl;
    cout << "Enter the column 1 header:" << endl;

    getline(cin, col1header);

    cout << "You entered: " << col1header << endl << endl;
    cout << "Enter the column 2 header:" << endl;

    getline(cin, col2header);

    cout << "You entered: " << col2header << endl << endl;


    cout << "Enter a data point (-1 to stop input):" << endl;

    getline(cin, input);

    while (input != "-1") {
        int commaCount = 0;
        int sectionIndex = 0;
        string section;
        stringstream stringStream(input);
        string inputs[2];

        for (auto character : input) {
            if (character == ',') commaCount++;
        }

        if (!commaCount) {
            cout
                << "Error: No comma in string." << endl << endl
                << "Enter a data point (-1 to stop input):" << endl;
            
            getline(cin, input);

            continue;
        }

        if (commaCount > 1) {
            cout
                << "Error: Too many commas in input." << endl << endl
                << "Enter a data point (-1 to stop input):" << endl;
            
            getline(cin, input);

            continue;
        }


        while (stringStream.good()) {
            getline(stringStream, section, ',');

            inputs[sectionIndex] = section;

            sectionIndex++;
        }

        if (isdigit(inputs[1][1])) {
            dataIntegers.push_back(stoi(inputs[1]));
            dataStrings.push_back(inputs[0]);
        } else {
            cout
                << "Error: Comma not followed by an integer." << endl << endl
                << "Enter a data point (-1 to stop input):" << endl;
            
            getline(cin, input);

            continue;
        }

        cout
            << "Data string: " << inputs[0] << endl
            << "Data integer:" << inputs[1] << endl << endl
            << "Enter a data point (-1 to stop input):" << endl;

        getline(cin, input);
    }

    cout
        << endl
        << setw(33) << right << title << endl
        << setw(20) << left << col1header << "|" << setw(23) << right << col2header << endl
        << "--------------------------------------------" << endl;

    for (int i = 0; i < static_cast<int>(dataStrings.size()); i++) {
        cout << setw(20) << left << dataStrings[i] << "|" << setw(23) << right << dataIntegers[i] << endl;
    }

    return 0;
}