#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Car.h"
#include "Bus.h"
#include "Driver.h"
#include "Reis.h"
#include "Timetable.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	ifstream infile("D:\\information.txt");

	if (!infile.is_open()) {
		cout << "Не вдалося вiдкрити файл!";
	}

	Timetable timetable;
	Reis reis;
	while (infile >> reis) {
		timetable.addReis(reis);
	}

	infile.close();

	cout << "Меню:\n"
		<< "1 - Вивести iнформацiю про рейс\n"
		<< "2 - Вивести iнформацiю про автомобiль\n"
		<< "3 - Вивести iнформацiю про водiя \n"
		<< "4 - Вивести iнформацiю про загальний об'єм перевезення \n"
		<< "5 - Вивести iнформацiю про загальний розхiд пального\n"
		<< "6 - Вивести iнформацiю про мiсткiсть та марку автомобiля\n"
		<< "7 - Редагувати iнформацiю\n"
		<< "0 - для виходу\n" << endl;
	int n, index;
	bool running = true, subrunning = true;

	while (running)
	{
		cout << "Ваш вибiр: ";
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
			subrunning = true;
			while (subrunning) {
				cout << "Меню:\n"
					<< "1 - Вивести iнформацiю про всi рейси\n"
					<< "2 - Вивести iнформацiю про конкретний рейс\n"
					<< "0 - вихiд" << endl;
				cout << "Ваш вибiр: ";
				cin >> n;
				switch (n) {
				case 0: {
					subrunning = false;
					cout << "Меню:\n"
						<< "1 - Вивести iнформацiю про рейс\n"
						<< "2 - Вивести iнформацiю про автомобiль\n"
						<< "3 - Вивести iнформацiю про водiя \n"
						<< "4 - Вивести iнформацiю про загальний об'єм перевезення \n"
						<< "5 - Вивести iнформацiю про загальний розхiд пального\n"
						<< "6 - Вивести iнформацiю про мiсткiсть та марку автомобiля\n"
						<< "7 - Додати новий рейс\n"
						<< "0 - для виходу\n" << endl;
					break;
				}
				case 1: {
					for (int i = 0;i < timetable.getCount();i++) {
						cout << "Iнформацiя про " << i + 1 << " рейс:" << endl;
						timetable[i].info();
						cout << "\n";
					}
					break;

				}
				case 2: {
					cout << "Кiлькiсть рейсiв: " << timetable.getCount() << endl;
					do {
						cout << "Введiть номер рейсу: ";
						cin >> index;
						if (index < 1 || index > timetable.getCount()) {
							cout << "Неправильний номер рейсу!" << endl;
						}
					} while (index < 1 || index > timetable.getCount());
					timetable[index - 1].info();
					break;

				}
				}
			}
			break;

		}
		case 2:
		{
			subrunning = true;
			while (subrunning) {
				cout << "Меню:\n"
					<< "1 - Вивести iнформацiю про автомобiль усiх рейсiв\n"
					<< "2 - Вивести iнформацiю про автомобiль конкретного рейсу\n"
					<< "0 - вихiд" << endl;
				cout << "Ваш вибiр: ";
				cin >> n;
				switch (n) {
				case 0: {
					subrunning = false;
					cout << "Меню:\n"
						<< "1 - Вивести iнформацiю про рейс\n"
						<< "2 - Вивести iнформацiю про автомобiль\n"
						<< "3 - Вивести iнформацiю про водiя \n"
						<< "4 - Вивести iнформацiю про загальний об'єм перевезення \n"
						<< "5 - Вивести iнформацiю про загальний розхiд пального\n"
						<< "6 - Вивести iнформацiю про мiсткiсть та марку автомобiля\n"
						<< "7 - Додати новий рейс\n"
						<< "0 - для виходу\n" << endl;
					break;
				}
				case 1: {
					for (int i = 0;i < timetable.getCount();i++) {
						cout << "Iнформацiя про автомобiль " << i + 1 << " рейсу:" << endl;
						timetable[i].carInfo();
						cout << "\n";
					}
					break;
				}
				case 2: {
					cout << "Кiлькiсть рейсiв: " << timetable.getCount() << endl;
					do {
						cout << "Введiть номер рейсу: ";
						cin >> index;
						if (index < 1 || index > timetable.getCount()) {
							cout << "Неправильний номер рейсу!" << endl;
						}
					} while (index < 1 || index > timetable.getCount());
					timetable[index - 1].carInfo();
					break;
				}
				}
			}
			break;
		}
		case 3:
		{
			subrunning = true;
			while (subrunning) {
				cout << "Меню:\n"
					<< "1 - Вивести iнформацiю про водiя кожного рейсу\n"
					<< "2-Вивести iнформацiю про водiя конкретного рейсу\n"
					<< "0-вихiд" << endl;
				cout << "Ваш вибiр: ";
				cin >> n;
				switch (n) {
				case 0: {
					subrunning = false;
					cout << "Меню:\n"
						<< "1 - Вивести iнформацiю про рейс\n"
						<< "2 - Вивести iнформацiю про автомобiль\n"
						<< "3 - Вивести iнформацiю про водiя \n"
						<< "4 - Вивести iнформацiю про загальний об'єм перевезення \n"
						<< "5 - Вивести iнформацiю про загальний розхiд пального\n"
						<< "6 - Вивести iнформацiю про мiсткiсть та марку автомобiля\n"
						<< "7 - Додати новий рейс\n"
						<< "0 - для виходу\n" << endl;
					break;
				}
				case 1: {
					for (int i = 0;i < timetable.getCount();i++) {
						cout << "Iнформацiя про водiя " << i + 1 << " рейсу:" << endl;
						timetable[i].driverInfo();
						cout << "\n";
					}
					break;

				}
				case 2: {
					cout << "Кiлькiсть рейсiв: " << timetable.getCount() << endl;
					do {
						cout << "Введiть номер рейсу: ";
						cin >> index;
						if (index < 1 || index > timetable.getCount()) {
							cout << "Неправильний номер рейсу!" << endl;
						}
					} while (index < 1 || index > timetable.getCount());
					timetable[index - 1].driverInfo();
					break;
				}
				}
			}
			break;
		}
		case 4:
		{
			double totalTransported = timetable.totalTransported();
			cout << "Загальний об'єм перевезень: " << totalTransported << endl;
			cout << "Меню:\n"
				<< "1 - Вивести iнформацiю про рейс\n"
				<< "2 - Вивести iнформацiю про автомобiль\n"
				<< "3 - Вивести iнформацiю про водiя \n"
				<< "4 - Вивести iнформацiю про загальний об'єм перевезення \n"
				<< "5 - Вивести iнформацiю про загальний розхiд пального\n"
				<< "6 - Вивести iнформацiю про мiсткiсть та марку автомобiля\n"
				<< "7 - Додати новий рейс\n"
				<< "0 - для виходу\n" << endl;
			break;
		}
		case 5:
		{
			double totalConsumption = timetable.totalConsumption();
			cout << "Загальний розхiд пального: " << totalConsumption << endl;
			cout << "Меню:\n"
				<< "1 - Вивести iнформацiю про рейс\n"
				<< "2 - Вивести iнформацiю про автомобiль\n"
				<< "3 - Вивести iнформацiю про водiя \n"
				<< "4 - Вивести iнформацiю про загальний об'єм перевезення \n"
				<< "5 - Вивести iнформацiю про загальний розхiд пального\n"
				<< "6 - Вивести iнформацiю про мiсткiсть та марку автомобiля\n"
				<< "7 - Додати новий рейс\n"
				<< "0 - для виходу\n" << endl;
			break;
		}
		case 6:
		{
			subrunning = true;
			while (subrunning) {
				cout << "Оберiть рейс:\n"
					<< "1 - Перший рейс\n"
					<< "2 - Другий рейс\n"
					<< "0 - вихiд" << endl;
				cout << "Ваш вибiр: ";
				cin >> n;
				switch (n) {
				case 0: {
					subrunning = false;
					cout << "Меню:\n"
						<< "1 - Вивести iнформацiю про рейс\n"
						<< "2 - Вивести iнформацiю про автомобiль\n"
						<< "3 - Вивести iнформацiю про водiя \n"
						<< "4 - Вивести iнформацiю про загальний об'єм перевезення \n"
						<< "5 - Вивести iнформацiю про загальний розхiд пального\n"
						<< "6 - Вивести iнформацiю про мiсткiсть та марку автомобiля\n"
						<< "7 - Додати новий рейс\n"
						<< "0 - для виходу\n" << endl;
					break;
				}
				case 1: {
					Car* busObject = new Bus("BC4883", "BMW", 20, 30, "Львiв", 2);
			        Car* carObject = new Car("BC4883", "BMW", 20, 30, "Львiв");

			        Car** busPointerArray = new Car*[2];
			        busPointerArray[0] = busObject;
			        busPointerArray[1] = carObject;

			        cout << "Bus information \n";
			        busPointerArray[0]->info();
			        cout << "\nCar information \n";
			        busPointerArray[1]->info();
					cout << "\n";
					break;

				}
				case 2: {
					Car* busObject = new Bus("AA4733", "Scania", 42, 38, "Київ", 3);
			        Car* carObject = new Car("AA4733", "Scania", 42, 38, "Київ");

			        Car** busPointerArray = new Car*[2];
			        busPointerArray[0] = busObject;
			        busPointerArray[1] = carObject;

			        cout << "Bus information \n";
			        busPointerArray[0]->info();
			        cout << "\nCar information \n";
			        busPointerArray[1]->info();
					cout << "\n";
					break;
				}
				}
			}
			break;
			
		}
		case 7: 
		{
			cout << "Введiть новий рейс: " << endl;
			Reis newReis;
			cin >> newReis;
			timetable.addReis(newReis);
			ofstream outfile("D:\\information.txt", ios::app);

			if (!outfile.is_open()) {
				cout << "Не вдалося вiдкрити файл!";
			}
			outfile << newReis << "\n";
			cout << "Iнформацiю записано у файл" << endl;
			outfile.close();
			cout << "Меню:\n"
				<< "1 - Вивести iнформацiю про рейс\n"
				<< "2 - Вивести iнформацiю про автомобiль\n"
				<< "3 - Вивести iнформацiю про водiя \n"
				<< "4 - Вивести iнформацiю про загальний об'єм перевезення \n"
				<< "5 - Вивести iнформацiю про загальний розхiд пального\n"
				<< "6 - Вивести iнформацiю про мiсткiсть та марку автомобiля\n"
				<< "7 - Додати новий рейс\n"
				<< "0 - для виходу\n" << endl;
			break;
		}
		}
	}

	return 0;
}



