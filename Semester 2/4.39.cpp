#include <iostream>
#include <cctype>
using namespace std;

bool hasNumber(string input) {
   for (char character : input) {
      if (isdigit(character)) return true;
   }
   
   cout << "Missing number" << endl;
   
   return false;
   
}

bool hasLetter(string input) {
   for (char character : input) {
      if (isalpha(character)) return true;
   }
   
   cout << "Missing letter" << endl;
   
   return false;
}

bool hasSpecialChar(string input) {
   for (char character : input) {
      if (character == '!' || character == '#' || character == '%') return true;
   }
   
   cout << "Missing special" << endl;
   
   return false;
   
}

int main() {
   string input;
   
   getline(cin, input);
   
   if (static_cast<int>(input.size()) < 7) cout << "Too short" << endl;
   
   bool hasLtr = hasLetter(input);
   bool hasNum = hasNumber(input);
   bool hasSpcl = hasSpecialChar(input);
   
   if (hasNum && hasLtr && hasSpcl) cout << "OK" << endl;

   return 0;
}