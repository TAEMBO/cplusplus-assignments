#include <iostream>
#include <string>

using namespace std;

// Same as 2.28
int main() {
   long long phoneNumber;

   cin >> phoneNumber;
   
   int areaCode = phoneNumber / 10000000;
   int prefix = (phoneNumber % 10000000) / 10000;
   int lineNumber = (phoneNumber % 10000000) % 10000;
   
   cout << "(" << areaCode << ") " << prefix << "-" << lineNumber << endl;
   
   return 0;
}
