#include<iostream>
using namespace std;

class Produs {
	//to do home (denumire initializata cu Anonim)
	char* denumire = nullptr;
	int stoc = 0;
	double pret = 0;
	//camp constant?
	//camp static??

public:
	//constructori
	Produs() {
		cout << "\nApel constructor fara param";
	}

	//DP Builder care ofera posibilitate de construire obj complexe
	Produs(const char* _denumire, int _stoc, double _pret) {
		cout << "\nApel constructor cu toti param";

		if (_denumire!=nullptr && strlen(_denumire) > 3) {
			this->denumire = new char[strlen(_denumire) + 1];
			strcpy_s(this->denumire, 
				strlen(_denumire) + 1, _denumire);
		}
		if (_stoc > 0) {
			this->stoc = _stoc;
		}
		if (_pret > 0) {
			this->pret = _pret;
		}
	}

	//constructor copiere
	//home: chiar daca e const ce anume totusi pot modifica din p
	Produs(const Produs& p) {
		cout << "\nApel copy constructor";
		if (p.denumire != nullptr) {
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy_s(this->denumire,
				strlen(p.denumire) + 1, p.denumire);
		}
		this->stoc = p.stoc;
		this->pret = p.pret;
	}

	//operator =
	Produs& operator=(const Produs& p) {
		////obj this deja exista
		//destructor
		//constructor de copiere
		if (this != &p) {
			if (this->denumire != nullptr) {
				delete[] this->denumire;
				this->denumire = nullptr;
			}
			if (p.denumire != nullptr) {
				this->denumire = new char[strlen(p.denumire) + 1];
				strcpy_s(this->denumire,
					strlen(p.denumire) + 1, p.denumire);
			}
			else {
				//de adaugat caci nu mai este constructor
				this->denumire = nullptr;
			}
			this->stoc = p.stoc;
			this->pret = p.pret;
		}
		return *this;
	}
	
	//destructor
	~Produs() {
		cout << "\nApel destructor";
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}
	}

	//meth afisare
	void afisare() {
		cout << "\nDenumire: ";
		if (this->denumire != nullptr) {
			cout << this->denumire;
		}
		else {
			cout << "-";
		}
		cout << "\nStoc: " << this->stoc;
		cout << "\nPret: " << this->pret;
	}
};

Produs fctGlobala(Produs p) {
	return p;
}

int main() {
	Produs p1;
	Produs p2("Carte", 100, 120);
	p1.afisare();
	p2.afisare();
	Produs p3 = p2;
	Produs p4(p3);
	cout << "\n--------------";
	Produs p5;
	fctGlobala(p5);
	cout << "\n--------------";
	Produs* pp = new Produs();
	delete pp;
	pp = nullptr;

	p1 = p3 = p2;//operanzi (p3 si p2) pentru operator +
	p1 = p1;//auto-asignare (nasoala daca am alocare dinamica)
	p1.afisare();
	//REGULI SUPRAINCARCARE OPERATORI
	//p1.se identifica operanzii
	//p2.daca I operand este de tipul clasei
	//atunci se poate supraincarca printr-o metoda a clasei
	//iar I operand este "inghitit" de this
	//else la p2,(aka cout<<p), daca I operand
	//nu este de tipul clasei, atunci se supraincarca
	//obligatoriu prin functie globala(no more this)
	//p3.CE returneaza operatorul?
	//p4.CE SE MODIFICA!!!!

	return 0;
}