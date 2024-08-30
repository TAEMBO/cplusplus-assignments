#include "FancyCar.h"

FancyCar::FancyCar() {
    odometer = 5;
    gasLevel = FULL_TANK;
    mpg = 24.0;
    model = "Old Clunker";
    engineRunning = false; 
}

FancyCar::FancyCar(string carMake, double carMpg) {
    odometer = 5;
    gasLevel = FULL_TANK;
    mpg = carMpg;
    model = carMake;
    engineRunning = false;
}

// Return car model
string FancyCar::GetModel() {
    return model;
}

// Return miles per gallon (MPG)
double FancyCar::GetMPG() {
    return mpg;
}

// Return miles on odometer
int FancyCar::CheckOdometer() {
    return odometer;
}

// Return amount of gas in tank
double FancyCar::CheckGasGauge() {
    return gasLevel;
}

// Honk horn
void FancyCar::HonkHorn() {
   cout << "The " << model << " says beep beep!";
}

// Drive car requested miles but check for enough
// gas and check for positive value
void FancyCar::Drive(int milesToDrive) {
    if (milesToDrive <= 0 || !engineRunning) return;

    double driveableMiles = gasLevel * mpg;

    if (driveableMiles < milesToDrive) {
        odometer += driveableMiles;
        gasLevel = 0.0;
        engineRunning = false;
        
        return;
    }

    odometer += milesToDrive;
    gasLevel = milesToDrive / mpg;
}

// Add gas to tank. Check for positive value.
void FancyCar::AddGas(double amtToAdd) {
    if (amtToAdd <= 0 || engineRunning) return;

    double totalAmount = gasLevel + amtToAdd;

    gasLevel = totalAmount > FULL_TANK ? FULL_TANK : totalAmount;
}

// Set boolean variable to true
 void FancyCar::StartEngine() {
    engineRunning = true;
}

// Set boolean variable to false
void FancyCar::StopEngine() {
    engineRunning = false;
}
