#include<iostream>
using namespace std;

//citire si afisare de enum folosind ostream si istream

class Angajat {

protected:
	string nume = "Anonim";
	float salariuBaza = 0;

public:
	//to do home: unde ne impacteaza daca putem explicit la nivel de constructor?
	explicit Angajat() {
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

ostream& operator<<(ostream& out, const Angajat& a) {
	out << "\nNume: " << a.nume;
	out << "\nSalariu baza: " << a.salariuBaza;
	return out;
}

istream& operator>>(istream& in, Angajat& a) {
	cout << "\nIntroduceti nume: ";
	in >> a.nume;
	cout << "Introduceti salariu baza: ";
	in >> a.salariuBaza;
	return in;
}

//relatia de tipul is a
//relatia de derivare/mostenire

//clasa de baza/parinte ->Angajat
//clasa derivata/copil ->Manager

//Design pattern Composite (structura ierarhica/ de tip arborescent)
//Manager is a Angajat
//Manager has a Angajat
class Manager:public Angajat {
	int nrSubordonati = 0;
	//Angajat* listaSubordonati = nullptr;

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

	Manager(const Manager& m):Angajat(m) {//conceptul de upcast
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

	bool operator==(const Manager& m) const{
		return (Angajat)*this==(Angajat)m && this->nrSubordonati == m.nrSubordonati;
		//return this->Angajat::operator==(m) && this->nrSubordonati == m.nrSubordonati;
	}

	friend ostream& operator<<(ostream& out, const Manager& m);
	friend istream& operator>>(istream& in, Manager& m);
};

ostream& operator<<(ostream& out, const Manager& m) {
	out << (Angajat)m;//upcast explicit
	out << "\nNr subordonati: " << m.nrSubordonati;
	return out;
}

istream& operator>>(istream& in, Manager& m) {
	in >> (Angajat&)m;//upcast prin referinta (care NU face apel de constructor de copiere)
	cout << "\nIntroduceti nr subordonati: ";
	in >> m.nrSubordonati;
	return in;
}

class AngajatExtins :Angajat {
	//acele campuri noi care au aparut dat fiind modificari in specificatii
};

int main() {
	Manager m1;
	Manager m2("Gigel", 1200, 3);
	Manager m3(m2);
	cout << "\n-----------------------------";
	Angajat a("Costel", 1500);
	Manager m4(a, 2);
	cout << "\n-----------------------------";
	Manager m5(Angajat("Maria", 1234), 4);
	cout << "\n-----------------------------";
	m1 = m4;
	cout << "\n--------------<<--------------";
	cout << m1;
	cout << "\n--------------<<--------------";
	cin >> m1;
	cout << m1;

	if (m1 == m2)
		cout << "\nObj de tip manager au acelasi nume si nr de subordonati";
	else
		cout << "\nInvers";
	return 0;
}