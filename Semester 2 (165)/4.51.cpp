#include <iostream>
#include <string>
using namespace std;

int main() {
   string input0;
   string input1;
   int matched = 0;
   
   cin >> input0;
   cin >> input1;
   
   int max = input0.size() > input1.size() ? static_cast<int>(input0.size()) : static_cast<int>(input1.size());
   
   for (int i = 0; i < max; i++) {
      if (input0[i] == input1[i]) matched++;
   }
   
   if (matched == 1) {
      cout << matched << " character matches" << endl;
   } else {
      cout << matched << " characters match" << endl;
   }
   return 0;
}