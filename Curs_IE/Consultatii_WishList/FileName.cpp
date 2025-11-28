
//relatia de compunere / has a intre clase
//try-catch pentru gestionarea exceptiilor

#include<iostream>
using namespace std;

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

	friend ostream& operator<<(ostream& out, const Produs& p);
};

ostream& operator<<(ostream& out, const Produs& p) {
	out << "\nDenumire: " << p.denumire << ", pret: " << p.pret;
}

//deep copy /shallow copy
//obiect vs referinta 

class Wishlist2
{
	Produs* lista[50]; //vector static de produse
	int nrProduse;
	double buget;
};

class Wishlist3
{
	Produs* lista[50]; //vector static de Produs*(referinte catre produse)
	int nrProduse;
	double buget;
};

//de rezolvat si cu shallow copy si cu deep copy

class Wishlist4
{
	Produs** lista; //vector dinamic de Produs* (referinte catre produse)
	int nrProduse;
	double buget;
};


//relatie de compunere de tipul 1-1
class Wishlist5
{
	Produs theCadou;
	double buget;
};

class Wishlist6
{
	Produs* theCadou;  //referinta catre un produs
	double buget;
};

//pentru fiecare prieten
	//retin o colectie de produse de referinte la produse
//pe care vreau sa le ofer cadou
class Wishlist7
{
	Produs*** lista;
	int nrPrieteni;
	int* nrProduse; //nr produse per fiecare prieten
	double buget;

};

class Wishlist8
{
	//calendar advent 
	//pentru fiecare zi 1-24 decembrie
	//vreau sa imi ofer un numar de produse(obiecte , nu referinta) cadou
	Produs* lista[24];
	int nrCadouriPerZi[24];
};

class Wishlist
{
	Produs* lista = nullptr; //vector dinamic de produse
	int nrProduse = 0;
	double buget = 0;

public:
	Wishlist() {}

	//constructor cu toti param
	Wishlist(Produs* _lista, int _nrProduse, double _buget)
	{
		if (_nrProduse > 0 && _lista != nullptr)
		{
			this->nrProduse = _nrProduse;
			this->lista = new Produs[_nrProduse]; // ce metoda se apeleaza din clasa produs si de cate ori -> constructorul default de fiecare element
			for (int i = 0; i < _nrProduse; i++)
				this->lista[i] = _lista[i]; //apel operatorul =
		}
		this->buget = _buget;
	}

	//constructor de copiere
	Wishlist(const Wishlist& w)
	{
		if (w.nrProduse > 0 && w.lista != nullptr)
		{
			this->nrProduse = w.nrProduse;
			this->lista = new Produs[w.nrProduse]; // ce metoda se apeleaza din clasa produs si de cate ori -> constructorul default de fiecare element
			for (int i = 0; i < w.nrProduse; i++)
				this->lista[i] = w.lista[i]; //apel operatorul =
		}
		this->buget = w.buget;

	}

	//supraincarcare operator =
	Wishlist& operator=(const Wishlist& w)
	{
		//verificare autoasignare
		if (this != &w)
		{
			//destructor
			if (this->lista != nullptr)
			{
				delete[] this->lista;
				this->lista = nullptr; // evitam dangling pointer
				this->nrProduse = 0;
			}


			//constructor de copiere
			if (w.nrProduse > 0 && w.lista != nullptr)
			{
				this->nrProduse = w.nrProduse;
				this->lista = new Produs[w.nrProduse]; // ce metoda se apeleaza din clasa produs si de cate ori -> constructorul default de fiecare element
				for (int i = 0; i < w.nrProduse; i++)
					this->lista[i] = w.lista[i]; //apel operatorul =
			}
			this->buget = w.buget;
		}
		return *this;
	}

	//destructor
	~Wishlist()
	{
		if (this->lista != nullptr)
		{
			delete[] this->lista;
			this->lista = nullptr; // evitam dangling pointer
			this->nrProduse = 0;
		}
	}
	//supraincarcare operator += pentru adaugare buget
	//+= operator binar , de tipul clasei deci construi supraincarcarea ca metoda membra a clasei

	Wishlist& operator+=(double _x) //
	{
		if (_x > 0)
			this->buget += _x;
		else
		{
			throw exception("Valoare incorecta pentru adaugare buget!");
		}

		return *this;
		//se returneaza prin referinta doar obiectele care nu se distrug

	}

	friend ostream& operator<<(ostream& out, const Wishlist& w);

};

ostream& operator<<(ostream& out, const Wishlist& w) {
	out << "\nWishlist: buget=" << w.buget << ", nr produse=" << w.nrProduse;
	for (int i = 0; i < w.nrProduse; i++)
		out << w.lista[i];
	return out;
}


int main() {
	Produs p1("Laptop", 3500);
	Produs p2("Telefon", 1500);
	Produs p3("Tableta", 1200);
	Produs lista[] = { p1,p2,p3 }; 
	return 0;
}