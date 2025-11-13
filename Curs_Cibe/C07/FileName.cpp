#include<iostream>
using namespace std;




class Produs {
	const int id;
	char* denumire = nullptr;
	int stoc = 0;
	double pret = 0;
public:
	Produs() :id(0) {
	}

	Produs(int _id, const char* _denumire, int _stoc, double _pret) :id(_id) {
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

	Produs(const Produs& p) :id(p.id) {
		if (p.denumire != nullptr) {
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy(this->denumire, p.denumire);
		}
		this->stoc = p.stoc;
		this->pret = p.pret;
	}

	Produs& operator=(const Produs& p) {
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

	~Produs() {
		cout << "\nDestructor";
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}
	}
};


int main() {
	Produs p1(13, "Stilou", 100, 1000);
	
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