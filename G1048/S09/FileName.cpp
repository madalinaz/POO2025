#include<iostream>
using namespace std;


//TEMA1 ->clasa Caracter in care putereArme este alocat static
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
	}

	~Caracter() {
		if (this->putereArme != nullptr) {
			delete[] this->putereArme;
			this->putereArme = nullptr;
			this->nrArme = 0;
		}
	}

	Caracter& operator+=(double _x) {
		if (_x > 0) {
			Caracter copie = *this;
			if (this->putereArme != nullptr) {
				delete[] this->putereArme;
				this->putereArme = nullptr;
				this->nrArme = 0;
			}
			this->putereArme = new double[copie.nrArme + 1];
			for (int i = 0; i < copie.nrArme; i++)
				this->putereArme[i] = copie.putereArme[i];
			this->putereArme[copie.nrArme] = _x;
			this->nrArme = copie.nrArme + 1;
			return *this;
		}
	}

	friend ostream& operator<<(ostream& out, const Caracter& c);
};

int Caracter::minViata = 10;

ostream& operator<<(ostream& out, const Caracter& c) {
	out << "\nId: " << c.id;
	out << "\nDenumire: " << c.denumire;
	out << "\nNivel viata: " << c.nivelViata;
	out << "\nNr arme: " << c.nrArme;
	for (int i = 0; i < c.nrArme; i++)
		out << c.putereArme[i] << " ";
	return out;
}

int main() {
	Caracter c1(12, "Zburator 1");
	cout << c1;
	c1 += 10;//adaug o arma cu putere de lovire 10
	//cout << c1;
	//c1++;//cresc nivelul de viata cu 10% fata de nivelul anterior
	Caracter c2(13);
	//c2 = 2 * c1;//returneaza un obj care are viata dublata in limita intervalului
	return 0;
}