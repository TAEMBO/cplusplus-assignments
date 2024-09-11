#include <iostream>
using namespace std;

int syracuse1(int n, int limit, int &highest) {
    if (n == 1) return 1;

    if (!limit) return 0;

    if (n > highest) highest = n;

    cout << n << endl;

    int result = ((n % 2) == 0)
        ? n / 2
        : ((3 * n) + 1) / 2;

    return syracuse1(result, limit - 1, highest);
}

int syracuse2(int n, int limit, int &highest) {
    int result = n;

    while (limit && result != 1) {
        cout << result << endl;

        if (result > highest) highest = result;

        result = ((result % 2) == 0)
            ? result / 2
            : ((3 * result) + 1) / 2;

        limit--;
    }

    return limit ? 1 : 0;
}

int main() {
    int inputN = 0;
    int inputLimit = 0;
    int highest = 0;

    while (inputN <= 1) {
        cout << "Input value for N" << endl;
        cin >> inputN;
    }

    while (inputLimit <= 1) {
        cout << "Input limit for sequence" << endl;
        cin >> inputLimit;
    }

    int result = syracuse1(inputN, inputLimit, highest);

    cout << (result ? "\"1\" has been reached!" : "Aborted due to reaching limit") << endl;
    cout << "Highest number reached: " << highest << endl;

    return 0;
}