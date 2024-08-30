#include <iostream>
#include <iomanip>              // needed for setprecision() and fixed
#include <cmath>                // needed for ceil()
using namespace std;

int main() {
   double height, width, cost;
   
   cin >> height;
   cin >> width;
   cin >> cost;
   
   double gallons = height * width / 350;
   int cans = gallons + 1;
   double totalCost = cost * cans;
   double TAX_RATE = 0.07;
   double salesTax = totalCost * TAX_RATE;
   
   cout
      << fixed << setprecision(1)
      << "Wall area: " << height * width << " sq ft" << endl
      << setprecision(3)
      << "Paint needed: " << gallons << " gallons" << endl
      << "Cans needed: " << cans << " can(s)" << endl
      << setprecision(2)
      << "Paint cost: $" << cost * cans << endl
      << setprecision(2)
      << "Sales tax: $" << salesTax << endl
      << "Total cost: $" << totalCost + salesTax << endl;
      

   return 0;
}
