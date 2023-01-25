#include "MojeAuto.h"
#include <iostream>

MojeAuto::MojeAuto() {
	strcpy_s(this->registracija, "000-0-000");
	this->brzina = ler;
	this->stanje = ugasen;
}
void MojeAuto::setMojeAuto() {
	this->mojeAuto.postaviAuto();
}
void MojeAuto::setDatumRegistracije() {
	cout << "Unesite datum registracije: \n";
	this->DatumRegistracije.postaviDatum();
	cin.ignore();
}
void MojeAuto::setRegistracija() {
	cout << "Unesite registraciju auta: ";
	cin.getline(this->registracija, 20);
	cin.ignore();
}
Auto MojeAuto::getMojeAuto() {
	return this->mojeAuto;
}
Datum MojeAuto::getDatumRegistracije() {
	return this->DatumRegistracije;
}
char* MojeAuto::getRegistracija() {
	return this->registracija;
}
Brzina MojeAuto::getBrzina() {
	return this->brzina;
}
Stanje MojeAuto::getStanje() {
	return this->stanje;
}
void MojeAuto::unosMogAuta() {
	this->setMojeAuto();
	this->setDatumRegistracije();
	this->setRegistracija();
}
void MojeAuto::ispisMogAuta() {
	cout << "Auto: " << this->getMojeAuto().getMarka().getNaziv() << " - " << this->getMojeAuto().getTip()
		<< " proizvedeno u " << this->getMojeAuto().getMarka().getZemljaPorijekla() << " - " << this->getMojeAuto().getGodinaProizvodnje() << " godine.\n";
	cout << "Stanje: ";
	if (stanje == ugasen) {
		cout << "Ugasen.\n";
	}
	else {
		cout << "Upaljen.\n";
	}
	cout << "Brzina: ";
	this->trenutnaBrzina();
	cout << endl;
}
void MojeAuto::trenutnaBrzina() {
	switch (this->brzina)
	{
	case rikverc:
		cout << "Rikverc.";
		break;
	case ler:
		cout << "Ler";
		break;
	case prva:
		cout << "Prva.";
		break;
	case druga:
		cout << "Druga.";
		break;
	case treca:
		cout << "Treca.";
		break;
	case cetvrta:
		cout << "Cetvrta.";
		break;
	case peta:
		cout << "Peta.";
		break;
	case sesta:
		cout << "Sesta.";
		break;
	default:
		cout << "Pogresna brzina.";
	}
}
void MojeAuto::prebaciRikverc() {
	this->brzina = rikverc;
}
void MojeAuto::prebaciPrvaBrzina() {
	this->brzina = prva;
}
void MojeAuto::prebaciVecuBrzinu() {
	if (this->brzina < this->getMojeAuto().getBrojBrzina()) {
		this->brzina = Brzina(int(this->brzina) + 1);
		cout << "Brzina: ";
		this->trenutnaBrzina();
		cout << "\n";
	}
	else {
		cout << "Auto je u najvecoj brzini!\n";
	}
}
void MojeAuto::prebaciManjuBrzinu() {
	if (this->brzina > rikverc) {
		this->brzina = Brzina(int(this->brzina) - 1);
		cout << "Brzina: ";
		this->trenutnaBrzina();
		cout << "\n";
	}
	else {
		cout << "Auto je u rikvercu!\n";
	}
}
void MojeAuto::promijeniStanje() {
	if (this->stanje == ugasen) {
		this->stanje = upaljen;
		this->prebaciPrvaBrzina();
		system("cls");
		cout << "Auto pokrenuto!\n";
		this->trenutnaBrzina();
		cout << "\n";
		int odabir = 1;
		do {
			do {
				cout << "\t1. Povecaj brzinu \n\t2. Smanji brzinu \n\t3. Ugasi auto \nOdabir: ";
				cin >> odabir;
			} while (odabir < 1 || odabir>3);
			if (odabir == 1) {
				this->prebaciVecuBrzinu();
			}
			else if (odabir == 2) {
				this->prebaciManjuBrzinu();
			}
			else if (odabir == 3) {
				this->promijeniStanje();
			}
		} while (this->stanje==upaljen);
	}
	else {
		this->stanje = ugasen;
		this->brzina = ler;
		cout << "Auto ugaseno!\n";
	}
}
