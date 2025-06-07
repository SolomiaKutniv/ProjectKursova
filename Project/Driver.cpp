#include <iostream>
#include <string>
#include "Driver.h"
#include <fstream>

using namespace std;

Driver::Driver() : surname(""), initials(""), persnum(1), salary(4) {}
//Конструктор ініціалізації
Driver::Driver(const string& surname, const string& initials, int persnum, int salary) : surname(surname), initials(initials), persnum(persnum), salary(salary) {}

//Конструктор копіювання
Driver::Driver(const Driver& other) : surname(other.surname), initials(other.initials), persnum(other.persnum), salary(other.salary) {}


//Конструктор переміщення
Driver::Driver(Driver&& other) noexcept : surname(move(other.surname)), initials(move(other.initials)), persnum(move(other.persnum)), salary(move(other.salary)) {}
Driver::~Driver() {}

//Оператор для встановлення значень полів
void Driver::operator()(const string& surname, const string& initials, int persnum, int salary) {
	this->surname = surname;
	this->initials = initials;
	this->persnum = persnum;
	this->salary = salary;
}

//Оператор присвоєння для копіювання
Driver& Driver::operator=(const Driver& other) {
	if (this != &other) {
		surname = other.surname;
		initials = other.initials;
		persnum = other.persnum;
		salary = other.salary;
	}
	return *this;
}

//Оператор переміщення
Driver& Driver::operator=(Driver&& other) noexcept {
	if (this != &other) {
		surname = move(other.surname);
		initials = move(other.initials);
		persnum = move(other.persnum);
		salary = move(other.salary);
	}
	return *this;
}

//Потоковий оператор виведення
ostream& operator<<(ostream& os, const Driver& driver) {
	os << driver.surname << "\n";
	os << driver.initials << "\n";
	os << driver.persnum << "\n";
	os << driver.salary;
	return os;
}


//Потоковий оператор введення
istream& operator>>(istream& is, Driver& driver) {
	if (&is == &cin) {
		cout << "Прiзвище: ";
		is >> driver.surname;
		cout << "Iнiцiали: ";
		is >> driver.initials;
		cout << "Персональний номер: ";
		is >> driver.persnum;
		cout << "Оклад: ";
		is >> driver.salary;
		return is;
	}
	else {
		is >> driver.surname;
		is >> driver.initials;
		is >> driver.persnum;
		is >> driver.salary;
		return is;
	}
}

//Встановлення
void Driver::setSurname(const string& surname) { this->surname = surname; }
void Driver::setInitials(const string& initials) { this->initials = initials; }
void Driver::setPersnum(int persnum) { this->persnum = persnum; }
void Driver::setSalary(int salary) { this->salary = salary; }

string Driver::getSurname() const { return surname; }
string Driver::getInitials() const { return initials; }
int Driver::getPersnum() const { return persnum; }
int Driver::getSalary() const { return salary; }

//Виведення
void Driver::info() {
	cout << "Прiзвище: " << getSurname() << "\nIнiцiали: " << getInitials() << "\nПерсональний номер: " << getPersnum() << "\nОклад: " << getSalary() << endl;
}

/*istream& operator>>(istream& is, Driver& driver) {
	if (&is == &cin) {
		cout << "Прiзвище: ";
		is >> driver.surname;
		cout << "Iнiцiали: ";
		is >> driver.initials;
		cout << "Персональний номер: ";
		is >> driver.persnum;
		cout << "Оклад: ";
		is >> driver.salary;
		return is;
	}
	else {
		is >> driver.surname;
		is >> driver.initials;
		is >> driver.persnum;
		is >> driver.salary;
		return is;
	}
}*/