#include "Plant.h"
#include "Flower.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

// TODO: Define a PrintVector function that prints a vector of plant (or flower) object pointers

int main() {
    string input;
    vector<Plant*> myGarden;
    int index = 0;
    
    getline(cin, input);
    
    while(input != "-1") {
        vector<string> values;
        string value;
        stringstream stringStream(input);

        while (stringStream.good()) {
            getline(stringStream, value, ' ');

            values.push_back(value);
        }

        if (values.at(0) == "flower") {
            Flower *flower = new Flower();

            flower->SetPlantName(values.at(1));
            flower->SetPlantCost(stoi(values.at(2)));
            flower->SetPlantType(values.at(3) == "true" ? true : false);
            flower->SetColorOfFlowers(values.at(4));

            myGarden.push_back(flower);
        } else {
            Plant *plant = new Plant();

            plant->SetPlantName(values.at(1));
            plant->SetPlantCost(stoi(values.at(2)));

            myGarden.push_back(plant);
        }
        getline(cin, input);

        index++;
    }
        
    // TODO: Call the method PrintVector to print myGarden
    for (size_t i = 0; i < myGarden.size(); ++i) {
        cout << "Plant " << i + 1 << " Information:" << endl;
        myGarden.at(i)->PrintInfo();
        cout << endl;
    }
    
    return 0;
}