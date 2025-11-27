//NEXT TIME (s09)
//terminam toti operatorii de supraincarcat
//comparatie done
//= done
//<< done
// >>
// [] done
// !
// cast
// ++ (pre si post)
// + 
//functie
//+=

#include<iostream>
using namespace std;

//HOME1 ->DE IMPLEMENTAT LOGICA CLASEI DAR PE ALOCARE STATICA A PUTERILOR ARMELOR
//HOME2 ->ALOCARE DINAMICA HIBRID (LA INCEPUT ARE UN DEFAULT SPATIU PENTRU ARME DE 5. ATUNCI CAND IL UMPLE, REDIMENSIONEAZA PE DUBLU)
class Caracter {
	const int id;
	string denumire = "-";
	int nivelViata = 80;//apartine intervalului (0;100]
	int nrArme = 0;
	double* putereArme = nullptr;
	static int minViata;

public:
	Caracter(int _id) :id(_id) {
	}

	Caracter(int _id, string _denumire) :id(_id) {
		this->denumire = _denumire;
	}

	Caracter(const Caracter& c) :id(c.id) {
		this->denumire = c.denumire;
		this->nivelViata = c.nivelViata;
		if (c.nrArme > 0 && c.putereArme != nullptr) {
			this->nrArme = c.nrArme;
			this->putereArme = new double[this->nrArme];
			for (int i = 0; i < this->nrArme; i++)
				this->putereArme[i] = c.putereArme[i];
		}
	}

	Caracter& operator=(const Caracter& c) {
		if (this != &c) {
			if (this->putereArme != nullptr) {
				delete[] this->putereArme;
				this->putereArme = nullptr;
				this->nrArme = 0;
			}
			this->denumire = c.denumire;
			this->nivelViata = c.nivelViata;
			if (c.nrArme > 0 && c.putereArme != nullptr) {
				this->nrArme = c.nrArme;
				this->putereArme = new double[this->nrArme];
				for (int i = 0; i < this->nrArme; i++)
					this->putereArme[i] = c.putereArme[i];
			}
		}
		return *this;
	}

	~Caracter() {
		if (this->putereArme != nullptr) {
			delete[] this->putereArme;
			this->putereArme = nullptr;
			this->nrArme = 0;
		}
	}

	Caracter& operator+=(double _x) {
		if (_x > 0) {
			//V1
			/*Caracter copie = *this;
			delete[] this->putereArme;
			this->putereArme = new double[this->nrArme + 1];
			for (int i = 0; i < copie.nrArme; i++)
				this->putereArme[i] = copie.putereArme[i];
			this->putereArme[this->nrArme] = _x;
			this->nrArme++;
			return *this;*/

			//V2
			double* rez = new double[this->nrArme + 1];
			for (int i = 0; i < this->nrArme; i++)
				rez[i] = this->putereArme[i];
			rez[this->nrArme] = _x;
			delete[] this->putereArme;
			this->putereArme = rez;
			this->nrArme++;
			return *this;
		}

	}

	//forma-prefixata
	Caracter& operator++() {
		this->nivelViata *= 1.1;
		if (this->nivelViata > 100) {
			this->nivelViata = 100;
		}
		return *this;//returnam obj de dupa modificare
	}

	//forma-postfixata
	Caracter operator++(int) {
		Caracter copie = *this;
		++(*this);
		//this->operator++();
		return copie;//returnam obj de dinainte de modificare

	}

	//cast explicit la double
	explicit operator double() {
		double total = 0;
		for (int i = 0; i < this->nrArme; i++)
			total += this->putereArme[i];
		return total;
	}

	//HOME, de reimplementat dar fara utilizarea lui +=
	Caracter operator+(const Caracter& c) const{
		Caracter rez = *this;
		for (int i = 0; i < c.nrArme; i++)
			rez += c.putereArme[i];
		return rez;
	}

	//HOME, fara a apela operatorul + tocmai implementat
	//this+=c; -> this = this+c;
	Caracter operator+=(const Caracter& c) {
		Caracter copie = *this;
		*this = *this + c;
		return *this;
	}

	//this-ul il ataca pe c
	void operator>>(Caracter& c) {
		if (this->nivelViata > Caracter::minViata) {
			//this->operator+=(c);
			(*this) += c;
			delete[] c.putereArme;
			c.putereArme = nullptr;
			c.nrArme = 0;
		}
	}

	friend ostream& operator<<(ostream& out, const Caracter& c);
};

int Caracter::minViata = 20;

ostream& operator<<(ostream& out, const Caracter& c) {
	out << "\nId: " << c.id;
	out << "\nDenumire: " << c.denumire;
	out << "\nNivel viata: " << c.nivelViata;
	out << "\nNr arme: " << c.nrArme;
	out << "\nArme: ";
	for (int i = 0; i < c.nrArme; i++)
		out << c.putereArme[i] << " ";
	return out;
}

int main() {
	Caracter c1(12);
	Caracter c2(14, "Zburatorul");
	cout << c1;
	c1 += 10;//adaugam o noua arma
	cout << c1;
	c1 += 12;
	cout << "\n----------- ++(pre) ----------";
	cout << c2 << c1;
	c2 = ++c1;
	cout << c2 << c1;
	cout << "\n----------- ++(post) ----------";
	cout << c2 << c1;
	c2 = c1++;//marim viata cu 10% fata de cat era inainte in limita acceptata
	cout << c2 << c1;
	double totalArme = (double)c1;//cast/conversie => returnez suma tuturor puterilor armelor
	cout << endl << "Total arme: " << totalArme;
	Caracter c3(15);
	//cin >> c3;
	c3 = c1 + c2;//returneaza un nou caracter concatenand puterile lui c1 si c2
	cout << c3;
	//double d = 12.5;
	//c3 = d + 5;
	
	//c3 = c1 + 10;//returneaza un nou caracter suplimentand viata cu 10 unitati (HOME)
	c3 += c1;//echivalent de tipul c3 = c3 + c1;
	c3 >> c1;//c3 ataca pe c1, preluand toate armele
	return 0;
}