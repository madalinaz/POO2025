#include<iostream>
using namespace std;

class Grupa {

};

//Serie has a colectie de grupe
class Serie1 {
	Grupa lista[10];//vector alocat static de obj de tip Grupa
	int nrGrupe;
};

class Serie2 {
	Grupa* lista;//vector alocat dinamic de obj de tip Grupa
	int nrGrupe;
};





string generareCNP() {
	return "123456789";
}

class Persoana {
	const string CNP;
	string nume = "-";
	int varsta = 0;

public:

	Persoana() :CNP(generareCNP()) {
		cout << "\nApel constructor fara param Persoana";
	}

	Persoana(string _nume, int _varsta) :CNP(generareCNP()) {
		this->nume = _nume;
		this->varsta = _varsta;
	}

	Persoana(const Persoana& p) : CNP(p.CNP) {
		cout << "\nApel constructor copiere Persoana";
		this->nume = p.nume;
		this->varsta = p.varsta;
	}

	Persoana& operator=(const Persoana& p) {
		cout << "\nApel op= Persoana";
		this->nume = p.nume;
		this->varsta = p.varsta;
		return *this;
	}

	~Persoana() {
		cout << "\nApel destructor Persoana";
	}

	friend ostream& operator<<(ostream& out, const Persoana& p);
};

ostream& operator<<(ostream& out, const Persoana& p) {
	out << "\nCNP: " << p.CNP;
	out << "\nNume: " << p.nume;
	out << "\nVarsta: " << p.varsta;
	return out;
}

int main() {
	Persoana p1;
	cout << p1;
	return 0;
}