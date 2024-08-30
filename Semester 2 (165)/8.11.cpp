#include <iostream>

using namespace std;

void PrintNumPattern(int num1, int num2, int origin, bool& hitNeg) {
    cout << num1 << " ";

    if (num1 < 0) hitNeg = true;

    if (!hitNeg) {
        PrintNumPattern(num1 - num2, num2, origin, hitNeg);
    } else if (num1 < origin) {
        PrintNumPattern(num1 + num2, num2, origin, hitNeg);
    }
}

int main() {
    int num1;
    int num2;
    bool hitNeg = false;
    
    cin >> num1;
    cin >> num2;

    int origin = num1;

    PrintNumPattern(num1, num2, origin, hitNeg);

    return 0;
}