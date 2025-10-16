#include<iostream>
using namespace std;

//lucrare S05
//clase: constructori(cu param, fara param, cu dimensiune variabila param)
//clase: meth accesor (get si set)
//lucrul cu orice tip de data(pointeri -> vector alocat dinamic)
//functii globale

//int, float, double
//bool (x)
//enumeratie (x)
//vector numeric alocat static
//vector numeric alocat dinamic
//sir de caractere alocat static
//sir de caractere alocat dinamic
//un caracter
//vector de bool
//vector de enum

struct DataCalendaristica {
	int zi, luna, an;
};

enum FormaInvatamant {
	IF, ID, IFR
};

class Student {
public:
	bool areBursa;
private:
	char* nume;
	FormaInvatamant formaInvatamant;
	double medieAdmitere;

public:
	Student() {
		cout << "\nApel constructor fara param";
		//pointerului this ->adresa obj apelator
		this->nume = new char[strlen("Anonim") + 1];
		strcpy_s(this->nume,strlen("Anonim")+1, "Anonim");
		//(*this).areBursa
		this->areBursa = false;
		this->formaInvatamant = FormaInvatamant::IF;
		this->medieAdmitere = 0.0;
	}

	//meth accesor (get si set)
	double getMedieAdmitere() {
		return this->medieAdmitere;
	}

	void setMedieAdmitere(double _medieAdmitere) {
		if (_medieAdmitere >= 5 && _medieAdmitere <= 10) {
			this->medieAdmitere = _medieAdmitere;
		}
	}

	FormaInvatamant getFormaInvatamant() {
		return this->formaInvatamant;
	}

	void setFormaInvatamant(FormaInvatamant _formaInvatamant) {
		this->formaInvatamant = _formaInvatamant;
	}

	//forma asta incalca incapsularea
	char* getNume1() {
		return this->nume;
	}

	//forma asta incalca incapsularea
	const char* getNume2() {
		return this->nume;
	}

	//forma corecta
	char* getNume() {
		//se face o copie a numelui
		char* copie = new char[strlen(this->nume) + 1];
		strcpy_s(copie, strlen(this->nume) + 1, this->nume);
		return copie;
	}
};

int main() {
	Student s;
	cout << "\nMedia admitere: " << s.getMedieAdmitere();
	s.setMedieAdmitere(9);
	cout << "\nMedia admitere dupa set: " << s.getMedieAdmitere();
	cout << "\nNume student: " << s.getNume1();
	char* text = s.getNume1();
	strcpy_s(text, strlen("Nu mai e Anonim") + 1, "Nu mai e Anonim");
	cout << "\nNume student: " << s.getNume1();

	char* text2 = (char*)s.getNume2();
	strcpy_s(text2, strlen("Acu e altceva") + 1, "Acu e altceva");
	cout << "\nNume student: " << s.getNume2();
	return 0;
}