#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> userValues;
    int count;
    int value; 

    cin >> count;

    for (int i = 0; i < count; i++) {
        cin >> value;

        userValues.push_back(value);
    }
    
    int lastValue = userValues.at(static_cast<int>(userValues.size()) - 1);

    for (int i = static_cast<int>(userValues.size()) - 1; i > 0; i--) {
        userValues.at(i) = userValues.at(i - 1);
    }

    userValues.at(0) = lastValue;

    for (int i = 0; i < static_cast<int>(userValues.size()); i++) {
        cout << userValues.at(i) << " ";
    }
    
    cout << endl;

    return 0;
}