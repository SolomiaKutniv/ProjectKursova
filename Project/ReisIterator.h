#pragma once
#include <iostream>
#include <vector>
#include <cstddef>
#include "Reis.h"

class ReisIterator
{
private:
	Reis* reiss;
	size_t count;
	size_t max_count; //������ ���'�� �� �������� �� ����� ��� ������ �������� ���� ���� � �����

	void resize(size_t newMaxCount);

public:

	ReisIterator();
	~ReisIterator();

	void Add(const Reis& reis);
	size_t size() const;

	class Iterator {
	private:
		Reis* reis;
	public:
		Iterator(Reis* reis);

		Reis& operator*() const;
		Reis* operator ->() const;
		Iterator& operator++();
		bool operator!=(const Iterator& other) const;
	};

	Iterator begin() const;
	Iterator end() const;
	Reis& operator[](size_t index);
};

//1) ������ ������� - ��������� ����� 2) ���� �������� �� ��������� ��������� �� ������� �� ����� �� ��������� ����� 3) ���� ������ ���������� ������(�������)

/*#include <cstddef>
#include "Reis.h"

class Iterator
{
private:
	Reis* reiss;
	size_t count;
	size_t max_count; //������ ���'�� �� �������� �� ����� ��� ������ �������� ���� ���� � �����

	void resize(size_t newMaxCount);

public:

	Iterator();
	~Iterator();

	void Add(const Reis& reis);

	Reis* begin() const;
	Reis* end() const;
	size_t size() const;
};*/