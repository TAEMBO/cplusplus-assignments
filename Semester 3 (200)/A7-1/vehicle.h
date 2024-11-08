#include <iostream>

using namespace std;

class Vehicle {
    protected:
        string vehicleId;
        string manufacturer;
        string dateEnteredService;
        int capacity;
        char status;
};

class Bus : public Vehicle {
    private:
        char fuelType;
        int milageSinceInspection;
        string tireSize;

};

class Railcar : public Vehicle {
    private:
        int powerOnTimeSinceInspection;
        char motorType;
        int motorVoltage;

};

class AutoCab : public Vehicle {
    private:
        int mileageSinceInspection;
        int batteryOperatingHours;
        int softwareLevel;
};
