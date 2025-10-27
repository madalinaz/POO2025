#include<iostream>
using namespace std;

class Student {
	char* nume;
	float bugetDisponibil;
	int nrNote;
	int* note;


public:
	//constructor fara param
	//constructor care primeste nume si bugetDisponibil
	//constructor care primeste toti param dar valideaza notele
	//(nu se vor adauga in vector notele care nu apartin [1;10]
	//metoda care primeste o noua nota si o adauga in lista de note
	//metoda care elimina notele sub medie
	//metoda care dubleaza ultima nota din lista
	//metoda care suplimenteaza bugetul disponibil cu o valoare primita ca parametru

};

//functie globala care verifica daca o valoare intreaga reprezinta o nota

class Produs {
	char denumire[21];
	int nrPreturi;
	double* preturi;//stocheaza istoricul preturilor Produsului
	//nu va contine 2 valori alaturate egale

public:
	//constructor fara param
	//constructor doar cu denumire
	//constructor cu toti param dar care verifica proprietatea enuntata pentru
	//vectorul de preturi
	//metoda care primeste un nou pret si il adauga la sf de vector daca respecta conditia
	//metoda care elimina din vectorul de preturi primele k valori
	//metoda care goleste vectorul de preturi
	//metoda care returneaza pretul mediu in functie de istoric
	//metoda care returneaza cel mai mic pret
};

class Magazin {
	char* denumire;
	int nrProduse;
	int* coduri;//retine codurile produselor ( se respecta unicitatea)

public:
	//constructor fara param
	//constructor cu denumire
	//constructor care primeste toti param dar valideaza unicitatea elem din vector (va elimina dublurile)
	//metoda care adauga un nou cod in vectorul coduri
};

class Zbor {
	char* destinatie;
	char* sursa;
	int nrLocuri;
	bool* loc;//true->locul este ocupat

public:
	//constructor fara param
	//constructor care primeste destinatie si sursa
	//constructor care primeste destinatie, sursa si nrLocuri si initializeaza vectorul pe false
	//metoda care verifica daca mai exista k locuri libere in avion
	//metoda care verifica daca mai exista k locuri alaturate libere in avion
	//metoda care ocupa un anume loc in avion
	//metoda care suplimenteaza cu un nr de locuri (k) primit ca parametru disponibilul din avion
};

//clasele pot fi exersate si optand pentru alocare statica acolo unde a fost propusa o alocare dinamica

int main() {
	return 0;
}