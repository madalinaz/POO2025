
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

	void afisare() {
		cout << "\nDenumire: " << this->denumire << ", pret: " << this->pret;
	}
};

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

	//metoda afisare
	void afisare()
	{
		cout << "\nWishlist: buget=" << this->buget << ", nr produse=" << this->nrProduse;
		for (int i = 0; i < this->nrProduse; i++)
			this->lista[i].afisare(); //apel metoda afisare din clasa Produs
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

};


int main() {
	Produs p1("Laptop", 3500);
	Produs p2("Telefon", 1500);
	Produs p3("Tableta", 1200);
	Produs lista[] = { p1,p2,p3 }; //ce metoda se apeleaza aici si de cate ori -> constructorul de copiere de 3 ori
	Produs* lista2[] = { &p1,&p2 }; // vector alocat static de adrese de produse -> nu se apeleaza nicio metoda din clasa Produs
	Wishlist w1(lista, 3, 10000);
	w1.afisare();
	//test constructor de copiere
	Wishlist w2(w1); //apel constructor de copiere
	w2.afisare();

	//operator =
	Wishlist w3;
	w3 = w2; //apel operator =
	w3.afisare();

	w3 += 100; //adaugam buget
	w3.afisare();
	//test exceptie
	// 
	//sa se modeleze contextul a.i sa se ceara reintroducere daca se trimite ceva negativ (daca se doreste se poate prin functie recursiva)

	try
	{
		w3 += -50; //arunca exceptie
		w3.afisare();
	}
	catch (exception ex)
	{
		cout << endl << ex.what();
	}
	return 0;
}