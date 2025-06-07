#pragma once
#include <string>
#include "Car.h"
#include "Driver.h"

using namespace std;

class Reis {
private:
	Car car;
	Driver driver;
	string date; //дата
	string item; //кінцевий пункт рейсу
	double mileage; //кілометраж
	double transported; //перевезено(тонн)
	double consumption; //розхід пального
	
public: 

	Reis();
	
	Reis(string& date, const string& item, double mileage, double transported, double consumption);

	Reis(const Reis& other);

	Reis(Reis&& other) noexcept;

	~Reis();

	void operator()(const Car& car, const Driver& driver, const string& date, const string& item, double mileage, double transported, double consumption);
	
	Reis& operator=(const Reis& other);

	Reis& operator=(Reis&& other) noexcept;

	void setCarObj(const Car& car);
	void setDriverObj(const Driver& driver);
	void setDate(const string& date);
	void setItem(const string& item);
	void setMileage(double mileage);
	void setTransported(double transported);
	void setConsumption(double consumption);
	
	const Car& getCarObj() const;
	const Driver& getDriverObj() const; 
	string getDate() const;
	string getItem() const;
	double getMileage() const;
	double getTransported() const;
	double getConsumption() const;


	friend istream& operator>>(istream& is, Reis& reis);
	friend ostream& operator<<(ostream& os, const Reis& reis);
	void driverInfo();
	void carInfo();
	void info();

};
