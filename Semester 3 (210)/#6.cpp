#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
using namespace std;

const int HASH_SIZE = 1051;
const string INFILE = "nflix.csv";
const int NFIELDS = 6;
const char DELIMITER = ',';

struct netflixEntry {
    string type; 
    string title;
    string director;
    string country; 
    int year;
    string duration;
    netflixEntry* next = 0;
};

netflixEntry *entryHash[HASH_SIZE] = { 0 };

unsigned int getHashIndex(string hashInput) {
    unsigned int hashval = 0;

    for (unsigned int i = 0; i < hashInput.size(); i++) hashval = (int)hashInput[i] + 31 * hashval;

    return (hashval % HASH_SIZE);
}

netflixEntry *readSingleEntry(const string &lineFromFile) {
    istringstream istr(lineFromFile);
    string fields[NFIELDS];
    string tmp, dstr;
    netflixEntry *np = 0;
    int i = 0;

    while (getline(istr, tmp, DELIMITER) && i < NFIELDS) {
        fields[i++] = tmp;
    }
    if (i < NFIELDS) {
        cout << "Warning:  skipping malformed line: " << lineFromFile << endl;
        return 0;
    }

    np = new netflixEntry;

    np->type = fields[0];
    np->title = fields[1];
    np->director = fields[2];
    np->country = fields[3];
    np->year = atoi(fields[4].c_str());

    dstr = fields[5];

    if (dstr.size() != 0 && dstr[dstr.size() - 1] == '\r') dstr.erase(dstr.size() - 1);

    np->duration = dstr;

    return np;
}

void entryInsert(netflixEntry *newEnt, unsigned int hashIndex) {
    netflixEntry* entry = entryHash[hashIndex];

    if (entry == 0) {
        entryHash[hashIndex] = newEnt;
    } else {
        while (entry->next != 0) entry = entry->next;
        
        entry = newEnt;
    }
}

netflixEntry *entryFind(const string &title, unsigned int hashIndex, int &ncmp) {
    netflixEntry *foundPtr = 0;
    ncmp = 0;

    foundPtr = entryHash[hashIndex];

    while (foundPtr != 0) {
        ncmp++;

        if (foundPtr->title == title) break;

        foundPtr = foundPtr->next;
    }

    return foundPtr;
}

int main() {
    ifstream inFile(INFILE);
    string inputLine, inputStr;
    netflixEntry *np = 0;
    int linesRead = 0;

    if (!inFile.good()) {
        cerr << "Cannot open the input file!" << endl;
        exit(-1);
    } 

    while (getline(inFile, inputLine)) {
        linesRead++;

        np = readSingleEntry(inputLine);
        if (!np) continue;

        entryInsert(np, getHashIndex(np->title));

    }

    if (linesRead == 0) {
        cerr << "Nothing was read from the file!" << endl;
        return (-1);
    } else {
        cout << "Read " << linesRead << " entries." << endl;
        cout << "Last entry added: " << np->title
             << " (" << np->director << ", " << np->year << ")" << endl;
    }

    string prompt = "Enter a movie";

    cout << prompt << endl;

    while (true) {
        string input;

        getline(cin, input);

        if (!input.length() || input == "-1") break;

        int ncmp;
        netflixEntry* entry = entryFind(input, getHashIndex(input), ncmp);

        cout << "Comparisons: " << ncmp << endl;

        if (entry == 0) {
            cout << "Not found in the hash table." << endl << endl;
        } else {
            cout
                << "Type: " << entry->type << endl
                << "Movie: " << entry->title << endl
                << "Director: " << entry->director << endl
                << "Country: " << entry->country << endl
                << "Year of Release: " << entry->year << endl
                << "Duration: " << entry->duration << endl << endl;
        }

        cout << prompt << endl;
    }

    cout << "Exiting..." << endl;

    return (0);
}
