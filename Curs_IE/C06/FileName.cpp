#include<iostream>
using namespace std;

//TO DO
//operator =
//static + const
//friend
//reguli supraincarcare operatori

class Produs {
	static double TVA;
	char* denumire = nullptr;
	int stoc = 0;
	double pret = 0;

public:
	Produs() {
		cout << "\nApel constructor fara param";
	}

	Produs(const char* _denumire, int _stoc, double _pret) {
		cout << "\nApel constructor cu toti param";
		if (_denumire != nullptr) {
			this->denumire = new char[strlen(_denumire) + 1];
			strcpy(this->denumire, _denumire);
		}
		if (_stoc > 0) {
			this->stoc = _stoc;
		}
		if (_pret > 0) {
			this->pret = _pret;
		}
	}

	//to do home->const protejeaza dar nu chiar tot
	Produs(const Produs& p) {
		cout << "\nApel constructor copiere";
		if (p.denumire != nullptr) {
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy(this->denumire, p.denumire);
		}
		this->stoc = p.stoc;
		this->pret = p.pret;
	}

	void afisare() {
		if (this->denumire != nullptr) {
			cout << "\nDenumire: " << this->denumire;
		}
		else {
			cout << "\nDenumire: -";

		}
		cout << "\nStoc: " << this->stoc;
		cout << "\nPret: " << this->pret;
	}

	~Produs() {
		cout << "\nApel destructor";
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}
	}

};

int main() {
	Produs p1("Carte", 100, 1000);
	p1.afisare();
	return 0;
}