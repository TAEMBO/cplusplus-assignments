#include <iostream>
#include <fstream>
#include "vehicle.h"
using namespace std;

int main() {
	ifstream file("a7dataF24.txt");

	if (!file.good()) {
		cout << "Error opening file" << endl;

		return EXIT_FAILURE;
	}

	string data;
	Vehicle* vehicles[100];
	int vehiclesIndex = 0;

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

	return EXIT_SUCCESS;
}
