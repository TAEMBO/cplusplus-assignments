#include <iostream>
using namespace std;

int main() {
   string input;
   
   getline(cin, input);
   
   for (char character : input) {
      if (isalpha(character)) cout << character;
   }
   
   cout << endl;
   
   return 0;
}