#include<iostream>
using namespace std;

//tipuri de date(vectori numerici/caractere, alocati
//static sau dinamic +....)
//clasa (constructori + meth de prelucrare)
//fct globale
//redimensionare pe vectori

class Produs {
	int cod;
	int stoc;
	float* istoricPreturi;
	int nrPreturi;
	//meth in zona private

public:
	//atribute care au voie in zona public (ex: constante)
	
	//constructori
	Produs() {
		cout << "\nApel constructor fara param";
		this->cod = 0;
		this->stoc = 0;
		this->istoricPreturi = nullptr;
		this->nrPreturi = 0;
	}

	Produs(int _cod) {
		cout << "\nApel constructor cu 1 param";
		if (_cod >= 100) {
			this->cod = _cod;
		}
		else {
			this->cod = 0;
		}
		this->stoc = 0;
		this->istoricPreturi = nullptr;
		this->nrPreturi = 0;
	}

	Produs(int _cod, int _stoc, float* _istoricPreturi, int _nrPreturi) {
		if (_cod >= 100) {
			this->cod = _cod;
		}
		else {
			this->cod = 0;
		}
		if (_stoc > 0) {
			this->stoc = _stoc;
		}
		else {
			this->stoc = 0;
		}
		if (_nrPreturi > 0 && _istoricPreturi!=nullptr) {
			this->nrPreturi = _nrPreturi;
			this->istoricPreturi = new float[this->nrPreturi];
			for (int i = 0; i < this->nrPreturi; i++) {
				this->istoricPreturi[i] = _istoricPreturi[i];
			}
		}
		else {
			this->istoricPreturi = nullptr;
			this->nrPreturi = 0;
		}
	}
	//meth de acces/accesor (get si set)
	//meth de prelucrare (afisare)
	//orice meth non-statica are this-ul
	void afisare() const{//this este constant
		//this->cod = 12;
		cout << "\nCod produs: " << this->cod;
		cout << ", stoc: " << this->stoc;
		cout << ", nr preturi: " << this->nrPreturi;
		cout << ", preturi: ";
		for (int i = 0; i < this->nrPreturi; i++)
			cout << this->istoricPreturi[i] << " ";
	}
	//supraincarcare de operatori
	//destructor
};


int main() {
	Produs p1;
	p1.afisare();
	Produs p2[5];
	Produs* p3;
	p3 = new Produs();
	p3 = new Produs[5];
	Produs* p4[5];
	int* v[5];
	Produs** p5;
	//Produs p6();
	Produs p7(2);
	Produs p8 = 2;

	//conversii
	//nedegradante
	char c = 'a';
	int x = c;
	//degradante
	float f = 12.5;
	int x2 = f;
	return 0;
}