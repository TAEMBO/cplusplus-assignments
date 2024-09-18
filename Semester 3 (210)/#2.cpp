#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int main() {
    ifstream file;

    file.open("./file.txt");

    if (!file.is_open()) {
        cout << "Failed to open file" << endl;

        return 1;
    }

    string record;

    getline(file, record);

    while (!file.eof()) {
        if (record.length() == 1) {
            string chunk;
            stack<string> stack;
            bool failed = false;

            for (int i = 0; i < stoi(record); i++) {
                getline(file, chunk);

                char action = chunk[0];
                string data = chunk.substr(2);

                if (action == 'i') {
                    stack.push(data);
                } else {
                    if (stack.empty()) {
                        failed = true;
                    } else if (stack.top() == data) {
                        stack.pop();
                    } else {
                        failed = true;
                    }
                }
            }

            if (!stack.empty()) failed = true;

            cout << (failed ? "NOT A STACK" : "STACK") << endl;
        }

        getline(file, record);
    }

    return 0;
}