/*#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Car.h"
#include "Bus.h"
#include "Driver.h"
#include "Reis.h"
#include "Timetable.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	ifstream infile("D:\\information.txt");

	if (!infile.is_open()) {
		cout << "Не вдалося відкрити файл!";
	}

	Timetable timetable;
	Reis reis1, reis2;
	infile >> reis1 >> reis2;
	timetable.addReis(reis1);
	timetable.addReis(reis2);


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
	bool running = true, subrunning = true;

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
			subrunning = true;
			while (subrunning) {
				cout << "Меню:\n"
					<< "1 - Вивести інформацію про всі рейси\n"
					<< "2 - Вивести інформацію про перший рейс\n"
					<< "3-Вивести інформацію про другий рейс\n"
					<< "0-вихід" << endl;
				cout << "Ваш вибір: ";
				cin >> n;
				switch (n) {
				case 0: {
					subrunning = false;
					cout << "Меню:\n"
						<< "1 - Вивести інформацію про рейси\n"
						<< "2 - Вивести інформацію про автомобіль\n"
						<< "3 - Вивести інформацію про водія \n"
						<< "4 - Вивести інформацію про загальногий об'єм перевезення \n"
						<< "5 - Вивести інформацію про загальний розхід пального\n"
						<< "6 - Вивести інформацію про місткість та марку автомобіля\n"
						<< "7 -  Записати інформацію у файл\n"
						<< "0 - для виходу\n" << endl;
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
			break;

		}
		case 2:
		{
			subrunning = true;
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
					cout << "Меню:\n"
						<< "1 - Вивести інформацію про рейси\n"
						<< "2 - Вивести інформацію про автомобіль\n"
						<< "3 - Вивести інформацію про водія \n"
						<< "4 - Вивести інформацію про загальногий об'єм перевезення \n"
						<< "5 - Вивести інформацію про загальний розхід пального\n"
						<< "6 - Вивести інформацію про місткість та марку автомобіля\n"
						<< "7 -  Записати інформацію у файл\n"
						<< "0 - для виходу\n" << endl;
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
			subrunning = true;
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
					cout << "Меню:\n"
						<< "1 - Вивести інформацію про рейси\n"
						<< "2 - Вивести інформацію про автомобіль\n"
						<< "3 - Вивести інформацію про водія \n"
						<< "4 - Вивести інформацію про загальногий об'єм перевезення \n"
						<< "5 - Вивести інформацію про загальний розхід пального\n"
						<< "6 - Вивести інформацію про місткість та марку автомобіля\n"
						<< "7 -  Записати інформацію у файл\n"
						<< "0 - для виходу\n" << endl;
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
			double totalTransported = timetable.totalTransported();
			cout << "Загальний об'єм перевезень: " << totalTransported << endl;
			break;
		}
		case 5:
		{
			double totalConsumption = timetable.totalConsumption();
			cout << "Загальний розхід пального: " << totalConsumption << endl;
			break;
		}
		case 6:
		{
			subrunning = true;
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
					cout << "Меню:\n"
						<< "1 - Вивести інформацію про рейси\n"
						<< "2 - Вивести інформацію про автомобіль\n"
						<< "3 - Вивести інформацію про водія \n"
						<< "4 - Вивести інформацію про загальногий об'єм перевезення \n"
						<< "5 - Вивести інформацію про загальний розхід пального\n"
						<< "6 - Вивести інформацію про місткість та марку автомобіля\n"
						<< "7 -  Записати інформацію у файл\n"
						<< "0 - для виходу\n" << endl;
					break;
				}
				case 1: {
					Car* busObject = new Bus("BC4883", "BMW", 20, 30, "Львів", 2);
			        Car* carObject = new Car("BC4883", "BMW", 20, 30, "Львів");

			        Car** busPointerArray = new Car*[2];
			        busPointerArray[0] = busObject;
			        busPointerArray[1] = carObject;

			        cout << "Bus information \n";
			        busPointerArray[0]->info();
			        cout << "\nCar information \n";
			        busPointerArray[1]->info();
					cout << "\n";
					break;

				}
				case 2: {
					Car* busObject = new Bus("AA4733", "Scania", 42, 38, "Київ", 3);
			        Car* carObject = new Car("AA4733", "Scania", 42, 38, "Київ");

			        Car** busPointerArray = new Car*[2];
			        busPointerArray[0] = busObject;
			        busPointerArray[1] = carObject;

			        cout << "Bus information \n";
			        busPointerArray[0]->info();
			        cout << "\nCar information \n";
			        busPointerArray[1]->info();
					cout << "\n";
					break;
				}
				}
			}
			break;
			
		}
		case 7:
			ofstream outfile("D:\\information.txt");

			if (!outfile.is_open()) {
				cout << "Не вдалося відкрити файл!";
			}
			outfile << reis1 << reis2;
			cout << "Інформацію записано у файл" << endl;
			outfile.close();
			cout << "Меню:\n"
				<< "1 - Вивести інформацію про рейси\n"
				<< "2 - Вивести інформацію про автомобіль\n"
				<< "3 - Вивести інформацію про водія \n"
				<< "4 - Вивести інформацію про загальногий об'єм перевезення \n"
				<< "5 - Вивести інформацію про загальний розхід пального\n"
				<< "6 - Вивести інформацію про місткість та марку автомобіля\n"
				<< "7 -  Записати інформацію у файл\n"
				<< "0 - для виходу\n" << endl;
			break;
		}
	}

	return 0;
}*/

/*Car* busObject = new Bus();
			Car* carObject = new Car();

			Car** busPointerArray = new Car*[2];
			busPointerArray[0] = busObject;
			busPointerArray[1] = carObject;

			cout << "Bus information \n";
			busPointerArray[0]->info();
			cout << "\nCar information \n";
			busPointerArray[1]->info();
			*/



/*//ifstream infile("D:\\inform2.txt");
	//ofstream outfile("D:\\inform2.txt");

	if (!infile.is_open() || !outfile.is_open()) {
		cout << "Не вдалося відкрити файл!";
	}
	

Timetable timetable;
Reis reis1, reis2;
//Car* carPtr;
Bus bus1, bus2;
//Car someCar = Car("some Numner", "some Brand", 123, 111, "Some registration");


//infile >> reis1 >> reis2 >> bus1 >> bus2;
infile >> reis1 >> reis2;
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




*/




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