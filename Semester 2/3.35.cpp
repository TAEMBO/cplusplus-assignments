#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1;
	string str2;
	string longest;
	string shortest;
	
	cin >> str1;
   cin >> str2;
	
	longest = str1.size() > str2.size() ? str1 : str2; 
	shortest = str1.size() < str2.size() ? str1 : str2;
	
	if (str1.size() == str2.size()) {
	   cout << str1 << " and " << str2 << " have the same length" << endl;
	} else {
	   cout << longest << " is longer than " << shortest << endl;
	}

   return 0;
}