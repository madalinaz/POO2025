#include<iostream>
using namespace std;

class Caracter {
	string denumire="Anonim";
	int nivelViata=100;
	int x=0;
	int y=0;

public:
	Caracter() {

	}

	Caracter(string _denumire, int _nivelViata, int _x, int _y) {
		this->denumire = _denumire;
		this->nivelViata = _nivelViata;
		this->x = _x;
		this->y = _y;
	}

	Caracter(const Caracter& c) {
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

	void afisare() {
		cout << "\nDenumire: " << this->denumire << ", nivel viata: " << this->nivelViata;
		cout << ", x: " << this->x << ", y=" << this->y;
	}
};

int main() {
	return 0;
}