#include <iostream>
using namespace std;

int main() {
    int val1;
    int val2;
    int val3;
    int max;
    
    cin >> val1;
    cin >> val2;
    cin >> val3;
    
    max = val1 > val2
      ? val1 > val3
         ? val1
         : val3
      : val2 > val3
         ? val2
         : val3;
         
   cout << "Max of [" << val1 << ", " << val2 << ", " << val3 << "] is " << max << endl;

    return 0;
}