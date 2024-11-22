#include <iostream>

using namespace std;

class Vehicle {
public:
		Vehicle(string vehicleId, string manufacturer, string dateEnteredService, int capacity, char status) {
			this->vehicleId = vehicleId;
			this->manufacturer = manufacturer;
			this->dateEnteredService = dateEnteredService;
			this->capacity = capacity;
			this->status = status;
		};
        virtual void print() = 0;
        virtual bool needsMaintenance() = 0;
        string getId() {
        	return vehicleId;
        };
        void setStatus(char status) {
        	this->status = status;
        }
    protected:
        string vehicleId;
        string manufacturer;
        string dateEnteredService;
        int capacity;
        char status;
        virtual ~Vehicle() {};
        void printBase() {
        	cout
				<< endl
				<< "ID: " << vehicleId << endl
				<< "Manufacturer: " << manufacturer << endl
				<< "Date entered service: " << dateEnteredService << endl
				<< "Capacity: " << capacity << endl
				<< "Status: " << status << endl;
        };
};

class Bus : public Vehicle {
	public:
		Bus(
			string vehicleId,
			string manufacturer,
			string dateEnteredService,
			int capacity,
			char status,
			char fuelType,
			int mileageSinceInspection,
			string tireSize
		) : Vehicle(vehicleId, manufacturer, dateEnteredService, capacity, status) {
			this->fuelType = fuelType;
			this->mileageSinceInspection = mileageSinceInspection;
			this->tireSize = tireSize;
		};
        virtual void print() {
        	printBase();

        	cout
				<< "Mileage since last inspection: " << mileageSinceInspection << endl
				<< "Fuel type: " << fuelType << endl
				<< "Tire size: " << tireSize << endl;
        };
        virtual bool needsMaintenance() {
        	return mileageSinceInspection >= 25000;
        }
    private:
        char fuelType;
        int mileageSinceInspection;
        string tireSize;

};

class Railcar : public Vehicle {
	public:
		Railcar(
			string vehicleId,
			string manufacturer,
			string dateEnteredService,
			int capacity,
			char status,
			int powerOnTimeSinceInspection,
			char motorType,
			int motorVoltage
		) : Vehicle(vehicleId, manufacturer, dateEnteredService, capacity, status) {
			this->powerOnTimeSinceInspection = powerOnTimeSinceInspection;
			this->motorType = motorType;
			this->motorVoltage = motorVoltage;
		};
        virtual void print() {
        	printBase();

        	cout
				<< "Power on time since last inspection: " << powerOnTimeSinceInspection << endl
				<< "Motor type: " << motorType << endl
				<< "Motor voltage: " << motorVoltage << endl;
        };
        virtual bool needsMaintenance() {
        	return powerOnTimeSinceInspection >= 100;
        }
    private:
        int powerOnTimeSinceInspection;
        char motorType;
        int motorVoltage;

};

class AutoCab : public Vehicle {
	public:
		AutoCab(
			string vehicleId,
			string manufacturer,
			string dateEnteredService,
			int capacity,
			char status,
			int mileageSinceInspection,
			int batteryOperatingHours,
			int softwareLevel
		) : Vehicle(vehicleId, manufacturer, dateEnteredService, capacity, status) {
			this->mileageSinceInspection = mileageSinceInspection;
			this->batteryOperatingHours = batteryOperatingHours;
			this->softwareLevel = softwareLevel;
		};
        virtual void print() {
        	printBase();

        	cout
				<< "Mileage since last inspection: " << mileageSinceInspection << endl
				<< "Battery Operating hours: " << batteryOperatingHours << endl
				<< "Software level: " << softwareLevel << endl;
        };
        virtual bool needsMaintenance() {
        	return mileageSinceInspection >= 500 || batteryOperatingHours >= 750;
        }
    private:
        int mileageSinceInspection;
        int batteryOperatingHours;
        int softwareLevel;
};
