//Lucrare 2 : 8 decembrie 
//Materie: Supraincarcarea operatorilor, constructori de copiere, destructori, tot ce nu a intrat la lucrarea 1

#include <iostream>
using namespace std;

class Abonament {
	const int id; // nu se citeste, se primeste ca parametru  
	string nume = "Anonim";
	int nrContacte = 0;
	string* contacte = nullptr; //char** 
	static int generatorID;

public:

	// To do home: 
	// 1.Cum generam id-ul dar nu consecutiv? (Poate se afla intr-o lista predefinita) ex1: {100,107, 113}, ex2: {doar nr prime}

	Abonament() :id(++Abonament::generatorID) {

	}

	Abonament(string nume_, int nrContacte_, string* contacte_) :id(++Abonament::generatorID) {
		this->nume = nume_;
		if (nrContacte_ > 0)
			this->nrContacte = nrContacte_;
		else
			nrContacte_ = 0;

		if (nrContacte_ == 0)
			this->contacte = nullptr;
		else {
			this->contacte = new string[nrContacte];
			for (int i = 0; i < nrContacte; i++)
				this->contacte[i] = contacte_[i];
		}
	}

	Abonament(const Abonament& a) :id(++Abonament::generatorID) { //Constructor de copiere
		this->nume = a.nume;
		if (a.nrContacte > 0)
			this->nrContacte = a.nrContacte;
		else
			this->nrContacte = 0;

		if (a.nrContacte == 0)
			this->contacte = nullptr;
		else {
			this->contacte = new string[nrContacte];
			for (int i = 0; i < nrContacte; i++)
				this->contacte[i] = a.contacte[i];
		}
	}

	Abonament& operator =(const Abonament& a) { //Operator egal 
		if (this != &a) // ptr autoasignare
			if (this->contacte != nullptr) { //Daca nu apelam destructorul riscam memory leaks
				delete[] contacte;
				contacte = nullptr;
			}

		this->nume = a.nume;
		if (a.nrContacte > 0)
			this->nrContacte = a.nrContacte;
		else
			this->nrContacte = 0;

		if (a.nrContacte == 0)
			this->contacte = nullptr;
		else {
			this->contacte = new string[nrContacte];
			for (int i = 0; i < nrContacte; i++)
				this->contacte[i] = a.contacte[i];
		}
		return *this;
	}

	bool operator!=(string _x) { //operatori de comparatie : >, <, =, ==
		for (int i = 0; i < nrContacte; i++)
			if (this->contacte[i] == _x)
				return false;
		return true;
	}

	void afisare() {
		cout << "\n---------------------------------------";
		cout << "\nID: " << this->id;
		cout << "\nNume: " << this->nume;
		cout << "\nNr de contacte: " << this->nrContacte;
		cout << "\nContactele sunt: ";
		for (int i = 0; i < nrContacte; i++)
			cout << "\nContactul " << i + 1 << " este: " << this->contacte[i];
		cout << "\n---------------------------------------";
	}

	~Abonament() {
		if (contacte != nullptr) {
			delete[] contacte;
			contacte = nullptr;
		}
	}

};

int Abonament::generatorID = 100;

int main() {
	string s[] = { "Ion", "Gigel" };
	Abonament a1("Andrei Ionescu", 2, s);
	a1.afisare(); // 101
	Abonament* pa = new Abonament();
	delete pa;  //102
	Abonament a2 = a1; //103
	a1 = a2;
	a2.afisare();
	a1 = a2 = a1; //apel in cascada operator
	if (a1 != "Ion") // operator "!=", operanzi a1 si "Ion"
		cout << "\nIon nu este in contactul lui a1";
	else
		cout << "\nIon este in contactul lui a1";

	a1.afisare();

	return 0;
}