#pragma once
#include <vector>
#include <string>
#include "Reis.h"
#include "ReisIterator.h"

using namespace std;
class Timetable
{
private:
	ReisIterator reiss;
public:
	void addReis(const Reis& reis);

	//Підрахунок загального об'єму перевезення тон
	double totalTransported() const;

	//Загальний розхід пального
	double totalConsumption() const;

	ReisIterator::Iterator begin() const;

	ReisIterator::Iterator end() const;

	size_t getCount() const;
	Reis& operator[](size_t index);
};



/*#pragma once
////#include <vector>
////#include <string>
////#include "Reis.h"
////#include "Iterator.h"
////
////using namespace std;
////class Timetable
////{
////private:
////	Iterator reiss; 
////public:
////	void addReis(const Reis& reis);
////
////	//Підрахунок загального об'єму перевезення тон
////	double totalTransported() const;
////
////	//Загальний розхід пального
////	double totalConsumption() const;
////
////	size_t getCount() const;
////	Reis& operator[](size_t index);
////};*/
