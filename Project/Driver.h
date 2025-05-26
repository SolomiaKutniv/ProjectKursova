#pragma once
#include <string>
using namespace std;

class Driver {
private:
	string surname; //прізвище
	string initials; //ініціали
	int persnum; //табельний номер
	int salary; //оклад
public:
	Driver();

	Driver(const string& surname, const string& initials, int persnum, int salary);

	Driver(Driver&& other) noexcept;

	Driver(const Driver& other);

	~Driver();

	//Оператор для встановлення значень полів
	void operator()(const string& surname, const string& initials, int persnum, int salary);

	//Оператор присвоєння для копіювання
	Driver& operator=(const Driver& other);

	//Оператор переміщення
	Driver& operator=(Driver&& other) noexcept;

	//Потоковий оператор виведення
	friend ostream& operator<<(ostream& os, const Driver& driver);

	//Потоковий оператор введення
	friend istream& operator>>(istream& is, Driver& driver);

	//Встановлення
	void setSurname(const string& surname);
	void setInitials(const string& initials);
	void setPersnum(int persnum);
	void setSalary(int salary);

	string getSurname() const;
	string getInitials() const;
	int getPersnum() const;
	int getSalary() const;

	//Виведення
	void info();
};
