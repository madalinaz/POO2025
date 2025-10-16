#include<iostream>
using namespace std;

enum Facultate {
	CSIE, FABIZ, MK, MN
};

enum FormaInvatamant {
	IF, ID, IFR
};

struct DataCalendaristica{
	int zi, luna, an;
};

class Student {
public:
	int cnp;
private:
	//char* nume;
	string nume;
protected:
	int grupa;
	float medieAnI;
	bool esteAngajat;
	//bool areBursa;
	//vector alocat dinamic
	//char* materieFacultativa;
	int* note;
	int nrNote;
	//vector numeric alocat static
	bool fraudaExamen[100];//100 este nr de examene
	//int cnp[13];
};

class Masina {
	//sir de caractere alocat static
	char VIN[19];
	char nrInmatriculare[9];
};

int main() {
	char* facultate1;//sir de caractere alocat dinamic
	char facultate2[20];//sir de caractere alocat static
	//string facultate3;
	Facultate facultate;
	facultate = Facultate::CSIE;
	facultate = CSIE;
	cout << "\nAfisare facultate prin enum: "
		<< facultate;
	cout << "\nIntroduceti facultate: (0-CSIE 1-FABIZ....)";
	//cin >> facultate;
	int x = 0;
	//cin >> x;
	facultate = (Facultate)x;//cast explicit
	cout << "\nAfisare facultate prin enum: "
		<< facultate;

	cout << "\n----Utilizare struct--------";
	DataCalendaristica data;
	data.zi = 1;
	data.luna = 5;
	data.an = 1960;
	cout << "\nZi: " << data.zi;

	cout << "\n----Utilizare string--------";
	string text;
	text = "ABC";
	cout << endl << text;
	text = "DEF";
	text += "alt text";
	cout << endl << text;
	cout << "\nIntroduceti text: ";
	cin >> text;
	cout << endl << text;

	cout << "\n----Utilizare class--------";
	Student s;
	s.cnp = 12345;
	return 0;
}