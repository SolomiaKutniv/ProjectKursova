#include <iostream>
#include <string>
#include "Car.h"
#include <fstream>

using namespace std;

Car::Car() : number(""), brand(""), payload(1), fuel(1), registration("") {}
//Конструктор ініціалізації
Car::Car(const string& number, const string& brand, int payload, double fuel, const string& registration) : number(number), brand(brand), payload(payload), fuel(fuel), registration(registration) {}


//Конструктор копіювання
Car::Car(const Car& other) : number(other.number), brand(other.brand), payload(other.payload), fuel(other.fuel), registration(other.registration) {}

//Конструктор переміщення
Car::Car(Car&& other) noexcept : number(move(other.number)), brand(move(other.brand)), payload(move(other.payload)), fuel(move(other.fuel)), registration(move(other.registration)) {}
Car::~Car() {}

//Оператор для встановлення значень полів
void Car::operator()(const string& number, const string& brand, int payload, double fuel, const string& registration) {
	this->number = number;
	this->brand = brand;
	this->payload = payload;
	this->fuel = fuel;
	this->registration = registration;
}

//Оператор присвоєння для копіювання
Car& Car::operator=(const Car& other) {
	if (this != &other) {
		number = other.number;
		brand = other.brand;
		payload = other.payload;
		fuel = other.fuel;
		registration = other.registration;
	}
	return *this;
}

//Оператор переміщення
Car& Car::operator=(Car&& other) noexcept {
	if (this != &other) {
		number = move(other.number);
		brand = move(other.brand);
		payload = move(other.payload);
		fuel = move(other.fuel);
		registration = move(other.registration);
	}
	return *this;
}

//Потоковий оператор виведення
ostream& operator<<(ostream& os, const Car& car) {
	os << car.number<< "\n"
		<< car.brand << "\n"
		<< car.payload << "\n"
		<< car.fuel<< "\n"
		<< car.registration << "\n";
	return os;
}



//Потоковий оператор введення
istream& operator>>(istream& is, Car& bus) {
	is >> bus.number;
	is >> bus.brand;
	is >> bus.payload;
	is >> bus.fuel;
	is.ignore();
	is >> bus.registration;
	return is;
}

string Car::getNumber() const { return number; }
string Car::getBrand() const { return brand; }
int Car::getPayload() const { return payload; }
double Car::getFuel() const { return fuel; }
string Car::getRegistration() const { return registration; }

//Встановлення
void Car::setNumber(const string& number) { this->number = number; }
void Car::setBrand(const string& brand) { this->brand = brand; }
void Car::setPayload(int payload) { this->payload = payload; }
void Car::setFuel(double fuel) { this->fuel = fuel; }
void Car::setRegistration(const string& registration) { this->registration = registration; }


//Виведення
void Car::info() {
	cout << "Номер: " << getNumber() << "\nМарка: " << getBrand() << "\nВантажопідйомність: " << getPayload() << "\nНорма витрат пального: " << getFuel() << "л \nМісце прописки: " << getRegistration() << endl;
};