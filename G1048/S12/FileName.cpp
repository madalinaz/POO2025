#include<iostream>
using namespace std;

//concept de virtualizare
//meth virtuale
//meth virtuale pure
//clase abstracte
//interfete

class Angajat {

protected:
	string nume = "Anonim";
	float salariuBaza = 0;

public:

	Angajat() {

	}

	Angajat(string _nume) {
		this->nume = _nume;
	}

	Angajat(string _nume, float _salariuBaza) {
		this->nume = _nume;
		this->salariuBaza = _salariuBaza;
	}

	Angajat(const Angajat& a) {
		this->nume = a.nume;
		this->salariuBaza = a.salariuBaza;
	}

	Angajat& operator=(const Angajat& a) {
		if (this != &a) {
			this->nume = a.nume;
			this->salariuBaza = a.salariuBaza;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Angajat& a);

	float calculSalariu() {
		//pp ca exista o regula complexa de calcul salariu
		return this->salariuBaza;
	}

	~Angajat() {
	}
};

ostream& operator<<(ostream& out, const Angajat& a) {
	out << "\nNume: " << a.nume;
	out << "\nSalariu baza: " << a.salariuBaza;
	return out;
}

class Manager :public Angajat {
	int nrSubordonati = 0;

public:
	Manager(string _nume, float _salariuBaza, int _nrSubordonati):Angajat(_nume,_salariuBaza) {
		this->nrSubordonati = _nrSubordonati;
	}

	friend ostream& operator<<(ostream& out, const Manager& m);
};

ostream& operator<<(ostream& out, const Manager& m) {
	out << (Angajat)m;//upcast prin valoare explicit
	out << "\nNr subordonati: " << m.nrSubordonati;
	return out;
}

int main() {

	return 0;
}