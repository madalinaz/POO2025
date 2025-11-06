#include<iostream>
using namespace std;

class Produs {
	char* denumire = nullptr;
	int stoc = 0;
	double pret = 0;

public:
	Produs(){ cout << "\nConstructor fara param"; }

	Produs(const char* _denumire, int _stoc, double _pret){
		cout << "\nConstructor cu toti param";
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

	Produs(const Produs& p) {
		cout << "\nConstructor copiere";
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

	char* getDenumire() {
		return this->denumire;
	}

	char* getDenumireBun() {
		if (this->denumire != nullptr) {
			char* copie;
			copie = new char[strlen(this->denumire) + 1];
			strcpy(copie, this->denumire);
			return copie;
		}
		else {
			return nullptr;
		}
	}

	void setDenumire(const char* _denumire) {
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}
		if (_denumire != nullptr) {
			this->denumire = new char[strlen(_denumire) + 1];
			strcpy(this->denumire, _denumire);
		}
		else {
			this->denumire = nullptr;
		}
	}

	int getStoc() {
		return this->stoc;
	}

	//destructor
	~Produs() {
		cout << "\nDestructor";
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}
	}
};

int main() {
	Produs p1("Stilou", 100, 1000);
	p1.afisare();
	return 0;
}