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
		return *this;
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

	//TEMA 2. DE REGESTIONAT ACEASTA IMPLEMENTARE ASTFEL INCAT SA NU NE FOLOSIM DE CELALALT OPERATOR +=
	//actualizeaza this-ul prin preluarea din c a tuturor armelor
	Caracter& operator+=(Caracter& c) {
		if (this != &c) {
			for (int i = 0; i < c.nrArme; i++) {
				//this->operator+=(c.putereArme[i]);
				(*this) += c.putereArme[i];
			}
			if (c.putereArme != nullptr) {
				delete[] c.putereArme;
				c.putereArme = nullptr;
				c.nrArme = 0;
			}
		}
		return *this;
	}

	//de adaugat validare pe nivel viata ca sa nu depaseasca 100
	//pre-fixata
	Caracter& operator++() {
		this->nivelViata *= 1.1;
		return *this;//returnam starea de dupa modificare
	}

	//de adaugat validare pe nivel viata ca sa nu depaseasca 100
	//post-fixata
	Caracter operator++(int) {
		Caracter copie = *this;
		this->nivelViata *= 1.1;
		return copie;
	}

	double operator[](int _index) {
		if (_index >= 0 && _index < this->nrArme) {
			return this->putereArme[_index];
		}
	}

	friend ostream& operator<<(ostream& out, const Caracter& c);

	friend Caracter operator*(int _x, const Caracter& c);
};

int Caracter::minViata = 10;

ostream& operator<<(ostream& out, const Caracter& c) {
	out << "\nId: " << c.id;
	out << "\nDenumire: " << c.denumire;
	out << "\nNivel viata: " << c.nivelViata;
	out << "\nNr arme: " << c.nrArme;
	out << "\nArme: ";
	for (int i = 0; i < c.nrArme; i++)
		out << c.putereArme[i] << " ";
	return out;
}

Caracter operator*(int _x, const Caracter& c) {
	if (_x > 0) {
		Caracter rez = c;
		rez.nivelViata *= _x;
		if (rez.nivelViata >= 100)
			rez.nivelViata = 100;
		return rez;
	}
}

//TEMA3
class Joc {
	//colectie de Caractere (NU putem stoca obiecte, merg doar pointeri)
	//+= un nou caracter in joc
	//cum gestionati prin operatori situatia in care un caracter moare
};

//TEMA4 
//Cum gestionati astfel incat clasa Joc sa permita crearea unui UNIC obiect de tip Joc (Singleton)

int main() {
	Caracter c1(12, "Zburator 1");
	cout << c1;
	c1 += 10;//adaug o arma cu putere de lovire 10
	c1 += c1 += 12;
	cout << c1;
	c1++;//cresc nivelul de viata cu 10% fata de nivelul anterior
	c1.operator++(2);
	++c1;
	c1.~Caracter();
	cout << c1;
	Caracter c2(13);
	c2 = 2 * c1;//returneaza un obj care are viata dublata in limita intervalului
	operator*(2, c1);

	//operator [] pentru pastrarea incapsularii
	double putere = c1[2];//preluarea nivelul de putere a armei de pe index 2
	//c1[2] = -100;
	return 0;
}