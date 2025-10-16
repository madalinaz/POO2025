#include<iostream>
using namespace std;

enum Culoare {
	ALB, NEGRU, ROSU, VERDE, DEFAULT
};

union Id {
	int cui;
	long cnp;
};

//doar cu rol de grupare
struct DataCalendaristica{
	int zi, luna, an;
};

class MasinaTest {
public:
	int codMasina;
private:
	char* marca;
protected:
	Culoare culoare;
	double vitezaMaxima;
};

class Matrice {

};

class Masina {
	int codMasina;
	char* marca;
	Culoare culoare;
	double vitezaMaxima;
	int kilometriBord;

public:
	//mecanisme de comunicare "controlat" cu zona private
	//metode
	//existenta constructor default la crearea clasei
	
	Masina() {
		//this -> adresa obiectului apelator
		cout << "\nApel constructor default/fara param";
		this->codMasina = 0;
		this->marca = nullptr;
		this->culoare = Culoare::DEFAULT;
		this->vitezaMaxima = 0;
		this->kilometriBord = 0;
	}

	Masina(int _codMasina) {
		cout << "\nApel constructor cu cativa param";
		this->codMasina = _codMasina;
		this->marca = nullptr;
		this->culoare = Culoare::DEFAULT;
		this->vitezaMaxima = 0;
		this->kilometriBord = 0;
	}

	void afisare() {
		cout << "\n**********************";
		cout << "\nCod masina: " << this->codMasina;
		if (this->marca != nullptr) {
			cout << "\nMarca: " << this->marca;
		}
		else {
			cout << "\nMarca: -";
		}
		cout << "\nCuloare: " << this->culoare;
		cout << "\nViteza maxima: " << this->vitezaMaxima;
		cout << "\nKilometri bord: " << this->kilometriBord;
		cout << "\n**********************";
	}
};

int main() {
	cout << "\n-------UNION--------";
	Id id;
	id.cnp = 1234;
	cout << "\nPersoana fizica: ";
	cout << id.cnp << " " << id.cui;
	id.cui = 56789;
	cout << "\nPersoana juridica: ";
	cout << id.cnp << " " << id.cui;
	cout << "\n-------STRUCT--------";
	DataCalendaristica data;
	data.zi = 12;
	data.luna = 12;
	data.an = 1990;
	cout << "\nZi: " << data.zi;
	cout << "\n-------CLASA--------";
	Masina m;//ptr ca exista acel constructor default
	m.afisare();
	Masina m2;
	m2.afisare();

	Masina m3(123);
	Masina m4 = 124;
	return 0;
}