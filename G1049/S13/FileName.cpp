#include<iostream>
using namespace std;

//functie + clasa template/sablon
//reutilizare de cod/implementa o "interfata"/layer intermediar de comunicare cu cod deja existent

//o clasa care sa faciliteze lucrul cu vectori de obiecte/int
//partea de populare cu noi valori, sortare, adunare/agregare, ...
class Colectie {
	int v[100];
	int nr = 0;

public:
	//NU implementam constructori

	void populare(int x) {

	}


};

class Angajat {
	string nume = "";
	float salariu = 0;

public:
	Angajat(string _nume, float _salariu) {
		this->nume = _nume;
		this->salariu = _salariu;
	}

	friend ostream& operator<<(ostream& out, const Angajat& a) {
		out << "\nNume: " << a.nume << ", salariu: " << a.salariu;
		return out;
	}
};

int main() {

	return 0;
}