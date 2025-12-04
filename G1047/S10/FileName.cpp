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

istream& operator>>(istream& in, Angajat& a) {
	cout << "\nIntroduceti nume: ";
	in >> a.nume;
	cout << "Introduceti salariu: ";
	in >> a.salariuBaza;
	return in;
}

ostream& operator<<(ostream& out, const Angajat& a) {
	out << "\nNume: " << a.nume;
	out << "\nSalariu baza: " << a.salariuBaza;
	return out;
}

enum Grad {
	ASIST, LECT, CONF, PROF
};

//clasa Manager care este in relatie de is a si has a cu clasa Angajat (Design pattern Composite->modelare ierarhica)

//CadruDidactic is a Angajat
//mostenire/derivare/specializare
class CadruDidactic:public Angajat {
	Grad gradDidactic=Grad::ASIST;

public:
	CadruDidactic() {
		cout << "\nApel constructor fara param CadruDidactic";
	}

	CadruDidactic(string _nume, float _salariuBaza, Grad _gradDidactic):Angajat(_nume,_salariuBaza) {
		cout << "\nApel constructor cu toti param CadruDidactic";
		this->gradDidactic = _gradDidactic;
	}

	CadruDidactic(const Angajat& a, Grad _gradDidactic):Angajat(a) {
		cout << "\nApel constructor cu toti param 2 CadruDidactic";
		this->gradDidactic = _gradDidactic;
	}

	CadruDidactic(const Angajat& a) :Angajat(a) {
		cout << "\nApel constructor cu param 3 CadruDidactic";
		//cat de poate, un fel de DownCast
	}

	CadruDidactic(const CadruDidactic& cd):Angajat(cd)//upcast implicit->NU construieste copii
	{
		cout << "\nApel constructor copiere CadruDidactic";
		this->gradDidactic = cd.gradDidactic;
	}

	CadruDidactic& operator=(const CadruDidactic& cd) {
		cout << "\nApel op= CadruDidactic";
		if (this != &cd) {
			Angajat::operator=(cd);
			this->gradDidactic = cd.gradDidactic;
		}
		return *this;
	}

	~CadruDidactic() {
		cout << "\nApel destructor CadruDidactic";
	}

	bool operator==(const CadruDidactic& cd) {
		return this->Angajat::operator==(cd) 
			&& this->gradDidactic == cd.gradDidactic;
	}

	friend ostream& operator<<(ostream& out, const CadruDidactic& cd);

	friend istream& operator>>(istream& in, CadruDidactic& cd);
};

ostream& operator<<(ostream& out, Grad grad) {
	//if (grad == 0)
	//	out << "Asistent";

	switch (grad) {
	case 0:
		out << "Asistent";
		break;
	case 1:
		out << "Lector";
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

ostream& operator<<(ostream& out, const CadruDidactic& cd) {
	out << (Angajat)cd;//upcast explicit(upcast prin valoar        ->returneaza o copie pe baza copy constructor din Angajat)
	out << "\nGrad didactic: " << cd.gradDidactic;
	return out;
}

istream& operator>>(istream& in, CadruDidactic& cd) {
	in >> (Angajat&)cd;
	cout << "\nIntroduceti grad didactic: ";
	int aux;
	in >> aux;
	cd.gradDidactic = (Grad)aux;
	return in;
}

void afisareSeparator(string mesaj) {
	cout << "\n------------------- ";
	cout << mesaj;
	cout << " -----------";
}

int main() {
	CadruDidactic cd1;
	CadruDidactic cd2("Gigel", 1200, Grad::CONF);
	CadruDidactic cd3(Angajat("Costel", 1500), Grad::CONF);
	Angajat a("Maria", 1234);
	CadruDidactic cd4 = a;//DownCast(merge doar pentru ca am adaugat acel constructor in clasa CadruDidactic)
	Angajat a2 = cd1;//Upcast(implicit disponibil)
	afisareSeparator("constructor copiere");
	CadruDidactic cd5 = cd4;
	afisareSeparator("constructor copiere");
	cd1 = cd4;
	cout << cd1;
	afisareSeparator("<<");
	cout << cd1;
	afisareSeparator("<<");

	//V1
	if (cd1 == cd2)
		cout << "\nCadrele didactice au acelasi nume si grad";

	//V2
	if (cd1 == cd2)
		cout << "\nCadrele didactice au acelasi salariu si grad";

	//V3
	if (cd1 == cd2)
		cout << "\nCadrele didactice au acelasi grad";

	//V4
	if (cd1 == cd2)
		cout << "\nCadrele didactice au acelasi nume";
	return 0;
}
