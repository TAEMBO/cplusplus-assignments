#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    ifstream file;
    string fileName;
    string input;
    char letter;

    getline(cin, input);

    stringstream inputs(input);

    getline(inputs, input, ' ');

    fileName = input;

    getline(inputs, input, ' ');

    letter = input[0];

    file.open("./" + fileName + ".txt");

    if (!file.is_open()) {
        cout << "Faile to open file" << endl;

        return 1;
    }

    string record;
    string section;

    getline(file, record);

    while (!file.eof()) {
        if (record[0] == letter) {
            stringstream stringStream(record);

            while (stringStream.good()) {
                getline(stringStream, section, ' ');

                cout << section << endl;
            }

            file.close();

            return 0;
        }

        getline(file, record);
    }

    cout << "No synonyms for " + fileName + " begin with " + letter + "." << endl;

    file.close();
    
    return 0;
}
