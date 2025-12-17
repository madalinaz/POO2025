#include<iostream>
using namespace std;

class A {
public:
	virtual void metoda() = 0;
};

class B :public A {
public:
	void metoda() override {
		A::metoda();
		cout << "\nAici sunt in metoda din clasa derivata";
	}
};

//conceptul de virtualizare = meth virtuala clasa Baza + vector de pointeri de tip clasa de baza + shallow copy
//meth virtuala DONE
//meth virtuala pura DONE
//clasa abstracta -> cel putin o meth virtuala pura
//interfata ->are doar meth virtuale pure = CONTRACT

class IPlatibil {
public:
	virtual float calculSalariu() = 0;
};

class IPrintabil {
public:
	virtual void afisareInfo() = 0;
};

class Angajat:public IPlatibil {

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

	//virtual float calculSalariu() = 0;//meth virtuala pura

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

class Manager :public Angajat {
	int nrSubordonati = 0;

public:
	Manager(string _nume, float _salariuBaza, int _nrSubordonati):Angajat(_nume,_salariuBaza) {
		this->nrSubordonati = _nrSubordonati;
	}

	float calculSalariu() override {
		return Angajat::calculSalariu() + this->nrSubordonati * 100;
	}

	friend ostream& operator<<(ostream& out, const Manager& m);
};

ostream& operator<<(ostream& out, const Manager& m) {
	out << (Angajat)m;//upcast explicit prin valoare
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
};

ostream& operator<<(ostream& out, const Lucrator& m) {
	out << (Angajat)m;//upcast explicit prin valoare
	out << "\nNr ore suplimentare: " << m.nrOreSuplimentare;
	return out;
}

int main() {
	//gestionarea salariilor in cadrul companiei
	Angajat a1("Angajat Gigel", 1000);
	Manager m1("Manager Gigel", 1000, 15);
	Lucrator l1("Lucrator Gigel", 1000, 25);
	cout << "\ncalcul salariu angajat: " << a1.calculSalariu();
	cout << "\ncalcul salariu manager: " << m1.calculSalariu();
	cout << "\ncalcul salariu lucrator: " << l1.calculSalariu();

	//companie
	Angajat v[] = { a1,m1,l1 };//upcast
	float totalSalarii = 0;
	for (int i = 0; i < 3; i++) {
		totalSalarii += v[i].calculSalariu();
	}
	cout << "\nTotal salarii folosind vector obiecte: " << totalSalarii;

	Angajat* vp[] = { &a1,&m1,&l1 };
	float totalSalarii2 = 0;
	for (int i = 0; i < 3; i++) {
		totalSalarii2 += vp[i]->calculSalariu();
	}
	cout << "\nTotal salarii folosind vector pointeri: " << totalSalarii2;
	cout << "\nAfisare informatii salariati: ";
	for (int i = 0; i < 3; i++) {
		cout << *vp[i];
	}

	//HOME: DE GESTIONAT VIRTUALIZAREA AFISARII IN OSTREAM
	//DE VAZUT TOSTRING() DIN JAVA

	//HOME2: DE IMPLEMENTAT CLASA COMPANIE IN RELATIE DE HAS A CU ANGAJAT(VECTOR DE POINTERI LA ANGAJAT) (DEEP VS SHALLOW)
	
	//A* pb = new B();
	A* pb2;
	return 0;
}