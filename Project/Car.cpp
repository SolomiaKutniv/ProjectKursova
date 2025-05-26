#include <iostream>
#include <string>
#include "Car.h"
#include <fstream>

using namespace std;

Car::Car() : number(""), brand(""), payload(1), fuel(1), registration("") {}
//����������� �����������
Car::Car(const string& number, const string& brand, int payload, double fuel, const string& registration) : number(number), brand(brand), payload(payload), fuel(fuel), registration(registration) {}


//����������� ���������
Car::Car(const Car& other) : number(other.number), brand(other.brand), payload(other.payload), fuel(other.fuel), registration(other.registration) {}

//����������� ����������
Car::Car(Car&& other) noexcept : number(move(other.number)), brand(move(other.brand)), payload(move(other.payload)), fuel(move(other.fuel)), registration(move(other.registration)) {}
Car::~Car() {}

//�������� ��� ������������ ������� ����
void Car::operator()(const string& number, const string& brand, int payload, double fuel, const string& registration) {
	this->number = number;
	this->brand = brand;
	this->payload = payload;
	this->fuel = fuel;
	this->registration = registration;
}

//�������� ��������� ��� ���������
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

//�������� ����������
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

//��������� �������� ���������
ostream& operator<<(ostream& os, const Car& car) {
	os << car.number<< "\n"
		<< car.brand << "\n"
		<< car.payload << "\n"
		<< car.fuel<< "\n"
		<< car.registration << "\n";
	return os;
}



//��������� �������� ��������
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

//������������
void Car::setNumber(const string& number) { this->number = number; }
void Car::setBrand(const string& brand) { this->brand = brand; }
void Car::setPayload(int payload) { this->payload = payload; }
void Car::setFuel(double fuel) { this->fuel = fuel; }
void Car::setRegistration(const string& registration) { this->registration = registration; }


//���������
void Car::info() {
	cout << "�����: " << getNumber() << "\n�����: " << getBrand() << "\n����������������: " << getPayload() << "\n����� ������ ��������: " << getFuel() << "� \n̳��� ��������: " << getRegistration() << endl;
};