#include<iostream>
using namespace std;

class Produs {
	string denumire;
	double pret;
	int stoc;

public:
	//metode
	//1. constructori
	//in oricare meth non-statica, exista this
	//this -> adresa obj apelator
	Produs() {
		cout << "\nConstructor fara param";
		this->denumire = "Anonim";
		this->pret = 0;
		this->stoc = 0;
	}

	Produs(string _denumire) {
		cout << "\nConstructor cu cativa param";
		if (_denumire.length() >= 2) {
			this->denumire = _denumire;
		}
		else {
			this->denumire = "Anonim";
		}
		this->pret = 0;
		this->stoc = 0;
	}

	Produs(string _denumire, double _pret, 
		int _stoc) {
		cout << "\nConstructor cu toti param";
		if (_denumire.length() >= 2) {
			this->denumire = _denumire;
		}
		else {
			this->denumire = "Anonim";
		}
		if (_pret > 0) {
			this->pret = _pret;
		}
		else {
			this->pret = 0;
		}
		if (_stoc > 0) {
			this->stoc = _stoc;
		}
		else {
			this->stoc = 0;
		}
	}
	//2. meth accesor (get si set)
	string getDenumire() {
		return this->denumire;
	}

	void setDenumire(string _denumire) {
		if (_denumire.length() >= 2) {
			this->denumire = _denumire;
		}
		else {
			this->denumire = "Anonim";
		}
	}
	//3. destructor
	//4. meth de prelucrare (afisare)

	//metoda de afisare
	void afisare() {
		cout << "\n-------------";
		cout << "\nDenumire: " << this->denumire;
		cout << "\nPret: " << this->pret;
		cout << "\nStoc: " << this->stoc;
		cout << "\n-------------";
	}
	//5. supraincarcare de operatori
};

int main() {
	Produs p;//apeleaza constructor fara param
	p.afisare();
	/*p.setDenumire("lapte");
	cout << p.getDenumire();
	p.afisare();
	cout << p;
	p += 10;*/

	cout << "\n----Apel constructori------";
	Produs p1;
	Produs p2[5];
	Produs* p3;
	p3 = new Produs;
	p3 = new Produs();
	p3 = new Produs[5];

	Produs* p4[5];
	Produs** p5;//matrice de Produs, pointer la pointer la Produs, vector dinamic de Produs*
	
	Produs p6("Lapte");
	p6.afisare();
	string denumire = "Stilou";
	Produs p7 = denumire;
	p7.afisare();
	Produs p8();//p8 este o functie
	Produs p9("Stilou", 100, 10);
	p9.afisare();
	cout << "\nAfisare denumire: " << p9.getDenumire();
	p9.setDenumire("Pix");
	return 0;
}