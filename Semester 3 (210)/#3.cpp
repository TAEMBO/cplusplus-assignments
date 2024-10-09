#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <cctype>
#include <chrono>

using namespace std;

const int PARAMS_MAX = 5;

bool customerArrived(double prob) {
    double rv = rand() / (double(RAND_MAX) + 1);

    return (rv < prob);
}

void runSimulation(
    int simTime,
    double arrivalRate,
    int serviceTime,
    int maxLine,
    int &nServed,
    int &totalWait,
    int &totalLength,
    int &totalDropped
) {
    queue<int> customerQueue;
    int curCustomerTime = 0;
    int totalLineSize = 0;
    nServed = 0;
    totalWait = 0;
    totalLength = 0;
    totalDropped = 0;

    for (int curTime = 0; curTime < simTime; curTime++) { 
        curCustomerTime--;

        if (customerArrived(arrivalRate)) {
            if (customerQueue.size() == maxLine) {
                totalDropped++;
            } else {
                customerQueue.push(curTime);
            }
        }

        if (curCustomerTime <= 0) {
            if (customerQueue.size() != 0) {
                int nextCustomer = customerQueue.front();
                
                curCustomerTime = serviceTime;
                totalWait += curTime - nextCustomer;
                nServed++;

                customerQueue.pop();
            }
        }

        totalLength += customerQueue.size();
    }
}

bool readNextSimulation(
    ifstream &f,
    string &name,
    int &simulationTime,
    double &arrivalRate,
    int &serviceTime,
    int &lineSize
) {
    string buf;
    string fileValues[5];
    int i = 0;

    while (getline(f, buf)) {
        if (f.eof()) break;

        fileValues[i++] = buf;

        if (i == PARAMS_MAX) {
            name = fileValues[0];

            if (name.size() != 0 && name[name.size() - 1] == '\r') name.erase(name.size() - 1);

            simulationTime = atoi(fileValues[1].c_str());
            arrivalRate = atof(fileValues[2].c_str());
            serviceTime = atoi(fileValues[3].c_str());
            lineSize = atoi(fileValues[4].c_str());

            return true;
        }
    }

    return false;
}

void printReport(
    string name,
    int simTime,
    double arrivalRate,
    int serviceTime,
    int maxLine,
    int nServed,
    int totalWait,
    int totalLength,
    int totalDropped
) {
    cout
        << left
        << endl
        << setw(25) << "Simulation name: " << setw(12) << name << endl
        << "--------------------------------------" << endl
        << setw(25) << "Simulation time: " << setw(12) << simTime << endl
        << setw(25) << "Arrival rate: " << setw(12) << arrivalRate << endl
        << setw(25) << "Service time: " << setw(12) << serviceTime << endl
        << setw(25) << "Max line size: " << setw(12) << maxLine << endl
        << endl
        << setw(25) << "Customers served:" << setw(12) << nServed << endl
        << setw(25) << "Average wait time:" << double(totalWait) / nServed << endl
        << setw(25) << "Average line length:" << setw(12) << double(totalLength) / simTime << endl
        << setw(25) << "Total dropped customers:" << setw(12) << totalDropped << endl;
}

int main() {
    chrono::system_clock::time_point begin = chrono::system_clock::now();
    int nServed;
    int totalWait;
    int totalLength;
    int totalDropped;

    string name;
    int simTime;
    double arrivalRate;
    int serviceTime;
    int maxLine;

    string buf;
    ifstream f("./simtest.txt");

    srand(int(time(NULL)));

    if (!f.good()) {
        cerr << "Invalid file, exiting." << endl;

        return -1;
    }

    while (readNextSimulation(f, name, simTime, arrivalRate, serviceTime, maxLine)) {
        runSimulation(
            simTime,
            arrivalRate,
            serviceTime,
            maxLine,
            nServed,
            totalWait,
            totalLength,
            totalDropped
        );

        printReport(
            name,
            simTime,
            arrivalRate,
            serviceTime,
            maxLine,
            nServed,
            totalWait,
            totalLength,
            totalDropped
        );
    }

    cout << endl << "Total computation time: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - begin).count() << "ms" << endl;

    return 0;
}
