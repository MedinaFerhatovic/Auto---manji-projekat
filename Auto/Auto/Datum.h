#pragma once
#include <string>
using namespace std;

class Datum
{
private:
	int dan, mjesec, godina;
public:
	Datum();
	void setDan();
	void setMjesec();
	void setGodina();
	int getDan();
	int getMjesec();
	int getGodina();
	void postaviDatum();
	void ispisiDatum();
	string getDatum();
	string nazivDana();
	~Datum() {};
};

