#include "Datum.h"
#include <iostream>
#include <iomanip>
using namespace std;

Datum::Datum() {
	this->dan = 1;
	this->mjesec = 1;
	this->godina = 1900;
}
void Datum::setDan() {
	switch (this->mjesec)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		do {
			cout << "Unesite dan: ";
			cin >> this->dan;
			if (this->dan < 1) {
				cout << "GRESKA! Dan mora biti pozitivan broj!\n";
			}
			else if (this->dan > 31) {
				cout << "GRESKA!" << this->mjesec << " ima samo 31 dan.\n";
			}
		} while (this->dan<1 || this->dan > 31);
		break;
	case 4: case 6: case 9: case 11:
		do {
			cout << "Unesite dan: ";
			cin >> this->dan;
			if (this->dan < 1) {
				cout << "GRESKA! Dan mora biti pozitivan broj!\n";
			}
			else if (this->dan > 30) {
				cout << "GRESKA!" << this->mjesec << " ima samo 30 dana.\n";
			}
		} while (this->dan < 1 || this->dan>31);
		break;
	case 2:
		if (this->godina % 4 == 0) {
			do {
				cout << "Unesite dan: ";
				cin >> this->dan;
				if (this->dan < 1) {
					cout << "GRESKA! Dan mora biti pozitivan broj!\n";
				}
				else if (this->dan > 29) {
					cout << "GRESKA!" << this->mjesec << "ima samo 29 dana.\n";
				}
			} while (this->dan < 1 || this->dan>29);
		}
		else {
			do {
				cout << "Unesite dan: ";
				cin >> this->dan;
				if (this->dan < 1) {
					cout << "GRESKA! Dan mora biti pozitivan broj!\n";
				}
				else if (this->dan > 28) {
					cout << "GRESKA!" << this->mjesec << " ima samo 28 dana.\n";
				}
			} while (this->dan < 1 || this->dan>28);
		}
		break;
	default:
		break;
	}
	cin.ignore();
}
void Datum::setMjesec() {
	do {
		cout << "Unesite mjesec: ";
		cin >> this->mjesec;
		if (this->mjesec < 1 || this->mjesec>12) {
			cout << "GRESKA! Pogresno unesen redni broj mjeseca!\n";
		}
	} while (this->mjesec < 1 || this->mjesec>12);
	cin.ignore();
}
void Datum::setGodina() {
	do {
		cout << "Unesite godinu: ";
		cin >> this->godina;
		if (this->godina < 1900) {
			cout << "GRESKA! Pogresno unesena godina!\n";
		}
	} while (this->godina < 1900);
	cin.ignore();
}
int Datum::getDan() {
	return this->dan;
}
int Datum::getMjesec() {
	return this->mjesec;
}
int Datum::getGodina() {
	return this->godina;
}
void Datum::postaviDatum() {
	cout << "\t***** Unos datuma *****\n";
	this->setDan();
	this->setMjesec();
	this->setGodina();
}
void Datum::ispisiDatum() {
	cout << setw(2) << setfill('0') << this->getDan() << "."
		<< setw(2) << setfill('0') << this->getMjesec() << "."
		<< setw(4) << this->getGodina() << ".\n";
}
string Datum::getDatum() {
	string stringDan, stringMjesec;
	if (this->dan < 10) {
		stringDan = "0" + to_string(this->dan);
	}
	else {
		stringDan = to_string(this->dan);
	}
	if (this->mjesec < 10) {
		stringMjesec = "0" + to_string(this->mjesec);
	}
	else {
		stringMjesec = to_string(this->mjesec);
	}
	string rez = stringDan + "." + stringMjesec + "." + to_string(this->godina) + ". - " + this->nazivDana();
	return rez;
}
string Datum::nazivDana() {
	int m = this->mjesec;
	if (m == 1) {
		m = 11;
	}
	else if (m == 2) {
		m = 12;
	}
	else {
		m -= 2;
	}
	int d = this->dan;
	int g = this->godina;
	int D = g % 100;
	int C = g / 100;
	int f = d + (13 * m - 1) / 5 + D + D / 4 + C / 4 - 2 * C;
	if (f < 0) {
		int temp = f;
		do {
			if (abs(temp) % 7 != 0) temp--;
		} while (abs(temp) % 7 != 0);
		f = abs(temp) - abs(f);
	}
	else {
		f %= 7;
	}
	switch (f)
	{
	case 0:
		return "Nedjelja";
		break;
	case 1:
		return "Ponedjeljak";
		break;
	case 2:
		return "Utorak";
		break;
	case 3:
		return "Srijeda";
		break;
	case 4:
		return "Cetvrtak";
		break;
	case 5:
		return "Petak";
		break;
	case 6:
		return "Subota";
		break;
	default:
		return "Ponedjeljak";
	}
}