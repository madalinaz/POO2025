#include<iostream>
using namespace std;

//interfata ->clasa care detine DOAR metode virtuale pure (interfata = contract)
class IPrintabil {
public:
	virtual void printare() = 0;
};

//clasa abstracta ->clasa care detine cel putin o metoda virtuala pura
class AbstractPersonaj {
	string nume;
	virtual void spuneCeva() = 0;//metoda virtuala pura
	virtual void reactioneaza() = 0;
};

//modelam niste piese de teatru ->scenete ->participa diverse personaje

class Personaj {
public:
	string nume;

	//metoda virtuala
	virtual void spuneCeva() {
		cout << "\n " + this->nume + " spune ceva";
	}

	virtual void reactioneaza() {
		cout << "\n " + this->nume + " pleaca de suparare";
	}
};

//alte tipuri de personaje: Robot, Animal->Pisica
class Robot :public Personaj {
public:
	void spuneCeva() {
		cout << "\n Robotul " + this->nume + " spune ceva in roboteasca";
	}

	void reactioneaza() {
		cout << "\n Robotul " + this->nume + " isi inchide circuitele";
	}
};

class Pisica :public Personaj {
public:
	string rasa;

	void spuneCeva() {
		cout << "\n Pisica " + this->nume + " miauna";
	}

	void reactioneaza() {
		cout << "\n Pisica " + this->nume + " zgarie";
	}
};

//scena nr I
//este o scena ce depinde de obiecte concrete
void scena1(Personaj p1, Personaj p2) {
	cout << "\n---------SCENA 1-----------";
	p1.spuneCeva();
	p2.reactioneaza();
}

//este o scena de depinde de pointeri la obiecte de tipul de baza
void scena1Virtuala(Personaj* pp1, Personaj* pp2) {
	cout << "\n---------SCENA 1 VIRTUALA-----------";
	pp1->spuneCeva();
	pp2->reactioneaza();
}

class FormaGeometrica {
public:
	virtual void afisare() {
		cout<<"\nAceasta este o forma geometrica generala";
	}
};

class Cerc :public FormaGeometrica {
public:
	void afisare() {
		cout << "\nAcesta este un cerc";
	}
};

class Patrat :public FormaGeometrica {
public:
	void afisare() {
		cout << "\nAcesta este un patrat";
	}
};

int main() {
	Personaj p1, p2;
	p1.nume = "Gigel";
	p2.nume = "Maria";
	scena1(p1, p2);
	Robot r1;
	r1.nume = "Robo";
	Pisica ps1;
	ps1.nume = "Zuza";
	ps1.reactioneaza();
	//UPCAST PRIN OBIECT REDUCE OBIECTUL LA CLASA DE BAZA SI PRIN COMPORTAMENT CARE ESTE MANIFESTAT PRIN METODE
	scena1(p1, ps1);

	Personaj* pp1, *pp2;
	pp1 = &p1;
	pp2 = &p2;
	cout << "\n--------SCENA VIRTUALA CU 2 POINTERI CE POINTEAZA OBJ DE TIP PERSONAJ";
	scena1Virtuala(pp1, pp2);
	pp1 = &ps1;//upcast prin pointeri
	pp2 = &r1;
	cout << "\n--------SCENA VIRTUALA CU 2 POINTERI CE POINTEAZA OBJ DE TIP PISICA SI ROBOT";
	scena1Virtuala(pp1, pp2);
	//HOME DE DOCUMENTAT SI DEMONSTRAT DE CE VIRTUALIZAREA SE ACCEPTA DOAR PE POINTERI SI NU SI PE OBIECTE

	cout << "\n////////////VIRTUALIZARE CU OBIECTE//////////////";
	FormaGeometrica fg;
	Cerc cerc;
	Patrat patrat;
	fg.afisare();
	fg = cerc; //upcast pe obiecte
	fg.afisare();
	FormaGeometrica* pfg;
	Cerc* pCerc;
	Patrat* pPatrat;
	pfg = &fg;
	pfg->afisare();
	pCerc = &cerc;
	pfg = pCerc;//upcast pe pointeri
	pfg->afisare();

	//AbstractPersonaj personajAbstract;
	AbstractPersonaj* pointerPersonajAbstract;
	return 0;
}