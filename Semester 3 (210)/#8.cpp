#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

const string FILENAME = "fb_weighted.csv";
const int MAX_ID = 201;

struct adjacency {
    int nodeId;
    int weight;
};

vector<adjacency> adjacencies[MAX_ID];
int bestPathCost[MAX_ID];
int bestParent[MAX_ID];

struct pathElement {
    int nodeId;
    int weight;
    int parent;

    bool operator< (const pathElement &rhs) const {
        return weight > rhs.weight;
    }
};


void parse_line(const string &str,
    vector<string> &line) {
    istringstream istr(str);
    string tmp;

    while (getline(istr, tmp, ',')) {
        line.push_back(tmp);
    }
}

bool shortestPaths(int nodeId, int targetId) {
    pathElement p;
    priority_queue<pathElement> tent;

    p.weight = 0;
    p.parent = -1;
    p.nodeId = nodeId;
    tent.push(p);

    while (!tent.empty()) {
        p = tent.top();
        tent.pop();

        if (bestPathCost[p.nodeId] != -1) continue;

        bestPathCost[p.nodeId] = p.weight;
        bestParent[p.nodeId] = p.parent;

        if (p.nodeId == targetId) return true;

        for (int i = 0; i < (int)adjacencies[p.nodeId].size(); i++) {
            adjacency thisFriend = adjacencies[p.nodeId][i];
            pathElement np;

            np.weight = p.weight + thisFriend.weight;
            np.parent = p.nodeId;
            np.nodeId = thisFriend.nodeId;

            tent.push(np);
        }
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

            if (adj_status != 0) {
                adjacency newAdj;
                newAdj.nodeId = j;
                newAdj.weight = adj_status;
                adjacencies[id].push_back(newAdj);
            }
        }

        id += 1;
    }
    cout << "Finished reading graph of " << id - 1 << " entries";

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

        for (int i = 0; i < MAX_ID; i++) bestPathCost[i] = -1;

        for (int i = 0; i < MAX_ID; i++) bestParent[i] = -1;

        bool result = shortestPaths(startIndex, endIndex);

        if (result) {
            stack<string> stk;
            int index = endIndex;
            int totalWeight = 0;

            while (index != -1) {
                stk.push(names[index]);

                totalWeight += bestPathCost[index];
                index = bestParent[index];
            }

            while (!stk.empty()) {
                cout << "  " << stk.top() << endl;

                stk.pop();
            }

            cout << endl << "The cost of this path is: " << totalWeight << endl;
        } else {
            cout << "There is NOT a path between these two people." << endl;
        }
    }

    cout << "Exiting..." << endl;

    return (0);
}
