#include <iostream>
#include <iomanip>                   // for setprecision()
#include <vector>
#include <algorithm>                 // for sort()
using namespace std;

bool isPalindrome(vector<int> input) {
    for (int i = 0; i < static_cast<int>(input.size()) / 2; i++) {
        if (input[i] != input.at(input.size() - i - 1)) return false;
    }

    return true;
}

int main() {
    int count;

    cin >> count;
    
    vector<int> nums(count);

    for (int i = 0; i < count; ++i) {
       cin >> nums.at(i);
    }

    // Step 1: Find minimum and maximum values
    int min = nums.at(0);
    int max = nums.at(0);
    int sum = 0;
   
    for (int i = 0; i < count; i++) {
        int value = nums.at(i);
      
        sum = sum + value;
      
        if (value > max) max = value;
    }
   
    for (int i = 0; i < count; i++) {
        if (nums.at(i) < min) min = nums.at(i);
    }

    cout
        << "Minimum: " << min << endl
        << "Maximum: " << max << endl;
    
    // Step 2: Calculate mean
    double mean = sum / static_cast<double>(count);

    cout
        << fixed << setprecision(1)
        << "Mean: " << mean << endl;

    // Step 3: Check if palindrome
    if (isPalindrome(nums)) {
        cout << "Palindrome: true" << endl;
    } else {
        cout << "Palindrome: false" << endl;
    }

    // Sort vector elements in ascending order
    sort(nums.begin(), nums.end());
    
    // Step 4: Find and output median
    int vectorSize = static_cast<int>(nums.size());
    double median;

    if ((vectorSize % 2) == 0) {
        int firstNum = nums.at(vectorSize / 2);
        int secondNum = nums.at((vectorSize / 2) - 1);

        median = (firstNum + secondNum) / 2.0;
    } else {
        median = nums.at(vectorSize / 2);
    }

    cout << "Median: " << median << endl;

    // Step 5: Find and output mode
    int numCounts[99];

    for (auto &num : numCounts) num = 0;

    for (auto num : nums) numCounts[num]++;

    int mode;

    for (int i = 0; i < 99; i++) {
        int numCount = numCounts[i];

        if (i == 0) {
            mode = 0;
        } else {
            if (numCount > numCounts[mode]) mode = i;
        }
    }

    cout << "Mode: " << mode << endl;

    return 0;
}
