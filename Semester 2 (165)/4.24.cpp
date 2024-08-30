#include <iostream>
using namespace std;

int main() {
   string input;
   
   getline(cin, input);
   
   while (input != "Done" && input != "done" && input != "d") {
      for (int i = static_cast<int>(input.size()) - 1; i >= 0; i--) {
         cout << input[i];
      }
      
      cout << endl;
      
      getline(cin, input);
   }

   return 0;
}
