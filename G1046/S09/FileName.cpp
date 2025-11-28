#include<iostream>
using namespace std;

//HOME2: DE IMPLEMENTAT CLASA FOLOSIND ALOCARE STATICA
//HOME3: DE IMPLEMENTAT CLASA FOLOSIND ALOCARE HIBRID (INITIAL ALOC 5 POZITII DISPONIBILE PENTRU ARME, APOI, CAND SE OCUPA TOATE, REDIMENSIONEZ PE DUBLU)
class Caracter {
	const int id;
	string denumire = "-";
	int nivelViata = 100;//apartine intervalului (0;100]
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
			for (int i = 0; i < copie.nrArme; i++) {
				this->putereArme[i] = copie.putereArme[i];
			}
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
		else {
			throw new exception("Puterea NU este pozitiva!");
		}
	}

	//forma pre-fixata
	Caracter& operator--() {
		this->nivelViata *= 0.9;
		return *this;//returnam starea de dupa actualizare
	}

	//forma post-fixata
	Caracter operator--(int) {
		Caracter copie = *this;
		--(*this);
		//this->operator--();

		return copie;//return starea de dinainte de actualizare
	}

	//HOME5: DE IMPLEMENTAT FARA UTILIZAREA LUI +=
	Caracter& operator+=(const Caracter& c) {

		for (int i = 0; i < c.nrArme; i++) {
			try {
				*this += c.putereArme[i];
			}
			catch (exception* ex) {

			}
		}
		return *this;
	}

	void operator>>(Caracter& c) {
		if (this->nivelViata > Caracter::minViata) {
			*this += c;
			delete[] c.putereArme;
			c.putereArme = nullptr;
			c.nrArme = 0;
		}
	}

	Caracter operator()(int _i1, int _i2) const{
		if (_i1 > _i2) {
			swap(_i1, _i2);
		}
		if (_i1 >= 0 && _i2 <= this->nrArme) {
			Caracter rez = *this;
			delete[] rez.putereArme;
			rez.nrArme = 0;
			for (int i = _i1; i <= _i2; i++) {
				rez += this->putereArme[i];
			}
			return rez;
		}
	}

	friend ostream& operator<<(ostream& out, const Caracter& c);

};

int Caracter::minViata = 10;

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

//HOME4: DE GANDIT/IMPLEMENTAT O MODALITATE CA OPERATOR+ SA NU TRATEZE INTERN EXCEPTIA, CI SA O TRIMITA MAI DEPARTE, DECI TRATATA IN MAIN
//cei 2 operanzi NU se modifica
Caracter operator+(double _x, const Caracter& c) {
	Caracter rez = c;
	try {
		rez += _x;
	}
	catch (exception* ex) {
		delete ex;
	}
	return rez;
}

int main() {
	Caracter c1(14);
	Caracter c2(15, "Zburatorul");
	//HOME 1: O MODALITATE DE REINTRODUCERE A VALORII PUTERII DE ADAUGAT PANA CAND ACEASTA ESTE VALIDA
	//V1 -> DO WHILE
	//V2 -> FUNCTIE RECURSIVA (ATENTIE LA OBJ/pointeri EXCEPTION)
	try {
		c2 += 10;
		cout << c2;
	}
	catch (exception* ex) {
		cout << endl << ex->what();
		delete ex;
	}
	c2 = 10 + c2;
	cout << c2;
	cout << "\n----------- -- pre --------";
	cout << c1 << c2;
	c1 = --c2;//scadem viata cu 10% din ce era 
	cout << c1 << c2;
	cout << "\n----------- -- post --------";
	cout << c1 << c2;
	c1 = c2--;//scadem viata cu 10% din ce era 
	cout << c1 << c2;

	c1 += c2 += c1;
	cout << c1;
	c2 >> c1;
	cout << c1;
	cout << c2;
	c1 = c2(2,5);//preiau doar armele din intervalul de indecsi 2-5

	return 0;
}