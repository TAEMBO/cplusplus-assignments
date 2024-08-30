#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool InOrder(vector<int> nums) {
   vector<int> preSorted = nums;
   bool sorted = true;
   
   sort(nums.begin(), nums.end());
   reverse(nums.begin(), nums.end());
   
   for (int i = 0; i < static_cast<int>(nums.size()); i++) {
      if (nums[i] != preSorted[i]) sorted = false;
   }
   
   return sorted;
}

int main() {

	vector<int> nums1 = {5, 6, 7, 8, 3};

	if (InOrder(nums1)) {
		cout << "In descending order" << endl;
	}
	else {
		cout << "Not in order" << endl;
	}

	vector<int> nums2 = {10, 8, 7, 6, 5};

	if (InOrder(nums2)) {
		cout << "In descending order" << endl;
	}
	else {
		cout << "Not in order" << endl;
	}

	return 0;
}