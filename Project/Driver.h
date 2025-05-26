#pragma once
#include <string>
using namespace std;

class Driver {
private:
	string surname; //�������
	string initials; //�������
	int persnum; //��������� �����
	int salary; //�����
public:
	Driver();

	Driver(const string& surname, const string& initials, int persnum, int salary);

	Driver(Driver&& other) noexcept;

	Driver(const Driver& other);

	~Driver();

	//�������� ��� ������������ ������� ����
	void operator()(const string& surname, const string& initials, int persnum, int salary);

	//�������� ��������� ��� ���������
	Driver& operator=(const Driver& other);

	//�������� ����������
	Driver& operator=(Driver&& other) noexcept;

	//��������� �������� ���������
	friend ostream& operator<<(ostream& os, const Driver& driver);

	//��������� �������� ��������
	friend istream& operator>>(istream& is, Driver& driver);

	//������������
	void setSurname(const string& surname);
	void setInitials(const string& initials);
	void setPersnum(int persnum);
	void setSalary(int salary);

	string getSurname() const;
	string getInitials() const;
	int getPersnum() const;
	int getSalary() const;

	//���������
	void info();
};
