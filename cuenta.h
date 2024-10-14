#pragma once

class Cuenta
{
	private:
		double capital;
		double interes;
	public:
		//Constructores
		Cuenta(double _capital=0.0, double _interes=0.0);

		double getCap() const;
		double getInt() const;

		void setCap(double _capital);
		void setInt(double _interes);

		virtual double valor(int t) = 0;
		virtual void actualiza();
		double tae();
		
};

class Cuenta_Corriente : public Cuenta {
	public:
		Cuenta_Corriente(double _capital, double _interes);

		double valor(int t) override;
};

class Plazo_Fijo : public Cuenta {
	private:
		int plazo;
	public:
		Plazo_Fijo(double _capital, double _interes, int _plazo);
		
		double valor(int t) override;
		void actualiza() override;
};

class Cuenta_Nomina : public Cuenta {
	private:
		double nomina;
	public:
		Cuenta_Nomina(double _nomina, double _interes);

		double valor(int t) override;
};

class Cuenta_Divisa : public Cuenta {
	private:
		Cuenta* cuenta;
		float factor;
	public:
		Cuenta_Divisa(Cuenta* _cuenta, float _factor);

		double valor(int t) override;
};
