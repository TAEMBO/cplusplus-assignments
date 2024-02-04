#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void crunch(
   string day,
   int people,
   double slicesPerPerson,
   double pizzaCost,
   double &totalCost
) {
   int neededPizzas = ((people * slicesPerPerson) / 8) + 1;
   double neededPizzasCost = neededPizzas * pizzaCost;
   double neededPizzasTax = neededPizzasCost * 0.07;
   double deliveryCost = (neededPizzasCost + neededPizzasTax) / 5;
   double totalDayCost = neededPizzasCost + neededPizzasTax + deliveryCost;
   
   cout
      << fixed << setprecision(2)
      << day << " Night Party" << endl
      << neededPizzas <<  " Pizzas: $" << neededPizzasCost << endl
      << "Tax: $" << neededPizzasTax << endl
      << "Delivery: $" << deliveryCost << endl
      << "Total: $" << totalDayCost << endl << endl;
   
   totalCost += totalDayCost;
}

int main() {
   int people0, people1, people2;
   double
      slicesPerPerson0, slicesPerPerson1, slicesPerPerson2,
      pizzaCost0, pizzaCost1, pizzaCost2;
   double totalCost = 0.00;
   
   cin >> people0;
   cin >> slicesPerPerson0;
   cin >> pizzaCost0;
   
   cin >> people1;
   cin >> slicesPerPerson1;
   cin >> pizzaCost1;
   
   cin >> people2;
   cin >> slicesPerPerson2;
   cin >> pizzaCost2;
   
   crunch("Friday", people0, slicesPerPerson0, pizzaCost0, totalCost);
   crunch("Saturday", people1, slicesPerPerson1, pizzaCost1, totalCost);
   crunch("Sunday", people2, slicesPerPerson2, pizzaCost2, totalCost);
   
   cout << fixed << setprecision(2) << "Weekend Total: $" << totalCost << endl;

   return 0;
}
