#include <iostream>
using namespace std;
//Tema - Sa se modeleze clasa masina(VIN/seria de sasium nr inmatriculare +extra: model, an fabricatie, echipare etc)
//VIN - ul este unic si constant(o primim ca parametru dar verificam ca este unica)
//numarul de inmatriculare este unic dar nu constant
//numarul se poate schimba cu un alt numar generat aleator sau cu numar preferential
//+modalitate de verificare a disponibilitatii numarului
//doua motive pentru care avem transfer prin referinta:
//ocolirea copierii/modificarea obiectului
//sa se modifice implementarea curenta ai id-ul generat sa respecte o regula - de ex: sa aibe cifre diferie
class Abonat {
	const int id;
	int nrApeluri = 0;
	string* apeluri = nullptr; //lista persoanelor contactate
	static int generatorID; //ajuta la generarea id-urilor dupa o regula

public:
	Abonat() :id(Abonat::generatorID++)
	{
	}
	Abonat(int _nrApeluri, string* _apeluri) :id(Abonat::generatorID++)
	{
		if (_nrApeluri > 0 && _apeluri != nullptr)
		{
			this->nrApeluri = _nrApeluri;
			this->apeluri = new string[this->nrApeluri];

			for (int i = 0; i < this->nrApeluri; i++)
			{
				this->apeluri[i] = _apeluri[i];
			}
		}
	}
	Abonat(const Abonat& a) :id(Abonat::generatorID++)
	{

		if (a.nrApeluri > 0 && a.apeluri != nullptr)
		{
			this->nrApeluri = a.nrApeluri;
			this->apeluri = new string[a.nrApeluri];

			for (int i = 0; i < this->nrApeluri; i++)
			{
				this->apeluri[i] = a.apeluri[i];
			}
		}
	}
	Abonat& operator=(const Abonat& a)
	{
		if (this != &a)
		{
			//destructor
			if (this->apeluri != nullptr)
			{
				delete[] this->apeluri;
				this->apeluri = nullptr;
			}
			//constructor de copiere
			if (a.nrApeluri > 0 && a.apeluri != nullptr)
			{
				this->nrApeluri = a.nrApeluri;
				this->apeluri = new string[a.nrApeluri];

				for (int i = 0; i < this->nrApeluri; i++)
				{
					this->apeluri[i] = a.apeluri[i];
				}
			}
			else
			{
				this->nrApeluri = 0;
				this->apeluri = nullptr;

			}
		}
		return *this;
		//return dereferentierea this-ului
	}
	bool operator==(string _x)
	{
		for (int i = 0; i < this->nrApeluri; i++)
		{
			if (this->apeluri[i] == _x)
				return true;
		}
		return false;
	}
	void afisare()
	{
		cout << this->id << " " << this->nrApeluri << " ";
		cout << "\n";
		for (int i = 0; i < this->nrApeluri; i++)
		{
			cout << this->apeluri[i] << " ";
		}

	}

	~Abonat()
	{
		if (this->apeluri != nullptr)
		{
			delete[] this->apeluri;
			this->apeluri = nullptr;
		}
	}
	friend bool operator<(int _x, const Abonat& a);
};
int Abonat::generatorID = 1000;
bool operator<(int _x, const Abonat& a)
{
	if (_x < a.nrApeluri)
		return true;
	return false;
}
int main()
{
	Abonat a;
	a.afisare();
	string vector[] = { "Ana", "Victor", "Gigel" };
	Abonat a1(3, vector);
	//Abonat a2 = a1;
	//a2.afisare();
	Abonat a2;
	a2 = a1;
	a2.afisare();
	if (a2 == "Victoras")

		cout << "A4 l-a contactat pe Victor.";
	else
		cout << "A4 nu l-a contactat pe Victor.";




	return 0;
}