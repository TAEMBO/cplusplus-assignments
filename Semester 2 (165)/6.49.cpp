#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// This method reverses contents of parameter vect.
vector<int> Reverse(vector<int> vect) {
	reverse(vect.begin(), vect.end());
	
	return vect;
}

int main() {
   size_t i = 0;
	vector<int> intVect(3);
	intVect.at(0) = 2;
	intVect.at(1) = 4;
	intVect.at(2) = 6;

	vector<int> reverseVect = Reverse(intVect);

   cout << "Reversed vector: {";
	for (i = 0; i < reverseVect.size() - 1; ++i) {
		cout << reverseVect.at(i) << ", ";
	}
   cout << reverseVect.at(i) << "}" << endl;
	return 0;
}