#include<iostream>
using namespace std;

class Produs {
	char* denumire = nullptr;
	int stoc = 0;
	double pret = 0;

public:
	Produs():pret(10){ }

	Produs(const char* _denumire, int _stoc, double _pret):Produs() {
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
		//construi this pe baza lui p
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

	//get si set pentru denumire
	//ASTA INCALCA PRINCIPIUL INCAPSULARII
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
		//obj this deja exista
		//poate are deja o denumire
		//trebuie sa o dezaloc inainte
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

	//return-ul int-ului este prin valoare
	//se face copie
	//deci nu am cum sa stric this-ul
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

Produs f(Produs p) {
	return p;
}

int main() {
	Produs p1;
	p1.afisare();
	Produs p2("Carte", 100, 150);
	p2.afisare();
	Produs p3 = p2;//constructor de copiere
	p3.afisare();
	Produs p4(p3);//copy constructor
	
	//context de apel explicit/sau nu
	// al destructorului
	{
		Produs p;
	}
	Produs* pp = new Produs(p2);
	delete pp;//apel destructor

	Produs* pp2 = new Produs[5];
	delete[] pp2;
	cout << "\nSUNT DUPA }";

	cout << "\n---UTILIZARE GET SI SET-----";
	//char* denumire = p2.getDenumire();
	//denumire[0] = 'P';
	//p2.afisare();

	char* denumire2 = p2.getDenumireBun();
	denumire2[0] = 'P';
	p2.afisare();
	delete[] denumire2;

	return 0;
}