#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;


bool isPalindrome(string input) {
   for(int i = 0; i < static_cast<int>(input.length()); i++) {
      if (input[i] == ' ') input.erase(i, 1);
   }
   
   for (int i = 0; i < static_cast<int>(input.length()) / 2; i++) {
      if (input[i] != input[input.length() - i - 1]) return false;
   }
   return true;
}


int main() {
   string input;
   
   getline(cin, input);
   
   bool result = isPalindrome(input);
   
   if (result) {
      cout << "palindrome: " << input << endl;
   } else {
      cout << "not a palindrome: " << input << endl;
   }

   return 0;
}
