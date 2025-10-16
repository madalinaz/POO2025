#include<iostream>
using namespace std;

//materie lucrarea 1(S05)
//functii globale care sa utilizeze
//vectori statici + dinamici
//stergeri sau adaugari in vectori
//POO -> utilizare enum
//utilizare clase (constructor(cu si fara param) + metode accesor(get si set))

enum Departament {
	IT, FINANTE, HR
};

struct Angajat {
	//int
	int  id;
	//double/float
	double salariu;
	//enum
	Departament departament;
	//bool
	bool esteRemote;
	//sir de caractere alocat static
	char userName[20];
	//sir de caractere alocat dinamic
	char* nume;
	//vector numeric alocat static
	int cnp[13];
	//vector numeric alocat dinamic
	int* oreLucrate;
	int nrZile;
	//un caracter
	char primaInitialaTata;
};

int main() {
	//enumeratie + bool
	//tipuri de date
	Angajat a;
	//citire campuri Angajat
	cout << "\nIntroduceti id: ";
	cin >> a.id;
	cout << "Introduceti salariu: ";
	cin >> a.salariu;
	cout << "Introduceti departament: (0-IT,...)";
	//cin >> a.departament;
	int x;
	cin >> x;
	a.departament = (Departament)x;
	cout << "Introduceti daca este remote: ";
	cin >> a.esteRemote;
	cout << "Introduceti user name: ";
	cin >> a.userName;
	cout << "Introduceti nume: ";
	//a.nume = nullptr;
	{
		char buffer[100];
		cin >> buffer;
		//a.nume = buffer;//shallow copy
		a.nume = new char[strlen(buffer) + 1];
		strcpy_s(a.nume, strlen(buffer) + 1, buffer);
	}
	cout << "Introduceti cnp: ";
	for (int i = 0; i < 13; i++) {
		cin >> a.cnp[i];
	}

	//afisare campuri Angajat
	cout << "\nId: " << a.id;
	cout << "\nSalariu: " << a.salariu;
	cout << "\nDepartament: " << a.departament;
	cout << "\nEste remote?: " << a.esteRemote;
	cout << "\nUser name: " << a.userName;
	cout << "\nNume: " << a.nume;
	cout << "\nCNP: ";
	for (int i = 0; i < 13; i++)
		cout << a.cnp[i];
	return 0;
}