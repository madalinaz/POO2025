
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

	void setPret(double _pret) {
		if (_pret > 0) {
			this->pret = _pret;
		}
	}

	friend ostream& operator<<(ostream& out, const Produs& p);
};

ostream& operator<<(ostream& out, const Produs& p) {
	out << "\nDenumire: " << p.denumire << ", pret: " << p.pret;
	return out;
}

//relatie de compunere de tipul 1-1
class Wishlist5
{
	Produs theCadou;
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

	Produs& operator[](int _index) {
		if (_index >= 0 && _index < this->nrProduse) {
			return this->lista[_index];
		}
	}
};

ostream& operator<<(ostream& out, const Wishlist& w) {
	out << "\nWishlist1: buget=" << w.buget << ", nr produse=" << w.nrProduse;
	for (int i = 0; i < w.nrProduse; i++)
		out << w.lista[i];
	return out;
}

class Wishlist2
{
	Produs lista[50]; //vector static de produse
	int nrProduse =0;
	double buget=0;

public:
	Wishlist2() {
	}

	//constructor cu toti param
	Wishlist2(Produs* _lista, int _nrProduse, double _buget)
	{
		//de suplimentat cu validari pe limita de 50
		if (_nrProduse > 0 && _lista != nullptr)
		{
			this->nrProduse = _nrProduse;
			for (int i = 0; i < _nrProduse; i++)
				this->lista[i] = _lista[i]; 
		}
		this->buget = _buget;
	}

	Wishlist2(const Wishlist2& w)
	{
		//aici nu este necesara validarea pe dimensiune de maxim 50 de produse
		if (w.nrProduse > 0 && w.lista != nullptr)
		{
			this->nrProduse = w.nrProduse;
			for (int i = 0; i < w.nrProduse; i++)
				this->lista[i] = w.lista[i];
		}
		this->buget = w.buget;
	}

	Wishlist2& operator=(const Wishlist2& w) {
		if (this != &w) {
			if (w.nrProduse > 0 && w.lista != nullptr)
			{
				this->nrProduse = w.nrProduse;
				for (int i = 0; i < w.nrProduse; i++)
					this->lista[i] = w.lista[i];
			}
			this->buget = w.buget;
		}
		return *this;
	}

	~Wishlist2() {
		//nu avem ce dezaloca pentru ca nu avem alocare dinamica
	}

	friend ostream& operator<<(ostream& out, const Wishlist2& w);
};

ostream& operator<<(ostream& out, const Wishlist2& w) {
	out << "\nWishlist2: buget=" << w.buget << ", nr produse=" << w.nrProduse;
	for (int i = 0; i < w.nrProduse; i++)
		out << w.lista[i];
	return out;
}

//implementarea este de tipul shallow copy la nivel de referinte(adica nu-mi fac propria zona de memorie in care sa copiez obiectele, ci stochez acele adrese/referinte pe care le-am primit ca parametru in constructori)
class Wishlist3
{
	Produs* lista[50]; //vector static de Produs*(referinte catre produse)
	int nrProduse=0;
	double buget=0;

public:
	Wishlist3() {
	}

	//constructor cu toti param
	Wishlist3(Produs** _lista, int _nrProduse, double _buget)
	{
		//de suplimentat cu validari pe limita de 50
		if (_nrProduse > 0 && _lista != nullptr)
		{
			this->nrProduse = _nrProduse;
			for (int i = 0; i < _nrProduse; i++)
				this->lista[i] = _lista[i];//aici se vede ca este shallow
		}
		this->buget = _buget;
	}

	//constructor copiere
	Wishlist3(const Wishlist3& w)
	{
		if (w.nrProduse > 0 && w.lista != nullptr)
		{
			this->nrProduse = w.nrProduse;
			for (int i = 0; i < w.nrProduse; i++)
				this->lista[i] = w.lista[i];//aici se vede ca este shallow
		}
		this->buget = w.buget;
	}

	Wishlist3& operator=(const Wishlist3& w) {
		if (this != &w) {
			if (w.nrProduse > 0 && w.lista != nullptr)
			{
				this->nrProduse = w.nrProduse;
				for (int i = 0; i < w.nrProduse; i++)
					this->lista[i] = w.lista[i];//aici se vede ca este shallow
			}
			this->buget = w.buget;
		}
		return *this;
	}

