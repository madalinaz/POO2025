#include<iostream>
using namespace std;

class Produs2 {
	string denumire;
	int stoc;
	double pret;

public:
	Produs2() :denumire("Anonim"), stoc(0), pret(0) {
		cout << "\nApel constructor fara param";
	}

	//Produs2(string _denumire) :denumire("Anonim"), stoc(0), pret(0) {
	Produs2(string _denumire) : Produs2() {
		cout << "\nApel constructor cu 1 param";
		if (_denumire.length() >= 3) {
			this->denumire = _denumire;
		}
	}

	void afisare() {
		cout << "\nDenumire: " << this->denumire;
		cout << "\nStoc: " << this->stoc;
		cout << "\nPret: " << this->pret;
	}
};

class Produs {
	string denumire="Anonim";
	int stoc=0;
	double pret=0;

public:
	//Produs() {
	//	cout << "\nApel constructor fara param";
	//}

	//Produs(string _denumire) {
	//	cout << "\nApel constructor cu 1 param";
	//	if (_denumire.length() >= 3) {
	//		this->denumire = _denumire;
	//	}
	//}

	Produs(string _denumire="Anonim",
		int _stoc=0, double _pret=0) {
		if (_denumire.length() >= 3) {
			this->denumire = _denumire;
		}
		if (_stoc >= 0) {
			this->stoc = _stoc;
		}
		if (_pret > 0) {
			this->pret = _pret;
		}
	}

	void afisare() {
		cout << "\nDenumire: " << this->denumire;
		cout << "\nStoc: " << this->stoc;
		cout << "\nPret: " << this->pret;
	}

	//mecanisme de accesare zona private
	//metode accesor (get si set)
	//vreau sa respecte incapsularea
	string getDenumire() {
		return this->denumire;
	}

	//Se apeleaza setteri in constructori?

	void setDenumire(string _nouaDenumire) {
		//obj this deja exista
		//deci grija la dezalocare unde este nevoie
		if (_nouaDenumire.length() >= 3) {
			this->denumire = _nouaDenumire;
		}
	}
};



int main() {
	Produs p;//constructor fara param
	Produs p2("S");
	p2.afisare();
	cout << "\nDenumire prin get: " << p2.getDenumire();
	p2.setDenumire("Stilou");
	p2.afisare();

	return 0;
}