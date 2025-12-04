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

};

ostream& operator<<(ostream& out, const Angajat& a) {
	out << "\nNume: " << a.nume;
	out << "\nSalariu baza: " << a.salariuBaza;
	return out;
}

enum Grad {
	ASIST, LECT, CONF, PROF
};

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
};

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
	return 0;
}
