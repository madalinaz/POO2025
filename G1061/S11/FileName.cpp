#include<iostream>
using namespace std;

//afisare+citire obj de tip enum folosind ostream si istream(HOME)

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

//Liskov substitution
//relatia de tipul is-a
//mostenire/derivare
//clasa Angajat ->clasa parinte/baza
//clasa Manager ->clasa derivata/copil

//Manager is a Angajat (done)
//Manager has a Angajat (1-M)(to do)
//Design pattern Composite (modeleaza o arborescenta)
class Manager :public Angajat {
	//campuri specifice unui Manager
	int nrSubordonati = 0;

public:
	Manager() {
	}

	Manager(string _nume, float _salariuBaza, int _nrSubordonati) :Angajat(_nume, _salariuBaza) {
		this->nrSubordonati = _nrSubordonati;
	}

	Manager(Angajat a, int _nrSubordonati) :Angajat(a) {
		this->nrSubordonati = _nrSubordonati;
	}

	Manager(const Manager& m) :Angajat(m) {
		this->nrSubordonati = m.nrSubordonati;
	}

	Manager& operator=(const Manager& m) {
		if (this != &m) {
			this->Angajat::operator=(m);//upcast
			this->nrSubordonati = m.nrSubordonati;
		}
		return *this;
	}

	~Manager() {
	}

	friend ostream& operator<<(ostream& out, const Manager& m);
};

ostream& operator<<(ostream& out, const Manager& m) {
	out << (Angajat)m;
	out << "\nNr subordonati: " << m.nrSubordonati;
	return out;
}

//home: istream vreau pentru Angajat si Manager

int main() {
	Angajat a1("Gigel", 1200);
	Angajat a2("Costel", 1500);
	
	return 0;
}