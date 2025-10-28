#include<iostream>
using namespace std;

bool apartine(int* v, int n, int x);

class Magazin {
	string denumire = "Anonim";
	int nrProd = 0;
	int* coduri = nullptr;//retine codurile produselor ( se respecta unicitatea)
	//vectorul contine elem in ordine strict crescatoare

public:
	Magazin() {
	}

	Magazin(string _denumire, int _nrProd, int* _coduri) {
		this->denumire = _denumire;
		if (_nrProd > 0 && _coduri != nullptr) {
			//aici e toata complexitatea
			for (int i = 0; i < _nrProd - 1; i++)
				for (int j = i + 1; j < _nrProd; j++) {
					if (_coduri[i] > _coduri[j]) {
						swap(_coduri[i], _coduri[j]);
					}
				}
			int nrDubluri = 0;
			for (int i = 1; i < _nrProd; i++) {
				if (_coduri[i] == _coduri[i - 1]) {
					nrDubluri++;
				}
			}
			this->nrProd = _nrProd - nrDubluri;
			this->coduri = new int[this->nrProd];
			int k = 0;
			this->coduri[k++] = _coduri[0];
			for (int i = 1; i < _nrProd; i++) {
				if (_coduri[i] != _coduri[i - 1]) {
					this->coduri[k++] = _coduri[i];
				}
			}
		}
	}

	void afisare() {
		cout << "\nDenumire: " << this->denumire;
		cout << "\nNr produse: " << this->nrProd;
		cout << "\nCoduri: ";
		for (int i = 0; i < this->nrProd; i++) {
			cout << this->coduri[i] << " ";
		}
	}

	//meth care adauga un nou elem in vectorul de coduri
	void adaugaCod(int _codNou) {
		if (!apartine(this->coduri, this->nrProd, _codNou)) {
			int* copie = new int[this->nrProd + 1];
			int i;
			for (i = 0;i<this->nrProd 
				&& this->coduri[i]<_codNou; i++) {
				copie[i] = this->coduri[i];
			}
			copie[i] = _codNou;
			for (; i < this->nrProd; i++) {
				copie[i+1] = this->coduri[i];
			}
			delete[] this->coduri;
			//this->coduri = nullptr;
			this->coduri = copie;
			this->nrProd++;
		}
	}
};

//functie globala care verifica daca un elem apartine 
// unui vector
//ca sa puteti apela fct globala in clasa, trebuie deasupra clasei

bool apartine(int* v, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (v[i] == x) {
			return true;
		}
	}
	return false;
}

int main() {
	Magazin m1;
	int v[] = { 10,5,7,10,3,4,7,5,10 };
	Magazin m2("ABC", 9, v);
	m2.afisare();
	m2.adaugaCod(8);
	m2.afisare();
	m2.adaugaCod(15);
	m2.afisare();
	m2.adaugaCod(2);
	m2.afisare();
	m2.adaugaCod(10);
	m2.afisare();
	return 0;
}