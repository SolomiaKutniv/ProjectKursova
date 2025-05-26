#include <iostream>
#include <string>
#include "Car.h"
#include "Bus.h"


using namespace std;

Bus::Bus(): Car(), num_of_seats(1) {}

Bus::Bus(const string& number, const string& brand, int payload, double fuel, const string& registration, int num_of_seats) : Car(number, brand, payload, fuel, registration), num_of_seats(num_of_seats) {}

Bus::~Bus() {}

void Bus::setNumOfSeats(int num_of_seats) { this->num_of_seats = num_of_seats; }

int Bus::getNumOfSeats() const { return num_of_seats; }

void Bus::info() {
	cout << "Марка авто: " << getBrand() << endl;
	cout << "Кількість місць: " << getNumOfSeats();
}

istream& operator>> (istream& is, Bus& bus) {
	is >> static_cast<Car&>(bus);
	is >> bus.num_of_seats;
	return is;
}