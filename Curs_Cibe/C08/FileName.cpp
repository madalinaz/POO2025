#include<iostream>
using namespace std;

//= done
//comparatie (!=; ==; >....) done
//+= -= /= done
//!(negatie) done
// ++ (pre si post) done
// cast/conversie
// index [] done
// << >> done
// + - / *
//functie

class Produs {
	const int id;
	char* denumire = nullptr;
	int stoc = 0;
	double pret = 0;
public:
	Produs() :id(0) {
	}

	Produs(int _id, const char* _denumire, int _stoc, double _pret) :id(_id) {
		if (_denumire != nullptr) {
			this->denumire = new char[strlen(_denumire) + 1];
			strcpy(this->denumire, _denumire);
		}
		if (_stoc > 0) {
			this->stoc = _stoc;
		}
		if (_pret > 0) {
			this->pret = _pret;
		}
	}

	Produs(const Produs& p) :id(p.id) {
		if (p.denumire != nullptr) {
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy(this->denumire, p.denumire);
		}
		this->stoc = p.stoc;
		this->pret = p.pret;
	}

	Produs& operator=(const Produs& p) {
		if (this != &p) {
			if (this->denumire != nullptr) {
				delete[] this->denumire;
				this->denumire = nullptr;
			}
			if (p.denumire != nullptr) {
				this->denumire = new char[strlen(p.denumire) + 1];
				strcpy(this->denumire, p.denumire);
			}
			this->stoc = p.stoc;
			this->pret = p.pret;
		}
		return *this;
	}

	void afisare() {
		cout << "\nId: " << this->id;
		if (this->denumire != nullptr) {
			cout << "\nDenumire: " << this->denumire;
		}
		else {
			cout << "\nDenumire: -";
		}
		cout << "\nStoc: " << this->stoc;
		cout << "\nPret: " << this->pret;
	}

	~Produs() {
		//cout << "\nDestructor";
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}
	}

	//supraincarcare operatori
	//compara pretul lui this cu _x
	bool operator>=(double _x) {
		if (this->pret >= _x)
			return true;
		return false;
	}

	// == != < <= > >= (home)
	friend bool operator>(double _x, const Produs& p);

	//home: exista risc la Produs&?
	Produs& operator+=(int _x) {
		this->stoc += _x;
		return *this;
	}

	friend Produs& operator-=(Produs& p,
		int _x);

	bool operator!() {
		if (this->stoc == 0)
			return true;//nu exista
		return false;
	}

	friend ostream& operator<<(ostream& out, const Produs& p);

	friend istream& operator>>(istream& in, Produs& p);

	//de regula, operatorul index NU returneaza referinta
	char operator[](int _index) {
		if (this->denumire != nullptr) {
			if (_index >= 0 && _index < strlen(this->denumire)) {
				return this->denumire[_index];
			}
		}
	}

	//++ forma pre incrementare
	Produs& operator++() {
		this->stoc++;
		return *this;//returneaz starea obj de DUPA incrementare
	}

	//++ forma de post incrementare
	//nu e return prin referinta pentru ca 
	//obj copie se distruge de pe stiva
	Produs operator++(int) {
		Produs copie = *this;//copiez starea anterioara a obj 
		this->stoc++;
		return copie;//returneaza starea de DINAINTE de incremetnare
	}

	//cast implicit si explicit la string
	operator string () {
		return this->denumire;
	}

	//cast explicit la int
	//se va apela doar atunci cand se cere explicit acest lucru
	explicit operator int() {
		return this->stoc;
	}
};


//functie globala pentru supraincarcare
//pentru ca I operand nu este de tipul clasei
bool operator>(double _x, const Produs& p) {
	if (_x > p.pret)
		return true;
	return false;
}

//const NU pentru ca acest operand trebuie sa fie modificat
Produs& operator-=(Produs& p,
	int _x) {
	p.stoc -= _x;
	return p;
}

//modalitati de a citi si id-ul const
istream& operator>>(istream& in, Produs& p) {
	//obj p deja exista
	if (p.denumire != nullptr) {
		delete[] p.denumire;
		p.denumire = nullptr;
	}
	//id-ul este const, deci NU se mai poate modifica
	cout << "\nIntroduceti denumire: ";
	char buffer[100];
	string bufferString;
	//meth 1
	in >> buffer;
	p.denumire = new char[strlen(buffer) + 1];
	strcpy(p.denumire, buffer);
	//meth 2
	//in >> bufferString;
	//p.denumire = new char[bufferString.length() + 1];
	//strcpy(p.denumire, bufferString.data());//data-ul extrage char*-ul dintr-un string
	cout << "Introduceti pret: ";
	in >> p.pret;
	cout << "Introduceti stoc: ";
	in >> p.stoc;
	return in;
}

ostream& operator<<(ostream& out, const Produs& p) {
	out << "\nId: " << p.id;
	if (p.denumire != nullptr) {
		out << "\nDenumire: " << p.denumire;
	}
	else {
		out << "\nDenumire: -";
	}
	out << "\nStoc: " << p.stoc;
	out << "\nPret: " << p.pret;
	return out;
}

int main() {

	//PASI SUPRAINCARCARE
	//P1. Se identifica tipul operatorului + nr de operanzi
	//P2. Se identifica tipul operanzitor
	//P3. Daca primul operand este de tipul clasei,
	//supraincarcarea se poate realiza printr-o metoda a clasei
	//I operand este inghitit de this
	//Daca nu, atunci obligatoriu se supraincarca printr-o functie globala
	//P4. Ce returneaza operatorul?
	//P5. Se modifica operanzii?
	Produs p1(13, "Stilou", 100, 1000);
	Produs p2;

	cout << "\n------operator <<---------";
	cout << p1; //ostream << Produs
	cout << p1 << p2;
	cout << "\n------operator >>---------";
	//cin >> p2; //istream >> Produs
	//cout << p2;
	cout << "\n------operator []---------";
	char caracter = p1[1];//extrage caracterul de pe pozitia 1
	//operatorul binar (Produs [] int)
	cout << "\nCaracterul de pe poz 1 din denumire este: " << caracter;
	cout << "\n------operator ++ pre---------";
	cout << p1;
	cout << p2;
	p2 = ++p1;//marim stocul cu 1 unitate
	cout << p1;
	cout << p2;
	cout << "\n------operator ++ post---------";
	cout << p1;
	cout << p2;
	p2 = p1++;//marim stocul cu 1 unitate
	cout << p1;
	cout << p2;
	cout << "\n------operator cast/conversie---------";
	string denumire = p1;//sa extrag dintr-un Produs denumirea sa
	int stoc = (int)p1;//extrag int-un dintr-un Produs(stoc)
	return 0;
}