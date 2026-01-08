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
	string nume="Anonim";
	float salariu=0;

public:
	Angajat() {

	}

	//operator + (Angajat + Angajat)
	//care returneaza un int reprezentat de suma salariilor
	/*friend int operator+(Angajat& a1, Angajat& a2) {
		return a1.salariu + a2.salariu;
	}*/

	int operator+(const Angajat& a){
		return this->salariu + a.salariu;
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

//relatie de tip Has a cu T
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

class Magazin {
	double cheltuieli[100];
	int nrCh;

public:
	
};

template<class T>
class Colet {
	int dim1, dim2, dim3;
	int codUnic;
	string adresaDestinatar;
	string adresaExpeditor;
	T obiect;
};

int main() {
	int rez = sumaInt(2, 5);
	cout << rez << endl;
	int rezFloat = sumaInt(2, 5.4);
	cout << rezFloat << endl;
	int rez2 = suma<int>(2, 5);
	cout << endl << rez2;
	float rez3 = suma<float>(2.5, 5.3);
	cout << endl << rez3;

	Magazin m1, m2;
	//cout << endl << m1 + m2;

	Angajat a1("Gigel", 100);
	Angajat a2("Costel", 200);
	int rez4 = sumaGenerala<int, Angajat>(a1, a2);
	
	cout << "\n\n-----CLASA TEMPLATE-----";
	int vInt[] = { 10,5,6 };
	Container<int> containerInt(vInt, 3);
	cout << containerInt;
	Angajat vAng[10];
	Container<Angajat> containerAngajat(vAng, 4);


	return 0;
}