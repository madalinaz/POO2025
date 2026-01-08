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

template<class T>
class Container {
	T v[10];
	int nrElem;

public:
	Container() {
		this->nrElem = 0;
	}

	Container(T _v[10], int _nrElem) {
		this->nrElem = _nrElem;
		for (int i = 0; i < this->nrElem; i++)
			this->v[i] = _v[i];
	}

	friend ostream& operator<<(ostream& out, const Container& c) {
		out << "\nNr elem: " << c.nrElem;
		out << "\nLista elem: ";
		for (int i = 0; i < c.nrElem; i++)
			out << c.v[i] << " ";
		return out;
	}
};

int main() {
	int rez = sumaInt(2, 5);
	cout << rez;
	int rez2 = suma<int>(2.5, 5.2);
	cout << endl << rez2;
	return 0;
}