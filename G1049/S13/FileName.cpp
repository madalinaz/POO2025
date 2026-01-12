#include<iostream>
using namespace std;

//functie + clasa template/sablon
//reutilizare de cod/implementa o "interfata"/layer intermediar de comunicare cu cod deja existent

//o clasa care sa faciliteze lucrul cu vectori de obiecte/int
//partea de populare cu noi valori, sortare, adunare/agregare, ...

template<class T>
class Colectie {
	T v[100];
	int nr = 0;

public:
	//NU implementam constructori

	//supraincarcare operator +=
	Colectie& operator+=(T _x) {
		//putem adauga validari de dimensiune
		this->v[this->nr++] = _x;
		return *this;
	}

	//o modalitate de a agrega toate elementele din cadrul vectorului
	//o functie/metoda 
	//cast la T/int
	explicit operator T() const{
		T suma = 0;
		for (int i = 0; i < this->nr; i++) {
			suma += this->v[i]; //Angajat += Angajat
		}
		return suma;
	}

	//metoda care intoarce/returneaza elem cel mai mic din vector
	//operatorul functie
	T operator()() {
		T min = this->v[0];
		for (int i = 1; i < this->nr; i++) {
			if (this->v[i] < min) //Angajat < Angajat
			{
				min = this->v[i];
			}
		}
		return min;
	}

	friend ostream& operator<<(ostream& out, const Colectie& c) {
		out << "\nNr de elemente: " << c.nr;
		out << "\nLista elemente:  ";
		for (int i = 0; i < c.nr; i++) {
			out << c.v[i] << " ";
		}
		return out;
	}
};

//template<class T>
//ostream& operator<<(ostream& out, const Colectie<T>& c) {
//	out << "\nNr de elemente: " << c.nr;
//	out << "\nLista elemente:  ";
//	for (int i = 0; i < c.nr; i++) {
//		out << c.v[i] << " ";
//	}
//	return out;
//}

class Angajat {
	string nume = "";
	float salariu = 0;
	//const string cnp;

public:
	//T3. dati un exemplu de situatie in cadrul unei clase in care se preteaza sa lipseasca constructorul default
	Angajat() {

	}

	Angajat(float _salariu) {
		this->salariu = _salariu;
	}

	Angajat(string _nume, float _salariu) {
		this->nume = _nume;
		this->salariu = _salariu;
	}

	friend ostream& operator<<(ostream& out, const Angajat& a) {
		out << "\nNume: " << a.nume << ", salariu: " << a.salariu;
		return out;
	}

	Angajat& operator+=(const Angajat& a) {
		this->nume += a.nume;
		this->salariu += a.salariu;
		return *this;
	}

	bool operator<(const Angajat& a)const {
		return this->salariu < a.salariu;
	}
};

int main() {
	/*Colectie c;
	c += 10;
	c += 20;
	c += 5;
	cout << c;
	cout << "\nSuma elem din c este: " << (int)c;
	cout << "\nCel mai mic elem din c este: " << c();*/

	Colectie<int> cInt;
	cInt += 10;
	cInt += 5.6;
	cInt += 20;
	cout << cInt;

	//Colectie<Angajat*> cAng;
	//T1. considerati ca implementarea curenta permite stocarea si prelucrarea si a pointerilor in loc de obiecte?

	//T2. daca implementarea curenta NU acopera si lucrul cu pointeri, ce propunere de implementare aveti ca sa gestioneze si lucrul cu colectii de pointeri la obiecte?
	Angajat a1("Costel", 100);
	Angajat a2("Marcel", 200);
	Colectie<Angajat> cAng;
	cAng += a1;
	cAng += a2;
	cAng += a1;
	Angajat aSuma;
	aSuma = (Angajat)cAng;//cast explicit de la Colectie<Angajat> la Angajat
	cout << aSuma;
	cout <<endl<< cAng();//apel operator functie

	//T3. transformarea clasei colectie prin utilizarea STL-ului vector
	//T4. gestionarea in context de unicitate a tuturor proprietarilor de masini (utilizand stl ->map + set) (fiecare proprietar poate avea o colectie de masini unice si vreau sa stochez toti proprietarii de masini) (poate sa existe posibilitatea ca mai multe persoane sa detina aceeasi masina sau NU). (unicitatea persoanelor se face prin cnp iar unicitatea masinilor prin VIN).

	return 0;
}