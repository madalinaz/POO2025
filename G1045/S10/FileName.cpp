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

	friend istream& operator>>(istream& in, Angajat& a);
};

istream& operator>>(istream& in, Angajat& a) {
	cout << "\nIntroduceti nume: ";
	in >> a.nume;
	cout << "Introduceti salariu baza: ";
	in >> a.salariuBaza;
	return in;
}

ostream& operator<<(ostream& out, const Angajat& a) {
	out << "\nNume: " << a.nume;
	out << "\nSalariu baza: " << a.salariuBaza;
	return out;
}

//am creat o arborescenta -> DP Composite
//Manager is a Angajat
//Manager has a Angajat (home)
class Manager: public Angajat {
	int nrSubordonati = 0;
	static float bonusPerSubordonat;

public:
	Manager() {
		cout << "\nApel const fara param Manager";
	}

	Manager(string _nume, float _salariuBaza, int _nrSubordonati):Angajat(_nume,_salariuBaza) {
		cout << "\nApel const cu param Manager";
		this->nrSubordonati = _nrSubordonati;
	}

	Manager(Angajat a, int _nrSubordonati):Angajat(a) {
		cout << "\nApel const cu param 2 Manager";
		this->nrSubordonati = _nrSubordonati;
	}

	//upcast de la copil la parinte, de la derivat la baza, de la Manager la Angajat
	Manager(const Manager& m):Angajat(m) {
		cout << "\nApel const copiere Manager";
		this->nrSubordonati = m.nrSubordonati;
	}

	Manager& operator=(const Manager& m) {
		cout << "\nApel op= Manager";
		if (this != &m) {
			this->Angajat::operator=(m);//al doilea upcast
			this->nrSubordonati = m.nrSubordonati;
		}
		return *this;
	}

	float calculSalariu() {
		float salariuAngajat = Angajat::calculSalariu();
		return salariuAngajat + Manager::bonusPerSubordonat * this->nrSubordonati;
	}

	~Manager() {
		cout << "\nApel destructor Manager";
	}

	friend ostream& operator<<(ostream& out, const Manager& m);

	friend istream& operator>>(istream& in, Manager& m);
};

float Manager::bonusPerSubordonat = 1000;

ostream& operator<<(ostream& out, const Manager& m) {
	out << (Angajat&)m;//primul upcast explicit
	out << "\nNr subordonati: " << m.nrSubordonati;
	return out;
}

istream& operator>>(istream& in, Manager& m) {
	in >> (Angajat&)m;
	cout << "Introduceti nr subordonati: ";
	in >> m.nrSubordonati;
	return in;
}

int main() {
	Manager m1;
	Manager m2("Gigel", 2000, 3);
	Manager m3(Angajat("Costel", 1000), 3);
	Manager m4(m2);
	m1 = m2;
	cout << "\n-----------------";
	cout << m1;
	cout << "\n-----------------";

	Angajat a;
	//cin >> a;
	cout << a;
	cin >> m1;
	cout << m1;
	cout << "\nSalariu lui m1 manager: " << m1.calculSalariu();
	return 0;
}