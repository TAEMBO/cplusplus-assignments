#include <iostream>
using namespace std;

int CountEvens(int num1, int num2, int num3, int num4, int num5) {
   int count = 0;
   
   if (num1 % 2 == 0) count++;
   if (num2 % 2 == 0) count++;
   if (num3 % 2 == 0) count++;
   if (num4 % 2 == 0) count++;
   if (num5 % 2 == 0) count++;
   
   return count;
}

int main() {
   int num1;
   int num2;
   int num3;
   int num4;
   int num5;
   int result;
   
   cin >> num1;
   cin >> num2;
   cin >> num3;
   cin >> num4;
   cin >> num5;
   
   result = CountEvens(num1, num2, num3, num4, num5);
	cout << "Total evens: " << result << endl;

   return 0;
}
