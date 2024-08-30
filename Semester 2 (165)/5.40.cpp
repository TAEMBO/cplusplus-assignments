#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(vector<int> input) {
   for (int i = 0; i < static_cast<int>(input.size()) / 2; i++) {
      if (input[i] != input.at(input.size() - i - 1)) return false;
   }
   return true;
}

int main() {
    int count;
    int input;
    vector<int> list;
    
    cin >> count;
    
    for (int i = 0; i < count; i++) {
        cin >> input;
        list.push_back(input);
    }
    
   if (isPalindrome(list)) {
      cout << "yes" << endl;
   } else {
      cout << "no" << endl;
   }

    return 0;
}