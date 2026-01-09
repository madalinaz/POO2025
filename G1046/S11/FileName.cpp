#include<iostream>
#include<vector>
using namespace std;

class IAfisabil {
public:
	virtual void afisare() = 0;
};

class IPlatibil {
	virtual float calculSalariu() = 0;
};

class Angajat //:public IAfisabil, public IPlatibil 
{
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

	//virtual float methVirtualaPura() = 0;

	virtual float calculSalariu() {
		//pp ca exista o regula complexa de calcul salariu
		return this->salariuBaza;
	}

	virtual ~Angajat() {
		cout << "\nApel destructor Angajat";
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
	Manager(string _nume, float _salariuBaza, int _nrSubordonati) :Angajat(_nume, _salariuBaza) {
		this->nrSubordonati = _nrSubordonati;
	}

	float calculSalariu() {
		return Angajat::calculSalariu() + this->nrSubordonati * 100;
	}

	friend ostream& operator<<(ostream& out, const Manager& m);

	~Manager() {
		cout << "\nApel destructor Manager";
	}
};

ostream& operator<<(ostream& out, const Manager& m) {
	out << (Angajat)m;//upcast prin valoare explicit
	out << "\nNr subordonati: " << m.nrSubordonati;
	return out;
}

class Lucrator :public Angajat {
	int nrOreSuplimentare = 0;

public:
	Lucrator(string _nume, float _salariuBaza, int _nrOreSuplimentare) :Angajat(_nume, _salariuBaza) {
		this->nrOreSuplimentare = _nrOreSuplimentare;
	}

	float calculSalariu() {
		return Angajat::calculSalariu() + this->nrOreSuplimentare * 10;
	}

	friend ostream& operator<<(ostream& out, const Lucrator& m);

	~Lucrator() {
		cout << "\nApel destructor Lucrator";
	}
};

ostream& operator<<(ostream& out, const Lucrator& m) {
	out << (Angajat)m;//upcast prin valoare explicit
	out << "\nNr ore suplimentare: " << m.nrOreSuplimentare;
	return out;
}

/*
int main() {
	Angajat a1("Angajat Gigel", 1000);
	Manager m1("Manager Costel", 1000, 10);
	Lucrator l1("Lucrator Marcel", 1000, 25);
	
	cout << "\nSalariu angajat: " << a1.calculSalariu();
	cout << "\nSalariu manager: " << m1.calculSalariu();
	cout << "\nSalariu lucrator: " << l1.calculSalariu();

	//Compania care detine angajati care pot fi de tipul: Angajat, Manager, Lucrator
	//sa se afiseze totalul salariilor tuturor angajatilor
	Angajat lista[] = { a1,m1,l1 };
	double total = 0;
	for (int i = 0; i < 3; i++) {
		total += lista[i].calculSalariu();
	}
	cout << "\nTotal salarii: " << total;

	Angajat* listaP[] = { &a1,&m1,&l1 };
	double total2 = 0;
	for (int i = 0; i < 3; i++) {
		total2 += listaP[i]->calculSalariu();
	}
	cout << "\nTotal salarii2: " << total2;

	cout << "\n----------------------";
	Angajat a2 = a1;
	a2 = m1;//upcast pe obiecte
	Angajat* pa2 = &a1;
	pa2 = &m1; //upcast pe adrese

	vector<Angajat*>v;
	v.push_back(&m1);
	v.push_back(&l1);
	return 0;
}
*/

int main() {
	Angajat a1("Angajat Gigel", 1000);
	Manager m1("Manager Costel", 1000, 10);
	Lucrator l1("Lucrator Marcel", 1000, 25);

	//a1 = m1;
	Angajat* pa;

	pa = new Angajat("Angajat Gigel", 1000);
	delete pa;
	pa = new Manager("Manager Costel", 1000, 10);
	delete pa;
	cout << "\nDupa delete";
	return 0;
}