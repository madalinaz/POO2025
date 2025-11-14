#include <iostream>
using namespace std;
//to do home (const + static)
//Serie sasiu, nr inmatriculare + extra;
//VIN- Seria Sasiu din 17 caractere si este constant
//nr inmatriculare - unic dar NU este constant;
//Modelare flux: vanzare cumparare, schimbare la cerere de numar inmatriculare
//Posibilitatea de asignare nr inmatriculare random sau preferential
//Posibilitate de verificare disponibilitate nr preferential;
class Masina {
private:
	const int VIN;//Unica si generata automat;
	int nrOptionale = 0;
	string* optionale = nullptr;
	static int contor;
public:
	//No initializer for const int VIN;
	Masina() :VIN(Masina::contor++) {

	}
	Masina(int nrOptionale, string* optionale) :VIN(Masina::contor++) {
		if (nrOptionale > 0)
			this->nrOptionale = nrOptionale;
		if (nrOptionale > 0 && optionale != nullptr) {
			this->optionale = new string[this->nrOptionale];
			for (int i = 0; i < this->nrOptionale; ++i)
				this->optionale[i] = optionale[i];
		}
	}
	//Referinta pentru ca daca ar fi copie, ar trebui sa existe un constructor de copiere, ceea ce nu e posibil pt ca il construim acum
	//Trasnfer prin referinta:
	//Motivul 1:
	// Ca sa putem modifica obiectul
	//Motivul 2:
	// Ca sa ocolim copierea (optimizare)
	Masina(const Masina& m) :VIN(Masina::contor++) {
		this->nrOptionale = m.nrOptionale;
		if (m.nrOptionale > 0 && m.optionale != nullptr) {
			this->optionale = new string[this->nrOptionale];
			for (int i = 0; i < this->nrOptionale; ++i)
				this->optionale[i] = m.optionale[i];
		}
	}
	//Nu mai trebuie lista initializatori ca lucram cu obiecte existente
	//Adica this-ul exista deja, nu il initializam la declarare 
	Masina& operator= (const Masina& a) {
		if (this != &a) {
			if (this->optionale != nullptr) {
				delete[] this->optionale;
				this->optionale = nullptr;
			}
			if (a.nrOptionale > 0) {
				this->nrOptionale = a.nrOptionale;
				this->optionale = new string[this->nrOptionale];
				for (int i = 0; i < this->nrOptionale; ++i)
					this->optionale[i] = a.optionale[i];
			}
			else {
				this->nrOptionale = 0;
				this->optionale = nullptr;
			}
		}
		return *this;
	}
	bool operator!=(const Masina& a) {
		if (this->nrOptionale != a.nrOptionale)
			return 1;
		for (int i = 0; i < this->nrOptionale; ++i)
			if (this->optionale[i] != a.optionale[i])
				return 1;
		return 0;
	}
	~Masina() {
		if (this->optionale != nullptr) {
			delete[] this->optionale;

			//Ca sa nu avem dangling pointers;
			this->optionale = nullptr;
		}
	}
	string getOptional(int index) {
		if (index < this->nrOptionale || index >= 0)
			return this->optionale[index];
		else
			throw exception("Index ul este in afara marimii!\n");
	}
	void afisare() {
		cout << "VIN: " << this->VIN << "\n";
		cout << "Nr optionale: " << this->nrOptionale << "\n";
		if (this->optionale != nullptr) {
			for (int i = 0; i < this->nrOptionale; ++i)
				cout << "Optional " << i + 1 << ": " << this->optionale[i] << " ";
			cout << "\n";
		}
		cout << "\n\n";
	}
	friend int getContor();
	//Astfel incat sa putem accesa campurile obiectului Masina;
	//Chiar daca implementam in corpul clasei, functia nu este a clasei
	/*friend bool operator==(const string str, const Masina& a) {

	}
	*/
	friend bool operator==(const string str, const Masina& a);
};
int getContor() {
	return Masina::contor;
}
//Initializarea campurilor statice se realizeaza inafara clasei!!!
int Masina::contor = 1000;
//Generam id-uri unice prin incrementarea contorului static

bool operator==(const string str, const Masina& a) {
	if (a.nrOptionale > 0 && a.optionale != nullptr) {
		for (int i = 0; i < a.nrOptionale; ++i)
			if (a.optionale[i] == str)
				return 1;
	}
	return 0;
}
int main() {
	cout << "A\n";
	Masina a;
	a.afisare();
	//string optionale[] e static by default in main;
	string optionale[] = { "ITP", "CASCO", "ABS" };
	Masina b(3, optionale);
	cout << "B\n";
	b.afisare();
	cout << "C\n";
	Masina c(b);
	c.afisare();
	cout << "C\n";
	c = a;
	c.afisare();

	if (c != b) {
		cout << "Obiectele difera prin cel putin un camp(Exceptand VIN-ul)\n";
	}
	else
		cout << "Obiectele sunt identice\n\n\n";
	c = b;
	//Nu poate fi implementat in clasa
	if ("ABS" == c) {
		cout << "Exista optionalul ABS in C\n";
	}
	else
		cout << "Nu exista optionalul ABS in C\n";
	cout << "\n\n";
	try {
		string optional = c.getOptional(5);
		cout << endl << optional;
	}
	catch (exception e) {
		//metoda what echivalent metodei get message
		cout << e.what();
	}

	cout << "Contor: " << getContor() << "\n";
	return 0;
}