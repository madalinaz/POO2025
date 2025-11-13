#include<iostream>
using namespace std;

//= done
// comparatie (< <= > >= != ==)
// negatie (!)
// += -= /= *=
// ++ (pre si post)
// << si >>
// operator index []
// cast/conversie
//functie
// + - * /

class exceptie {
	string mesaj;
public:
	exceptie(string _mesaj) {
		this->mesaj = _mesaj;
	}

	string getMesaj() {
		return this->mesaj;
	}
};

class Produs {
	string denumire = "Anonim";
	double pret=0;

public:
	Produs(string _denumire, double _pret) {
		this->denumire = _denumire;
		this->pret = _pret;
	}

	void afisare() {
		cout << "\nDenumire: " << this->denumire;
		cout << "\nPret: " << this->pret;
	}

	void setPret(double _pret) {
		if (_pret > 0) {
			this->pret = _pret;
		}
		else {
			//cout << "\nPretul este negativ!";
			throw exception("Pretul este negativ");
		}
	}

	bool operator==(const Produs& p) const{
		return this->denumire == p.denumire 
			&& this->pret == p.pret;
	}

	bool operator<(int _x) const{
		return this->pret < _x;
	}

	//friend bool operator>(int _x, const Produs& p);
};

void f(int x) {
	cout << "\n f(int)";
}

void f(int x, double y) {
	cout << "\n f(int, double)";
}

void f(double x, int y) {
	cout << "\n f(double, int)";
}

void f(double x, double y) {
	cout << "\n f(double, double)";
}

//functie globala ptr ca I operand nu este Produs
bool operator>(int _x, const Produs& p){
	//daca exista friend
	/*if (_x > p.pret)
		return true;
	return false;*/

	//folosind Produs<int
	return p < _x;
}

int main() {
	Produs p1("carte", 120);
	Produs p2("stilou", 1000);
	Produs p3(p2);
	p3.afisare();
	p1 = p2;
	p1.afisare();

	cout << "\n-------------f----------";
	f(10);
	f(12.5);//conversie degradanta
	f(12.5f);//conversie degradanta
	f(12.5, 12.5);
	f(12, 12.5);
	char x = 'a';
	f(x);//conversie nedegradanta
	//f("Stilou");
	//f(12, 12); eroare de ambiguitate
	cout << "\n-------------f----------";

	cout << "\n-------------try-catch----------";
	try {
		p2.setPret(13);
		p2.afisare();
	}
	catch (exception ex) {
		//to do in caz ca utilizatorul nu a introdus okai
		cout << ex.what();
	}

	try {
		p2.setPret(-13);
		p2.afisare();
	}
	catch (exception ex) {
		//to do in caz ca utilizatorul nu a introdus okai
		cout << ex.what();
	}
	
	cout << "\n-------------try-catch----------";

	cout << "\n-------------operator comparatie----------";
	//obj == obj
	if (p2 == p1) {
		cout << "\np2 si p1 au toate atributele egale";
	}
	else {
		cout << "\np2 si p1 au cel putin un atribut diferit";
	}

	if (10 > p2) {
		cout << "\n10 > ca pretul lui p2";
	}
	else {
		cout << "\n10 <= ca pretul lui p2";
	}

	//== pentru toate campurile exceptand id(alta clasa)
	//!= prin cel putin un atribut/camp
	//== pentru doar 1 camp
	return 0;
}