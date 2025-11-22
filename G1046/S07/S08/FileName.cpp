#include <iostream>

using namespace std;

// TODO @ HOME PT CURS
// Pt o clasa care are un id constant propuneti mecanisme sa fie citit 
// de la tastatura si sa acutalizeze id ul obiectului current citit la operator >>

enum TipObiect
{
	NAVA, AVION, ROCA
};

class Obiect2D
{
	TipObiect tip = TipObiect::NAVA;
	int nivelViata = 100;
	int pozX = 0;
	int pozY = 0;

public:

	Obiect2D()
	{

	}

	Obiect2D(TipObiect _tip, int _pozX, int _pozY)
	{
		this->tip = _tip;

		this->pozX = _pozX;
		this->pozY = _pozY;
	}

	friend ostream& operator<<(ostream& out, const Obiect2D& o)
	{

		// asta nu ineamna ca este metoda a clasei
		cout << "\nTip: " << o.tip;
		cout << "\nNivel Viata: " << o.nivelViata;
		cout << "\n(X, Y) : (" << o.pozX << ", " << o.pozY << ")";

		return out;
	}
};


// obiect sau referina 
// deep sau shallow copy

//// @HOME
//class Joc2
//{
//	string utilizatorul;
//	int nivelDificultate;
//	int scor;
//	Obiect2D lista[200]; // vector alocat STATIC de Obiect2D
//	int nrObiecte = 0;
//};
//
//implemetnarea sa fie prin deep copy vers 1 si shallow copy vers 2
//class Joc3
//{
//	string utilizatorul;
//	int nivelDificultate;
//	int scor;
//	Obiect2D* lista[200]; // vector static  de Obiect2D*
//	int nrObiecte = 0;
//};
//
//class Joc4
//{
//	string utilizatorul;
//	int nivelDificultate;
//	int scor;
//	Obiect2D** lista; // vector  dinamic de Obiect2D*
//	int nrObiecte = 0;
//};
//
//// relatie compunere 1-1
//class Joc5
//{
//	string utilizatorul;
//	int nivelDificultate;
//	int scor;
//	Obiect2D obiect; //un obiect
//};
//// relatie compunere 1-1 altfel
//class Joc6
//{
//	string utilizatorul;
//	int nivelDificultate;
//	int scor;
//	Obiect2D* obiect; //un pointer catre un obiect
//};
//class Joc7
//{
//	string utilizatorul;
//	int nrNiveluriDificultate;
//	int* scor; // dim vector de nrNiveluriDificultate
//	int* nrObiecte; // dim vector de nrNiveluriDificultate
//	Obiect2D** lista; // matrice cu vector de dim nrNiveluriDificultate de dim de nrObiecte[nrNiveluriDificultate]
//
//};

// relatia de compunere 1 - M (has a)
class Joc
{
	string utilizatorul = "Anonim";
	int nivelDificultate = 0;
	int scor = 0;
	Obiect2D** lista = nullptr; // vector alocat dinamic de adrese la obiecte Obiect2D
	int nrObiecte = 0;

public:
	Joc() {}

	Joc(string _utilizatorul, int _nivelDificultate, int _scor, Obiect2D** _lista, int _nrObiecte)
	{
		this->utilizatorul = _utilizatorul;
		this->nivelDificultate = _nivelDificultate;

		this->scor = _scor;

		if (_nrObiecte > 0 && _lista != nullptr)
		{
			this->nrObiecte = _nrObiecte;
			this->lista = new Obiect2D * [this->nrObiecte];

			for (int i = 0; i < this->nrObiecte; i++)
			{
				// this->lista[i] = _lista[i]; // asa e shallow copy

				this->lista[i] = new Obiect2D(*_lista[i]); // deep copy
			}
		}
	}

	Joc(Joc& j)
	{
		this->utilizatorul = j.utilizatorul;
		this->nivelDificultate = j.nivelDificultate;

		this->scor = j.scor;

		if (j.nrObiecte > 0 && j.lista != nullptr)
		{
			this->nrObiecte = j.nrObiecte;
			this->lista = new Obiect2D * [this->nrObiecte];

			for (int i = 0; i < this->nrObiecte; i++)
			{
				this->lista[i] = new Obiect2D(*j.lista[i]); // deep copy
			}
		}
	}

	~Joc()
	{
		if (this->nrObiecte > 0 && this->lista != nullptr)
		{
			for (int i = 0; i < this->nrObiecte; i++)
			{
				delete this->lista[i];
			}

			delete[] this->lista;
			this->lista = nullptr;
			this->nrObiecte = 0;

		}
	}

	friend ostream& operator<< (ostream& out, Joc j)
	{
		out << "\nUtilizator: " << j.utilizatorul;
		out << "\nNivel Dif: " << j.nivelDificultate;
		out << "\nScor: " << j.scor;


		out << "\nNr Obiecte: " << j.nrObiecte << "\nObiecte: ";


		for (int i = 0; i < j.nrObiecte; i++)
		{
			out << *j.lista[i];
		}

		return out;
	}


	Joc& operator= (const Joc& j)
	{

		if (this != &j)
		{
			//destructor
			if (this->nrObiecte > 0 && this->lista != nullptr)
			{
				for (int i = 0; i < this->nrObiecte; i++)
				{
					delete this->lista[i];
				}

				delete[] this->lista;
				this->lista = nullptr;
				this->nrObiecte = 0;

			}

			//constrictor de copiere
			this->utilizatorul = j.utilizatorul;
			this->nivelDificultate = j.nivelDificultate;

			this->scor = j.scor;

			if (j.nrObiecte > 0 && j.lista != nullptr)
			{
				this->nrObiecte = j.nrObiecte;
				this->lista = new Obiect2D * [this->nrObiecte];

				for (int i = 0; i < this->nrObiecte; i++)
				{
					this->lista[i] = new Obiect2D(*j.lista[i]); // deep copy
				}
			}
			else
			{
				this->lista = nullptr;
				this->nrObiecte = 0;
			}
		}

		return *this;
	}

};

// TEMA SEMINAR
// 1. de adaugat clasa Proiectil (pozX, putereAtac)
// 2. de adaugat la clasa joc xMax , yMax (dim canvasului)
// 3. clasa Joc, metoda care adauga un nou Obiect2D tipul e generat aleator (iar pozitiile se valideaza cu try catch)
// 4. clasa Joc de adaugat metoda de lansareProiectil care primeste un obiect de tip Proiectil 
//		(ataca toatae obiecte de pe acel poz x pana nu mai are putere) 
//		(cand ataca, proiectilul distruge obiectele (deci se scot din Joc)
// 5. clasa Obiect2D, de implementat o metoda esteAtacat(proiectil) 
// 6. De reproiectat clasa joc dpdv al stocarii obiectelor Obiect2D 
//		astfel incat sa se caute optimizat obiectele care sunt pe o anumita traiectorie

int main()
{




	Obiect2D o1(TipObiect::AVION, 100, 21);
	Obiect2D o2(TipObiect::NAVA, 0, 24);
	Obiect2D o3(TipObiect::ROCA, 50, 211);

	Obiect2D* v[] = { &o1, &o3, &o3 };

	Joc j1("Gigel", 3, 0, v, 3);

	cout << j1;

	Joc j2(j1);

	cout << j2;

	Joc j3(j2);

	cout << j3;


	return 0;
}

// TODO Copy Elision