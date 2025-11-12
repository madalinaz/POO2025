#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


//clasa Masina  care contine VIN/seria sasiu(const si unica) +  nr inmatriculare(unic DAR NU CONSTANT) 
//sa ofere posibilitatea de schimbare nr inmatriculare (generat aleator) sau prefererential(dar sa fie disponibil)
// sa ofere posibilitatea de a schimba proprietarul
//+ proprietar


class Apartament
{
	const int id; //este generat automat pentru a asigura unicitatea
	int nrCamere = 0;
	double* suprafata = nullptr;
	static int generatorId; //care ma ajuta pentru id urile apartamentelor
	static double suprafataMaxima; //camera cu cea mai mare suprafata din apartamentele existente
	//home
	//static double suprafataTotala; //suprafata totala a tuturor apartamentelor
	//static int nrApartamente; // contorizeaza nr total curent de apartamente ->contorul creste la fiecare apel al constructorului si scade la fiecare apel al destructorului

public:
	Apartament() : id(Apartament::generatorId++)
	{

	}

	//constructor cu toti param
	Apartament(int _nrCamere, double* _suprafata) : id(Apartament::generatorId++)
	{
		if (_nrCamere > 0 && _suprafata != nullptr)
		{
			this->nrCamere = _nrCamere;
			this->suprafata = new double[_nrCamere];
			for (int i = 0; i < this->nrCamere; i++)
			{
				this->suprafata[i] = _suprafata[i];
			}
		}
		//gestionare camp static suprafataMaxima
		for (int i = 0; i < this->nrCamere; i++)
		{
			if (this->suprafata[i] > Apartament::suprafataMaxima)
			{
				Apartament::suprafataMaxima = this->suprafata[i];
			}
		}
	}
	//constructor de copiere
	Apartament(const Apartament& a) :id(Apartament::generatorId++)
	{
		if (a.nrCamere > 0 && a.suprafata != nullptr)
		{
			this->nrCamere = a.nrCamere;
			this->suprafata = new double[a.nrCamere];
			for (int i = 0; i < this->nrCamere; i++)
			{
				this->suprafata[i] = a.suprafata[i];
			}
		}
		else
		{
			this->nrCamere = 0;
			this->suprafata = nullptr;
		}
		//gestionare camp static suprafataMaxima -> nu gestionam camp static pentru ca nu generam suprafete noi
		/*for (int i = 0;i < this->nrCamere;i++)
		{
			if (this->suprafata[i] > Apartament::suprafataMaxima)
			{
				Apartament::suprafataMaxima = this->suprafata[i];
			}
		}*/
	}

	//operator de atribuire
	Apartament& operator=(const Apartament& a)
	{
		//verificare autoasignare
		if (this != &a)
		{
			//destructor
			if (this->suprafata != nullptr)
			{
				delete[] this->suprafata;
				this->suprafata = nullptr;
			}
			//constructor copiere
			if (a.nrCamere > 0 && a.suprafata != nullptr)
			{
				this->nrCamere = a.nrCamere;
				this->suprafata = new double[a.nrCamere];
				for (int i = 0; i < this->nrCamere; i++)
				{
					this->suprafata[i] = a.suprafata[i];
				}
			}

		}
		return *this;
	}
	//operator >= pentru a compara suprafata totala a unui apartament cu o valoare data
	bool operator>=(double _x)
	{
		double suprafataTotala = 0;
		for (int i = 0; i < this->nrCamere; i++)
		{
			suprafataTotala += this->suprafata[i];
		}
		return suprafataTotala >= _x;
	}
	~Apartament()
	{
		if (this->suprafata != nullptr)
		{
			delete[] this->suprafata;
			this->suprafata = nullptr;
		}
	}

	void afisare()
	{
		cout << "\nId apartament: " << this->id << endl;
		cout << "Nr camere: " << this->nrCamere << endl;
		for (int i = 0; i < this->nrCamere; i++)
		{
			cout << "Suprafata camera " << i + 1 << ": " << this->suprafata[i] << endl;
		}
	}

	//getter pt suprafata
	static double getSuprafataMaxima()
	{
		return Apartament::suprafataMaxima;
	}
};

int Apartament::generatorId = 100;
double Apartament::suprafataMaxima = 0;

int main() {

	Apartament a1;
	a1.afisare();
	cout << "\nSuprafata maxima: " << Apartament::getSuprafataMaxima() << endl;
	double v[] = { 12.5,15.3,20.1 }; //vector alocat static
	Apartament a2(3, v);

	a2.afisare();
	cout << "\nSuprafata maxima: " << Apartament::getSuprafataMaxima() << endl;
	//constructor de copiere
	Apartament a3(a2);
	a3.afisare();
	a3 = a2; // diferenta intre constructor de copiere si operator de atribuire este ca la constructorul de copiere se creeaza un obiect nou iar la operatorul de atribuire se suprascrie un obiect existent
	a3.afisare();
	a3 = a1; //nu functioneaza corect pentru ca a1 nu are suprafete alocate .
	//a3.afisare();

	if (a2 >= 100)
	{
		cout << "\nApartamentul a2 are suprafata totala mai mare sau egala decat 100";
	}
	else
	{
		cout << "\nApartamentul a2 are suprafata totala mai mica decat 100";
	}
	return 0;
}