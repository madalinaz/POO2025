#include<iostream>
using namespace std;

class Produs {
	char* denumire = nullptr;
	int stoc = 0;
	double pret = 0;

public:
	Produs() {
		cout << "\nApel constructor fara param";
	}

	Produs(const char* _denumire, int _stoc, double _pret) :Produs() {
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

};


int main() {
	
	

	
	return 0;
}