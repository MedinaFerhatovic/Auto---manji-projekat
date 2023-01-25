// Auto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Auto.h"
#include "Datum.h"
#include "MojeAuto.h"

int meni() {
	int izbor;
	cout << "\t------------MENI------------\n";
	cout << "1. Postavi auto\n";
	cout << "2. Ispisi auto (1. nacin)\n";
	cout << "3. Unesi auto\n";
	cout << "4. Ispisi auto (2. nacin)\n";
	cout << "5. Promijeni stanje auta\n";
	do {
		cout << "\n\tUnesite izbor: ";
		cin >> izbor;
	} while (izbor < 1 || izbor > 5);
	system("cls");
	cin.ignore();
	return izbor;
}

int main()
{
	Auto avto;
	MojeAuto automobil;
	int izbor;
	do {
		system("cls");
		izbor = meni();
		switch (izbor) {
		case 1:
			avto.postaviAuto();
			system("pause");
			break;
		case 2:
			avto.ispisAuta();
			system("pause");
			break;
		case 3:
			automobil.unosMogAuta();
			system("pause");
			break;
		case 4:
			automobil.ispisMogAuta();
			system("pause");
			break;
		case 5:
			automobil.promijeniStanje();
			system("pause");
			break;
		default:
			break;
		}
	} while (izbor != 5);
	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
