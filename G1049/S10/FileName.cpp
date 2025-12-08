#include<iostream>
using namespace std;


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

//reutilizare de cod
//clasa CadruDidactic ->clasa copil/derivata
//clasa Angajat ->clasa baza/parinte

class Angajat_Extins :public Angajat {
	//versiune de implementare "in doi pasi"
	long cnp;
	int nrPersoaneIntretinere;
};

enum Grad {
	ASIST, LECT, CONF, PROF
};

ostream& operator<<(ostream& out, Grad g) {
	switch (g) {
	case 0:
		out << "Asist";
		break;
	case 1:
		out << "Lect";
		break;
	case 2:
		out << "Conf";
		break;
	case 3:
		out << "Prof";
		break;
	}
	return out;
}

class CadruDidactic:public Angajat {
	//acele campuri specifice doar unui cadru didactic
	Grad grad = Grad::ASIST;
	string specializare="-";

public:
	CadruDidactic() {
		cout << "\nApel constructor fara param CadruDidactic";
	}

	CadruDidactic(string _nume, float _salariuBaza, Grad _grad, string _specializare): Angajat(_nume,_salariuBaza){
		cout << "\nApel constructor cu param CadruDidactic";
		this->grad = _grad;
		this->specializare = _specializare;
	}

	//upcast
	CadruDidactic(const CadruDidactic& c):Angajat(c) {
		cout << "\nApel constructor copiere CadruDidactic";
		this->grad = c.grad;
		this->specializare = c.specializare;
	}

	//downcast
	CadruDidactic(Angajat a):Angajat(a) {
		cout << "\nApel constructor CadruDidactic cu rol de downcast";
	}

	CadruDidactic& operator=(const CadruDidactic& c) {
		cout << "\nApel op= CadruDidactic";
		if (this != &c) {
			this->Angajat::operator=(c);
			this->grad = c.grad;
			this->specializare = c.specializare;
		}
		return *this;
	}

	~CadruDidactic() {
		cout << "\nApel destructor CadruDidactic";
	}

	friend ostream& operator<<(ostream& out, const CadruDidactic& c);
	friend istream& operator>>(istream& in, CadruDidactic& c);
};

istream& operator>>(istream& in, CadruDidactic& c) {
	in >> (Angajat&)c;//upcast explicit prin referinta
	cout << "Introduceti grad: ";
	//in >> c.grad;//istream pentru Grad
	int x;
	in >> x;
	c.grad = (Grad)x;
	cout << "Introduceti specializare: ";
	in >> c.specializare;
	return in;
}

ostream& operator<<(ostream& out, const CadruDidactic& c) {
	out << (Angajat)c;//upcast explicit prin valoare formeaza o copie care ulterior este distrusa
	out << "\nGrad: " << c.grad;
	out << "\nSpecializare: " << c.specializare;
	return out;
}

//HOME 1
//Manager is a Angajat
//Manager has a Angajat (1-M) (se pot stoca obiecte dar mai okai pointeri) (Design pattern Composite) ->modelare ierahica
class Manager {

};

int main() {
	CadruDidactic cd1;
	CadruDidactic cd2("Gigel", 1200, Grad::ASIST, "Economic");
	CadruDidactic cd3(cd2);
	cd1 = cd3;
	cout << cd1;
	cin >> cd1;
	cout << cd1;
	return 0;
}