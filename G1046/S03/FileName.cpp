#include<iostream>
using namespace std;

enum StatutJuridic {
	PFA, SA, SRL
};

struct Firma {
	//int/double/float
	int cui;
	//bool
	//bool esteActiva;
	bool platitoareTVA;
	//enumeratie
	StatutJuridic statut;

	//sir de caractere alocat static
	char codIban[25];
	//sir de caractere alocat dinamic
	char* denumire;
	//vector numeric alocat static
	int codCaen[5];
	int nrCifreCodCaen;
	double venituri[3]; //venituri din ultimul trimestru
	//vector numeric alocat dinamic
	int* coduriAngajati;
	int nrAngajati;
	//un caracter
	//home
};

int main() {
	Firma f;
	//citire campuri de la tastatura
	cout << "\nIntroduceti cui: ";
	cin >> f.cui;
	cout << "Introduceti daca este platitor de tva? ";
	cin >> f.platitoareTVA;
	cout << "Introduceti statut: (0-PFA, 1-SA,...)";
	//cin >> f.statut;
	int x;
	cin >> x;
	f.statut = (StatutJuridic)x;//cast explicit
	int a = 2;
	float b = 10.3;
	a = b;//cast implicit ->cu pierdere de informatie
	cout << "Introduceti cod iban: ";
	cin >> f.codIban;
	cout << "Introduceti denumire: ";
	//cin >> f.denumire;
	{
		char buffer[100];
		cin >> buffer;
		//f.denumire = buffer;//shallow copy
		f.denumire = new char[strlen(buffer) + 1];
		//f.denumire = buffer;
		strcpy_s(f.denumire, strlen(buffer) + 1, buffer);
	}
	cout << "Introduceti veniturile din ultimele trei luni: ";
	for (int i = 0; i < 3; i++) {
		cin >> f.venituri[i];
	}
	cout << "Introduceti nr angajati: ";
	cin >> f.nrAngajati;
	f.coduriAngajati = new int[f.nrAngajati];
	for (int i = 0; i < f.nrAngajati; i++) {
		cin >> f.coduriAngajati[i];
	}

	//afisare obj firma
	cout << "\nCui: " << f.cui;
	cout << "\nPlatitoare tva?: " << f.platitoareTVA;
	cout << "\nStatut: " << f.statut;
	cout << "\nCod iban: " << f.codIban;
	cout << "\nDenumire: " << f.denumire;
	cout << "\nVenituri ultimul trimestru: ";
	for (int i = 0; i < 3; i++) {
		cout << f.venituri[i] << " ";
	}
	cout << "\nNr angajati: " << f.nrAngajati;
	cout << "\nCoduri angajati: ";
	for (int i = 0; i < f.nrAngajati; i++) {
		cout << f.coduriAngajati[i] << " ";
	}

	//eliberare zona de memorie
	delete[] f.denumire;
	f.denumire = nullptr;
	delete[] f.coduriAngajati;
	f.coduriAngajati = nullptr;
	return 0;
}