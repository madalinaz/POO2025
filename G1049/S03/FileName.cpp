#include<iostream>
#include<string>
using namespace std;

//utilizarea de structuri
//recapitulare utilizare enum + bool

enum Facultate {
	CSIE, FABIZ, FABBV, MK, MN
};

struct Student{
	//int
	int id;
	//float
	float medieAdmitere;
	//double
	double bugetDisponibil;
	//bool
	bool areBursa;
	//sir de caractere alocat static
	char cnp[14];//13 dimensiune + 1 terminator de sir
	//sir de caractere alocat dinamic
	char* nume;
	//un caracter
	char serie;
	//enumeratie
	Facultate facultate;
	//vector numeric alocat static
	int nrTelefon[10];//NU am nevoie de terminator de sir
	//vector numeric alocat dinamic + dimensiune pentru parcurgere
	int* note;
	int nrNote;
};

int main() {
	//declarare obj de tip Student
	Student s;
	//tema1: sizeof(s) + padding pe octeti
	cout << "\nNr octeti student s: " << sizeof(s);
	//citesc de la tastatura toate campurile Studentului s
	cout << "\nIntroduceti id: ";
	cin >> s.id;
	cout << "\nIntroduceti medie admitere: ";
	cin >> s.medieAdmitere;
	cout << "\nIntroduceti buget disponibil: ";
	cin >> s.bugetDisponibil;
	cout << "\nIntroduceti daca are bursa? (0-NU, 1-DA): ";
	cin >> s.areBursa;
	cout << "\nIntroduceti CNP: ";
	cin.get();
	cin.get(s.cnp, 14);
	cout << "\nIntroduceti nume: ";
	char buffer[100];
	cin.get();
	cin.getline(buffer, 100);
	s.nume = new char[strlen(buffer) + 1];
	strcpy_s(s.nume, strlen(buffer) + 1, buffer);
	cout << "\nIntroduceti serie: ";
	cin >> s.serie;
	cout << "\nIntroduceti facultate: (0-CSIE 1-FABIZ....)";
	int x;
	cin >> x;
	s.facultate = (Facultate)x;
	cout << "\nIntroduceti nr telefon: ";
	for (int i = 0; i < 10; i++)
		cin >> s.nrTelefon[i];
	cout << "\nIntroduceti nr note: ";
	cin >> s.nrNote;
	s.note = new int[s.nrNote];
	cout << "\nIntroduceti notele: ";
	for (int i = 0; i < s.nrNote; i++)
		cin >> s.note[i];
	//afisare la consola a unui obj de tip student (s)
	cout << "\n--------Afisare obj de tip student--------";
	cout << "\nId: " << s.id;
	cout << "\nMedie admitere: " << s.medieAdmitere;
	cout << "\nBuget disponibil: " << s.bugetDisponibil;
	cout << "\nAre bursa?: " << s.areBursa;
	cout << "\nCNP: " << s.cnp;
	cout << "\nNume: " << s.nume;
	cout << "\nSerie: " << s.serie;
	cout << "\nFacultate: " << s.facultate;
	cout << "\nNr telefon: ";
	for (int i = 0; i < 10; i++)
		cout << s.nrTelefon[i];
	cout << "\nNr note: " << s.nrNote;
	cout << "\nNote: ";
	for (int i = 0; i < s.nrNote; i++)
		cout << s.note[i] << " ";

	//eliberare zona de memorie
	delete[] s.nume;
	delete[] s.note;
	return 0;
}