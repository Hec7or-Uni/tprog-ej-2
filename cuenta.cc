#include <cmath>
#include <iostream>
#include "cuenta.h"

using namespace std;

// ----- Cuenta --------------------
Cuenta::Cuenta(double _capital, double _interes)
	: capital(_capital), interes(_interes)
{ }

double Cuenta::getCap() const {
	return this->capital;
}

double Cuenta::getInt() const {
	return this->interes;
}

void Cuenta::setCap(double _capital) {
	this->capital = _capital;
}
void Cuenta::setInt(double _interes) {
	this->interes = _interes;
}

double Cuenta::tae() {
	try {
		if (capital != 0)
			return 100.0 * (valor(12) / valor(0) - 1);
		else
			throw capital;
	} catch(double capital) {
		cerr << "El capital inicial es: " << capital << endl;
		return 1;
	}
}

void Cuenta::actualiza() {
	this->capital = valor(1);
}

// ----- Cuenta -> Corriente -----------------
Cuenta_Corriente::Cuenta_Corriente(double _capital, double _interes) 
	: Cuenta(_capital, _interes)
{ }

double Cuenta_Corriente::valor(int t) {
	return getCap() * pow(1 + (getInt() / 100.0), t);
}

// ----- Cuenta -> Plazo Fijo ----------------
Plazo_Fijo::Plazo_Fijo(double _capital, double _interes, int _plazo) 
	: Cuenta(_capital, _interes), plazo(_plazo)
{ }

double Plazo_Fijo::valor(int t) {
	return (t < plazo) ? getCap() : getCap() * (1 + (getInt() / 100.0));
}

void Plazo_Fijo::actualiza() {
	switch (this->plazo) {
		case 0:	break;
		default: this->plazo--;	break;
	}
}

// ----- Cuenta -> Nomina --------------------
Cuenta_Nomina::Cuenta_Nomina(double _nomina, double _interes) 
	: Cuenta(_nomina, _interes), nomina(_nomina)
{ }

double Cuenta_Nomina::valor(int t) {
	return getCap() + t * nomina;
}

// ----- Cuenta -> Divisa --------------------
Cuenta_Divisa::Cuenta_Divisa(Cuenta* _cuenta, float _factor) 
	: Cuenta(_cuenta->getCap(), _cuenta->getInt()), cuenta(_cuenta), factor(_factor)
{ }

double Cuenta_Divisa::valor(int t) {
	return factor * cuenta->valor(t);
}
