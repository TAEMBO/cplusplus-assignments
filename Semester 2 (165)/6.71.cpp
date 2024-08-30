#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Calculate AGI and repair any negative values
int CalcAGI(int wages, int interest, int unemployment) {
    int gross = wages + interest + unemployment;

    if (gross < 0) gross = abs(gross);

    return gross;
}

// Calculate deduction depending on single, dependent or married
int GetDeduction(int status) {
    if (status == 1) {
        return 12000;
    } else if (status == 2) {
        return 24000;
    } else {
        return 6000;
    }
}

// Calculate taxable but not allow negative results
int CalcTaxable(int agi, int deduction) {
    int result = agi - deduction;

    if (result < 0) {
        return 0;
    } else {
        return result;
    }
}

// Calculate tax for single or dependent
int CalcTax(int status, int taxable) {
    double tax;

    if (status == 2) {
        if (taxable <= 20000) {
            tax = taxable * 0.10;
        } else if (taxable <= 80000) {
            tax = ((taxable - 20000) * 0.12) + 2000;
        } else {
            tax = ((taxable - 80000) * 0.22) + 9200;
        }
    } else {
        if (taxable <= 10000) {
            tax = taxable * 0.10;
        } else if (taxable <= 40000) {
            tax = ((taxable - 10000) * 0.12) + 1000;
        } else if (taxable <= 85000) {
            tax = ((taxable - 40000) * 0.22) + 4600;
        } else {
            tax = ((taxable - 85000) * 0.24) + 14500;
        }
    }

    return round(tax);
}

// Calculate tax due and check for negative withheld
int CalcTaxDue(int tax, int withheld) {
    if (withheld < 0) withheld = 0;
    
    return tax - withheld;
}

int main() {
    int wages, interest, unemployment,status, withheld;
    int tax, agi, due, deduction, taxable;
    
    // Step #1: Input information
    cin >> wages;
    cin >> interest;
    cin >> unemployment;
    cin >> status;
    cin >> withheld;

    // Step #2: Calculate AGI
    agi = CalcAGI(wages, interest, unemployment);
    deduction = GetDeduction(status);
    taxable = CalcTaxable(agi, deduction);
    tax = CalcTax(status, taxable);
    due = CalcTaxDue(tax, withheld);

    cout
        << "AGI: $" << agi << endl
        << "Deduction: $" << deduction << endl
        << "Taxable income: $" << taxable << endl
        << "Federal tax: $" << tax << endl
        << "Tax due: $" << due << endl;
    
    return 0;
}
