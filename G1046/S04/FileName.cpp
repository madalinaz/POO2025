#include<iostream>
using namespace std;

class Produs {

	//istoric al preturilor
	//astfel inca la fiecare modificare de pret
	//sa se populeze cu un nou element vectorul
	//preturilor
	string denumire = "Anonim";
	int nrPreturi=0;
	double* preturi=nullptr;
	int stoc=0;

public:
	//Constructori
	Produs() {
		cout << "\nApel constructor fara param";
	}

	Produs(int _stoc) {
		cout << "\nApel constructor 1 param";
		if (_stoc > 0) {
			this->stoc = _stoc;
		}
	}

	Produs(string _denumire, int _nrPreturi, 
		double* _preturi, int _stoc) {
		this->denumire = _denumire;
		if (_stoc > 0) {
			this->stoc = _stoc;
		} 
		if (_nrPreturi > 0 && _preturi != nullptr) {
			//...
		}
	}

	//meth de prelucrare(afisare,...)
	void afisare() const {
		cout << "\nDenumire: " << this->denumire;
		cout << "\nPretul curent: ";
		if (this->nrPreturi == 0) {
			cout << "-";
		}
		else {
			cout << this->preturi[this->nrPreturi - 1];
		}
	}
};

int main() {
	cout << endl << sizeof(Produs);
	Produs p1;
	p1.afisare();
	Produs* p2;
	p2 = new Produs();
	p2 = new Produs;
	p2 = new Produs(2);
	p2 = new Produs[5];
	Produs pp2[5];
	Produs* p3[5];//vector static de Produs*
	for (int i = 0; i < 5; i++) {
		p3[i] = new Produs[3];
	}
	Produs** p4;//pointer la pointer de Produs
	//vector dinamic de Produs*
	//matrice de Produs
	Produs p5(2);
	Produs p6(2.5);
	//cast/conversie degradanta
	int xxx = 12.5;
	//conversie nedegradanta
	int xx = 12;
	float fx = xx;
	Produs p7();//functie
	Produs p8[5][3];



	return 0;
}