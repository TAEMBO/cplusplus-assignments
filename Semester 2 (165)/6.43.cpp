#include <iostream>
#include <string>
using namespace std;

int GetNumOfNonWSCharacters(const string input) {
    int nonWhitespaceCount = 0;

    for (auto character : input) {
        if (character != ' ') nonWhitespaceCount++;
    }

    return nonWhitespaceCount;
}

int GetNumOfWords(const string input) {
    int wordCount = 0;
    bool inWord = false;
    
    for (int i = 0; i < static_cast<int>(input.size()); i++) {
        if (input[i] == ' ') {
            inWord = false;
        } else if (input[i] != ' ' && !inWord) {
            wordCount++;
            inWord = true;
        }
    }

    return wordCount;
}

int FindText(string searchText, string input) {
    int searchTextSize = static_cast<int>(searchText.size());
    int instanceCount = 0;

    for (int i = 0; i < static_cast<int>(input.size()) - searchTextSize + 1; i++) {
        string sample = input.substr(i, searchTextSize);

        if (sample == searchText) instanceCount++;
    }


    return instanceCount;
}

void ReplaceExclamation(string &input) {
    for (auto &character : input) {
        if (character == '!') character = '.';
    }
}

void ShortenSpace(string &input) {
    for (int i = 1; i < static_cast<int>(input.size()) - 1; i++) {
        while ((input[i - 1] == ' ' || input[i + 1] == ' ') && input[i] == ' ') input.erase(i, 1);
    }
}

void PrintMenu() {
    cout
        << "MENU" << endl
        << "c - Number of non-whitespace characters" << endl
        << "w - Number of words" << endl
        << "f - Find text" << endl
        << "r - Replace all !'s" << endl
        << "s - Shorten spaces" << endl
        << "q - Quit" << endl << endl;
}

void ExecuteMenu(char option, string input) {
    if (option == 'c') {
        int count = GetNumOfNonWSCharacters(input);

        cout << "Number of non-whitespace characters: " << count << endl << endl;
    } else if (option == 'w') {
        int count = GetNumOfWords(input);

        cout << "Number of words: " << count << endl << endl;
    } else if (option == 'f') {
        string searchText;

        cout << "Enter a word or phrase to be found:" << endl;

        getline(cin, searchText);

        int count = FindText(searchText, input);

        cout << "\"" << searchText << "\" instances: " << count << endl << endl;
    } else if (option == 'r') {
        ReplaceExclamation(input);

        cout << "Edited text: " << input << endl << endl;
    } else if (option == 's') {
        ShortenSpace(input);

        cout << "Edited text: " << input << endl << endl;
    } else {
        cout << "Error: Invalid option provided - " << option << endl << endl;
    }
}

int main() {
    string input;
    string inputOption;
    char option;
    
    cout << "Enter a sample text:" << endl << endl;
    
    getline(cin, input);
    
    cout << "You entered: " << input << endl << endl;
    
    PrintMenu();

    cout << "Choose an option:" << endl;

    getline(cin, inputOption);

    option = inputOption[0];

    while (option != 'q') {
        ExecuteMenu(option, input);

        PrintMenu();
        
        cout << "Choose an option:" << endl;
        
        getline(cin, inputOption);
        
        option = inputOption[0];
    };

    return 0;
}