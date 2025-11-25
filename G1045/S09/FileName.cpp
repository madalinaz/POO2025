#include<iostream>
using namespace std;


//TEMA1 ->clasa Caracter in care putereArme este alocat static

//TEMA2 ->putereArme este alocat dinamic dar iti dubleaza spatiul de stocare atunci cand trebuie adaugam un element si nu am loc
//!!!pentru inceput, puteti avea o alocare default(5 elem, de ex)
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

	friend ostream& operator<<(ostream& out, const Caracter& c);


	Caracter operator+=(double _x) {
		if (_x > 0) {
			//V1
			/*Caracter copie = *this;
			if (this->putereArme != nullptr) {
				delete[] this->putereArme;
				this->putereArme = nullptr;
				this->nrArme = 0;
			}
			this->putereArme = new double[copie.nrArme + 1];
			for (int i = 0; i < copie.nrArme; i++)
				this->putereArme[i] = copie.putereArme[i];
			this->putereArme[copie.nrArme] = _x;
			this->nrArme = copie.nrArme + 1;*/

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
			throw new exception("Puterea armei NU poate sa fie negativa!");
		}
	}

	//preluam toate armele lui c in this
	Caracter operator+=(Caracter c) {
		for (int i = 0; i < c.nrArme; i++) {
			this->operator+=(c.putereArme[i]);

		}
	}
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

int main() {
	Caracter c1(12, "Zburatorul");
	Caracter c2(13);
	cout << c1;
	//TEMA 3: IMPLEMENTATI CONTEXTUL CARE CERE REINTRODUCEREA VALORII PUTERII DE ADAUGAT PANA ESTE VALIDA
	//INTR-O FUNCTIE RECURSIVA
	try {
		c1 += 12;
	}
	catch (exception* ex) {
		//to do in functie de ce se cere
		cout << endl << ex->what();
		delete ex;
		//pot dezaloca pointerul inainte de apel recursiv
		//APELAM RECURSIVITATEA
	}
	cout << c1;
	c1 += c2 += 10;
	//c1 += c1;
	//++c1;
	//c2 = c1 / 2;

	return 0;
}