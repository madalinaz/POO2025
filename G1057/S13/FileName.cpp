#include<iostream>
using namespace std;


template<class T>
T suma(T a, T b) {
	return a + b;
}

//relatie has a
template<class T>
class Colectie {
	T v[10];
	int nr=0;

public:
	Colectie& operator+=(T _x) {
		this->v[this->nr++] = _x;
		return *this;
	}

	//cast la T
	operator T() const{
		T suma = 0;
		for (int i = 0; i < this->nr; i++) {
			suma += this->v[i];
		}
		return suma;
	}

	friend ostream& operator<<(ostream& out, const Colectie& c) {
		out << "\nNr elemente: " << c.nr;
		out << "\nElemente: ";
		for (int i = 0; i < c.nr; i++) {
			out << c.v[i] << endl;
		}
		return out;
	}
};

class Angajat {
	string nume = "";
	float salariu = 0;

public:
	Angajat() {

	}

	Angajat(string _nume, float _salariu) {
		this->nume = _nume;
		this->salariu = _salariu;
	}

	Angajat operator+(const Angajat& a) const{
		Angajat rez = *this;
		rez.nume += a.nume;
		rez.salariu += a.salariu;
		return rez;
	}

	friend ostream& operator<<(ostream& out, const Angajat& a); 
};

ostream& operator<<(ostream& out, const Angajat& a){
	out << "\nNume: " << a.nume << ", salariu: " << a.salariu;
	return out;
}


int main() {
	//clase + functii template ->sablon
	//STL

	int rezInt = suma<int>(2, 5);
	cout << rezInt << endl;

	Angajat a1("Gigel", 100), a2("Costel", 200);
	Angajat a3("Anonim", 0);
	a3 = suma<Angajat>(a1, a2);
	cout << a3;

	Colectie<int> cInt;
	cInt += 10;
	cInt += 20;
	cout << cInt;

	Colectie<Angajat> cAng;
	
	return 0;
}