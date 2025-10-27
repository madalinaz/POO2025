#include<iostream>
using namespace std;

class Magazin {
	string denumire="-";
	int nrProduse=0;
	//int nrMaximProduse;
	int* coduriProdus=nullptr;//vector cu valori unice

public:
	//meth de a adauga coduri dar pastrand unicitatea
	//1.constructor cu toti param dar cu validare 
	//2.meth de adaugaCodNou
	//3.meth globala de validare adaugare un nou 
	// cod intr-un vector existent
	//get si set pe int* pastrare incapsulare
	Magazin(string _denumire) {
		//pp ca nu avem validari la denumire
		this->denumire = _denumire;
	}

	//constructor cu toti param dar fara validare unicitate vector
	Magazin(string _denumire, int _nrProduse, int* _coduriProdus):Magazin(_denumire) {
		if (_nrProduse > 0 && _coduriProdus != nullptr) {
			this->nrProduse = _nrProduse;
			this->coduriProdus = new int[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++) {
				this->coduriProdus[i] = _coduriProdus[i];
			}
		}
	}

	void afisare() {
		cout << "\nDenumire: " << this->denumire;
		cout << "\nNr produse: " << this->nrProduse;
		cout << "\nCoduri produse: ";
		for (int i = 0; i < this->nrProduse; i++) {
			cout << this->coduriProdus[i] << " ";
		}
	}

	//meth care adauga un nou cod pastrand unicitatea
	void adaugaCod(int _cod) {

	}
};

int main() {
	int coduri[] = { 10, 4, 6 };
	Magazin m1("ABC", 3, coduri);
	m1.afisare();
	return 0;
}