#include <iostream>
using namespace std;

int main() {
   int int0;
   int int1;
   int int2;
   int int3;
   int oddOnes = 0;
   
   cin >> int0;
   cin >> int1;
   cin >> int2;
   cin >> int3;
   
   if ((int0 % 2) == 1) oddOnes++;
   if ((int1 % 2) == 1) oddOnes++;
   if ((int2 % 2) == 1) oddOnes++;
   if ((int3 % 2) == 1) oddOnes++;
   
   cout << oddOnes << endl;

   return 0;
}

