#include <iostream>
#include <string>
#include "Reis.h"

using namespace std;

Reis::Reis() : car(), driver(), date(""), item(""), mileage(0), transported(0), consumption(0) {}

//����������� �����������
Reis::Reis(string& date, const string& item, double mileage, double transported, double consumption) : car(), driver(), date(date), item(item),mileage(mileage),transported(transported), consumption(consumption) {}

Reis::Reis(const Reis& other) :car(other.car), driver(other.driver), date(other.date), item(other.item), mileage(other.mileage), transported(other.transported), consumption(other.consumption) {}
//����������� ����������
Reis::Reis(Reis&& other) noexcept :car(move(other.car)), driver(move(other.driver)), date(move(other.date)), item(move(other.item)), mileage(move(other.mileage)), transported(move(other.transported)), consumption(move(other.consumption)) {}

Reis::~Reis() {};

void Reis::operator()(const Car& car, const Driver& driver, const string& date, const string& item, double mileage, double transported, double consumption) {
	this->car = car;
	this->driver = driver;
	this->date = date;
	this->item = item;
	this->mileage = mileage;
	this->transported = transported;
	this->consumption = consumption;
}

Reis& Reis::operator=(const Reis& other) {
	if (this != &other) {
		car = other.car;
		driver = other.driver;
		date = other.date;
		item = other.item;
		mileage = other.mileage;
		transported = other.transported;
		consumption = other.consumption;
	}
	return *this;
}

Reis& Reis::operator=(Reis&& other) noexcept {
	if (this != &other) {
		car = move(other.car);
		driver = move(other.driver);
		date = move(other.date);
		item = move(other.item);
		mileage = move(other.mileage);
		transported = move(other.transported);
		consumption = move(other.consumption);
	}
	return *this;
}

void Reis::setCarObj(const Car& car) { this->car=car; }
void Reis::setDriverObj(const Driver& driver) { this->driver=driver; }
void Reis::setDate(const string& date) { this->date=date; }
void Reis::setItem(const string& item) { this->item = item; }
void Reis::setMileage(double mileage) { this->mileage = mileage; }
void Reis::setTransported(double transported) { this->transported = transported; }
void Reis::setConsumption(double consumption) { this->consumption; }

const Car& Reis::getCarObj() const { return car; }
const Driver& Reis::getDriverObj() const { return driver; }
string Reis::getDate() const { return date; }
string Reis::getItem() const { return item; }
double Reis::getMileage() const { return mileage; }
double Reis::getTransported() const { return transported; }
double Reis::getConsumption() const { return consumption; }

void Reis::driverInfo() {
	driver.info();
}

void::Reis::carInfo() {
	car.info();
}
void Reis::info() {
	cout << "���������� ��� ���������:" << endl;
	car.info();
	cout << "���������� ��� ����: " << endl;
	driver.info();
	cout << "���������� ��� ����: " << endl;
	cout << "���� �����: " << getDate() << "\nʳ������ ����� �����������: " << getItem() << "\nʳ��������: " << getMileage() << "�� \n����������: " << getTransported() << "���� \n������ ��������: " << getConsumption() << "�" << endl;
};

istream& operator>>(istream& is, Reis& reis) {
	is >> reis.car;
	is >> reis.driver;
	is >> reis.date;
	is.ignore();
	is >> reis.item;
	is >> reis.mileage;
	is >> reis.transported;
	is >> reis.consumption;
	is.ignore();
	return is;
}

ostream& operator<<(ostream& os, const Reis& reis) {
	os << reis.car << "\n"
		<< reis.driver << "\n"
		<< reis.date << "\n"
		<< reis.item << "\n"
		<< reis.mileage << "\n"
		<< reis.transported << "\n"
		<< reis.consumption;
	return os;
}