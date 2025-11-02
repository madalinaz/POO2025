#include<iostream>
using namespace std;

class AgendaTelefon {
	string posesor;
	int nrContacte;
	string* numeContacte;
	//alt atribut de tip enum si bool la alegere

public:
	//constructor fara parametri
	//constructor cu un singur parametru
	//metoda care adauga un nou contact in lista de contacte (numele nu trebuie sa se mai regaseasca)
	//metoda de afisare
};

class Masina {
	string numarMasina;
	double capacitateRezervor;
	double capacitateCurenta;
	int nrAlimentari;
	double* alimentari;

public:
	//constructor cu un singur parametru (string)
	//constructor cu parametri (numarMasina, capacitate rezervor)
	//constructor cu toti parametri (se vor adauga restrictii la nivelul vectorului de alimentari, daca se depaseste pentru 
	//o alimentare capacitatea rezervorului, atunci aceasta se va inlocui cu capacitatea maxima a rezervorului)
	//metoda care adauga o noua alimentare tinand cont de restrictiile (capacitate curenta si capacitate rezervor)
	//metoda de afisare dar care afiseaza in loc de vectorul de alimentari doar media tuturor alimentarilor
};

int main() {
	return 0;
}