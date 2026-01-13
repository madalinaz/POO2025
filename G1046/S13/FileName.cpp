#include<iostream>
#include<vector>
using namespace std;

class Angajat {
	string nume = "";
	float salariu = 0;

public:

	Angajat(string _nume, float _salariu) {
		this->nume = _nume;
		this->salariu = _salariu;
	}

	friend ostream& operator<<(ostream& out, const Angajat& a) {
		out << "\nNume: " << a.nume << ", salariu: " << a.salariu;
		return out;
	}
};

//clasa Concediu ->campuri la alegere

//colectie/relatie has a; clasa template
//o clasa care sa retina informatii pentru fiecare Angajat, o colectie de elemente generice (acea colectie/vector/lista -> un set de sporuri/ un set de concedii/.....)

//clasa template
//ColectieAngajati has a Angajat
template<class T>
class ColectieAngajati
{
	// Var 1
	// vector pt contorizarea angajatilor (shallow copy)
	// matrice cu obj generice (matrice de tip zig-zag)

	vector<Angajat*> angajati; //= vector<Angajat*>();
	vector<vector<T>> colectie; //= vector<vector<T>>();

public:

	// constr fara param
	// constr cu un singur param marimea de angajati
	// meth care adauga un nou T pt un anume angajat
	// o metoda de afisare 
	// 

	int getNumarAngajati()
	{
		return angajati.size();
	}

	ColectieAngajati()
	{
		cout << "Constructor fara param." << endl;
	}

	ColectieAngajati(int marime, Angajat** a) // :angajati(vector<Angajat*>(marime, { nullptr })), colectie(vector<vector<T>>(marime, { vector<T> }))
	{
		//incarcare in this a pointerilor de tip Angajat
		for (int i = 0; i < marime; i++)
		{
			this->angajati.push_back(a[i]);
		}

		//alocare vector<T> pentru fiecare angajat primit ca parametru
		for (int i = 0; i < marime; i++)
		{
			this->colectie.push_back(vector<T>());
		}

		cout << "Constructor cu un param." << endl;
	}

	void adauga(int idx, T element)
	{
		if (idx < 0 || this->angajati.size() <= idx)
		{
			throw exception("NU exista angajatul!");
		}

		this->colectie[idx].push_back(element);
	}

	friend ostream& operator<<(ostream& out, const ColectieAngajati& c)
	{
		for (int i = 0; i < c.colectie.size(); i++)
		{
			out << *c.angajati[i];
			out << " Lista: ";
			if (c.colectie[i].size() == 0)
			{
				out << " -";
			}

			for (int j = 0; j < c.colectie[i].size(); j++)
			{
				out << c.colectie[i][j] << " ";
			}
			out << endl;
		}

		return out;
	}
};


template<class T>
class ColectieAngajatiLight {
	int nrAngajati;
	//matrice de T-uri

	//constructor fara param/cu un singur parametru (nrAngajati)
	//meth care adauga un nou T pentru un anume angajat
	//o meth de afisare a obj de tip ColectieAngajatiLight
};

void adaugareValoare(vector<vector<int>>& m, int x, int l) {
	if (l < 0 || l >= m.size()) {
		throw exception("Linia mentionata NU este valida");
	}
	m[l].push_back(x);
}

int main() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(15);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	vector<int>::iterator it;
	cout << endl;
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}

	vector<vector<int>> m; //matricea bi-dimensionala
	//adaugam pe prima linie din vector valoarea 10;
	m.push_back(vector<int>{});
	m[0].push_back(10);
	m.push_back(vector<int>{});
	m[1].push_back(20);
	m[1].push_back(100);
	m[1].push_back(30);
	m.push_back(vector<int>{});
	m[2].push_back(30);
	m[2].push_back(30);
	m.push_back(vector<int>{});
	m[3].push_back(20);
	m[3].push_back(20);
	m[3].push_back(20);

	cout << "\n**************\n";
	//o metoda/forma de afisare a matricei noastre
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[i].size(); j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	//o functie globala care primeste o matrice (vector de vectori) si separat o valoare int x si linia (int ) si adauga la sfarsitul liniei l valoarea x primita ca parametru !!!Daca linia nu este valida, se va arunca o exceptie
	try {
		adaugareValoare(m, 1234, 2);
	}
	catch (exception ex) {
		cout << endl << ex.what();
	}

	cout << "\n**************\n";
	//o metoda/forma de afisare a matricei noastre
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[i].size(); j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\n*******clasa ColectieAngajat*******\n";
	Angajat a1("A", 100);
	Angajat a2("B", 100);
	Angajat a3("C", 100);
	Angajat a4("D", 100);

	Angajat* lista[] = { &a1, &a2, &a3, &a4 };
	ColectieAngajati<int> col(4,lista);
	col.adauga(1, 100);
	col.adauga(1, 200);
	col.adauga(2, 240);
	cout << col;

	return 0;
}