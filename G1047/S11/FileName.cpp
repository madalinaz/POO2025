#include<iostream>
using namespace std;

//DACA CLASA ANGAJAT ARE O METH VIRTUALA PURA, CUM PUTEM SA INTEGRAM OSTREAM SI SA PUTEM AFISA INTR-O MANIERA PARTEA COMUNA A OBIECTELOR DERIVATE DIN CLASA ANGAJAT
//HINT DIN JAVA: TOSTRING()

class Om {
public:
	void afisare() {
		cout << "\nAcesta este un om!";
	}
};

class Angajat:public Om {

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

	virtual float calculSalariu() {
		//pp ca exista o tehnica complexa de calcul salariu
		return this->salariuBaza;
	}

	//virtual int getNrZileConcediu() = 0;//meth virtuala pura

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

	float calculSalariu() {
		return Angajat::calculSalariu() + this->nrSubordonati * 100;
	}

	friend ostream& operator<<(ostream& out, const Manager& m);
};

class Paznic :public Angajat {
	int nrNoptiLucrate=0;
	static float sporNoapte;

public:
	Paznic(string _nume, float _salariuBaza, int _nrNoptiLucrate) :Angajat(_nume, _salariuBaza) {
		this->nrNoptiLucrate = _nrNoptiLucrate;
	}

	friend ostream& operator<<(ostream& out, const Paznic& m);

	float calculSalariu() override{
		return Angajat::calculSalariu() + this->nrNoptiLucrate * (1 + Paznic::sporNoapte) * this->salariuBaza / 20;
	}

	void altaMetodaPaznic() {

	}
};

float Paznic::sporNoapte = 0.2;

ostream& operator<<(ostream& out, const Paznic& m) {
	out << (Angajat)m;
	out << "\nNr nopti lucrate: " << m.nrNoptiLucrate;
	return out;
}

ostream& operator<<(ostream& out, const Manager& m) {
	out << (Angajat)m;
	out << "\nNr subordonati: " << m.nrSubordonati;
	return out;
}

int main() {
	Angajat a1("Angajat Gigel", 1000);
	Manager m1("Manager Gigel", 1000, 10);
	Paznic p1("Paznic Gigel", 1000, 4);
	cout << "\n------CALCUL SALARII PE OBIECTE-----";
	cout << "\nSalariu angajat: " << a1.calculSalariu();
	cout << "\nSalariu manager: " << m1.calculSalariu();
	cout << "\nSalariu paznic: " << p1.calculSalariu();

	//fondul de salarii pentru toti angajatii
	Angajat v[] = { a1,m1,p1 };
	float totalSalarii = 0;
	for (int i = 0; i < 3; i++) {
		totalSalarii += v[i].calculSalariu();
	}
	cout << "\nTotal salarii folosind vector obiecte: " << totalSalarii;

	Angajat* vp[] = { &a1,&m1,&p1 };
	float totalSalarii2 = 0;
	for (int i = 0; i < 3; i++) {
		totalSalarii2 += vp[i]->calculSalariu();
	}
	cout << "\nTotal salarii folosind vector pointeri: " << totalSalarii2;

	Om vo[] = {Om(), Om()};
	vo[0].afisare();


	return 0;
}