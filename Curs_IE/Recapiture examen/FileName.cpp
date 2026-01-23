#include <iostream>
using namespace std;

//char*
//string* / float* / int* /enum* / bool*

//lista de ingrediente pentru o prajitura
	//string* ->se introduce valorile la "liber"
	//ne definim enum(Ingredient) care cuprinde lista tuturor ingredientelor stabilite iar apoi Ingredient* listaIngrediente

//constante si statice in clase
//constante -> int/string
//statice -> statice folosite ca generatoare de coduri unice
		 //-> folosite pentru validari (varstaMinima, gramajMinim)
		 //-> pretAmbalaj
		 //->vector static(la nivelul clasei) care stocheaza preturile culturilor (grau, porumb, etc....)
		 //->meth statice(nu au this, nu sunt apelate plecand de la un obj de tipul clasei, ci sunt apelate prin numele clasei)
class Prajitura {
	const string denumire;
	const int cod;
	bool gatitCuptor = true;
	float* cantitate = nullptr;
	int nrIngrediente = 0;
	float pret;
public:
	Prajitura() :cod(0), denumire("Anonim") {

	}

	Prajitura(string _denumire, int _cod, bool _gatitCuptor, float* _cantitate, int _nrIngrediente, float _pret) :denumire(_denumire), cod(_cod) {
		this->gatitCuptor = _gatitCuptor;
		this->pret = _pret;
		if (_cantitate != nullptr && _nrIngrediente > 0) {
			this->nrIngrediente = _nrIngrediente;
			this->cantitate = new float[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++) {
				this->cantitate[i] = _cantitate[i];
			}
		}
	}

	//set si get
	void setCantitati(float* _cantitate, int _nrIngrediente) {
		//dezalocam din this
		//verificam ce primim ca parametru
		//alocam in this si copiem
	}

	float* getCantitati() {
		//nu returnam direct din this pentru ca incalcam incapsularea
		//return this->cantitate;
		float* copie = nullptr;
		if (this->nrIngrediente > 0) {
			copie = new float[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++) {
				copie[i] = this->cantitate[i];
			}
		}
		return copie;
	}

	float getCantitate(int _index) {
		if (_index >= 0 && _index < this->nrIngrediente) {
			return this->cantitate[_index];
		}
	}

	void setCantitate(int _index, float _valoare) {
		//modific o anume cantitate de pe pozitia index cu o alta valoarea primita ca parametru
		if (_index >= 0 && _index < this->nrIngrediente) {
			this->cantitate[_index] = _valoare;
		}
	}

	//de lucrat si get si set pe char*

	static int methStatica(int* v, int n) {
		//to do in functie de cerinta
		return n;
	}
	static void prajituriGatite(Prajitura v[10], int n) {
		for (int i = 0; i < n; i++) {
			if (v[i].gatitCuptor) {
				//cout << v[i];
			}
		}
	}

	//operator +=
	//lucreaza direct pe this
	Prajitura& operator+=(float _adaosPret) {
		this->pret += _adaosPret;
		return *this;
	}

	//casturi/conversii

	Prajitura operator+(float _adaosPret) const {
		Prajitura rezultat = *this;
		rezultat.pret += _adaosPret;
		return rezultat;
	}

	friend istream& operator>>(istream& in, Prajitura& p);
};

istream& operator>>(istream& in, Prajitura& p) {
	//dezalocam inainte memoria alocata in p
	//dupa ce faceti citirea, trebuie si realocare de zona de memorie
	return in;
}

Prajitura operator+(float _adaosPret, const Prajitura& p) {
	return p + _adaosPret;
}

//diferenta intre metoda/fct statica si functie globala
Prajitura functieGlobala(Prajitura p1, Prajitura p2) {
	//to do
	Prajitura p4;
	return p4;
}

//has a ->obiecte sau ->pointeri(pot face shallow copy sau deep copy)
//has a-> relatia de 1-1

//relatia de compunere ( has a)
class Cofetarie {
	Prajitura* lista[100];
	int nrPrajituri;
	string denumire;

	Cofetarie(Prajitura* _lista[100], int _nrPrajituri, string _denumire) {
		this->denumire = _denumire;
		if (_lista != nullptr && _nrPrajituri > 0) {
			this->nrPrajituri = _nrPrajituri;
			for (int i = 0; i < this->nrPrajituri; i++) {
				lista[i] = _lista[i];//shallow copy
				lista[i] = new Prajitura(*_lista[i]);//deep copy
			}
		}
	}
};

//class Tort {
//	Blat blat;
//	Umplutura umplutura;
//	Topping cremaExterior;
//};

//relatia is a
class Ecler :public Prajitura {
	string umplutura;

public:
	Ecler() :Prajitura("", 0, true, nullptr, 0, 0) {

	}

	Ecler(string _umplutura) {
		this->umplutura = _umplutura;
	}
};

enum Ingredient {
	FAINA, OUA, LAPTE, VANILIE, CIOCOLATA
};

class Prajitura2 {
	Ingredient* lista;
	int nrIngrediente;

	static float preturi[4];

public:
	Prajitura2(Ingredient* _lista, int _nrIngrediente) {
		if (_lista != nullptr && _nrIngrediente > 0) {
			this->nrIngrediente = _nrIngrediente;
			this->lista = new Ingredient[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++) {
				this->lista[i] = _lista[i];
			}
		}
	}
};

int main() {
	Ingredient v[] = { OUA, VANILIE, CIOCOLATA, LAPTE };
	Prajitura2 prajitura(v, 4);

	Prajitura::methStatica(nullptr, 6);
	Prajitura p1;
	float* v = p1.getCantitati();
	delete[] v;
	v = nullptr;
	Prajitura p2;
	p1 = p2 + 10; //trebuie sa se permita comutativitatea op +
	p1 = p2.operator+(10);

	//NU SE POATE DECLARA UN VECTOR DE OBIECTE
	//Prajitura v[10];
	//Prajitura* vp;
	//vp = new Prajitura[5];

	Ecler e;
	
	return 0;
}
