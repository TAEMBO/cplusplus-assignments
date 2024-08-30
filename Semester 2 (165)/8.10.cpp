#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void PrintAllPermutations(vector<string> permList, vector<string> nameList) { 
    if (!nameList.size()) {
        for (int i = 0; i < static_cast<int>(permList.size()); i++) {
            cout << permList.at(i);

            if (i != static_cast<int>(permList.size()) - 1) cout << ", ";
        }

        cout << endl;
    } else {
        vector<string> tempList;

        for (int i = 0; i < static_cast<int>(nameList.size()); i++) {
            tempList = nameList;
            
            permList.push_back(tempList.at(i));
            tempList.erase(tempList.begin() + i);

            PrintAllPermutations(permList, tempList);

            permList.pop_back();
        }
    }     
}

int main() {
    vector<string> permList;
    vector<string> nameList;
    string input;
    string section;

    getline(cin, input);

    stringstream stringStream(input);

    getline(stringStream, section, ' ');

    while (section != "-1" && stringStream.good()) {
        nameList.push_back(section);

        getline(stringStream, section, ' ');
    }

    PrintAllPermutations(permList, nameList);
}