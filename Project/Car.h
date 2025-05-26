#pragma once
#include <string>

using namespace std;

class Car {
private:
	string number; //державний номер
	string brand; //марка
	int payload; //вантажопідйомність
	double fuel; //норма витрат пального
	string registration; //місце прописки
public:
	Car();

	Car(const string& number, const string& brand, int payload, double fuel, const string& registration); 

	Car(const Car& other);

	Car(Car&& other) noexcept;

	~Car();

	//Оператор для встановлення значень полів
	void operator()(const string& number, const string& brand, int payload, double fuel, const string& registration);

	//Оператор присвоєння для копіювання
	Car& operator=(const Car& other);

	//Оператор переміщення
	Car& operator=(Car&& other) noexcept;

	//Встановлення
	void setNumber(const string& number);
	void setBrand(const string& brand);
	void setPayload(int payload);
	void setFuel(double fuel);
	void setRegistration(const string& registration);

	//Потоковий оператор виведення
	friend ostream& operator<<(ostream& os, const Car& car);

	//Потоковий оператор введення
	friend istream& operator>>(istream& is, Car& car);

	string getNumber() const;
	string getBrand() const;
	int getPayload() const;
	double getFuel() const;
	string getRegistration() const;


	//Виведення
	virtual void info();

};

