#include<iostream>
using namespace std;

class Produs {
	//totalitatea campurilor private
	int cod;
	int stoc;
	float* preturi;//istoric preturi
	int nrPreturi;

	//meth private???
	//meth de lucru intern al unei clase
public:
	//campuri public???
	//campuri pe care le am protejate
	//const int id;
	
	//totalitatea metodelor publice
	//1.constructori
	Produs() {
		cout << "\nConstructor fara param";
		this->cod = 0;
		this->stoc = 0;
		this->nrPreturi = 0;
		this->preturi = nullptr;
	}

	Produs(int _cod) {
		cout << "\nConstructor cu 1 param";
		if (_cod > 1000) {
			this->cod = _cod;
		}
		else {
			this->cod = 0;
		}
		this->stoc = 0;
		this->nrPreturi = 0;
		this->preturi = nullptr;
	}

	Produs(int _cod, int _stoc, 
		float* _preturi, int _nrPreturi) {
		cout << "\nConstructor cu toti param";
		if (_cod > 1000) {
			this->cod = _cod;
		}
		else {
			this->cod = 0;
		}

		if (_stoc > 0) {
			this->stoc = _stoc;
		}
		else {
			this->stoc = 0;
		}

		if (_preturi != nullptr && _nrPreturi > 0) {
			this->nrPreturi = _nrPreturi;
			this->preturi = new float[this->nrPreturi];
			for (int i = 0; i < this->nrPreturi; i++)
				this->preturi[i] = _preturi[i];
		}
		else {
			this->nrPreturi = 0;
			this->preturi = nullptr;
		}
	}

	//2.metode accesor (get si set) -> se ataseaza campurilor private
	//3.metode de prelucrare (afisare)
	void afisare() const{
		cout << "\nCod: " << this->cod;
		cout << "\nStoc: " << this->stoc;
		cout << "\nNr preturi: " << this->nrPreturi;
		cout << "\nPreturi: ";
		for (int i = 0; i < this->nrPreturi; i++) {
			cout << this->preturi[i] << " ";
		}
	}

	//meth care adauga un pret nou doar daca pretul este 
	//diferit de ultimul

	//4.supraincarcari de operatori
	//5.destructor
};

//fct globala
//face compactarea unui vector prin eliminarea 
//dublurilor consecutive


void test() {
	//bla bla
}

int main() {
	//apel fct globala
	test();
	/*Produs p;
	p.setStoc(20);
	cout << "\nStoc curent: " << p.getStoc();
	p.afisare();
	cout << p;
	p.adaugaStocSuplimentar(30);
	p += 30;*/

	Produs p1;
	Produs p2[5];
	Produs* p21;
	p21 = new Produs;
	p21 = new Produs();
	p21 = new Produs[4];
	Produs* p3[2];
	Produs** p4;
	//v1 ->pointer la pointer la produs
	p4 = new Produs *;
	*p4 = new Produs;

	//v2->vector alocat dinamic de Produs*
	p4 = new Produs * [2];
	p4[0] = new Produs;
	p4[1] = new Produs;

	//v3->matrice de Produs
	p4 = new Produs * [2];
	p4[0] = new Produs[10];
	p4[1] = new Produs[5];

	Produs p5(10);
	Produs p6 = 10;
	Produs p7();
	Produs p8(12.5);

	//conversie degradanta
	int x = 12.5;
	//conversie nedegradanta
	float fx = 12;
	char c = 'a';
	int x2 = c;
	return 0;
}