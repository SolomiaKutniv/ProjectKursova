#include "ReisIterator.h"
#include "Reis.h"
#include <iostream>
#include <vector>

using namespace std;

ReisIterator::ReisIterator() : reiss(nullptr), count(0), max_count(0) {}

ReisIterator::~ReisIterator() {
	delete[] reiss;
}

void ReisIterator::resize(size_t newMaxCount) {
	Reis* array = new Reis[newMaxCount];
	for (size_t i = 0;i < count;i++) {
		array[i] = reiss[i];
	}
	delete[] reiss;
	reiss = array;
	max_count = newMaxCount;
}

void ReisIterator::Add(const Reis& reis) {
	if (count >= max_count) {
		resize(max_count == 0 ? 1 : max_count * 2);
	}
	reiss[count++] = reis;
}

size_t ReisIterator::size() const {
	return count;
}

ReisIterator::Iterator::Iterator(Reis* reis):reis(reis) {}

Reis& ReisIterator::Iterator::operator*() const {
	return *reis;
}

Reis* ReisIterator::Iterator::operator ->() const {
	return reis;
}

ReisIterator::Iterator& ReisIterator::Iterator::operator++() {
	++reis;
	return *this;
}

bool ReisIterator::Iterator::operator!=(const Iterator& other) const {
	return reis != other.reis;
}

ReisIterator::Iterator ReisIterator::begin() const {
	return Iterator(reiss);
}

ReisIterator::Iterator ReisIterator::end() const {
	return Iterator(reiss+count);
}

Reis& ReisIterator::operator[](size_t index) {
	Iterator it = begin();
	for (size_t i = 0;i < index;++i) {
		++it;
	}
	return *it;
}



/*#include "Iterator.h"
#include "Reis.h"
#include <iostream>
#include <vector>

using namespace std;

Iterator::Iterator() : reiss(nullptr), count(0), max_count(0) {}

Iterator::~Iterator() {
	delete[] reiss;
}

void Iterator::resize(size_t newMaxCount) {
	Reis* Array = new Reis[newMaxCount];
	for (size_t i = 0;i < count;i++) {
		Array[i] = reiss[i];
	}
	delete[] reiss;
	reiss = Array;
	max_count = newMaxCount;
}

void Iterator::Add(const Reis& reis) {
	if (count >= max_count) {
		resize(max_count == 0 ? 1 : max_count * 2);
	}
	reiss[count++] = reis;
}

Reis* Iterator::begin() const {
	return reiss;
}

Reis* Iterator::end() const {
	return reiss + count;
}

size_t Iterator::size() const {
	return count;
}*/
