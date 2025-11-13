#include<iostream>
using namespace std;

class Produs {
	string denumire = "Anonim";
	double pret=0;

public:
	Produs(string _denumire, double _pret) {
		this->denumire = _denumire;
		this->pret = _pret;
	}

	void afisare() {
		cout << "\nDenumire: " << this->denumire;
		cout << "\nPret: " << this->pret;
	}
};



int main() {
	Produs p1("carte", 120);
	Produs p2("stilou", 1000);
	Produs p3(p2);
	p3.afisare();
	p1 = p2;
	p1.afisare();
	return 0;
}