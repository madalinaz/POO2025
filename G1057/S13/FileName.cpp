#include<iostream>
using namespace std;

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

	friend ostream& operator<<(ostream& out, const Angajat& a) {
		out << "\nNume: " << a.nume << ", salariu: " << a.salariu;
		return out;
	}
};


int main() {
	//clase template
	//STL
	return 0;
}