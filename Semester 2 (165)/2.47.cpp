#include <iostream>
#include <iomanip>
using namespace std;

double crunch(double cost, int width, int length, double &sales, int id) {
   int area = width * length;
   double areaCost = area * cost;
   double areaCostWWaste = areaCost + (areaCost / 5);
   double laborCost = area * 0.75;
   double tax = (areaCostWWaste + laborCost) * 0.07;
   
   cout
      << "Order #" << id << endl
      << "Room: " << area << " sq ft" << endl
      << fixed << setprecision(2)
      << "Carpet: $" << areaCostWWaste << endl
      << "Labor: $" << laborCost << endl
      << "Tax: $" << tax << endl
      << "Cost: $" << areaCostWWaste + laborCost + tax << endl << endl;
      
   sales = sales + areaCostWWaste + laborCost + tax;


}

int main() {
   int width0, width1, width2, length0, length1, length2;
   double cost0, cost1, cost2;
   double sales = 0.00;
   
   cin >> cost0;
   cin >> width0;
   cin >> length0;
   
   cin >> cost1;
   cin >> width1;
   cin >> length1;
   
   cin >> cost2;
   cin >> width2;
   cin >> length2;
   
   crunch(cost0, width0, length0, sales, 1);
   crunch(cost1, width1, length1, sales, 2);
   crunch(cost2, width2, length2, sales, 3);
   
   cout << fixed << setprecision(2) << "Total Sales: $" << sales << endl;
   
   return 0;
}
