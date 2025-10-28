#include<iostream>
using namespace std;

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
};

int main() {
	Magazin m1;
	int v[] = { 10,5,7,10,3,4,7,5,10 };
	Magazin m2("ABC", 9, v);
	m2.afisare();
	return 0;
}