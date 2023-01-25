#include "Marka.h"
#include <string.h>
#include <iostream>
using namespace std;

Marka::Marka() {
	strcpy_s(this->naziv, "Avto");
	strcpy_s(this->zemljaPorijekla, "Nigdjezemska");
}
void Marka::setNaziv() {
	cout << "Unesite naziv auta: ";
	cin.getline(this->naziv, 30);
}
void Marka::setZemlljaPorijekla() {
	cout << "Unesite zemlju porijekla: ";
	cin.getline(this->zemljaPorijekla, 40);
}
char* Marka::getNaziv() {
	return this->naziv;
}
char* Marka::getZemljaPorijekla() {
	return this->zemljaPorijekla;
}