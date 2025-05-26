#include <iostream>
#include <vector>
#include <string>
#include "Timetable.h"
#include "Reis.h"
#include "Iterator.h"

using namespace std;

void Timetable::addReis(const Reis& reis) {
	reiss.Add(reis);
}

//Підрахунок загального об'єму перевезення тон
double Timetable::totalTransported() const {
	double total1 = 0;
	for (auto it = reiss.begin();it != reiss.end();it++) {
		total1 += it->getTransported();
	}
	return total1;
}

//Загальний розхід пального
double Timetable::totalConsumption() const {
	double total2 = 0;
	for (auto it = reiss.begin();it != reiss.end();it++) {
		total2 += it->getConsumption();
	}
	return total2;
}

