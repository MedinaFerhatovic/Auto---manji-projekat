#include "Auto.h"
#include <iostream>
#include <string.h>
using namespace std;

Auto::Auto() {
	strcpy_s(this->tip, "Golf 2");
	strcpy_s(this->gorivo, "Dizel");
	this->godinaProizvodnje = 1985;
	this->brojBrzina = 5;
}

void Auto::setMarka() {
	this->marka.setNaziv();
	this->marka.setZemlljaPorijekla();
}
void Auto::setTip() {
	cout << "Unesite tip auta: ";
	cin.getline(this->tip, 30);
}
void Auto::setGorivo() {
	cout << "Unesite vrstu goriva: ";
	cin.getline(this->gorivo, 10);
}
void Auto::setGodinaProizvodnje() {
	cout << "Unesite godinu proizvodnje: ";
	cin >> this->godinaProizvodnje;
	cin.ignore();
}
void Auto::setBrojBrzina() {
	cout << "Unesite broj brzina: ";
	cin >> this->brojBrzina;
	cin.ignore();
}
Marka Auto::getMarka() {
	return this->marka;
}
char* Auto::getTip() {
	return this->tip;
}
char* Auto::getGorivo() {
	return this->gorivo;
}
int Auto::getGodinaProizvodnje() {
	return this->godinaProizvodnje;
}
int Auto::getBrojBrzina() {
	return this->brojBrzina;
}
void Auto::postaviAuto() {
	cout << "\t***** Unos auta *****\n";
	this->setMarka();
	this->setTip();
	this->setGorivo();
	this->setGodinaProizvodnje();
	this->setBrojBrzina();
}
void Auto::ispisAuta() {
	cout << "Auto: " << this->marka.getNaziv() << " - " << this->getTip()
		<< " iz " << this->marka.getZemljaPorijekla() << " sa "
		<< this->getBrojBrzina() << " brzina.\n";
	cout << "Proizvedeno: " << this->getGodinaProizvodnje() << " godine i trosi "
		<< this->getGorivo() << " gorivo.\n";
}