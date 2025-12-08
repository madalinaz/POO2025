#include<iostream>
using namespace std;

//modelam niste piese de teatru ->scenete ->participa diverse personaje

class Personaj {
public:
	string nume;

	void spuneCeva() {
		cout << "\n " + this->nume + " spune ceva";
	}

	void reactioneaza() {
		cout << "\n " + this->nume + " pleaca de suparare";
	}
};

//alte tipuri de personaje: Robot, Animal->Pisica
class Robot :public Personaj {
	void spuneCeva() {
		cout << "\n Robotul" + this->nume + " spune ceva in roboteasca";
	}

	void reactioneaza() {
		cout << "\n Robotul" + this->nume + " isi inchide circuitele";
	}
};

class Pisica :public Personaj {
	void spuneCeva() {
		cout << "\n Pisica" + this->nume + " miauna";
	}

	void reactioneaza() {
		cout << "\n Pisica" + this->nume + " zgarie";
	}
};

//scena nr I
void scena1(Personaj p1, Personaj p2) {
	cout << "\n---------SCENA 1-----------";
	p1.spuneCeva();
	p2.reactioneaza();
}

int main() {
	Personaj p1, p2;
	p1.nume = "Gigel";
	p2.nume = "Maria";
	scena1(p1, p2);
	Robot r1;
	r1.nume = "Robo";
	Pisica ps1;
	ps1.nume = "Zuza";
	scena1(p1, ps1);
	return 0;
}