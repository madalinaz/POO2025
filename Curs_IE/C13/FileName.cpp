#include<iostream>
using namespace std;

int sumaInt(int v1, int v2) {
	return v1 + v2;
}

//functie sablon/template
template<class T>
T suma(T v1, T v2) {
	return v1 + v2;
}

template<class T1, class T2>
T1 sumaGenerala(T2 v1, T2 v2) {
	return (T1)(v1 + v2);
}

class Angajat {
	string nume;
	float salariu;

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