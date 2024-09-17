#include <iostream>
#include <string>
#include "instructor.h"
#include "calcSalary.h"
using namespace std;

int calcSalary(Instructor* arr[], Instructor* &instructor) {
	int instructorCount = 0;
	int salaryTotal = 0;

	while (arr[instructorCount] != nullptr) {
		salaryTotal += arr[instructorCount]->salary;

		if (arr[instructorCount]->salary > instructor->salary) instructor = arr[instructorCount];

		instructorCount++;
	}

	return salaryTotal / instructorCount;
}
