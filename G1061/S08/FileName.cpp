#include<iostream>
using namespace std;

//relatia de compunere -> has a (1-M, 1-1)
//try catch


class Produs {
	string denumire = "";
	double pret = 0;

public:
	//de ce este nevoie de un constructor default?
	Produs(){ }

	Produs(string _denumire, double _pret) {
		this->denumire = _denumire;
		this->pret = _pret;
	}

	//meth de afisare ->supraincarcarea operatorului <<

	//permit obiectele de tipul Produs care sunt utilizate in functia mentionata sa aiba acces si la zona privata a clasei Produs
	friend ostream& operator<<(ostream& out, const Produs& p);
};
//transfer prin valoare
//face o copie a acelui obiect

//transfer prin referinta
//Caz 1. ca sa modifici obiectul respectiv (si aici nu putem si const)
//Caz 2. ca sa NU mai facem acea copie pe care ne-o realizeaza transferul prin valoare(dar aici putem const, pentru ca intentia NU este de a modifica obiectul) (cu rol de optimizare)
ostream& operator<<(ostream& out, const Produs& p) {
	out << "\nDenumire: " << p.denumire;
	out << ", pret: " << p.pret;
	return out;
}

//Versiuni diferite de colectii de obiecte/referinte de tip Produs
//obiect vs referinta la obiect
//deep copy vs shallow copy

class WishList2 {
	Produs lista[100];//vector alocat static de obj de tip Produs
	int nrProduse;
	double buget;
};

class WishList3 {
	Produs* lista[100];//vector alocat static de Produs* (referinte la Produs)
	int nrProduse;
	double buget;
};

class WishList4 {
	Produs** lista;//vector alocat dinamic de Produs* (referinte la Produs)
	int nrProduse;
	double buget;
};

//relatie de tip 1-1
class WishList5 {
	Produs theCadou; //un singur Produs
	double buget;
};

//relatie de tip 1-1
class WishList6 {
	Produs* theCadou; //un singur pointer catre 1 Produs
	double buget;
};

class WishList {
	Produs* lista= nullptr;//vector alocat dinamic de obj de tip Produs
	int nrProduse=0;
	double buget=0;

public:
	WishList(){ }

	WishList(Produs* _lista, int _nrProduse, double _buget) {
		if (_nrProduse > 0 && _lista != nullptr) {
			this->nrProduse = _nrProduse;
			this->lista = new Produs[this->nrProduse];//ce se apeleaza? (constructor fara param de nrProduse ori)
			for (int i = 0; i < this->nrProduse; i++) {
				this->lista[i] = _lista[i];//ce se apeleaza? (operator =)
			}
		}
		this->buget = _buget;
	}
};

int main() {
	Produs p1("Stilou", 500);
	//p1.afisare();
	cout << p1;// ostream << Produs
	return 0;
}