#include <iostream>
using namespace std;

int main() {
   int amount;
   
   cin >> amount;
   
   for (int i = amount; i > 0; i--) {
      for (int j = i; j > 0; j--) cout << "* ";
      
      cout << endl;
   }
   
   return 0;
}