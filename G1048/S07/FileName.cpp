//s11 lucrare - cei de la rercuperare vor da separat
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
//tema
//sa se modeleze clasa masina care sa gestioneze numarul de sasiu(constant si unic) si numarul de inmatriculare(care se poate schimba, dar este unic)
class Abonat {
	const int id;   //generat automat pe baza unui generator
	string nume = "Anonim";
	double costAbonament = 0;
	int nrOptiuni = 0;
	string* optiuni = nullptr;;
	static int generatorId;
	static double constTotalAbonament; //costul abonamentelor tuturor abonatilor
public:
	Abonat() :id(Abonat::generatorId++) {}

	Abonat(string _nume, double _costAbonament, int _nrOptiuni, string* _optiuni) :id(Abonat::generatorId++) { //de ce se initializeaza aici id ul? 
		this->nume = _nume;
		this->costAbonament = _costAbonament;
		if (_nrOptiuni != 0 && _optiuni != nullptr) {
			this->nrOptiuni = _nrOptiuni;
			this->optiuni = new string[this->nrOptiuni];
			for (int i = 0; i < this->nrOptiuni; i++) {
				this->optiuni[i] = _optiuni[i];
			}
		}
		//gestiune camp static
		Abonat::constTotalAbonament += this->costAbonament;
	}
	//const Abonat &a il trimitem asa pentru a nu mai avea nevoie de o copie ca sa facem alta copie 
	Abonat(const Abonat& a) :id(Abonat::generatorId++) {//la copie vrem in id nou
		this->nume = a.nume;
		this->costAbonament = a.costAbonament;
		if (a.nrOptiuni != 0 && a.optiuni != nullptr) {
			this->nrOptiuni = a.nrOptiuni;
			this->optiuni = new string[this->nrOptiuni];
			for (int i = 0; i < this->nrOptiuni; i++) {
				this->optiuni[i] = a.optiuni[i];
			}
		}
	}

	void afisare() {
		cout << "Id: " << this->id << endl;
		cout << "Nume: " << this->nume << endl;
		cout << "Cost abonament: " << this->costAbonament << endl;
		cout << "Nr optuni: " << this->nrOptiuni << endl;
		cout << "Optiuni: ";
		for (int i = 0; i < this->nrOptiuni; i++) {
			cout << this->optiuni[i] << " ";
		}
		cout << "\n------------------------------\n";
	}

	~Abonat() {
		if (this->optiuni != nullptr) {
			delete[] this->optiuni; //
			this->optiuni = nullptr;//sa nu avem dangling pointers
		}
	}

	static double getCostTotal() {
		return Abonat::constTotalAbonament;

	}

	Abonat& operator=(const Abonat& a) {
		if (this != &a) { //verificam auto asignarea
			//getsiune camp static
			Abonat::constTotalAbonament = Abonat::constTotalAbonament - this->costAbonament + a.costAbonament;
			//destructor - ca sa nu avem memory leaks
			if (this->optiuni != nullptr) {
				delete[] this->optiuni; //
				this->optiuni = nullptr;//sa nu avem dangling pointers
			}
			//constructor de copiere- sa il actualizam pe this in functie de ce rimim ca parametru
			this->nume = a.nume;
			this->costAbonament = a.costAbonament;
			if (a.nrOptiuni != 0 && a.optiuni != nullptr) {
				this->nrOptiuni = a.nrOptiuni;
				this->optiuni = new string[this->nrOptiuni];
				for (int i = 0; i < this->nrOptiuni; i++) {
					this->optiuni[i] = a.optiuni[i];
				}
			}
			else {
				this->nrOptiuni = 0;
				this->optiuni = nullptr;
			}
		}

		return *this;//dereferentierea this-ului
	}

	bool operator>(double _x) {
		if (this->costAbonament > _x) {
			return true;
		}
		else
			return false;
	}

};

int Abonat::generatorId = 1000;
double Abonat::constTotalAbonament = 0;

int main() {
	Abonat a1;
	a1.afisare();

	string optiuni[3] = { "opt1","opt2","opt3" };
	Abonat a2("maria", 15, 3, optiuni);
	a2.afisare();

	Abonat a3 = a2;
	a3.afisare();
	cout << "Cost total: " << Abonat::getCostTotal() << endl;

	a3 = a1;
	a3.afisare();
	cout << "Cost total: " << Abonat::getCostTotal() << endl;

	if (a2 > 50) {
		cout << "\n costul abonamentului a2>50";
	}
	else {
		cout << "\n costul abonamentului a2<=50";
	}
	return 0;
}