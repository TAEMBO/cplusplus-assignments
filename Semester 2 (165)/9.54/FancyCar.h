#ifndef FANCY_CAR_H
#define FANCY_CAR_H

#include <iostream>
#include <string>
using namespace std;

const int FULL_TANK = 14;

class FancyCar {
    public:
        FancyCar();
        FancyCar(string carMake, double carMpg);
        string GetModel();
        double GetMPG();
        int CheckOdometer();
        double CheckGasGauge();
        void HonkHorn();
        void Drive(int milesToDrive);
        void AddGas(double amtToAdd);
        void StartEngine();
        void StopEngine();
    private:
        int odometer;
        double gasLevel;
        double mpg;
        double driveCapacity;
        bool engineRunning;
        string model;
};

#endif
