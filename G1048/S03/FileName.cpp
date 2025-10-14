#include<iostream>
using namespace std;

enum FormaInvatamant {
	IF, ID, IFR
};

enum Test {
	VAL1, VAL2
};

struct Student {
	//int
	int id;
	//float/double
	double medieAdmitere;
	//bool
	bool isBuget;
	// vector de bool dinamic
	bool* esteReturnat;
	int nrCartiImprumutate;

	//sir de caractere alocat static
	char cnp[14];
	//sir de caractere alocat dinamic
	char* nume;
	//enumeratie
	FormaInvatamant formaInvatamant;
	//vector numeric alocat static
	int dataNastere[3];
	//vector numeric alocat dinamic
	int* note;
	int nrNote;
};

int main() {
	Student s;
	//sectiune de citire a unui student
	cout << "\nIntroduceti id: ";
	cin >> s.id;
	cout << "Introduceti medie admitere: ";
	cin >> s.medieAdmitere;
	cout << "Introduceti daca este la buget: ";
	cin >> s.isBuget;
	cout << "Introduceti cnp: ";
	cin >> s.cnp;
	cout << "Introduceti nume: ";
	char buffer[100];
	cin >> buffer;
	s.nume = new char[strlen(buffer) + 1];
	//s.nume = buffer;//shallow copy
	strcpy_s(s.nume,strlen(buffer)+1, buffer);
	cout << "Introduceti forma de invatamant: ";
	//cin >> s.formaInvatamant;
	int x;
	cin >> x;
	s.formaInvatamant = (FormaInvatamant)x;
	cout << "Introduceti nr note: ";
	cin >> s.nrNote;
	s.note = new int[s.nrNote];
	cout << "Introduceti notele: ";
	for (int i = 0; i < s.nrNote; i++) {
		cin >> s.note[i];
	}

	//sectiune de afisare a unui student
	cout << "\nId: " << s.id;
	cout << "\nMedie admitere: " << s.medieAdmitere;
	cout << "\nEste la buget? (0-NU, 1-DA): " << s.isBuget;
	cout << "\nCNP: " << s.cnp;
	cout << "\nNume: " << s.nume;
	cout << "\nForma invatamant: " << s.formaInvatamant;
	cout << "\nNr note: " << s.nrNote;
	cout << "\nNote: ";
	for (int i = 0; i < s.nrNote; i++) {
		cout << s.note[i]<<" ";
	}

	delete[] s.nume;
	s.nume = nullptr;
	delete[] s.note;
	s.note = nullptr;
	return 0;
}