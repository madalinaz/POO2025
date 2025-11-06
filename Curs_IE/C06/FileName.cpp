#include<iostream>
using namespace std;

//TO DO
//operator = done
//static + const = done
//friend
//reguli supraincarcare operatori done


//TEMA1
//modelati clasa astfel incat sa existe mai multe categorii de produse cu posibil tva diferit

//pp ca toate produsele gestionate sunt din aceeasi categorie(papetarie)
//TVA-ul este acelasi
class Produs {
	static double TVA;
	const int id;
	char* denumire = nullptr;
	int stoc = 0;
	double pret = 0;

public:
	Produs():id(0) {
		//this->id = 0; e prea tarziu
		cout << "\nApel constructor fara param";
	}

	//TEMA2 ->cum validam _id????
	Produs(int _id, const char* _denumire, int _stoc, double _pret):id(_id) {
		cout << "\nApel constructor cu toti param";
		if (_denumire != nullptr) {
			this->denumire = new char[strlen(_denumire) + 1];
			strcpy(this->denumire, _denumire);
		}
		if (_stoc > 0) {
			this->stoc = _stoc;
		}
		if (_pret > 0) {
			this->pret = _pret;
		}
	}

	//to do home->const protejeaza dar nu chiar tot
	Produs(const Produs& p):id(p.id) {
		//incercari de modificari:
		//p.pret = 100;
		//p.denumire[0] = 'P';
		//p.denumire = new char[3];

		cout << "\nApel constructor copiere";
		if (p.denumire != nullptr) {
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy(this->denumire, p.denumire);
		}
		this->stoc = p.stoc;
		this->pret = p.pret;
	}

	//daca vrem sa folosim operatori in 
	//compunere sau apel in cascada, atunci 
	//nu returneaza void
	Produs& operator=(const Produs& p) {
		//destructor (obj this deja exista)
		//constructor de copiere
		if (this != &p) {
			if (this->denumire != nullptr) {
				delete[] this->denumire;
				this->denumire = nullptr;
			}
			if (p.denumire != nullptr) {
				this->denumire = new char[strlen(p.denumire) + 1];
				strcpy(this->denumire, p.denumire);
			}
			this->stoc = p.stoc;
			this->pret = p.pret;
		}
		return *this;
	}
		

	//metoda non-statica ->are this
	void afisare() {
		cout << "\nId: " << this->id;
		if (this->denumire != nullptr) {
			cout << "\nDenumire: " << this->denumire;
		}
		else {
			cout << "\nDenumire: -";

		}
		cout << "\nStoc: " << this->stoc;
		cout << "\nPret: " << this->pret;
	}

	~Produs() {
		cout << "\nApel destructor";
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}
	}

	//metoda statica ->NU mai are this
	static void setTVA(double _TVA) {
		if (_TVA > 0 && _TVA < 1) {
			Produs::TVA = _TVA;
		}
	}

	//utilizare camp static in meth non-statica
	double calculTVA() {
		return Produs::TVA * this->pret;
	}

	friend bool gasit(Produs* v, int n, int id);
	friend class Magazin;
};

//sectiune initializare atribut static
double Produs::TVA = 0.21;

bool gasit(Produs* v, int n, int id) {
	for (int i = 0; i < n; i++) {
		if (v[i].id == id)
			return true;
	}
	return false;
}

//relatie de compunere
//relatie 1-M
class Magazin {
	string denumire;
	int nrProduse;
	Produs* listaProduse;
};

int main() {
	Produs::setTVA(0.23);
	Produs p1(12, "Carte", 100, 1000);
	p1.afisare();
	//p1.setTVA(0.23); //nu as recomanda

	Produs p2 = p1;
	Produs p3;
	p3 = p1;//atribuire
	p3.afisare();
	p3.operator=(p1);
	int x, y, z;
	x = y = z = 2;
	x = y == 2;
	p1 = p2 = p3;
	x = x;
	p3 = p3;
	p3.afisare();

	//REGULI SUPRAINCARCARE OPERATORI
	//p1.se identifica tipul operanzilor
	//p2.daca primul operand este de tipul clasei, supraincarea
	//se poate realiza printr-o metoda a clasei iar primul
	//operand este inghitit de this
	//altfel,supraincarcarea se realizeaza obligatoriu printr-o functie globala
	//p3.ce returneaza operator? Trebuie?
	//p4. se modifica operanzii? Trebuie?
	return 0;
}