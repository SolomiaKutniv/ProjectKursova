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

	//ϳ�������� ���������� ��'��� ����������� ���
	double totalTransported() const;

	//��������� ������ ��������
	double totalConsumption() const;

};

