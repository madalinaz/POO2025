#include<iostream>
using namespace std;

class Student {
	int codStudent;
	char nume[31];
	int nrNote;
	int* note;

public:
	//metode specifice
	//1. metode tip constructor
	//constructor default/fara param
	Student() {
		cout << "\nApel constructor default";
		codStudent = 0;
		strcpy_s(nume, "Anonim");
		nrNote = 0;
		note = nullptr;
	}

	//metode accesor (get si set)
	//se ataseaza campurilor private
	void setCodStudent(int _codStudent) {
		//validari
		if (_codStudent > 0) {
			this->codStudent = _codStudent;
		}
	}

	int getCodStudent() {
		return this->codStudent;
	}

	void setNume(const char* _nume) {
		if (strlen(_nume) >= 5) {
			strcpy_s(this->nume, _nume);
		}
	}

	//const char* getNume() {
	//	return this->nume;
	//}

	//tinand cont de INCAPSULARE!!!!!!!
	char* getNume() {
		//se face o copie a numelui
		//la o alta adresa ca sa pazim adresa reala
		char* copie;
		copie = new char[strlen(this->nume)+1];
		strcpy(copie, this->nume);
		return copie;
	}
};

int main() {
	//pana la lucrare (S5)
	//clasa + constructori(fara param + toti param)
	//get si set (meth accesor)

	Student s;//o clasa contine implicit constructorul default
	s.setCodStudent(123);
	cout << endl << s.getCodStudent();

	s.setNume("Ionescu Gigel");
	char* nume = s.getNume();
	cout << endl << nume;
	delete[] nume;
	//char* sir = (char*)s.getNume();
	//strcpy(sir, "nu mai e gigel");
	//cout << endl<<s.getNume();
	/*s.codStudent = 100;
	strcpy_s(s.nume, "Gigel");
	s.nrNote = 3;
	s.note = new int[s.nrNote];
	s.note[0] = 10;
	s.note[1] = 6;
	s.note[2] = 8;*/

	return 0;
}