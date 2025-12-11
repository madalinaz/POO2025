#include<iostream>
using namespace std;

class Nava {
public:
	int nivelViata=100;

	virtual void reactioneaza(){
		this->nivelViata -= 10;
		if (this->nivelViata == 0) {
			cout << "\nS-a distrus nava";
		}
		else {
			cout << "\nNivel viata: " << this->nivelViata;
		}
	}
};

class NavaSpatiala :public Nava {
public:
	int altitudine=10;
	void reactioneaza() {
		if (this->altitudine == 0) {
			this->nivelViata -= 10;
			if (this->nivelViata == 0) {
				cout << "\nS-a distrus nava spatiala";
			}
			else {
				cout << "\nNivel viata nava spatiala: " << this->nivelViata;
			}
		}
		else {
			cout << "\nNava NU poate fi atacata!";
		}
	}
};

//depind de concret
void ataca(Nava& nava) {
	cout << "\nNava este atacata!";
	nava.reactioneaza();
}

void atacaAbstract(Nava* nava) {
	cout << "\nNava este atacata abstract!";
	nava->reactioneaza();
}

//clasa Abstracta -> are cel putin o meth virtuala pura
//clasa tip Interfata ->acea clasa care are doar meth virtuale pure
//interfata = CONTRACT
class AreSunet{
	virtual void scoateSunet() = 0;//meth virtuala pura
};

class Animal: public AreSunet {
public:
	virtual void afisare() {
		cout << "\nAcesta este un animal";
	}

	void scoateSunet() override{
		cout << "\nAnimalul scoate sunete!";
	}
};

class Pisica :public Animal {
public:
	void afisare() override{
		cout << "\nAceasta este o pisica";
	}

	void methPisica() {
		cout << "\nMeth pisica";
	}
};

class Caine : public Animal {
public:
	void afisare() {
		cout << "\nAcesta este un caine";
	}

	void methCaine() {
		cout << "\nMeth caine";
	}
};

int main() {
	//in cadrul jocului avem doar obj de tip Nava
	Nava n1;
	ataca(n1);
	ataca(n1);

	cout << "\nINCERCARE CU OBIECTE";
	NavaSpatiala ns1;
	ataca(ns1);//s-a realizat un upcast

	cout << "\nINCERCARE CU POINTERI";
	atacaAbstract(&ns1);

	//ca virtualizarea sa aiba loc
	//ne trebuie o metoda virtuala
	//plus lucrul pe pointeri

	cout << "\n------ANIMALE-----";
	Animal a1;
	a1.afisare();
	Pisica p1;
	p1.afisare();
	Caine c1;
	c1.afisare();
	//o colectie de animale de tip obiect
	Animal v[] = { a1,p1,c1 };//se face upcast ->taie din obiecte
	for (int i = 0; i < 3; i++)
		v[i].afisare();
	//o colectie de pointeri
	Animal* vp[] = { &a1,&p1,&c1 };
	for (int i = 0; i < 3; i++)
		vp[i]->afisare();

	//AreSunet obiect;
	AreSunet* pObiect;

	//TEMA
	//CLASA DE BAZA ANGAJAT(SALARIUL BAZA)
	//CLASA DERIVATA CADRU DIDACTIC(GRADUL SAU(LECT, CONF, PROF)
	//ALTA CLASA DERIVATA DIN ANGAJAT (CLASA SECRETARA)(NR DE STUDENTI GESTIONATI)
	//FIECARE CLASA ARE PROPRIA METH DE CALCUL SALARIU
	//CLASA DE TIP HAS A CU ANGAJAT
	//ADICA VREAU SA RETIN TOTI ANGAJATII DIN FACULTATE SI SA LE CALCULEZ FONDUL DE SALARII
	return 0;
}