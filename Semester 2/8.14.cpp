#include <iostream>
#include <iomanip>
using namespace std;

void DrawTriangle(int baseLength, int max = 0) {
    if (baseLength > max) return;

    string fill;
    string space;

    for (int i = 0; i < (baseLength / 2); i++) fill += '*';

    for (int i = 0; i < (9 - (baseLength / 2)); i++) space += ' ';

    cout << space << fill << "*" << fill << endl;

    DrawTriangle(baseLength + 2, max);
}

int main() {
   int baseLength;
   
   cin >> baseLength;

   DrawTriangle(1, baseLength);

   return 0;
}