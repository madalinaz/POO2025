#include<iostream>
using namespace std;

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

class Manager :public Angajat {
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

class Paznic :public Angajat {
	int nrZileNoapte = 0;
	static float sporNoapte;

public:
	Paznic() {
	}

	Paznic(string _nume, float _salariuBaza, int _nrZileNoapte) :Angajat(_nume, _salariuBaza) {
		this->nrZileNoapte = _nrZileNoapte;
	}

	Paznic(const Paznic& p) :Angajat(p) {
		this->nrZileNoapte = p.nrZileNoapte;
	}

	Paznic& operator=(const Paznic& p) {
		if (this != &p) {
			this->Angajat::operator=(p);//upcast
			this->nrZileNoapte = p.nrZileNoapte;
		}
		return *this;
	}

	~Paznic() {
	}

	friend ostream& operator<<(ostream& out, const Paznic& p);
};

ostream& operator<<(ostream& out, const Paznic& p) {
	out << (Angajat)p;
	out << "\nNr zile noapte: " << p.nrZileNoapte;
	return out;
}

float Paznic::sporNoapte = 0.2;

int main() {
	Angajat a1("Gigel", 1200);
	Angajat a2("Costel", 1500);

	//depend upon the abstract, not upon the concret
	//meth virtuale
	//meth virtuale pure
	//clase abstracte; interfete

	
	return 0;
}