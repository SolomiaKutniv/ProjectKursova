#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Car.h"
#include "Bus.h"
#include "Driver.h"
#include "Reis.h"
#include "Timetable.h"



int main()
{
	setlocale(LC_ALL, "Ukrainian");
	ifstream infile("D:\\inform.txt");
	ofstream outfile("D:\\timet.txt");

	if (!infile.is_open() || !outfile.is_open()) {
		cout << "Не вдалося відкрити файл!";
	}

	Timetable timetable;
	Reis reis1, reis2;
	Car* carPtr;
	Bus bus1, bus2;
	//Car someCar = Car("some Numner", "some Brand", 123, 111, "Some registration");


	infile >> reis1 >> reis2 >> bus1 >> bus2;
	timetable.addReis(reis1);
	timetable.addReis(reis2);
	

	//cout << "\n---------------------------------------------------------------------------------------" << endl;
	//cout << "Інформація про місткість:" << endl;
	//carPtr = &bus1;
	//carPtr->info();
	//cout << "\n";
	//	carPtr = &bus2;
		//carPtr->info();
	//someCar.info();

	infile.close();

	cout << "Меню:\n"
		<< "1 - Вивести інформацію про рейси\n"
		<< "2 - Вивести інформацію про автомобіль\n"
		<< "3 - Вивести інформацію про водія \n"
		<< "4 - Вивести інформацію про загальногий об'єм перевезення \n"
		<< "5 - Вивести інформацію про загальний розхід пального\n"
		<< "6 - Вивести інформацію про місткість та марку автомобіля\n"
		<< "7 -  Записати інформацію у файл\n"
		<< "0 - для виходу\n" << endl;
	int n;
	bool running=true, subrunning=true;

	while (running)
	{
		cout << "Ваш вибір: ";
		cin >> n;
		switch (n) 
		{
		case 0: 
		{
			cout << "\n";
			return 0;
		}
		case 1: 
		{
			while (subrunning){
			cout << "Меню:\n"
				<< "1 - Вивести інформацію про всі рейси\n"
				<< "2 - Вивести інформацію про перший рейс\n"
				<< "3-Вивести інформацію про другий рейс\n" 
				<< "0-вихід"<<endl;
			cout << "Ваш вибір: ";
			cin >> n; 
				switch (n) {
				case 0: {
					subrunning = false;
					break;
				}
				case 1: {
					reis1.info();
					reis2.info();
					break;

				}
				case 2: {
					reis1.info();
					break;

				}
				case 3: {
					reis2.info();
					break;
				}
				}	
			}
			
			
		}
		case 2: 
		{
			while (subrunning) {
				cout << "Меню:\n"
					<< "1 - Вивести інформацію про автомобіль першого рейсу\n"
					<< "2-Вивести інформацію про автомобіль другого рейсу\n"
					<< "0-вихід" << endl;
				cout << "Ваш вибір: ";
				cin >> n;
				switch (n) {
				case 0: {
					subrunning = false;
					break;
				}
				case 1: {
					reis1.carInfo();
					break;

				}
				case 2: {
					reis2.carInfo();
					break;
				}
				}
			}
			break;
		}
		case 3: 
		{
			while (subrunning) {
				cout << "Меню:\n"
					<< "1 - Вивести інформацію про водія першого рейсу\n"
					<< "2-Вивести інформацію про волія другого рейсу\n"
					<< "0-вихід" << endl;
				cout << "Ваш вибір: ";
				cin >> n;
				switch (n) {
				case 0: {
					subrunning = false;
					break;
				}
				case 1: {
					reis1.driverInfo();
					break;

				}
				case 2: {
					reis2.driverInfo();
					break;
				}
				}
			}
			break;
		}
		case 4:
		{
			double totalConsumption = timetable.totalConsumption();
			cout << "Загальний об'єм перевезень: " << totalConsumption << endl;
			break;
		}
		case 5:
		{
			double totalTransported = timetable.totalTransported();
			cout << "Загальний розхід пального: " << totalTransported << endl;
			break;
		}
		case 6:
		{
			while (subrunning) {
				cout << "Оберіть рейс:\n"
					<< "1 - Перший рейс\n"
					<< "2-Другий рейс\n"
					<< "0-вихід" << endl;
				cout << "Ваш вибір: ";
				cin >> n;
				switch (n) {
				case 0: {
					subrunning = false;
					break;
				}
				case 1: {
					bus1.info();
					cout << "\n";
					break;

				}
				case 2: {
					bus2.info();
					cout << "\n";
					break;
				}
				}
			} 
			break;
		}
		case 7:
			outfile << reis1 << reis2;
			cout << "Інформацію записано у файл" << endl;
			outfile.close();
			break;
		}
	}

	return 0;
}










/*int main()
{
	setlocale(LC_ALL, "Ukrainian");
	ifstream infile("D:\\ffile.txt");
	ofstream oinfile("D:\\ffile.txt");
	ofstream outfile("D:\\timet.txt");

	if (!infile.is_open()|| !outfile.is_open()) {
		cout << "Не вдалося відкрити файл!";
	}
	int n=3;
	for (int i = 0;i < n;i++) {
		Reis reis;
		cin >> reis;
		oinfile << reis << endl;
	}
	oinfile.close();

	vector<Reis> reisi;
	Reis reis;
	while (infile >> reis) {
		reisi.push_back(reis);
	}
	infile.close();
	
	Timetable timetable;
	for (const Reis& r : reisi) {
		timetable.addReis(r);
	}


	double totalTransported = timetable.totalTransported();
	double totalConsumption = timetable.totalConsumption();
	cout << "Загальний об'єм перевезень:" << totalTransported;
	cout << "Загальний розхід пального:" << totalConsumption;

	outfile << totalTransported << endl;
	outfile << totalConsumption << endl;

	return 0;

}*/