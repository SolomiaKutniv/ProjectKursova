#pragma once
#include <string>

using namespace std;

class Car {
private:
	string number; //��������� �����
	string brand; //�����
	int payload; //����������������
	double fuel; //����� ������ ��������
	string registration; //���� ��������
public:
	Car();

	Car(const string& number, const string& brand, int payload, double fuel, const string& registration); 

	Car(const Car& other);

	Car(Car&& other) noexcept;

	~Car();

	//�������� ��� ������������ ������� ����
	void operator()(const string& number, const string& brand, int payload, double fuel, const string& registration);

	//�������� ��������� ��� ���������
	Car& operator=(const Car& other);

	//�������� ����������
	Car& operator=(Car&& other) noexcept;

	//������������
	void setNumber(const string& number);
	void setBrand(const string& brand);
	void setPayload(int payload);
	void setFuel(double fuel);
	void setRegistration(const string& registration);

	//��������� �������� ���������
	friend ostream& operator<<(ostream& os, const Car& car);

	//��������� �������� ��������
	friend istream& operator>>(istream& is, Car& car);

	string getNumber() const;
	string getBrand() const;
	int getPayload() const;
	double getFuel() const;
	string getRegistration() const;


	//���������
	virtual void info();

};

