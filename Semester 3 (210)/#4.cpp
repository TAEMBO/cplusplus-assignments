#include <iostream>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAXNUM = 1000;

void fillRandom(int *, int);
void tableRow(int, double, double);
double calculateExpected(double, double, int, const string);

int main() {
    const int START_ARRAY_SIZE = 50000;
    const string BIG_O_GUESS = "O(n squared)";
    const int N_RUNS = 4;
    int *testArray = 0;
    int arraySize = START_ARRAY_SIZE;
    double baseline = 0;
    double expected = 0;

    cout << fixed << setprecision(4) << left;
    srand(time(0));
    tableRow(-1, 0, 0);

    for (int cycle = 0; cycle < N_RUNS; cycle++) {
        testArray = new int[arraySize];
        fillRandom(testArray, arraySize);

        auto start = chrono::high_resolution_clock::now();
        
        bool sorted = false;
        int pass = 1;
        bool exch = false;
        
        while (!sorted && (pass < arraySize)) {
            sorted = true;

            for (int i = 0; i < arraySize - 1; i++) {
                exch = testArray[i] > testArray[i + 1];

                if (exch) {
                    swap(testArray[i], testArray[i + 1]);
                    sorted = false;
                }
            }
            
            pass++;
        }

        auto end = chrono::high_resolution_clock::now();
        double elapsed = chrono::duration<double>(end - start).count();

        for (int i = 0; i < arraySize - 1; i++) {
            if (testArray[i] > testArray[i + 1]) {
                cout << "Sorting invalid, array index: " << i << endl;
                
                return -1;
            }
        }

        if (cycle == 0) baseline = elapsed;

        expected = calculateExpected(arraySize, baseline, cycle, BIG_O_GUESS);

        tableRow(arraySize, elapsed, expected);

        delete [] testArray;

        testArray = 0;
        arraySize *= 2;
    }
    return 0;
}

void fillRandom(int array[], int len) {
    for (int i = 0; i < len; i++) array[i] = rand() % MAXNUM;
}

void tableRow(int asize, double elapsed, double expected) {
    const int cw = 16;
    double diff = 0, pct = 0;
    stringstream ss;

    if (asize == -1) {
        cout << endl;
        cout << setw(cw * 4) << setfill('-') << "" << endl;
        cout << setfill(' ');
        cout << setw(cw)
             << "Array size"
             << setw(cw)
             << "Elapsed (s)"
             << setw(cw)
             << "Expected (s)"
             << setw(cw)
             << "Difference" << endl;

        cout << setw(cw * 4) << setfill('-') << "" << endl;
        cout << setfill(' ');
        return;
    }

    diff = abs(expected - elapsed);
    pct = (diff / expected) * 100;
    ss << fixed;
    ss << setprecision(4) << diff;
    ss << setprecision(2) <<  " (" << pct << "%)";
    cout
        << setw(cw)
        << asize
        << setw(cw)
        << elapsed
        << setw(cw)
        << expected
        << ss.str()
        << endl;
}

double calculateExpected(double arraySize, double baseline, int cycle, const string guess) {
    double factor = pow(2, cycle);

    if (cycle == 0) return baseline;

    if (guess == "O(n)") return (factor * baseline);

    if (guess == "O(n log n)")  return (factor * log(double(arraySize)) / log(arraySize / factor) * baseline);

    if (guess == "O(n squared)") return (factor * factor * baseline);

    cout << "WARNING:  calculateExpected() with unkown big-O value: " << guess << endl;
    
    return 0;
}
