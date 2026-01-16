#include<iostream>
using namespace std;

enum Judet{
	B, IF, CJ
};

class Companie {
	const int cod;//cod companie (cod unic primit ca parametru de catre constructori)
	//exersati cu un const care nu este primit ca parametru de catre constructor, dar este generat automat pe baza unui camp static (generatorId sau ctCompanie)
	string denumire="Anonim";//sir de caractere (daca se cere sir de caractere alocat dinamic ->char*)
	int nrAngajati=0;
	double* salarii=nullptr;//vector alocat dinamic ce stocheaza salariul pentru fiecare angajat in parte(dimensiunea vectorului este data de nrAngajati) (Acasa, de lucrat si pe alti vectori alocati dinamic (int* / bool* / string* !!!!! -> vector de siruri de caractere (ex: vector format din numele tuturor angajatilor din cadrul companiei))
	Judet judet = Judet::B;
	double cifraAfaceri=0;

public:
	Companie(int _cod):cod(_cod) {
		//nu mai avem nevoie de nimic, avem deja initializarile pentru celelalte facute la declarare
	}

	Companie(int _cod, string _denumire, int _nrAngajati, double* _salarii, Judet _judet, double _cifraAfaceri):cod(_cod) {
		this->denumire = _denumire;
		if (_nrAngajati > 0 && _salarii != nullptr) {
			this->nrAngajati = _nrAngajati;
			this->salarii = new double[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = _salarii[i];
			}
			this->cifraAfaceri = _cifraAfaceri;
		}
		this->judet = _judet;
	}

	//construiesc un obj nou pe baza unui obj existent (c)
	Companie(const Companie& c):cod(c.cod) {
		this->denumire = c.denumire;
		if (c.nrAngajati > 0 && c.salarii != nullptr) {
			this->nrAngajati = c.nrAngajati;
			this->salarii = new double[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = c.salarii[i];
			}
			this->cifraAfaceri = c.cifraAfaceri;
		}
		this->judet = c.judet;
	}

	Companie& operator=(const Companie& c) {
		if (this != &c) //verificam sa nu fim in auto-asignare
		{
			//destructor -> ptr ca obj this deja exista, deci poate are nevoie de dezalocari
			if (this->salarii != nullptr) {
				delete[] this->salarii;
				this->salarii = nullptr;
			}
			//constructor de copiere
			this->denumire = c.denumire;
			if (c.nrAngajati > 0 && c.salarii != nullptr) {
				this->nrAngajati = c.nrAngajati;
				this->salarii = new double[this->nrAngajati];
				for (int i = 0; i < this->nrAngajati; i++) {
					this->salarii[i] = c.salarii[i];
				}
				this->cifraAfaceri = c.cifraAfaceri;
			}
			else { //acopera situatia in care this-ul avea inainte elemente in vector dar c-ul nu are, deci si this-ul acum trebuie sa fie "gol"
				this->nrAngajati = 0;
				this->salarii = nullptr;
			}
			this->judet = c.judet;
		}
		return *this;
	}

	~Companie() {
		if (this->salarii != nullptr) {
			delete[] this->salarii;
			this->salarii = nullptr;
		}
	}

	friend ostream& operator<<(ostream& out, const Companie& c) {
		out << "\nCod: " << c.cod;
		out << "\nDenumire: " << c.denumire;
		out << "\nNr angajati: " << c.nrAngajati;
		out << "\nSalarii angajati: ";
		for (int i = 0; i < c.nrAngajati; i++) {
			out << c.salarii[i] << " ";
		}
		out << "\nJudet: " << c.judet;//se va afisa codul aferent fiecarui judet 
		out << "\nCifra afaceri: " << c.cifraAfaceri;
		return out;
	}

	//exemplu metoda de prelucrare
	double getTotalSalarii() {
		double total = 0;
		for (int i = 0; i < this->nrAngajati; i++) {
			total += this->salarii[i];
		}
		return total;
	}

