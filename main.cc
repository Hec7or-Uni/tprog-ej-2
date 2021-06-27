# include "Cuenta.h"
# include <iostream>
# include <iomanip>

using namespace std;

const int NUM_CUENTAS = 4;

void   mostrar_taes(Cuenta* cuentas[], int n);
double total(Cuenta* cuentas[], int n, int t);
void   valor_cuentas(Cuenta* cuentas[], int n, int t);
void   actualizacion(Cuenta* cuentas[], int n, int t);

int main() {
	Cuenta* cuentas[NUM_CUENTAS];

	cuentas[0] = new Cuenta_Corriente(1000, 1.0);
	cuentas[1] = new Plazo_Fijo(1000, 1.0, 12);
	cuentas[2] = new Cuenta_Nomina(1000, 0.0);
	cuentas[3] = new Cuenta_Divisa(cuentas[0], 0.84);

	mostrar_taes(cuentas, NUM_CUENTAS);
	cout << endl;

	valor_cuentas(cuentas, NUM_CUENTAS, 24);
	cout << endl;

	actualizacion(cuentas, NUM_CUENTAS, 24);
	cout << endl;

	for (int i = 0; i < NUM_CUENTAS; i++)
		delete cuentas[i];

	return 0;
}

void mostrar_taes(Cuenta* cuentas[], int n) {
	cout << "TAEs: ";
	for (int i = 0; i < n; i++)
		cout << cuentas[i]->tae() << " ";
}

double total(Cuenta* cuentas[], int n, int t) {
	double sol = 0.0;
	for (int i = 0; i < n; i++)
		sol += cuentas[i]->valor(t);
	return sol;
}

void valor_cuentas(Cuenta* cuentas[], int n, int t) {
	cout << "Mes |  Valor cuentas                           |  Total      " << endl;
	cout << "=============================================================" << endl;
	for (int i = 0; i <= t; i++)
	{
		cout << setw(3) << i;
		cout << " | ";

		for (int j = 0; j < n; j++)
			cout << fixed << setw(10) << setprecision(2) << cuentas[j]->valor(i);

		cout << " | ";
		cout << fixed << setw(10) << setprecision(2) << total(cuentas, NUM_CUENTAS, t);
		cout << " €" << endl;
	}
}

void actualizacion(Cuenta* cuentas[], int n, int t) {
	cout << "Mes |  Valor cuentas                                " << endl;
	cout << "====================================================" << endl;
	for (int i = 0; i <= t; i++) {
		cout << setw(3) << i;
		cout << " | ";
		
		for (int j = 0; j < n; j++) {
			if (i != 0)	cuentas[j]->actualiza();
			cout << fixed << setw(10) << setprecision(2) << cuentas[j]->valor(0) << "€";
		}
		cout << " | ";
		cout << endl;
	}
}