	~Wishlist3() {
		//NU am ce dezaloca, pentru in constructori NU am alocat nicio zona de memorie folosind operatorul new
	}

	friend ostream& operator<<(ostream& out, const Wishlist3& w);
};

ostream& operator<<(ostream& out, const Wishlist3& w) {
	out << "\nWishlist3: buget=" << w.buget << ", nr produse=" << w.nrProduse;
	for (int i = 0; i < w.nrProduse; i++)
		out << *w.lista[i];
	return out;
}

//implementarea este de tip shallow 
class Wishlist4
{
	Produs** lista=nullptr; //vector dinamic de Produs* (referinte catre produse)
	int nrProduse=0;
	double buget=0;

public:
	Wishlist4(){ }

	//constructor cu toti param
	Wishlist4(Produs** _lista, int _nrProduse, double _buget)
	{
		if (_nrProduse > 0 && _lista != nullptr)
		{
			this->nrProduse = _nrProduse;
			this->lista = new Produs * [this->nrProduse];
			for (int i = 0; i < _nrProduse; i++)
				this->lista[i] = _lista[i];//aici se vede ca este shallow
		}
		this->buget = _buget;
	}

	Wishlist4(const Wishlist4 & w)
	{
		if (w.nrProduse > 0 && w.lista != nullptr)
		{
			this->nrProduse = w.nrProduse;
			this->lista = new Produs * [this->nrProduse];
			for (int i = 0; i < w.nrProduse; i++)
				this->lista[i] = w.lista[i];//aici se vede ca este shallow(aici NU se apeleaza operatorul = din clasa Produs, ci se face atribuire dintre 2 adrese/referinte
		}
		this->buget = w.buget;
	}

	Wishlist4& operator=(const Wishlist4& w) {
		if (this != &w) {
			if (this->lista != nullptr) {
				delete[] this->lista;
				this->lista = nullptr;
			}
			if (w.nrProduse > 0 && w.lista != nullptr)
			{
				this->nrProduse = w.nrProduse;
				this->lista = new Produs * [this->nrProduse];
				for (int i = 0; i < w.nrProduse; i++)
					this->lista[i] = w.lista[i];//aici se vede ca este shallow(aici NU se apeleaza operatorul = din clasa Produs, ci se face atribuire dintre 2 adrese/referinte
			}
			this->buget = w.buget;
		}
		return *this;
	}

	~Wishlist4() {
		if (this->lista != nullptr) {
			delete[] this->lista;
			this->lista = nullptr;
		}
	}

	friend ostream& operator<<(ostream& out, const Wishlist4& w);
};

ostream& operator<<(ostream& out, const Wishlist4& w) {
	out << "\nWishlist4: buget=" << w.buget << ", nr produse=" << w.nrProduse;
	for (int i = 0; i < w.nrProduse; i++)
		out << *w.lista[i];
	return out;
}

//implementarea este de tip deepcopy (adica primim niste referinte, dar ne alocam propria noastra zona de memorie pentru fiecare referinta, iar noi la nivel de obj wishlist, stocam o lista/vector de astfel de referinte 
class Wishlist4_1
{
	Produs** lista = nullptr; //vector dinamic de Produs* (referinte catre produse)
	int nrProduse = 0;
	double buget = 0;

public:
	Wishlist4_1() {}

	//constructor cu toti param
	Wishlist4_1(Produs** _lista, int _nrProduse, double _buget)
	{
		if (_nrProduse > 0 && _lista != nullptr)
		{
			this->nrProduse = _nrProduse;
			this->lista = new Produs * [this->nrProduse];
			for (int i = 0; i < _nrProduse; i++)
				this->lista[i] = new Produs(*_lista[i]);//apelez constructor de copiere
		}
		this->buget = _buget;
	}

	Wishlist4_1(const Wishlist4_1& w)
	{
		if (w.nrProduse > 0 && w.lista != nullptr)
		{
			this->nrProduse = w.nrProduse;
			this->lista = new Produs * [this->nrProduse];
			for (int i = 0; i < w.nrProduse; i++)
				this->lista[i] = new Produs(*w.lista[i]);
		}
		this->buget = w.buget;
	}

