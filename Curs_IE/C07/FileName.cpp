#include<iostream>
using namespace std;

class Produs {
	string denumire = "Anonim";
	double pret=0;

public:
	Produs(string _denumire, double _pret) {
		this->denumire = _denumire;
		this->pret = _pret;
	}

	void afisare() {
		cout << "\nDenumire: " << this->denumire;
		cout << "\nPret: " << this->pret;
	}
};

void f(int x) {
	cout << "\n f(int)";
}

void f(int x, double y) {
	cout << "\n f(int, double)";
}

void f(double x, int y) {
	cout << "\n f(double, int)";
}

void f(double x, double y) {
	cout << "\n f(double, double)";
}

int main() {
	Produs p1("carte", 120);
	Produs p2("stilou", 1000);
	Produs p3(p2);
	p3.afisare();
	p1 = p2;
	p1.afisare();

	cout << "\n-------------f----------";
	f(10);
	f(12.5);
	f(12.5f);
	f(12.5, 12.5);
	f(12, 12.5);
	char x = 'a';
	f(x);
	f("Stilou");
	f(12, 12);
	cout << "\n-------------f----------";
	return 0;
}