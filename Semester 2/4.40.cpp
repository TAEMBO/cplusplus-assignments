#include <iostream>
using namespace std;

int main() {
   int userRows;
   int userCols;
   
   cin >> userRows;
   cin >> userCols;

   cout << "<table>" << endl;
   
   for (int i = 0; i < userRows; i++) {
      cout << "<tr> ";
      
      for (int j = 0; j < userCols; j++) {
         cout << "<td> c </td> ";
      }
      
      cout << "</tr>" << endl;
      
   }
   
   cout << "</table>" << endl;
   
   return 0;
}