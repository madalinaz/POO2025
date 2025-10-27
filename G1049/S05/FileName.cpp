#include<iostream>
using namespace std;

bool existaCod(int* _coduri, int _nrCoduri, int _cod) {
	for (int i = 0; i < _nrCoduri; i++) {
		if (_coduri[i] == _cod) {
			return true;
		}
	}
	return false;
}

class Magazin {
	string denumire="-";
	int nrProduse=0;
	//int nrMaximProduse;
	int* coduriProdus=nullptr;//vector cu valori unice

public:
	//meth de a adauga coduri dar pastrand unicitatea
	//1.constructor cu toti param dar cu validare 
	//2.meth de adaugaCodNou
	//3.functie globala de validare adaugare un nou 
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

	//to do home
	//constructor care primeste toti param dar apeleaza pentru fiecare
	//elem din vector meth adaugaCod

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
		bool exista = false;
		for (int i = 0; i < this->nrProduse; i++) {
			if (this->coduriProdus[i] == _cod) {
				exista = true;
			}
		}
		if (!exista) {
			//to do next
			int* aux = new int[this->nrProduse + 1];
			for (int i = 0; i < this->nrProduse; i++) {
				aux[i] = this->coduriProdus[i];
			}
			aux[this->nrProduse] = _cod;
			delete[] this->coduriProdus;
			this->coduriProdus = aux;
			this->nrProduse++;
		}
	}

	void adaugaCod2(int _cod) {
		
		if (!existaCod(this->coduriProdus,this->nrProduse,_cod)) {
			int* aux = new int[this->nrProduse + 1];
			for (int i = 0; i < this->nrProduse; i++) {
				aux[i] = this->coduriProdus[i];
			}
			aux[this->nrProduse] = _cod;
			delete[] this->coduriProdus;
			this->coduriProdus = aux;
			this->nrProduse++;
		}
	}

	//meth accesor (get si set)
	string getDenumire() {
		return this->denumire;
	}

	void setDenumire(string _denumire) {
		//nu avem validari pe denumire
		this->denumire = _denumire;
	}

	int* getCoduriProdus() {
		//incalcati incapsularea prin primul return
		//return this->coduriProdus;

		//se returneaza o copie
		int* copie = new int[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			copie[i] = this->coduriProdus[i];
		}
		return copie;
	}

	//to do home pentru meth accesor
	int getNrCoduri() {
		return 0;
	}

	//return-ul este prin valoare, deci oricum se face 
	//o copie, deci este protejat obj nostru din vector
	int getCod(int _index) {
		//returneaza un cod in functie de _index
		return 0;
	}

	void setCoduriProduse(int* _coduriProdus, int _nrProduse) {
		//de avut in vedere eliberare z.m. existenta
	}

	void setCod(int _cod, int _index) {
		//de avut in vedere unicitatea
	}
};


int main() {
	int coduri[] = { 10, 4, 6 };
	Magazin m1("ABC", 3, coduri);
	m1.afisare();
	m1.adaugaCod(12);
	m1.afisare();
	m1.adaugaCod(10);
	m1.afisare();
	Magazin m2("CDE",0,nullptr);
	m2.adaugaCod(13);
	m2.afisare();

	cout << "\n----testare incapsulare prin get-------";
	int* v = m1.getCoduriProdus();
	v[0] = 12345;
	m1.afisare();
	//apoi dezaloc v-ul care s-a alocat in getCoduriProdus
	delete[] v;
	return 0;
}