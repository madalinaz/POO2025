#include<iostream>
using namespace std;
//get si set pe alocari dinamice
//fct globala

class Produs {
	string denumire="Anonim";
	int nrPreturi=0;
	double* preturi = nullptr;

public:
	Produs() {

	}

	//constructor in care nu validez componentele vectorului
	//de fapt presupun ca primesc ca param ok acel vector
	Produs(string _denumire, int _nrPreturi, double* _preturi) {
		this->denumire = _denumire;
		if (_nrPreturi > 0 && _preturi != nullptr) {
			this->nrPreturi = _nrPreturi;
			this->preturi = new double[this->nrPreturi];
			for (int i = 0; i < this->nrPreturi; i++) {
				this->preturi[i] = _preturi[i];
			}
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
	double v[]{ 10,18,20,13,11,15 };
	Produs p1("Carte", 6, v);
	p1.afisare();
	return 0;
}