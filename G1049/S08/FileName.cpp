#include<iostream>
using namespace std;

//Tema 1 (const + static) 
//clasa Masina (seria de sasiu si nr de inmatriculare + etra) 
//Seria de sasiu (constanta si unica)
//Nr de inmatriculare (unic, dar NU este constant)
//Modelati procesul de schimbare nr inmatriculare 
//Se pot adauga clase in plus + friend (daca vreau sa imi aleg un nr de inmatriculare preferential)

class Produs {
	string denumire = "Anonim";
	double pret = 0;

public:
	Produs() {}

	Produs(string _denumire, double _pret) {
		this->denumire = _denumire;
		this->pret = _pret;
	}

	Produs(const Produs& p) {
		this->denumire = p.denumire;
		this->pret = p.pret;
	}

	Produs& operator=(const Produs& p) {
		this->denumire = p.denumire;
		this->pret = p.pret;
		return *this;
	}

	void afisare() {
		cout << "\nDenumire: " << this->denumire << ", pret: " << this->pret;
	}
};

//relatia de compunere (has a)
class WishList {
	//o colectie de produse
	Produs* produse = nullptr; //vector alocat dinamic de Produs
	int nrProduse = 0;
	double buget = 0;

public:
	WishList() {
	}

	WishList(Produs* _produse, int _nrProduse, double _buget) {
		if (_produse != nullptr && _nrProduse > 0) {
			this->nrProduse = _nrProduse;
			this->produse = new Produs[this->nrProduse];
			for (int i = 0; i < _nrProduse; i++)
				this->produse[i] = _produse[i];
		}
		this->buget = _buget;
	}

	WishList(const WishList& w) { // constructor de copiere
		if (w.produse != nullptr && w.nrProduse > 0) {
			this->nrProduse = w.nrProduse;
			this->produse = new Produs[this->nrProduse];
			for (int i = 0; i < w.nrProduse; i++)
				this->produse[i] = w.produse[i];
		}
		this->buget = w.buget;
	}


	// Sablon 
	WishList& operator=(const WishList& w) {
		if (this != &w)
		{
			// destructor
			if (this->produse != nullptr) {
				delete[] this->produse;
				this->produse = nullptr; //dangling pointers
			}
			// constructor copiere
			if (w.produse != nullptr && w.nrProduse > 0) {
				this->nrProduse = w.nrProduse;
				this->produse = new Produs[this->nrProduse];
				for (int i = 0; i < w.nrProduse; i++)
					this->produse[i] = w.produse[i];
			}
			this->buget = w.buget;

		}
		return *this; // dereferentierea this-ului
	}

	WishList& operator+=(double _x) {
		if (_x > 0)
			this->buget += _x;
		else
			throw exception("Buget negativ!");
		return *this;
	}

	~WishList() {
		if (this->produse != nullptr) {
			delete[] this->produse;
			this->produse = nullptr; //dangling pointers
		}
	}

	void afisare() {
		cout << "\n-----------------------------------";
		cout << "\nnrProduse: " << this->nrProduse;
		cout << "\nproduse: ";
		for (int i = 0; i < nrProduse; i++)
			this->produse[i].afisare();
		cout << "\nbuget: " << this->buget;
		cout << "\n-----------------------------------";
	}

};

//!!!Atentie la deep copy
//class WishList2 {
//	//o colectie de produse
//	Produs** produse; //vector alocat dinamic de Produs*
//	int nrProduse;
//	double buget;
//};
//
//class WishList3 {
//	//o colectie de produse
//	Produs* produse[100]; //vector alocat static de Produs*
//	int nrProduse;
//	double buget;
//};
//
//
////Relatie de tipul 1-m
//class WishList4 {
//	//o colectie de produse
//	Produs produse[100]; //vector alocat static de Produs
//	int nrProduse;
//	double buget;
//
//};
//
////Relatie 1 la 1
//class WishList5 {
//	Produs cadouP;
//	double buget;
//
//};

int main() {
	int v[] = { 1, 2, 3 };
	Produs p1("Laptop", 2000);
	Produs p2("Masina", 5000);
	Produs p3("Telefon", 3000);
	Produs vp[] = { p1, p2, p3 }; //se apeleaza operatorul "=" de 3 ori
	WishList w1(vp, 3, 10000);
	w1.afisare();
	WishList w2 = w1;
	w2.afisare();
	//p1.setPret(1500); 
	WishList w3;
	w3 = w1;
	w3.afisare();
	try {
		w3 += -100; //Vreau sa suplimentez bugetul cu 100
		w3.afisare();
	}
	catch (exception ex) {
		// to do in caz daca imi arunca exceptie
		cout << endl << ex.what();
	}
	return 0;
}