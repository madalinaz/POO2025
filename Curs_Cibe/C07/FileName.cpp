#include<iostream>
using namespace std;

//= done
//comparatie (!=; ==; >....) done
//+= -= /= done
//!(negatie)
// ++ (pre si post)
// cast/conversie
// index []
// << >>
// + - / *
//functie

class Produs {
	const int id;
	char* denumire = nullptr;
	int stoc = 0;
	double pret = 0;
public:
	Produs() :id(0) {
	}

	Produs(int _id, const char* _denumire, int _stoc, double _pret) :id(_id) {
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

	Produs(const Produs& p) :id(p.id) {
		if (p.denumire != nullptr) {
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy(this->denumire, p.denumire);
		}
		this->stoc = p.stoc;
		this->pret = p.pret;
	}

	Produs& operator=(const Produs& p) {
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
		cout << "\nDestructor";
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}
	}

	//supraincarcare operatori
	//compara pretul lui this cu _x
	bool operator>=(double _x) {
		if (this->pret >= _x)
			return true;
		return false;
	}

	// == != < <= > >= (home)
	friend bool operator>(double _x, const Produs& p);

	//home: exista risc la Produs&?
	Produs& operator+=(int _x) {
		this->stoc += _x;
		return *this;
	}

	friend Produs& operator-=(Produs& p,
		int _x);

	bool operator!() {
		if (this->stoc == 0)
			return true;//nu exista
		return false;
	}
};

//int functie(int x) {
//	cout << "\nApel functie (int)";
//	return 0;
//}

void functie(int x) {
	cout << "\nApel functie (int)";
}

void functie(double x) {
	cout << "\nApel functie (double)";
}

void functie(int x, double y) {
	cout << "\nApel functie (int, double)";
}

void functie(double x, int y) {
	cout << "\nApel functie (double, int)";
}

//functie globala pentru supraincarcare
//pentru ca I operand nu este de tipul clasei
bool operator>(double _x, const Produs& p) {
	if (_x > p.pret)
		return true;
	return false;
}

//const NU pentru ca acest operand trebuie sa fie modificat
Produs& operator-=(Produs& p, 
	int _x) {
	p.stoc -= _x;
	return p;
}

int main() {
	functie(10);
	functie(10.5);
	functie(10.5f);
	//functie("Gigel");
	functie(10, 10.5);
	//functie(10.5, 10.5);-> eroare de ambiguitate
	char x = 'a';
	functie(x);
	
	//PASI SUPRAINCARCARE
	//P1. Se identifica tipul operatorului + nr de operanzi
	//P2. Se identifica tipul operanzitor
	//P3. Daca primul operand este de tipul clasei,
	//supraincarcarea se poate realiza printr-o metoda a clasei
	//I operand este inghitit de this
	//Daca nu, atunci obligatoriu se supraincarca printr-o functie globala
	//P4. Ce returneaza operatorul?
	//P5. Se modifica operanzii?
	Produs p1(13, "Stilou", 100, 1000);
	Produs p2;

	p2 = p1;//metoda a clasei(exista this-ul)
	p2.operator=(p1);

	double pret = 10;
	if (p1 >= pret) {
		cout << "\nP1 are pretul >= 10";
	}
	else {
		cout << "\nP1 NU are pretul >= 10";
	}

	//if (p1 == p2) {
	//	cout << "\nP1 si p2 are toate atributele egale";
	//}
	//else {
	//	cout << "\nInvers";
	//}

	//if (p1 != p2) {
	//	cout << "\nP1 si p2 difera prin cel putin un atribut";
	//}
	//else {
	//	cout << "\nInvers";
	//}

	//if (p1 > p2) {
	//	cout << "\nP1 are pret > ca p2 ";
	//}
	//else {
	//	cout << "\nInvers";
	//}

	// int > Produs
	if (10 > p1) {
		cout<<"\nP1 are pretul <10";
	}
	else {
		cout << "\nInvers";
	}

	p2 += 10;//mareste stoc-ul cu 10 unitati
	p2.afisare();
	/*int x, y;
	x = y += 10;*/

	p2 -= 10;
	operator-= (p2, 10);
	//p2.operator/=(2);

	if (!p2) {
		cout << "\nProdus p2 nu exista (nu are stoc)";
	}
	else {
		cout << "\nInvers";
	}
	return 0;
}