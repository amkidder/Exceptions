//Alyssa Kidder
//April 27, 2020 ©
//Chapter 16 Assignment

#include <iostream>
using namespace std;

class Employee {
private:
	string name;
	int number;
	string hired;
public:
	class InvalidEmployeeNumber {}; //exception

	Employee() { //constructors
		name = "";
		number = 0;
		hired = "";
	}
	Employee(string inputName, int id, string hiredDate) {
		if (id > 0 && id < 9999) {
			name = inputName;
			number = id;
			hired = hiredDate;
		}
		else
			throw InvalidEmployeeNumber();
	}
	string getName() { //getters
		return name;
	}
	int getID() {
		return number;
	}
	string getHiredDate() {
		return hired;
	}
	void setName(string newName) { //setters
		name = newName;
	}
	void setID(int id) {
		if (id < 0 && id > 9999) {
			number = id;
		}
		else
			throw InvalidEmployeeNumber();
	}
	void setHiredDate(string date) {
		hired = date;
	}
};

class ProductionWorker : public Employee {
private:
	int shift; //1 = day, 2 = night
	double hourlyPay;
public:
	class InvalidShift {}; //exceptions
	class InvalidPayRate{};

	ProductionWorker() : Employee() { //constructors
		shift = 0;
		hourlyPay = 0;
	}
	ProductionWorker(string name, int id, string hired, int shiftNum, double payRate) : Employee(name, id, hired) {
		if (shiftNum == 1 || shiftNum == 2) 
			shift = shiftNum;
		else
			throw InvalidShift();
		if (payRate >= 0)
			hourlyPay = payRate;
		else
			throw InvalidPayRate();
	}
	int getShift() { //getters
		return shift;
	}
	double getRate() {
		return hourlyPay;
	}
	void setShift(int shiftNum) { //setters
		if (shiftNum == 1 || shiftNum == 2)
			shift = shiftNum;
		else
			throw InvalidShift();
	}
	void setRate(double payRate) {
		if (payRate >= 0)
			hourlyPay = payRate;
		else
			throw InvalidPayRate();
	}
};

int main() {
	//InvalidEmployeeNumber catch demonstration
	try {
		ProductionWorker employee1 = ProductionWorker("Sally May", 12345, "1/2/2020", 1, 1.25);
		cout << "ProductionWorker Demonstration\nEmployee Name: " << employee1.getName()
			<< "\nID: " << employee1.getID()
			<< "\nHired Date: " << employee1.getHiredDate()
			<< "\nShift Num: " << employee1.getShift()
			<< "\nHourly Pay Rate: " << employee1.getRate() << endl;
	}
	catch (Employee::InvalidEmployeeNumber) {
		cout << "ERROR: Employee number is invalid." << endl;
	}

	//InvalidShift catch demonstration
	try {
		ProductionWorker employee2 = ProductionWorker("May Day", 2345, "1/3/2020", 0, 1.25);
		cout << "ProductionWorker Demonstration\nEmployee Name: " << employee2.getName()
			<< "\nID: " << employee2.getID()
			<< "\nHired Date: " << employee2.getHiredDate()
			<< "\nShift Num: " << employee2.getShift()
			<< "\nHourly Pay Rate: " << employee2.getRate() << endl;
	}
	catch (ProductionWorker::InvalidShift) {
		cout << "ERROR: Shift number is invalid" << endl;
	}

	//InvalidPayRate catch demonstration
	try {
		ProductionWorker employee3 = ProductionWorker("Scooby Doo", 3456, "1/4/2020", 1, -1);
		cout << "ProductionWorker Demonstration\nEmployee Name: " << employee3.getName()
			<< "\nID: " << employee3.getID()
			<< "\nHired Date: " << employee3.getHiredDate()
			<< "\nShift Num: " << employee3.getShift()
			<< "\nHourly Pay Rate: " << employee3.getRate() << endl;
	}
	catch (ProductionWorker::InvalidPayRate) {
		cout << "ERROR: Pay rate is invalid" << endl;
	}
}