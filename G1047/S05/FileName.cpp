#include<iostream>
using namespace std;
//get si set pe alocari dinamice
//fct globala
void globalAdaugaPretNou(double*& v, int& n, 
	double _pretNou);

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
	/*Produs(string _denumire, int _nrPreturi, double* _preturi) {
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
	}*/

	//sa se modifice constructorul cu toti param
	//astfel incat sa apelati meth adaugaPret
	/*Produs(string _denumire, int _nrPreturi, double* _preturi) {
		this->denumire = _denumire;
		if (_nrPreturi > 0 && _preturi != nullptr) {
			for (int i = 0; i < _nrPreturi; i++) {
				adaugaPret(_preturi[i]);
			}
		}
	}*/

	//aici apelez functia globala care adauga un nou elem intr-un vector
	Produs(string _denumire, int _nrPreturi, double* _preturi) {
		this->denumire = _denumire;
		if (_nrPreturi > 0 && _preturi != nullptr) {
			for (int i = 0; i < _nrPreturi; i++) {
				globalAdaugaPretNou(this->preturi, 
					this->nrPreturi, _preturi[i]);
			}
		}
	}

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

	const double* getPreturi() {
		return this->preturi;
	}

	//LA FEL PROCEDAM SI PENTRU VECTOR STATIC(DE CE????-HOME)
	//DAR, cine apeleaza meth, trebuie sa se 
	// ocupe si de dezalocarea lui copie
	//respecta incapsularea
	double* getPreturiBun() {
		double* copie = new double[this->nrPreturi];
		for (int i = 0; i < this->nrPreturi; i++)
			copie[i] = this->preturi[i];
		return copie;
	}

	int getNrPreturi() {
		return this->nrPreturi;
	}
};

//fct globala
//care adauga un nou pret intr-un vector de preturi
//pastrand logica.....
void globalAdaugaPretNou(double*& v, int& n, double _pretNou) {
	if (_pretNou > 0) {
		if (n == 0 || _pretNou != v[n - 1]) {
			double* aux = new double[n + 1];
			for (int i = 0; i < n; i++)
				aux[i] = v[i];
			aux[n] = _pretNou;
			delete[] v;
			v = nullptr;
			v = aux;
			n++;
		}
		else {
			cout << "\nPretul este identic cu ultimul din lista";
		}
	}
	else {
		cout << "\nNu este pret (este negativ)";
	}
}

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

	cout << "\n-----------GET SI SET-----------";
	double* vv = (double*)p1.getPreturiBun();
	int n = p1.getNrPreturi();
	for (int i = 0; i < n; i++)
		cout << vv[i] << " ";
	vv[0] = 123456;
	p1.afisare();
	//dezalocam copia!!!!!!
	delete[] vv;
	return 0;
}