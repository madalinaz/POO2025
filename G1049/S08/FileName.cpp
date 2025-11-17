#include<iostream>
using namespace std;

class Produs {
	string denumire="Anonim";
	double pret=0;

public:
	Produs(){}

	Produs(string _denumire, double _pret) {
		this->denumire = _denumire;
		this->pret = _pret;
	}

	Produs(const Produs& p) {
		this->denumire = p.denumire;
		this->pret = p.pret;
	}

	Produs& operator=(const Produs& p) {
		this->denumire = p.denumire;
		this->pret = p.pret;
		return *this;
	}

	void afisare() {
		cout << "\nDenumire: " << this->denumire << ", pret: " << this->pret;
	}
};

int main() {
	return 0;
}