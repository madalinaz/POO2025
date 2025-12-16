#include<iostream>
using namespace std;

class Baza {
public:
	virtual void afisare() = 0;
};

class Derivata : public Baza {
	void afisare() {
		Baza::afisare();
		cout << "\nSi aici este afisarea din Derivata";
	}
};


//concept de virtualizare DONE
//meth virtuale DONE
//meth virtuale pure ->meth virtuale care NU sunt implementate inca
//clase abstracte ->este o clasa care detine cel putin o meth virtuala pura
//interfete ->clasa care contine doar meth virtuale pure = Contract

class IPlatibil {
	virtual float calculSalariu() = 0;
};

class IAfisabil {
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

	float calculSalariu() {
		return this->Angajat::calculSalariu() + this->nrSubordonati * 100;
	}

	friend ostream& operator<<(ostream& out, const Manager& m);
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
		return this->Angajat::calculSalariu() + this->nrOreSuplimentare * 10;
	}

	friend ostream& operator<<(ostream& out, const Lucrator& m);
};

ostream& operator<<(ostream& out, const Lucrator& m) {
	out << (Angajat)m;//upcast prin valoare explicit
	out << "\nNr ore suplimentare: " << m.nrOreSuplimentare;
	return out;
}

int main() {
	Angajat a1("Angajat Gigel", 1000);
	Manager m1("Manager Costel", 1000, 10);
	Lucrator l1("Lucrator Marcel", 1000, 25);
	cout << "\nCalcul salariu angajat: " << a1.calculSalariu();
	cout << "\nCalcul salariu manager: " << m1.calculSalariu();
	cout << "\nCalcul salariu lucrator: " << l1.calculSalariu();

	//este o implementare cu concept de extindere in timp
	// //Open-Closed P ->opened for extensions, closed for modifications
	//venim cu nivelul de Companie -> HOME: clasa Companie in relatie de has a cu Angajat
	Angajat v[] = { a1,m1,l1 };//upcast
	float totalSalarii = 0;
	for (int i = 0; i < 3; i++) {
		totalSalarii += v[i].calculSalariu();
	}
	cout << "\nTotal salarii folosind vector de obiecte: " << totalSalarii;

	Angajat* vp[] = { &a1,&m1,&l1 };//shallow copy?
	float totalSalarii2 = 0;
	for (int i = 0; i < 3; i++) {
		totalSalarii2 += vp[i]->calculSalariu();
	}
	cout << "\nTotal salarii folosind vector de pointeri: " << totalSalarii2;

	//HOME: de "virtualizat afisare"
	//de gandit si contextul java a lui toString()
	cout << "\nAfisare obiecte plecand de la vector de pointeri: ";
	for (int i = 0; i < 3; i++) {
		cout << *vp[i] << endl;
	}

	cout << "\n---------------------";
	//Baza* b = new Derivata();
	//b->afisare();
	return 0;
}