	Wishlist4_1& operator=(const Wishlist4_1& w) {
		if (this != &w) {
			if (this->lista != nullptr) {
				for (int i = 0; i < this->nrProduse; i++)
					delete this->lista[i];
				delete[] this->lista;
				this->lista = nullptr;
			}
			if (w.nrProduse > 0 && w.lista != nullptr)
			{
				this->nrProduse = w.nrProduse;
				this->lista = new Produs * [this->nrProduse];
				for (int i = 0; i < w.nrProduse; i++)
					this->lista[i] = new Produs(*w.lista[i]);
			}
			this->buget = w.buget;
		}
		return *this;
	}

	~Wishlist4_1() {
		if (this->lista != nullptr) {
			for (int i = 0; i < this->nrProduse; i++)
				delete this->lista[i];
			delete[] this->lista;
			this->lista = nullptr;
		}
	}

	friend ostream& operator<<(ostream& out, const Wishlist4_1& w);
};

ostream& operator<<(ostream& out, const Wishlist4_1& w) {
	out << "\nWishlist4: buget=" << w.buget << ", nr produse=" << w.nrProduse;
	for (int i = 0; i < w.nrProduse; i++)
		out << *w.lista[i];
	return out;
}

//implementarea curenta este de tipul shallow copy
//home puteti si in versiune de deep copy
class Wishlist6
{
	Produs* theCadou=nullptr;  //referinta catre un produs
	double buget=0;

public:
	Wishlist6() {

	}

	Wishlist6(Produs* _theCadou, double _buget) {
		this->theCadou = _theCadou;
		this->buget = _buget;
	}

	Wishlist6(const Wishlist6& w) {
		this->theCadou = w.theCadou;
		this->buget = w.buget;
	}

	Wishlist6& operator=(const Wishlist6& w) {
		if (this != &w) {
			this->theCadou = w.theCadou;
			this->buget = w.buget;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Wishlist6& w);
};

ostream& operator<<(ostream& out, const Wishlist6& w) {
	out << "\nWishlist6: buget=" << w.buget << ", the cadou: " << *w.theCadou;
	return out;
}

int main() {
	Produs p1("Laptop", 3500);
	Produs p2("Telefon", 1500);
	Produs p3("Tableta", 1200);
	Produs lista[] = { p1,p2,p3 }; 
	cout << "\n--------------- Wishlist2 ---------------";
	Wishlist2 w21(lista, 3, 1000);
	cout << w21;
	cout << "\n--------------- Wishlist3 ---------------";
	Produs* lista2[] = { &p1, &p2, new Produs("Pix",150) };
	Wishlist3 w31(lista2, 3, 1000);
	cout << w31;
	//noi, cei din main, suntem responsabili sa dezalocam pe Produs pix
	delete lista2[2];
	cout << "\n--------------- Wishlist4 ---------------";
	Produs* lista3[] = { &p1, &p2, new Produs("Glob de Craciun",150) };
	Wishlist4 w41(lista3, 3, 1000);
	cout << w41;
	//vrem sa validam contextul de shallow copy (magazinul Emag schimba pretul pentru produsul Laptop). Vrem sa vedem daca whishlist w41 vede noul pret
	p1.setPret(3300);
	cout << w41;
	//noi, cei din main, suntem responsabili sa dezalocam pe Produs Glob de Craciun
	delete lista3[2];
	cout << "\n--------------- Wishlist4_1 ---------------";
	Produs* lista4[] = { &p1, &p2, new Produs("Glob de Craciun",150) };
	Wishlist4 w411(lista4, 3, 1000);
	cout << w411;
	delete lista4[2];
	cout << "\n--------------- Wishlist6 ---------------";
	Wishlist6 w61(&p1, 1000);
	cout << w61;
	cout << "\n--------------- operator[] pentru clasa Wishlist ---------------";
	Wishlist w(lista, 3, 1000);
	cout << w;
	Produs p = w[0];
	cout << "\nProdusul extras pe baza operatorului []: " << p;
	w[0].setPret(1000);
	cout << w;
	return 0;
}