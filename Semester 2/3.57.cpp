#include <iostream>
#include <string>

using namespace std;

int main() {
   long long phoneNumber;

   cin >> phoneNumber;
   
   int areaCode = phoneNumber / 10000000;
   int prefix = (phoneNumber % 10000000) / 10000;
   int lineNumber = (phoneNumber % 10000000) % 10000;
   
   cout << "(" << areaCode << ") " << prefix << "-" << lineNumber << endl;
   
   return 0;
}
