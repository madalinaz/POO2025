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

	Produs(const char* _denumire, int _stoc, double _pret){
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

Produs& fct(Produs& p) {
	//to do...
	return p;
}

Produs fct2(Produs p[10], int n) {
	return p[0];
}

Produs& fct3(Produs p[10], int n) {
	return p[0];
}

Produs& fct4(Produs p) {
	Produs p2;
	//.....
	return p2;
}


int main() {
	Produs p1;
	p1.afisare();
	Produs p2("Carte", 100, 150);
	p2.afisare();
	Produs p3(p2);//o copie a unui obiect ->constructorul de copiere
	p3.afisare();

	//context de apel explicit sau nu destructor
	Produs* pp = new Produs();
	delete pp;
	Produs* pp2 = new Produs[5];
	delete[] pp2;

	{
		Produs p4;
	}
	cout << "\n----Inchidere }---";

	cout << "\n------------fct--------";
	fct(p2);
	cout << "\n------------fct--------";

	return 0;
}