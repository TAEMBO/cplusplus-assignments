#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <cstdlib>
using namespace std;

const string FILENAME = "facebook.csv";
const int MAX_ID = 201;
vector<int> adjacencies[MAX_ID];
int visited[MAX_ID] = {  0  };

void parse_line(const string &str,
    vector<string> &line) {
    istringstream istr(str);
    string tmp;

    while (getline(istr, tmp, ',')) {
        line.push_back(tmp);
    }
}

bool DFS(int nodeId, int targetId) {
    visited[nodeId] = 1;

    for (int i = 0; i < adjacencies[nodeId].size(); i++) {
        int thisFriend = adjacencies[nodeId][i];

        if (thisFriend == targetId) return true;

        if (visited[thisFriend]) continue;

        if (DFS(thisFriend, targetId)) return true;
    }

    return false;
}

int main() {
    ifstream inFile(FILENAME);
    vector<string> row;
    vector<string> names;
    string inputLine;
    int id = 1;

    if (!inFile.good()) {
        cerr << "Invalid file." << endl;
        return (-1);
    }

    getline(inFile, inputLine);

    if (inputLine.back() == '\r' || inputLine.back() == '\n') inputLine.pop_back();

    parse_line(inputLine, names);

    for (int i = 0; i < MAX_ID - 1; i++) {
        vector<string> row;

        getline(inFile, inputLine);

        parse_line(inputLine, row);

        for (int j = 1; j < (int)row.size(); j++) {
            int adj_status = atoi(row[j].c_str());

            if (adj_status == 1) adjacencies[id].push_back(j);
        }

        id += 1;
    }

    cout << "Finished reading graph of " << id - 1 << " entries" << endl;

    for (;;) {
        string start;
        string end;

        cout << "Enter starting person:" << endl;
        getline(cin, start);

        cout << "Enter ending person:" << endl;
        getline(cin, end);

        if (start == "" || end == "") break;

        int startIndex = -1;
        int endIndex = -1;

        for (int i = 0; i < (int)names.size(); i++) {
            if (names[i] == start) startIndex = i;

            if (names[i] == end) endIndex = i;
        }

        if (startIndex == -1 || endIndex == -1) {
            cout << "Either the start or end was not found." << endl;
            continue;
        }

        for (int i = 0; i < MAX_ID; i++) visited[i] = 0;

        bool result = DFS(startIndex, endIndex);
        string answer = result ? "IS" : "IS NOT";

        cout << "There " << answer << " a path between these two people." << endl;

    }

    cout << "Exiting..." << endl;

    return (0);
}
