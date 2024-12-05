#include <iostream>
#include <fstream>

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
		Vehicle() {}
        ~Vehicle() {};
        virtual void print() {};
        virtual bool needsMaintenance() {
        	return false;
        };
        string getId() {
        	return vehicleId;
        };
        void setStatus(char status) {
        	this->status = status;
        }
        void phase2();
        void phase3();
    protected:
        string vehicleId;
        string manufacturer;
        string dateEnteredService;
        int capacity;
        char status;
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

Vehicle* vehicles[100];
int vehiclesIndex = 0;

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

void Vehicle::phase2() {
	ifstream file("C:\\Users\\taembo\\Downloads\\a7dataF24.txt");

	if (!file.good()) {
		cout << "Error opening file" << endl;

		return;
	}

	string data;

	getline(file, data);

	while (!file.eof()) {
		string id = data.substr(0, 5);
		string manufacturer = data.substr(5, 15);
		string dateEnteredService = data.substr(20, 8);
		int capacity = stoi(data.substr(28, 3));
		char status = data.substr(31, 1)[0];

		switch (id[0]) {
			case 'B': {
				int mileageSinceInspection = stoi(data.substr(32, 7));
				string tireSize = data.substr(39, 9);
				char fuelType = data[48];

				vehicles[vehiclesIndex++] = new Bus(id, manufacturer, dateEnteredService, capacity, status, fuelType, mileageSinceInspection, tireSize);

				break;
			};
			case 'R': {
				int powerOnSinceInspection = stoi(data.substr(32, 3));
				char motorType = data[35];
				int motorVoltage = stoi(data.substr(36, 4));

				vehicles[vehiclesIndex++] = new Railcar(id, manufacturer, dateEnteredService, capacity, status, powerOnSinceInspection, motorType, motorVoltage);

				break;
			};
			case 'C': {
				int mileageSinceInspection = stoi(data.substr(32, 4));
				int batteryOpHours = stoi(data.substr(36, 4));
				int softwareVersion = stoi(data.substr(40, 6));

				vehicles[vehiclesIndex++] = new AutoCab(id, manufacturer, dateEnteredService, capacity, status, mileageSinceInspection, batteryOpHours, softwareVersion);

				break;
			};
			default: {
				cout << "Unknown vehicle type: " << id[0] << endl;
			};
		}

		getline(file, data);
	}

	for (int i = 0; i < vehiclesIndex; i++) vehicles[i]->print();
}

void Vehicle::phase3() {
	string input;

	getline(cin, input);

	while (input != "00000") {
		int foundVehicleIndex = -1;

		for (int i = 0; i < vehiclesIndex; i++) {
			if (vehicles[i]->getId() == input) {
				foundVehicleIndex = i;

				break;
			}
		}

		if (foundVehicleIndex == -1) {
			cout << "\nVehicle not found" << endl;
		} else {
			Vehicle* vehicle = vehicles[foundVehicleIndex];

			vehicle->print();

			if (vehicle->needsMaintenance()) {
				cout << "\nVehicle needs maintenance!" << endl;

				vehicles[foundVehicleIndex]->setStatus('M');
			}
		}

		getline(cin, input);
	}

	for (int i = 0; i < vehiclesIndex; i++) vehicles[i]->print();
}
