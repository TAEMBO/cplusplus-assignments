#include <iostream>
#include <vector>

using namespace std;

int main() {
   vector<int> userValues(10);
   
   for (int i = 0; i < 10; ++i) {
      cin >> userValues.at(i);
   }
   
   int min = userValues.at(0);
   int max = userValues.at(0);
   int sum = 0;
   
   for (int i = 0; i < 10; i++) {
      int value = userValues.at(i);
      
      sum = sum + value;
      
      if (value > max) max = value;
   }
   
   min = max;
   
   for (int i = 0; i < 10; i++) {
      if (userValues.at(i) < min) min = userValues.at(i);
   }
   
   cout << min << " " << max << " " << sum / 10.0 << endl;
   
   return 0;
}