	//sa se afiseze salariile care depasesc un prag primit ca parametru
	void afisareSalariiPestePrag(double _prag) {
		bool afisat = false;
		for (int i = 0; i < this->nrAngajati; i++) {
			if (this->salarii[i] > _prag) {
				cout << this->salarii[i] << " ";
				afisat = true;
			}
		}
		if (!afisat) {
			cout << "\nNu exista astfel de salarii";
		}
	}

	//OPERATORI
	Companie& operator+=(double _x) {
		if (_x > 0) {
			this->cifraAfaceri += _x;
		}
		return *this;
	}

	//pre-incrementare
	Companie& operator++() {//returnam referinta intrucat returnam this-ul, care nu se distruge impreuna cu stiva functiei operatorului
		//creste cu 1%
		this->cifraAfaceri *= 1.01;
		return *this;//returnam obj de dupa incrementare
	}

	//post-incrementare
	Companie operator++(int) {
		Companie copie = *this;
		this->cifraAfaceri *= 1.01;
		return copie;//returnam obj de dinainte de incrementare
	}

	//cast la string
	operator string() {
		return this->denumire;
	}

	//cast la double explicit
	explicit operator double() {
		//salariul cel mai mare
		double max = 0;
		for (int i = 0; i < this->nrAngajati; i++) {
			if (this->salarii[i] > max) {
				max = this->salarii[i];
			}
		}
		return max;
	}

	double operator+(int _x) const{
		//NU se modifica this-ul!!!!!!
		return this->cifraAfaceri + _x;
	}

	Companie operator+(string _x) const{//return prin valoare a lui rezultat pentru ca el se va distruge
		Companie rezultat = *this;
		rezultat.denumire += _x;//concatenare pe string-uri
		return rezultat;
	}
};

//has a 1-M
class Persoana {
	string denumire;
	int nrCompanii;
	Companie* lista;//colectia companiilor la care persoana curenta este actionar

public:

};

// relatie has a 1-1
// class Masina has a 1 Proprietar
//class Masina {
//	string model;
//	int anFabricatie;
//	Proprietar proprietar;
//};

int main() {
	Companie c1(105);
	double v[] = { 100, 120, 150.5, 160 ,90};//vector alocat static
	Companie c2(103, "XYZ S.A.", 5, v, Judet::CJ,10000);
	cout << c1;
	cout << c2;//I operand (cout) NU este de tipul clasei, deci supraincarcam obligatoriu prin functie globala friend, deci NU va exista nici this
	Companie c3(c2);//apel constructor copiere
	Companie c4 = c2;//apel constructor copiere
	cout << c4;
	c1 = c2;//operator de atribuire este obligatoriu daca am cel putin un camp din clasa alocat dinamic
	cout << c1;

	//meth de prelucrare pe vector -> min/max/ suma(total) / medie /cautare
	cout << "\nTotal salarii: " << c1.getTotalSalarii();
	cout << "\nSalarii peste pragul de 150: ";
	c1.afisareSalariiPestePrag(150);

	//operatori
	c1 += 10; //lucreaza direct pe this
	cout << c1;

	
	c2 = ++c1;//forma de pre incrementare
	cout << c2;
	cout << c1;
	c2 = c1++;//post incrementare
	cout << c2;
	cout << c1;

	string denumire = c2; //cast la string (conversie) /operator string
	cout << "\nDenumire folosind cast la string: " << denumire;
	double salariuMax = (double)c2;//apel cast la double explicit
	cout << "\nSalariu max folosind cast la double este: " << salariuMax;

	double rezultat = c2 + 10;//rezultat va lua valoarea CA a lui c2 la care suplimenteaza valoarea 10
	//double rezultat2 = 10 + c2;//obligatoriu se implementeaza prin functie friend, pentru ca primul operator nu este de tipul clasei
	Companie c5 = c2 + "AB";//operatorul plus completeaza numele companiei cu ce primeste suplimentar ca parametru
	cout << c5;

	//cin >> c5;


	return 0;
}