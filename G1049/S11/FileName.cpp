#include<iostream>
using namespace std;

//IMPLEMENTARE CARE PERMITE EXTINDEREA IN TIMP
//clasa tip interfata ->clasa abstracta care are doar metode virtuale pure
//interfata = contract semnat de toate clasele derivate interfetei si care doresc sa instantieze obj de tipul lor
class IPayable {
	virtual float calculSalariu() = 0;
};

class IShowable {
	virtual void afisare() = 0;
};

class Angajat:public IPayable, public IShowable{

protected:
	string nume = "Anonim";
	float salariuBaza = 0;

public:
	void afisare() override{
		cout << "\nAcesta este un angajat";
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
	int nrSubordonati;
	bool areMBA;

public:
	Manager(string _nume, float _salariuBaza, int _nrSubordonati, bool _areMBA):Angajat(_nume,_salariuBaza) {
		this->nrSubordonati = _nrSubordonati;
		this->areMBA = _areMBA;
	}

	friend ostream& operator<<(ostream& out, const Manager& m);

	float calculSalariu() {
		return Angajat::calculSalariu() + this->nrSubordonati * 100 + this->areMBA * 1000;
	}
};

ostream& operator<<(ostream& out, const Manager& m) {
	out << (Angajat)m;
	out << "\nNr subordonati: " << m.nrSubordonati;
	out << "\nAre MBA? " << m.areMBA;
	return out;
}

class Lucrator :public Angajat {
	int nrOreSuplimentare;

public:
	Lucrator(string _nume, float _salariuBaza, int _nrOreSuplimentare) :Angajat(_nume, _salariuBaza) {
		this->nrOreSuplimentare = _nrOreSuplimentare;
	}

	friend ostream& operator<<(ostream& out, const Lucrator& l);

	float calculSalariu() {
		return Angajat::calculSalariu() + this->nrOreSuplimentare * 20;
	}

	void altaMethLucrator() {
		//to do
	}
};

ostream& operator<<(ostream& out, const Lucrator& l) {
	out << (Angajat)l;
	out << "\nNr ore suplimentare: " << l.nrOreSuplimentare;
	return out;
}

int main() {
	Angajat a1("Gigel angajatul", 1000);
	Manager m1("Gigel managerul", 1000, 10, true);
	Lucrator l1("Gigel lucratorul", 1000, 20);
	cout << a1.calculSalariu();
	cout << endl << m1.calculSalariu();
	cout << endl << l1.calculSalariu();

	//vrem sa stocam agregat toti angajatii companiei astfel incat sa putem calcula fondul necesar de salarii
	Angajat v[3];
	v[0] = a1;
	v[1] = m1; //upcast
	v[2] = l1; //upcast
	float totalSalarii = 0;
	for (int i = 0; i < 3; i++) {
		totalSalarii += v[i].calculSalariu();
	}
	cout << "\nTotal salarii folosind obiecte: " << totalSalarii;
	
	//VIRTUALIZAREA FUNCTIONEAZA DOAR PE POINTERI
	Angajat* vp[3];
	vp[0] = &a1;
	vp[1] = &m1;
	vp[2] = &l1; //NU mai facem upcast pe obiecte, deci obiectele noastre nu se mai reduc la clasa de baza
	float totalSalarii2 = 0;
	for (int i = 0; i < 3; i++) {
		totalSalarii2 += vp[i]->calculSalariu();
	}
	cout << "\nTotal salarii folosind pointeri: " << totalSalarii2;
	return 0;
}

