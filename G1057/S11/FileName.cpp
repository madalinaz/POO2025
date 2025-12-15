#include<iostream>
using namespace std;

//HOME: echivalent toString din java

//meth virtuale DONE
//meth virtuale pure
//clase abstracte ->clasa care contine cel putin o meth virtuala pura
//interfete ->clasa abstracta care contine doar meth virtuale pure

//depend upon the abstract, DO NOT depend upon the concrete
//open-closed principle => many client specific interfaces are better then one general interface

class Printable {

};

class Showable {
public:
	virtual void displayInfo() = 0;
};

class Payable {
public:
	virtual float calculSalariu() = 0;//meth virtuala pura
};

class Angajat:public Payable, public Showable {

protected:
	string nume = "Anonim";
	float salariuBaza = 0;

public:
	void displayInfo() {
		cout << "\nAfisare angajat";
	}

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

	
	virtual float calculSalariu() {
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

class Manager:public Angajat {
	int nrSubordonati = 0;

public:
	Manager(string _nume, float _salariuBaza, int _nrSubordonati) :Angajat(_nume, _salariuBaza) {
		this->nrSubordonati = _nrSubordonati;
	}

	float calculSalariu() {
		//return this->salariuBaza + this->nrSubordonati * 100;
		return Angajat::calculSalariu() + this->nrSubordonati * 100;
	}

	friend ostream& operator<<(ostream& out, const Manager& m);
};

ostream& operator<<(ostream& out, const Manager& m) {
	out << (Angajat&)m;
	out << "\nNr subordonati: " << m.nrSubordonati;
	return out;
}

class Lucrator :public Angajat {
	int nrNoptiLucrate = 0;

public:
	Lucrator(string _nume, float _salariuBaza, int _nrNoptiLucrate) :Angajat(_nume, _salariuBaza) {
		this->nrNoptiLucrate = _nrNoptiLucrate;
	}

	float calculSalariu() override{
		return Angajat::calculSalariu() + this->nrNoptiLucrate * 50;
	}

	friend ostream& operator<<(ostream& out, const Lucrator& m);
};

ostream& operator<<(ostream& out, const Lucrator& m) {
	out << (Angajat&)m;
	out << "\nNr nopti lucrate: " << m.nrNoptiLucrate;
	return out;
}

//clasa Companie in relatie de has a cu Angajat

int main() {
	Angajat a1("Angajatul Gigel", 1000);
	Manager m1("Manager Gigel", 1000, 10);
	Lucrator l1("Lucrator Gigel", 1000, 5);
	cout << "\nSalariu angajat: " << a1.calculSalariu();
	cout << "\nSalariu manager: " << m1.calculSalariu();
	cout << "\nSalariu lucrator: " << l1.calculSalariu();

	//calculam fondul necesar de salarii
	float totalSalarii = 0;
	Angajat v[] = { a1,m1,l1 };//upcast
	for (int i = 0; i < 3; i++)
		totalSalarii += v[i].calculSalariu();
	cout << "\nTotal salarii folosind vector obiecte: " << totalSalarii;

	float totalSalarii2 = 0;
	//Angajat* pointer;
	//pointer = new Manager(m1);
	Angajat* vp[] = { &a1,&m1,&l1 };
	for (int i = 0; i < 3; i++)
		totalSalarii2 += vp[i]->calculSalariu();
	cout << "\nTotal salarii folosind vector pointeri: " << totalSalarii2;

	//HOME 2: de transformat vectorul de pointeri din main in clasa Companie care este in relatie de has a cu familia de clase
	return 0;
}
