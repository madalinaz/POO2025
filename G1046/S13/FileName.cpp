#include<iostream>
using namespace std;

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

//clasa Concediu ->campuri la alegere

//colectie/relatie has a; clasa template
//o clasa care sa retina informatii pentru fiecare Angajat, o colectie de elemente generice (acea colectie/vector/lista -> un set de sporuri/ un set de concedii/.....)

//ColectieAngajati has a Angajat
class ColectieAngajati {

};

int main() {

	return 0;
}