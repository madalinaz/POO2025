#include<iostream>
using namespace std;
//get si set pe alocari dinamice
//fct globala

//to do home -> de completat si cu restrictii ca sa fie pret
class Produs {
	string denumire="Anonim";
	int nrPreturi=0;
	double* preturi = nullptr;

public:
	Produs() {

	}

	//constructor in care nu validez componentele vectorului
	//de fapt presupun ca primesc ca param ok acel vector
	/*Produs(string _denumire, int _nrPreturi, double* _preturi) {
		this->denumire = _denumire;
		if (_nrPreturi > 0 && _preturi != nullptr) {
			this->nrPreturi = _nrPreturi;
			this->preturi = new double[this->nrPreturi];
			for (int i = 0; i < this->nrPreturi; i++) {
				this->preturi[i] = _preturi[i];
			}
		}
	}*/

	//adaugam validare pe continut vector
	//adica NU avem voie 2 valori alaturate egale
	//daca gasim, le eliminam
	Produs(string _denumire, int _nrPreturi, double* _preturi) {
		this->denumire = _denumire;
		if (_nrPreturi > 0 && _preturi != nullptr) {
			int ct = 1;
			for (int i = 1; i < _nrPreturi; i++) {
				if (_preturi[i] != _preturi[i - 1]) {
					ct++;
				}
			}
			this->preturi = new double[ct];
			this->nrPreturi = ct;
			int k = 0;
			this->preturi[k++] = _preturi[0];
			for (int i = 1; i < _nrPreturi; i++) {
				if (_preturi[i] != _preturi[i - 1]) {
					this->preturi[k++] = _preturi[i];
				}
			}
		}
	}

	//sa se modifice constructorul cu toti param
	//astfel incat sa apelati meth adaugaPret


	//meth care sa adauge un nou pret in vector
	void adaugaPret(double _pretNou) {
		if (_pretNou > 0) {
			if (this->nrPreturi==0 || 
				_pretNou != this->preturi[this->nrPreturi - 1]) {
				double* aux = new double[this->nrPreturi + 1];
				for (int i = 0; i < this->nrPreturi; i++)
					aux[i] = this->preturi[i];
				aux[this->nrPreturi] = _pretNou;
				delete[] this->preturi;
				this->preturi = nullptr;
				this->preturi = aux;
				this->nrPreturi++;
			}
			else {
				cout << "\nPretul este identic cu ultimul din lista";
			}
		}
		else {
			cout << "\nNu este pret (este negativ)";
		}
	}

	void afisare() {
		cout << "\nDenumire: " << this->denumire;
		cout << "\nNr preturi: " << this->nrPreturi;
		cout << "\nPreturi: ";
		for (int i = 0; i < this->nrPreturi; i++) {
			cout << this->preturi[i] << " ";
		}
	}
};

int main() {
	double v[]{ 10,18,18,13,18,11,15 };
	Produs p1("Carte", 7, v);
	p1.afisare();
	p1.adaugaPret(15);
	p1.afisare();
	p1.adaugaPret(-10);
	p1.afisare();
	p1.adaugaPret(13);
	p1.afisare();
	return 0;
}