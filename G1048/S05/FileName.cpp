#include<iostream>
using namespace std;

//get si set pe vector
//constructor care respecta conditie pentru vector

class Magazin {
	//char* denumire;
	//char denumire[31];
	string denumire = "Anonim";
	int nrProduse = 0;
	int* coduriProdus = nullptr;//codurile sunt pozitive si unice
	//int coduri[100];
public:
	Magazin() {
	}

	//Magazin(string _denumire, int _nrProduse, int* _coduriProdus){
	//	this->denumire = _denumire;
	//	//validari in cadrul constructorului
	//	if (_nrProduse > 0 && _coduriProdus != nullptr) {
	//		int nrDubluri = 0;
	//		for (int i = 0; i < _nrProduse; i++) {
	//			for (int j = i + 1; j < _nrProduse; j++) {
	//				if (_coduriProdus[i] == _coduriProdus[j]
	//					&& _coduriProdus[i] != -1) {
	//					nrDubluri++;
	//					_coduriProdus[j] = -1;
	//				}
	//			}
	//		}
	//		this->nrProduse = _nrProduse - nrDubluri;
	//		this->coduriProdus = new int[this->nrProduse];
	//		int k = 0;
	//		for (int i = 0; i < _nrProduse; i++) {
	//			if (_coduriProdus[i] != -1) {
	//				this->coduriProdus[k++] = _coduriProdus[i];
	//			}
	//		}
	//	}
	//}

	Magazin(string _denumire, int _nrProduse, int* _coduriProdus) {
		this->denumire = _denumire;
		//validari in cadrul constructorului
		if (_nrProduse > 0 && _coduriProdus != nullptr) {
			for (int i = 0;  i < _nrProduse; i++) {
				adaugaCod(_coduriProdus[i]);
			}
		}
	}

	void afisare() {
		cout << "\nDenumire: " << this->denumire;
		cout << "\nNr produse: " << this->nrProduse;
		cout << "\nCoduri: ";
		for (int i = 0; i < this->nrProduse; i++)
			cout << this->coduriProdus[i] << " ";
	} 

	void adaugaCod(int _codNou) {
		bool ok = true;
		for (int i = 0; i < this->nrProduse; i++) {
			if (this->coduriProdus[i] == _codNou) {
				ok = false;
				//return;
				//break;
			}
		}
		if (ok) {
			//se baga _codNou la sfarsit de vector
			int* copie = new int[this->nrProduse + 1];
			for (int i = 0; i < this->nrProduse; i++) {
				copie[i] = this->coduriProdus[i];
			}
			copie[this->nrProduse] = _codNou;
			delete[] this->coduriProdus;
			this->coduriProdus = nullptr;
			this->coduriProdus = copie;
			this->nrProduse++;
		}
	}
};

//trebuie deasupra clasei daca vrem sa o apelam in clasa
//fct globala care verifica daca un elem apartine unui vector
bool apartine(int* v, int n, int x) {
	//to do home
}

int main() {
	int v[] = { 10,5,7,5,10,10,9,8 };
	Magazin m1("ABC", 8, v);
	m1.afisare();
	m1.adaugaCod(10);
	m1.afisare();
	m1.adaugaCod(99);
	m1.afisare();
	return 0;
}