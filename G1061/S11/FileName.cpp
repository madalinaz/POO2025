#include<iostream>
using namespace std;

//o clasa cu cel putin o meth virtuala pura => clasa abstracta
//2 metode virtuale pure
//clasa Om, in caz particular, este chiar interfata(clasa abstracta care are doar meth virtuale pure)
//interfata = Contract
class Om {
public:
	virtual void afisare() = 0;
	virtual float calculSalariu() = 0;
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
		return this->salariuBaza;
	}

	void afisare() override{
		cout << "\nAcesta este un angajat";
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

	float calculSalariu() {
		//return this->salariuBaza + this->nrSubordonati * 100;
		return Angajat::calculSalariu() + this->nrSubordonati * 100;
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

	float calculSalariu() {
		return Angajat::calculSalariu() + this->nrZileNoapte * (1+Paznic::sporNoapte) * this->salariuBaza / 20;
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

	//depend upon the abstract, not upon the concrete
	Angajat a1("Angajat Gigel", 1000);
	Manager m1("Manager Gigel", 1000, 10);
	Paznic p1("Paznic Gigel", 1000, 3);
	cout << "\nCalcul salariu angajat: " << a1.calculSalariu();
	cout << "\nCalcul salariu manager: " << m1.calculSalariu();
	cout << "\nCalcul salariu paznic: " << p1.calculSalariu();

	//colectie formata din toti angajatii companiei
	//vreau sa le calculez salariul total de plata la sf de luna

	Angajat v[] = { a1,m1,p1 };
	float totalSalarii = 0;
	for (int i = 0; i < 3; i++) {
		totalSalarii += v[i].calculSalariu();
	}
	cout << "\nTotal salarii has a obiecte: " << totalSalarii;

	Angajat* vp[] = { &a1,&m1,&p1 };
	float totalSalarii2 = 0;
	for (int i = 0; i < 3; i++) {
		totalSalarii2 += vp[i]->calculSalariu();
	}
	cout << "\nTotal salarii has a pointeri: " << totalSalarii2;

	/*Om* vpo[]= { &a1,&m1,&p1 };
	vpo[0]->display();*/
	//meth virtuale
	//meth virtuale pure
	//clase abstracte; interfete

	//Om om;
	Om* pOm;//aici vom pointa catre clase derivate din clasa noastra abstracta care obligatoriu vor avea si o implementare concreta a meth virtuale pure expuse in clasa de baza abstracta
	return 0;
}