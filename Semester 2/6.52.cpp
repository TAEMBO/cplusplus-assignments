#include <iostream>
using namespace std;

string CheckCharacter(string word, int index) {
	char character = word[index];
    string type;

    if (isalpha(character)) {
        type = "Letter: ";
    } else if (isspace(character)) {
        type = "Whitespace: ";
    } else if (isdigit(character)) {
        type = "Digit: ";
    } else {
        type = "Unknown: ";
    }

    return type + '\'' + character + '\'';
}

int main() {
	cout << CheckCharacter("happy birthday", 2) << endl;
	cout << CheckCharacter("happy birthday", 5) << endl;
	cout << CheckCharacter("happy birthday 2 you", 15) << endl;
	cout << CheckCharacter("happy birthday!", 14) << endl;

	return 0;
}