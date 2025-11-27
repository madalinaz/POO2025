#include<iostream>
using namespace std;

//= done
// comparatie (< <= > >= != ==) done
// negatie (!) done
// += -= /= *= done
// ++ (pre si post) done
// << si >> done
// operator index []
// cast/conversie
// functie
// + - * / done

class exceptie {
	string mesaj;
public:
	exceptie(string _mesaj) {
		this->mesaj = _mesaj;
	}

	string getMesaj() {
		return this->mesaj;
	}
};


class Produs {
	string denumire = "Anonim";
	double pret = 0;

public:

	Produs(){ }

	//cast "mascat" de la double la Produs 
	explicit Produs(double _pret) {
		this->pret = _pret;
	}

	Produs(string _denumire, double _pret) {
		this->denumire = _denumire;
		this->pret = _pret;
	}

	void afisare() {
		cout << "\nDenumire: " << this->denumire;
		cout << "\nPret: " << this->pret;
	}

	void setPret(double _pret) {
		if (_pret > 0) {
			this->pret = _pret;
		}
		else {
			//cout << "\nPretul este negativ!";
			throw exception("Pretul este negativ");
		}
	}

	bool operator==(const Produs& p) const {
		return this->denumire == p.denumire
			&& this->pret == p.pret;
	}

	bool operator<(int _x) const {
		return this->pret < _x;
	}

	//friend bool operator>(int _x, const Produs& p);

	//!!!!return prin & doar daca ne bazam pe obj (NU se distruge)
	Produs& operator+=(double _x) {
		this->pret += _x;
		return *this;
	}

	bool operator!() {
		return this->denumire == "Anonim";
	}

	friend ostream& operator<<(ostream& out, const Produs& p);

	friend istream& operator>>(istream& in, Produs& p);

	Produs operator+(double _x) const{
		Produs rez = *this;
		rez += _x;
		return rez;
	}

	//forma pre-incrementare
	//HOME1: Nu incalcam incapsularea si daca returnam Produs prin referinta??
	Produs& operator++() {
		this->pret++;
		return *this;//returneaza starea de DUPA incrementare
	}

	//forma post-incrementare
	Produs operator++(int) {
		Produs copie = *this;
		this->pret++;
		return copie;//returnez starea de DINAINTE de incrementare
	}

	//HOME2: de ce doar prin clasa???
	char operator[](int _index) {
		//validari pentru _index
		return this->denumire[_index];
	}

	//cast la char*
	explicit operator char* () {
		char* rez = new char[this->denumire.length() + 1];
		strcpy(rez, this->denumire.data());
		return rez;
	}

	bool operator==(const Produs& p) {
		return this->denumire == p.denumire && this->pret == p.pret;
	}

	//operator functie
	bool operator()(Produs* v, int nrProduse) {
		for (int i = 0; i < nrProduse; i++)
			if (*this == v[i])
				return true;
		return false;
	}

	double operator()() {
		return this->pret;
	}
};

//functie globala ptr ca I operand nu este Produs
bool operator>(int _x, const Produs& p) {
	//daca exista friend
	/*if (_x > p.pret)
		return true;
	return false;*/

	//folosind Produs<int
	return p < _x;
}

istream& operator>>(istream& in, Produs& p) {
	//obj p deja exista
	//de apelat destructorul
	//pentru zona heap(alocata dinamic)

	cout << "\nIntroduceti denumire: ";
	in >> p.denumire;
	cout << "Introduceti pret: ";
	in >> p.pret;
	return in;
}

ostream& operator<<(ostream& out, const Produs& p) {
	out << "\nDenumire: " << p.denumire;
	out << "\nPret: " << p.pret;
	return out;
}

Produs operator+(double _x, const Produs& p) {
	return p + _x;
}


int main() {
	Produs p1("carte", 120);
	Produs p2("stilou", 1000);

	cout << "\n------ += ------";
	p1 += 10;//marim stocul cu 10 unitati
	p1.afisare();

	cout << "\n------ ! ------";
	if (!p1)
		cout << "\nP1 nu are denumire";
	else
		cout << "\nInvers";
	cout << "\n------ << ------";
	cout << p1;//ostream << Produs
	cout << p1 << p2;
	cout << 2 << p1;

	cout << "\n------ >> ------";
	Produs p4;
	//cin >> p4;//istream >> Produs
	cout << p4;

	cout << "\n------ + ------";
	p4 = p2 + 10;
	p4 = 10 + p2;
	//Produs + Produs

	cout << "\n------ ++ pre ------";
	cout << p1 << p2;
	p2 = ++p1;
	cout << p1 << p2;

	cout << "\n------ ++ post ------";
	cout << p1 << p2;
	p2 = p1++;
	cout << p1 << p2;

	cout << "\n------ [] ------";
	char caracter = p2[2];
	//Produs [] int
	//OBLIGATORIU PRIN METH MEMBRA

	cout << "\n------ cast/conversiei ------";
	char* denumire = (char*)p2;//apel cast explicit
	cout << endl << "\nDenumire prin intermediul cast: " << denumire;
	delete[] denumire;
	//double pret = p2;
	//int pret = p2;
	//string denumireString = p2;

	double val = 10.5;
	p1 = (Produs)(val + 5);//apel constructor in versiune implicita
	//op = in clasa Produs care primeste un double

	cout << "\n------ functie ------";
	Produs vp[10] = { p1,p2 };
	bool gasit = p1(vp, 2);
	int pret = p1();
	return 0;
}