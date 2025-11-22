#include<iostream>
using namespace std;

//relatia de compunere -> has a (1-M, 1-1)
//try catch

//NEXT TIME (s09)
//terminam toti operatorii de supraincarcat
//comparatie done
//= done
//<< done
// >>
// [] done
// !
// cast
// ++ (pre si post)
// + 
//functie
//+=


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

	WishList(const WishList& w) {
		if (w.nrProduse > 0 && w.lista != nullptr) {
			this->nrProduse = w.nrProduse;
			this->lista = new Produs[this->nrProduse];//ce se apeleaza? (constructor fara param de nrProduse ori)
			for (int i = 0; i < this->nrProduse; i++) {
				this->lista[i] = w.lista[i];//ce se apeleaza? (operator =)
			}
		}
		this->buget = w.buget;
	}

	WishList& operator=(const WishList& w) {
		if (this != &w) {
			//destructor
			if (this->lista != nullptr) {
				delete[] this->lista;
				this->lista = nullptr;
			}
			//constructor de copiere
			if (w.nrProduse > 0 && w.lista != nullptr) {
				this->nrProduse = w.nrProduse;
				this->lista = new Produs[this->nrProduse];//ce se apeleaza? (constructor fara param de nrProduse ori)
				for (int i = 0; i < this->nrProduse; i++) {
					this->lista[i] = w.lista[i];//ce se apeleaza? (operator =)
				}
			}
			else {
				//situatia in care this avea produse dar w nu are
				this->nrProduse = 0;
				this->lista = nullptr;
			}
			this->buget = w.buget;
		}
		return *this;
	}

	~WishList() {
		if (this->lista != nullptr) {
			delete[] this->lista;
			this->lista = nullptr;
		}
	}

	friend ostream& operator<<(ostream& out, const WishList& w);


	//HOME ->!!!!NU FACEM RETURN PRIN REFERINTA LA TIPURI DE DATE DE BAZA(INT/FLOAT/DOUBLE)!!! DE CE????
	//operator[] cu rol doar de consultare va intoarce mereu un obiect, si nu referinta sa
	//daca se doreste si cu rol de modificare, atunci va intoarce o referinta
	Produs& operator[](int _index) {
		if (_index >= 0 && _index < this->nrProduse) {
			return this->lista[_index];
		}
		else {
			//cout<<"\nIndexul nu este valid";
			throw exception("Indexul nu este valid");//arunca un nou obiect de tipul clasei exception care este construit pe baza constructorului cu parametru care primeste un string cu rol de mesaj
		}
	}
};

ostream& operator<<(ostream& out, const WishList& w) {
	out << "\nNr produse: " << w.nrProduse;
	out << "\nProduse: ";
	for (int i = 0; i < w.nrProduse; i++)
		out << w.lista[i];
	out << "\nBuget: " << w.buget;
	return out;
}

int main() {
	Produs p1("Stilou", 500);
	//p1.afisare();
	cout << p1;// ostream << Produs
	Produs p2("Pix", 200);
	Produs p3("Ciocolata", 150);
	Produs v[] = { p1,p2,p3 };//ce se apeleaza?(constructor copiere)
	WishList w(v, 3, 1200);
	cout << w;
	WishList w2 = w;
	cout << w2;
	cout << "\n-------------- operator [] ---------";
	Produs p4;
	p4 = w[1];//operatorul index[] extrage obiectul de pe index-ul primit ca parametru
	//operator binar (WishList [] int)
	//obligatoriu se implementeaza in clasa printr-o functie membra

	//TO DO HOME: DE REMODELAT MECANISMUL DE APEL OPERATOR INDEX[] 
	//UTILIZATORUL REINTRODUCE INDEXUL PANA CE ACESTA ESTE VALID
	try {
		w[-1] = p3;//daca implementez operatorul si cu rol de modificare (adica intoarce o referinta si modifica in lista de obiecte/produse ale lui WishList w)
		cout << w;
	}
	catch (exception ex) {
		//to do in situatia in care metoda a fost apelata cu input neconform
		cout <<endl<< ex.what();//echivalent cu un getMesaj()
	}
	

	return 0;
}