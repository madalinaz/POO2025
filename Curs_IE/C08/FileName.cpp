#include<iostream>
using namespace std;

//= done
// comparatie (< <= > >= != ==) done
// negatie (!) done
// += -= /= *= done
// ++ (pre si post)
// << si >>
// operator index []
// cast/conversie
//functie
// + - * /

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
	cout << p1;
	return 0;
}