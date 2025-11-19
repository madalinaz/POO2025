#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//de facut tema de la S7

//to do
//relatia de compunere (has a) 
//try-catch
//operatori

//is a (relatia de mostenire)

class Caracter {
	string denumire = "Anonim";
	int nivelViata = 100;
	int x = 0; //pozitionare in plan dimensional
	int y = 0; //pozitionare in plan dimensional

public:
	Caracter() {
		//cout << "\nApel constr fara param";
	}

	Caracter(string _denumire, int _nivelViata, int _x, int _y) {
		this->denumire = _denumire;
		this->nivelViata = _nivelViata;
		this->x = _x;
		this->y = _y;
	}

	//constr de copiere
	Caracter(const Caracter& c) {
		//cout << "\nApel copy";
		this->denumire = c.denumire;
		this->nivelViata = c.nivelViata;
		this->x = c.x;
		this->y = c.y;
	}

	Caracter& operator=(const Caracter& c) {
		if (this != &c) {
			this->denumire = c.denumire;
			this->nivelViata = c.nivelViata;
			this->x = c.x;
			this->y = c.y;
		}
		return *this;
	}

	~Caracter() {
		//cout << "\nApel destructor";
	}

	void afisare() {
		cout << "\nDenumire: " << this->denumire << ", nivel viata: " << this->nivelViata;
		cout << ", x: " << this->x << ", y=" << this->y;
	}
};

Caracter f(Caracter& c) {
	//to do
	//Caracter c;
	return c;
}

class Canvas5 {
	//stocam pt fiecare jucator canvasul sau format dintr-un vector dinamic de Caracter
	//vector dinamic de Caracter
	Caracter** lista; //daca e static Caracter*[3] SAU Caracter** poate deveni matrice zig-zag
	int nrJucatori;
	int* nrCaractere;//stocam pt fiecare jucator cate caractere are un joc
	int xMax;
	int yMax;
};

class Canvas4 {
	//vector alocat dinamic de Caracter*
	Caracter** lista; //* ATRIBUIM DIMENSIUNII DE VECTOR, *o lipim de obiect
	int nrCaractere;
	int xMax;
	int yMax;
};

class Canvas3 {
	//vector alocat static de Caracter*
	//exemplu lista de favorite emag
	Caracter* lista[50]; //ca sa fie mai usor de accesat, optimizare de memorie
	int nrCaractere;
	int xMax;
	int yMax;
};

//to do home
class Canvas2 {
	//vector alocat static de Caracter
	Caracter lista[50]; //obiect
	int nrCaractere;
	int xMax;
	int yMax;
};

//clasa Canvas sa fie in relatie has a cu clasa Caracter -> tre sa detina cel putin un caracter
class Canvas {
	//vector alocat dinamic de Caracter
	Caracter* lista = nullptr;
	int nrCaractere = 0;
	int xMax = 0;
	int yMax = 0;

public:

	Canvas() {
	}

	Canvas(Caracter* _lista, int _nrCaractere, int _xMax, int _yMax) {
		//pp ca poz caracterelor sunt corecte
		if (_nrCaractere > 0 && _lista != nullptr) {
			this->nrCaractere = _nrCaractere;
			this->lista = new Caracter[this->nrCaractere]; //se apeleaza constr fara param
			for (int i = 0; i < this->nrCaractere; i++) {
				this->lista[i] = _lista[i]; //am asignat, se apeleaza operatorul=
			}
		}
		this->xMax = _xMax;
		this->yMax = _yMax;
	}

	Canvas(const Canvas& c) {
		if (c.nrCaractere > 0 && c.lista != nullptr) {
			this->nrCaractere = c.nrCaractere;
			this->lista = new Caracter[this->nrCaractere]; //se apeleaza constr fara param
			for (int i = 0; i < this->nrCaractere; i++) {
				this->lista[i] = c.lista[i]; //am asignat, se apeleaza operatorul=
			}
		}
		this->xMax = c.xMax;
		this->yMax = c.yMax;
	}

	Canvas& operator=(const Canvas& c) {
		if (this != &c) {
			if (this->lista != nullptr) {
				delete[] this->lista;
				this->lista = nullptr;
			}
			if (c.nrCaractere > 0 && c.lista != nullptr) {
				this->nrCaractere = c.nrCaractere;
				this->lista = new Caracter[this->nrCaractere]; //se apeleaza constr fara param
				for (int i = 0; i < this->nrCaractere; i++) {
					this->lista[i] = c.lista[i]; //am asignat, se apeleaza operatorul=
				}
			}
			else {
				this->lista = nullptr;
				this->nrCaractere = 0;
			}
			this->xMax = c.xMax;
			this->yMax = c.yMax;
		}
		return *this;
	}

	void afisare() {
		cout << "\nCaractere: ";
		for (int i = 0; i < this->nrCaractere; i++) {
			this->lista[i].afisare(); //nu putem cu cout pt ca n avem operatorul<<
		}
		cout << "\nNr caractere: " << this->nrCaractere;
		cout << "\nxMax: " << this->xMax;
		cout << "\nyMax: " << this->yMax;
	}

	~Canvas() {
		if (this->lista != nullptr) {
			delete[] this->lista;
			this->lista = nullptr;
		}
	}

};

int main() {
	//Caracter c2;
	//Caracter c1 = c2;
	////copy elision - eludarea copierii (ma astept la 2 si produce una singura) - se intamla DOAR LA CONSTR DE OBIECTE si la RETURN-URI. 
	////Chiar daca return ul e prin valoare, nu se face copie.
	//cout << "\n--- copy elision---";
	//Caracter car = f(c1); //trimisa pe baza constr de copiere (se apeleaza)
	//cout << "\n--- copy elision---";
	//car = f(c1);//return prin valoare, deci se face copie care apoi se distruge
	//cout << "\n--- copy elision---";
	Caracter c1("C1", 100, 20, 30);
	Caracter c2("Steve", 100, 40, 100);
	Caracter c3("Mario", 70, 80, 90);
	Caracter v[] = { c1, c2, c3 }; //apel de 3 ori constr copiere
	Canvas cv1(v, 3, 100, 100);
	cv1.afisare();
	Canvas cv2(cv1);
	cv2.afisare();

	Canvas cv3;
	cv3 = cv2;
	cv3.afisare();

	return 0;
}