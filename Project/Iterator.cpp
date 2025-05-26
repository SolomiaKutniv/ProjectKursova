#include "Iterator.h"
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
}

