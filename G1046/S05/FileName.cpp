#include<iostream>
using namespace std;

class Magazin {
	string denumire = "Anonim";
	int nrProduse = 0;
	int* coduri = nullptr;//retine codurile produselor ( se respecta unicitatea)

public:
	//constructor fara param
	Magazin(){ }
	//constructor cu denumire
	
	//constructor care primeste toti param
	//fara validari de continut vector
	/*Magazin(string _denumire, int _nrProduse, int* _coduri) {
		this->denumire = _denumire;
		if (_nrProduse > 0 && _coduri != nullptr) {
			this->nrProduse = _nrProduse;
			this->coduri = new int[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
				this->coduri[i] = _coduri[i];
		}
	}*/

	//cu validari in interiorul constructorului
	Magazin(string _denumire, int _nrProduse, int* _coduri) {
		this->denumire = _denumire;
		if (_nrProduse > 0 && _coduri != nullptr) {
			int ct = 1;
			for (int i = 1; i < _nrProduse; i++) {
				bool gasit = false;
				for (int j = 0; j < i && gasit == false; j++) {
					if (_coduri[i] == _coduri[j])
						gasit = true;
				}
				if (!gasit) {
					ct++;
				}
			}
			this->coduri = new int[ct];
			this->nrProduse = ct;
			int k = 0;
			this->coduri[k++] = _coduri[0];
			for (int i = 1; i < _nrProduse; i++) {
				bool gasit = false;
				for (int j = 0; j < i && gasit == false; j++) {
					if (_coduri[i] == _coduri[j])
						gasit = true;
				}
				if (!gasit) {
					this->coduri[k++] = _coduri[i];
				}
			}
		}
	}

	void afisare() {
		cout << "\nDenumire: " << this->denumire;
		cout << "\nNr produse: " << this->nrProduse;
		cout << "\nCoduri: ";
		for (int i = 0; i < this->nrProduse; i++)
			cout << this->coduri[i] << " ";
	}

	//metoda care adauga un nou cod in vectorul coduri
};

int main() {
	int v[]{ 10,45,13,40,13, 12 };
	Magazin m1("ABC", 5, v);
	m1.afisare();
	return 0;
}