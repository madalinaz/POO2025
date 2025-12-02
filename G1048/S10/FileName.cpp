#include<iostream>
using namespace std;

//afisare prin ostream de enum
//citire prin istream de enum

class Angajat {

protected:
	string nume = "Anonim";
	float salariuBaza = 0;

public:
	Angajat() {
		cout << "\nApel constructor fara param Angajat";
	}

	Angajat(string _nume, float _salariuBaza) {
		cout << "\nApel constructor cu param Angajat";
		this->nume = _nume;
		this->salariuBaza = _salariuBaza;
	}

	Angajat(const Angajat& a) {
		cout << "\nApel constructor copiere Angajat";
		this->nume = a.nume;
		this->salariuBaza = a.salariuBaza;
	}

	Angajat& operator=(const Angajat& a) {
		cout << "\nApel operator= Angajat";
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

	bool operator==(const Angajat& a)const {
		return this->nume == a.nume;
	}

	~Angajat() {
		cout << "\nApel destructor Angajat";
	}
};

ostream& operator<<(ostream& out, const Angajat& a) {
	out << "\nNume: " << a.nume;
	out << "\nSalariu baza: " << a.salariuBaza;
	return out;
}

//clasa derivata/copil ->Manager
//clasa baza/parinte ->Angajat

//DP Composite -> modeleaza o ierahizare folosind un arbore
//Manager is a Angajat, dar Manager has a lista de subAngajati

class Manager:public Angajat {
	int nrSubordonati=0;
	//Angajat* listaSubordonati = nullptr;
	static float sporPerAngajat;

public:
	Manager() {
		cout << "\nApel constructor fara param Manager";
	}

	Manager(string _nume, float _salariuBaza, int _nrSubordonati):Angajat(_nume,_salariuBaza) {
		cout << "\nApel constructor cu param Manager";
		this->nrSubordonati = _nrSubordonati;
	}

	//upcast: orice Manager este un Angajat
	Manager(const Manager& m):Angajat(m) {
		cout << "\nApel constructor copiere Manager";
		this->nrSubordonati = m.nrSubordonati;
	}

	Manager& operator=(const Manager& m) {
		cout << "\nApel operator= Manager";
		if (this != &m) {
			Angajat::operator=(m);//upcast de la Manager la Angajat
			this->nrSubordonati = m.nrSubordonati;
		}
		return *this;
	}

	~Manager() {
		cout << "\nApel destructor Manager";
	}

	friend ostream& operator<<(ostream& out, const Manager& m);

	bool operator==(const Manager& m) const{
		return this->nrSubordonati == m.nrSubordonati && (Angajat)*this == (Angajat)m;
		//Angajat::operator==(m);
	}
};

ostream& operator<<(ostream& out, const Manager& m) {
	out << (Angajat&)m;//explicit cer upcast
	out << "\nNr subordonati: " << m.nrSubordonati;
	return out;
}

float Manager::sporPerAngajat = 100;

int main() {
	Manager m1;
	Manager m2("Gigel", 1200, 3);
	Manager m3(m2);
	//Manager m4("Costel", 1500, 2);
	m2 = m1;
	cout << "\n------------------";
	cout << m3;
	cout << "\n------------------";
	if (m1 == m2)
		cout << "\nCele 2 obj de tip Manager au acelasi nume si nr de subordonati";
	else
		cout << "\nInvers";
	return 0;
}