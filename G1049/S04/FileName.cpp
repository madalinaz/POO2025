#include<iostream>
using namespace std;

class Student {
	int cod;
	char nume[21];
	int nrNote;
	int* note;
	//metode in zona private
	//void testPrivate() {
	//	cout << "\nafisare in zona private";
	//}

public:
	//campuri care sunt accesibile din exterior
	//const int id;
	//metode
	//constructorii
	//metode accesor(get si set)
	//destructor
	//metode de prelucrare
	//supraincarcare operatori(specializare)

	//metoda non-statica ->care tine de obiect
	//adica are this
	Student() {
		cout << "\nApel constructor fara param";
		this->cod = 0;
		strcpy_s(this->nume, strlen("Anonim") + 1, "Anonim");
		this->nrNote = 0;
		this->note = nullptr;
	}

	Student(int _cod, const char* _nume) {
		cout << "\nApel constructor cu cativa param";
		if (_cod >= 0) {
			this->cod = _cod;
		}
		else {
			this->cod = 0;
		}
		if (strlen(_nume) >= 3 && strlen(_nume) < 21) {
			strcpy_s(this->nume, strlen(_nume) + 1, _nume);
		}
		else {
			strcpy_s(this->nume, strlen("Anonim") + 1, "Anonim");
		}
		this->nrNote = 0;
		this->note = nullptr;
	}

	void afisare() const{
		//this->cod = 10;(ca este const la antet)
		cout << "\n---------------";
		cout << "\nCod: " << this->cod;
		cout << "\nNume: " << this->nume;
		cout << "\nNr note: " << this->nrNote;
		cout << "\nNote: ";
		for (int i = 0; i < this->nrNote; i++) {
			cout << this->note[i] << " ";
		}
		cout << "\n---------------";
	}
};
	
//zona globala
double prelucrareNote(int* note, int nrNote) {
	//returneaza media notelor primite ca parametru
	return 0;
}

int main() {
	Student s;
	s.afisare();
	Student s2[5];//vector de studenti
	Student* ps;
	ps = new Student();

	Student s3(1234, "Gigel");
	s3.afisare();
	//int x, y;
	//x = y + 2;
	//s = s2 + 10;
	return 0;
}