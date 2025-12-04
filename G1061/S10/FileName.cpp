#include<iostream>
using namespace std;

//afisare+citire obj de tip enum folosind ostream si istream(HOME)

class Angajat {

protected:
	string nume = "Anonim";
	float salariuBaza = 0;

public:
	Angajat() {
		cout << "\nApel constructor fara param Angajat";
	}

	explicit Angajat(string _nume) {
		this->nume = _nume;
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

	bool operator!() {
		return this->salariuBaza == 0;
	}

	//cast la string
	operator string () {
		return this->nume;
	}

	//cast la double
	explicit operator double() {
		return this->salariuBaza;
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

//Liskov substitution
//relatia de tipul is-a
//mostenire/derivare
//clasa Angajat ->clasa parinte/baza
//clasa Manager ->clasa derivata/copil

//Manager is a Angajat (done)
//Manager has a Angajat (1-M)(to do)
//Design pattern Composite (modeleaza o arborescenta)
class Manager:public Angajat {
	//campuri specifice unui Manager
	int nrSubordonati = 0;

public:
	Manager() {
		cout << "\nApel constructor fara param Manager";
	}

	Manager(string _nume, float _salariuBaza, int _nrSubordonati):Angajat(_nume,_salariuBaza) {
		cout << "\nApel constructor cu param Manager";
		this->nrSubordonati = _nrSubordonati;
	}

	Manager(Angajat a, int _nrSubordonati):Angajat(a) {
		cout << "\nApel constructor cu param 2 Manager";
		this->nrSubordonati = _nrSubordonati;
	}

	Manager(const Manager& m):Angajat(m) {//constructor de copiere, folosind upcast
		cout << "\nApel constructor copiere Manager";
		this->nrSubordonati = m.nrSubordonati;
	}

	Manager& operator=(const Manager& m) {
		cout << "\nApel operator= Manager";
		if (this != &m) {
			this->Angajat::operator=(m);//upcast
			this->nrSubordonati = m.nrSubordonati;
		}
		return *this;
	}

	~Manager() {
		cout << "\nApel destructor Manager";
	}

	friend ostream& operator<<(ostream& out, const Manager& m);
};

ostream& operator<<(ostream& out, const Manager& m) {
	out << (Angajat)m;//upcast explicit prin valoare returneaza o copie care ulterior este distrusa
	out << "\nNr subordonati: " << m.nrSubordonati;
	return out;
}

//home: istream vreau pentru Angajat si Manager

class Angajat_extins : public Angajat {

};

int main() {
	Angajat a1("Gigel", 1200);
	Angajat a2("Costel", 1500);
	cout << "\n---------- operator ! ----------";
	if (!a1)
		cout << "\nAngajatul a1 nu are salariu";
	else
		cout << "\nAngajatul a1 are salariul >0";

	cout << "\n---------- operator cast/conversie ----------";
	string nume = a1;//conversie implicita
	cout << "\nNume folosind cast la string: " << nume;
	double salariu = (double)a1;//cast explicit
	cout << "\nSalariul folosind cast la double: " << salariu;
	//to do toString din java folosind cast la string
//	if (a1 != 1500)
//		cout << "\nA1 are salariu diferit de 1500";
	string nume2 = "Maria";
	//a1 = nume2;//a1 devine un angajat cu numele Maria si salariul 0
	//cast de la string la Angajat

	cout << "\n|||||||||||||||MOSTENIRI|||||||||||||||";
	Manager m1;
	Manager m2("Costelus", 1234, 5);
	return 0;
}
