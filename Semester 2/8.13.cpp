#include <iostream>
using namespace std;

int DigitCount(int num, int count = 0) {
    if (!num && !count) return 1;

    if (num < 1) {
        return count;
    } else {
        count++;
        return DigitCount(num / 10, count);
    }
}

int main() {
   int num;

   cin >> num;

   int digits = DigitCount(num);

   cout << digits << endl;
   return 0;
}
