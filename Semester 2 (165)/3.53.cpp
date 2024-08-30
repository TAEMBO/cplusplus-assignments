#include <iostream>
using namespace std;

int main() {
   int num;
   
   cin >> num;
   
   string input = to_string(num);
   
   cout << input.size() << " digit" << (input.size() == 1 ? "" : "s") << endl;
   
   return 0;
}