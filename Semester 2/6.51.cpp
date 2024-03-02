#include <iostream>
#include <vector>
using namespace std;

vector<int> RemoveOdds(vector<int> nums) {
    vector<int> newNums;

	for (int i = 0; i < static_cast<int>(nums.size()); i++) {
	    if ((nums[i] % 2) == 0) newNums.push_back(nums[i]);
	}
	
	return newNums;
}

int main() {
	vector<int> input = {-2, -1, 3, 3, 3};

	vector<int> result = RemoveOdds(input); // Should return [2, 4, 6, 8]

	cout << "[";
	for (size_t i = 0; i < result.size(); ++i) {
		cout << result.at(i);
		if (i != result.size() - 1) {
		   cout << ", ";
		}
	}
	cout << "]" << endl;

	return 0;
}
