#pragma once
#include <string>
#include <fstream>
#include "Car.h"

using namespace std;

class Bus : public Car {
private:
	int num_of_seats;

public:
	Bus();

	Bus(const string& number, const string& brand, int payload, double fuel, const string& registration, int num_of_seats);

	~Bus();
	
	void setNumOfSeats(int num_of_seats);

	int getNumOfSeats() const;

	void info() override;

	friend istream& operator>>(istream& is, Bus& bus);
};
