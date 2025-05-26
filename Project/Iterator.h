#pragma once
#include <iostream>
#include <vector>
#include <cstddef>
#include "Reis.h"

class Iterator
{
private:
	Reis* reiss;
	size_t count;
	size_t max_count; //Скільки пам'яті ми виділяємо на масив або скільки елементів може бути у масиві

	void resize(size_t newMaxCount);

public:

	Iterator();
	~Iterator();

	void Add(const Reis& reis);

	Reis* begin() const;
	Reis* end() const;
	size_t size() const;
};

