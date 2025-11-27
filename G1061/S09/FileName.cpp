//NEXT TIME (s09)
//terminam toti operatorii de supraincarcat
//comparatie done
//= done
//<< done
// >>
// [] done
// !
// cast
// ++ (pre si post)
// + 
//functie
//+=

#include<iostream>
using namespace std;

class Caracter {
	const int id;
	string denumire = "-";
	int nivelViata = 100;//apartine intervalului (0;100]
	int nrArme = 0;
	double* putereArme = nullptr;
	static int minViata;

public:
	Caracter(int _id) :id(_id) {
	}

	Caracter(int _id, string _denumire) :id(_id) {
		this->denumire = _denumire;
	}

	Caracter(const Caracter& c) :id(c.id) {
		this->denumire = c.denumire;
		this->nivelViata = c.nivelViata;
		if (c.nrArme > 0 && c.putereArme != nullptr) {
			this->nrArme = c.nrArme;
			this->putereArme = new double[this->nrArme];
			for (int i = 0; i < this->nrArme; i++)
				this->putereArme[i] = c.putereArme[i];
		}
	}

	Caracter& operator=(const Caracter& c) {
		if (this != &c) {
			if (this->putereArme != nullptr) {
				delete[] this->putereArme;
				this->putereArme = nullptr;
				this->nrArme = 0;
			}
			this->denumire = c.denumire;
			this->nivelViata = c.nivelViata;
			if (c.nrArme > 0 && c.putereArme != nullptr) {
				this->nrArme = c.nrArme;
				this->putereArme = new double[this->nrArme];
				for (int i = 0; i < this->nrArme; i++)
					this->putereArme[i] = c.putereArme[i];
			}
		}
		return *this;
	}

	~Caracter() {
		if (this->putereArme != nullptr) {
			delete[] this->putereArme;
			this->putereArme = nullptr;
			this->nrArme = 0;
		}
	}
};

int Caracter::minViata = 20;

int main() {
	return 0;
}