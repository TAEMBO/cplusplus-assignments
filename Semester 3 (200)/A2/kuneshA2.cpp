//============================================================================
// Name        : 
// Author      : 
// Class       : 
// Assignment  : A2
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include "instructor.h"
#include "calcSalary.h"
using namespace std;

const int ARR_SIZE = 100;

int main() {
	ifstream file;
	Instructor** instructors = new Instructor*[ARR_SIZE]();

	file.open("pa2data");

	if (!file.is_open()) {
		cout << "Failed to open file" << endl;

		return 1;
	}

	char record[45];
	int instInd = 0;

	file.read(record, 46);

	while (!file.eof()) {

		string recNumber;
		string recPayrollCode;
		string recFirstName;
		string recLastName;
		string recSalary;
		string recDeptCode;

		for (int i = 0; i < 6; i++) recNumber += record[i];

		for (int i = 6; i < 9; i++) recPayrollCode += record[i];

		for (int i = 9; i < 19; i++) recFirstName += record[i];

		for (int i = 20; i < 35; i++) recLastName += record[i];

		for (int i = 35; i < 41; i++) recSalary += record[i];

		for (int i = 41; i < 46; i++) recDeptCode += record[i];

		instructors[instInd] = new Instructor();

		Instructor* instructor = instructors[instInd];

		instructor->number = stoi(recNumber);
		instructor->payrollCode = recPayrollCode;
		instructor->firstName = recFirstName;
		instructor->middleInitial = record[19];
		instructor->lastName = recLastName;
		instructor->salary = stoi(recSalary);
		instructor->deptCode = recDeptCode;

		instInd++;

		file.read(record, 46);
	}

	cout
		<< "Employee ID  Last name       MI  First Name    Department    Salary"
		<< endl
		<< "======================================================================"
		<< endl;

	for (int i = 0; i < ARR_SIZE; i++) {
		if (instructors[i] == nullptr) break;

		Instructor inst = *instructors[i];

		cout
			<< inst.number
			<< inst.payrollCode
			<< "    "
			<< inst.firstName
			<< "      "
			<< inst.middleInitial
			<< "   "
			<< inst.lastName
			<< "  "
			<< inst.deptCode
			<< "      "
			<< inst.salary
			<< endl;
	}

	Instructor *highestSalaryInst = new Instructor();

	int avgSalary = calcSalary(instructors, highestSalaryInst);

	cout
		<< endl
		<< "The average salary is $"
		<< avgSalary
		<< " and the instructor with the highest salary at $"
		<< highestSalaryInst->salary
		<< " is "
		<< highestSalaryInst->firstName
		<< endl;

	delete[] instructors;

	file.close();

	return 0;
}
