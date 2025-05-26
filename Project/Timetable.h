#pragma once
#include <vector>
#include <string>
#include "Reis.h"
#include "Iterator.h"

using namespace std;
class Timetable
{
private:
	Iterator reiss; 
public:
	void addReis(const Reis& reis);

	//Підрахунок загального об'єму перевезення тон
	double totalTransported() const;

	//Загальний розхід пального
	double totalConsumption() const;

};

