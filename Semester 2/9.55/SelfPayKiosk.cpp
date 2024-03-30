#include "SelfPayKiosk.h"

// Constructor
SelfPayKiosk::SelfPayKiosk() {
    customersServed = 0;
    totalSales = 0.0;
    currentAmtDue = 0.0;
    checkedOutAndReady = false;
}

// Return total daily sales
double SelfPayKiosk::GetTotalSales() {
    return totalSales;
}

// Return current amount due
double SelfPayKiosk::GetAmountDue() {
    return currentAmtDue;
}

// Return number of customers served
int SelfPayKiosk::GetNumCustomers() {
    return customersServed;
}

// Scan one item
void SelfPayKiosk::ScanItem(double price) {
    if (price < 0.0) return;

    currentAmtDue += price;
}

// Apply sales tax to current purchases
void SelfPayKiosk::CheckOut() {
    currentAmtDue += currentAmtDue * SALES_TAX;
    checkedOutAndReady = true;
}

// Cancel current purchases
void SelfPayKiosk::CancelTransaction() {
    if (checkedOutAndReady) return;

    currentAmtDue = 0.0;
}

// Reset register for the day
void SelfPayKiosk::ResetKiosk() {
    customersServed = 0;
    totalSales = 0.0;
    currentAmtDue = 0.0;
}

// Apply payment to amount due
void SelfPayKiosk::MakePayment(double payment) {
    if (!checkedOutAndReady) return;

    if (payment < 0.0) return;

    if (payment < currentAmtDue) {
        totalSales += payment;
        currentAmtDue -= payment;

        return;
    }

    customersServed++;
    totalSales += currentAmtDue;
    currentAmtDue = 0.0;
    checkedOutAndReady = false;
}

// Simulate multiple transactions
void SelfPayKiosk::SimulateSales(int numSales, double initialPrice, double incrPrice) {
    for (int i = 0; i < numSales; i++) {
        ScanItem(initialPrice);
        CheckOut();
        MakePayment(currentAmtDue + 1.0);

        initialPrice += incrPrice;
    }
}
