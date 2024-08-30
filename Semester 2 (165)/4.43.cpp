#include <iostream>
#include <string>
using namespace std;

int main() {
   string input;
   int spaceCount = 0;
   bool inWord = false;
   
   getline(cin, input);
   
   for (int i = 0; i < static_cast<int>(input.size()); i++) {
      if (input[i] == ' ') {
         inWord = false;
      } else if (input[i] != ' ' && !inWord) {
         spaceCount++;
         inWord = true;
      }
      
   }
   
   cout << spaceCount << endl;
   
   return 0;
}