#include <iostream>
#include "Calculator.h"
using namespace std;

Calculator::Calculator() {
    value = 0.0;
}

void Calculator::Add(double num) {
    value = value + num;
}

void Calculator::Subtract(double num) {
    value = value - num;
}

void Calculator::Multiply(double num) {
    value = value * num;
}

void Calculator::Divide(double num) {
    value = value / num;
}

void Calculator::Clear() {
    value = 0.0;
}

double Calculator::GetValue() {
    return value;
}

