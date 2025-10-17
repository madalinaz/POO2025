#include<iostream>
using namespace std;

//TO DO HOME
//de gestionat citirea cu spatieri(cin.getline())
//vector de enumeratii
//alta structura in care sa adaugati tipurile de date discutate
//fct care transforma o enumeratie in char*-ul aferent
//fct care limiteaza citirea in context de enumeratie doar a valorilor aferente enumeratiei

enum TipZbor {
	LINIE, CHARTER, PRIVAT
};

struct Zbor{
	//int/float/double
	double pretBilet;
	int codZbor;
	//bool
	bool esteAnulat;
	//enumeratie
	TipZbor tipZbor;
	//sir de caractere alocat static
	char destinatie[20];
	//sir de caractere alocat dinamic
	char* pilotPrincipal;
	//vector numeric alocat static
	int dataZbor[3];
	//vector numeric alocat dinamic
	bool* esteOcupat;
	int nrLocuri;
	//un caracter
	char caracterTerminal; 
};

//fct globala
void fctGlobala(int x) {
	if (x % 2 == 0)
		cout << "Este par";
	else
		cout << "Nu este par";
}

char* transformareTipZbor(TipZbor tipZbor) {
	//in fct de tipZbor returnati LINIE, CHARTER, PRIVAT
	return nullptr;
}

int main() {
	Zbor z;
	//citire date
	cout << "\nIntroduceti pret bilet: ";
	cin >> z.pretBilet;
	cout << "\nIntroduceti daca este anulat sau nu?: ";
	cin >> z.esteAnulat;
	cout << "\nIntroduceti tip zbor (0-Linie, 1-Charter, 2-Privat): ";
	//cin >> z.tipZbor;
	int x;
	cin >> x;
	z.tipZbor = (TipZbor)x;//cast explicit
	cout << "\nIntroduceti destinatie: ";
	cin >> z.destinatie;//citesc direct pentru ca am zona de memorie alocata static
	cout << "\nIntroduceti pilot principal: ";
	//cin >> z.pilotPrincipal;//nu putem, pentru ca NU avem z.m. alocata anterior
	{
		char buffer[100];
		cin >> buffer;
		z.pilotPrincipal = new char[strlen(buffer) + 1];
		//z.pilotPrincipal = buffer;//NU e bine pentru ca este shallow copy
		strcpy_s(z.pilotPrincipal, strlen(buffer) + 1, buffer);//deep copy
	}
	cout << "\nIntroduceti data: ";
	for (int i = 0; i < 3; i++) {
		cin >> z.dataZbor[i];
	}
	cout << "Introduceti nr locuri: ";
	cin >> z.nrLocuri;
	z.esteOcupat = new bool[z.nrLocuri];
	cout << "Introduceti disponibilitate(este ocupat sau nu): ";
	for (int i = 0; i < z.nrLocuri; i++) {
		cin >> z.esteOcupat[i];
	}
	cout << "Introduceti cod-caracter terminal: ";
	cin >> z.caracterTerminal;

	//afisare obj construit
	cout << "\nPret bilet: " << z.pretBilet;
	cout << "\nEste anulat?: " << z.esteAnulat;
	cout << "\nTip zbor: " << z.tipZbor;
	cout << "\nDestinatie: " << z.destinatie;
	cout << "\nPilot principal: " << z.pilotPrincipal;
	cout << "\nData zbor: ";
	for (int i = 0; i < 3; i++) {
		cout << z.dataZbor[i] << "/";
	}
	cout << "\nNr locuri: " << z.nrLocuri;
	cout << "\nDisponibilitate locuri: ";
	for (int i = 0; i < z.nrLocuri; i++) {
		cout << z.esteOcupat[i] << " ";
	}
	cout << "\nCaracter terminal: " << z.caracterTerminal;

	//dezalocari zona de memorie
	delete[] z.pilotPrincipal;
	delete[] z.esteOcupat;
	return 0;
}