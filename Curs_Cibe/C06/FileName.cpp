#include<iostream>
using namespace std;

//TO DO
//operator = DONE
//atribute constante
//atribute statice si metode statice
//clase si functii friend

//pp ca toate produsele sunt din aceeasi categorie

class Produs {
	const int id;
	char* denumire = nullptr;
	int stoc = 0;
	double pret = 0;
	static double TVA;//variabila globala
	//static double taxaImpachetare;
public:
	Produs():id(0){ 
		//this->id = 0;
		cout << "\nConstructor fara param"; }

	Produs(int _id, const char* _denumire, int _stoc, double _pret):id(_id){
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

	Produs(const Produs& p):id(p.id){
		cout << "\nConstructor copiere";
		if (p.denumire != nullptr) {
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy(this->denumire, p.denumire);
		}
		this->stoc = p.stoc;
		this->pret = p.pret;
	}

	//primul operand este inghitit de this
	Produs& operator=(const Produs& p) {
		//dezalocare obj this
		//modificare this in functie de p
		if (this != &p) {
			if (this->denumire != nullptr) {
				delete[] this->denumire;
				this->denumire = nullptr;
			}
			if (p.denumire != nullptr) {
				this->denumire = new char[strlen(p.denumire) + 1];
				strcpy(this->denumire, p.denumire);
			}
			this->stoc = p.stoc;
			this->pret = p.pret;
		}
		return *this;
	}

	void afisare() {
		cout << "\nId: " << this->id;
		if (this->denumire != nullptr) {
			cout << "\nDenumire: " << this->denumire;
		}
		else {
			cout << "\nDenumire: -";

		}
		cout << "\nStoc: " << this->stoc;
		cout << "\nPret: " << this->pret;
	}

	double calculTVA() {
		return Produs::TVA * this->pret;
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

	~Produs() {
		cout << "\nDestructor";
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}
	}

	static void setTVA(double _TVA) {
		if (_TVA > 0 && _TVA < 1) {
			Produs::TVA = _TVA;
		}
	}

	friend bool gasit(Produs* _vp, int _n, int _id);
};

double Produs::TVA = 0.21;

//cauta id-ul in vectorul de produse
bool gasit(Produs* _vp, int _n, int _id) {
	for (int i = 0; i < _n; i++) {
		if (_vp[i].id == _id)
			return true;
	}
	return false;
}

int main() {
	Produs::setTVA(0.18);//de preferat aceasta versiune
	Produs p1(13,"Stilou", 100, 1000);
	p1.setTVA(0.23);
	p1.afisare();

	Produs p2 = p1;

	Produs p3;
	p3 = p2;//operatorul de atribuire(=)
	//p3.operator=(p2);
	p3.afisare();
	//p1 = p2 = p3;
	p3 = p3;
	p3.afisare();
	cout << p3.calculTVA();
	int x, y, z;
	x = y = z = 2;
	x += y = z;
	x = x;

	const int val=2;

	//PASI SUPRAINCARCARE
	//P1. Se identifica tipul operatorului + nr de operanzi
	//P2. Se identifica tipul operanzitor
	//P3. Daca primul operand este de tipul clasei,
	//supraincarcarea se poate realiza printr-o metoda a clasei
	//I operand este inghitit de this
	//Daca nu, atunci obligatoriu se supraincarca printr-o functie globala
	//P4. Ce returneaza operatorul?
	//P5. Se modifica operanzii?
	return 0;
}