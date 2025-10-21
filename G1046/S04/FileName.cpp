#include<iostream>
using namespace std;

//tipuri de date(vectori(siruri caractere/numerici) 
// statici + dinamici)
//redimensionare vectori
//clase (constructori + meth de prelucrare)
//fct globale

class Student {
private:
	char nume[21];
	int nrNote;
	int* note;
	float buget;
public:
	//metode
	//constructori
	Student() {
		cout << "\nApel constructor fara param";
		strcpy_s(this->nume, strlen("Anonim") + 1, "Anonim");
		this->nrNote = 0;
		this->note = nullptr;
		this->buget = 0;
	}

	Student(const char* _nume) {
		cout << "\nApel constructor cu 1 param";
		if (strlen(_nume) < 21) {
			strcpy_s(this->nume, strlen(_nume) + 1, _nume);
		}
		else {
			strcpy_s(this->nume, strlen("Anonim") + 1, "Anonim");
		}
		this->nrNote = 0;
		this->note = nullptr;
		this->buget = 0;
	}

	Student(const char* _nume, int _nrNote, 
		int* _note, float _buget) {
		cout << "\nApel constructor cu toti param";
		if (strlen(_nume) < 21) {
			strcpy_s(this->nume, strlen(_nume) + 1, _nume);
		}
		else {
			strcpy_s(this->nume, strlen("Anonim") + 1, "Anonim");
		}
		if (_nrNote > 0 && _note!=nullptr) {
			this->nrNote = _nrNote;
			//deep copy
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = _note[i];
		}
		else {
			this->nrNote = 0;
			this->note = nullptr;
		}
		if (_buget > 0) {
			this->buget = _buget;
		}
		else {
			this->buget = 0;
		}
	}

	//metode accesor(get si set)
	//meth de prelucrare (afisare)
	void afisare() {
		cout << "\nNume: " << this->nume;
		cout << ", nr note: " << this->nrNote;
		cout << ", note: ";
		for (int i = 0; i < this->nrNote; i++)
			cout << this->note[i] << " ";
		cout << ", buget: " << this->buget;
	}

	//meth care elimina ultima nota
	// meth care elimina notele care nu sunt de trecere
	// meth care adauga o noua nota la sfarsit
	//supraincarcare operatori(specializare operatori)
	//destructor
};

void testGlobal(int x) {
	cout << "\nAfisez pe x prin functie globala: " << x;
}

int main() {
	//apel functie globala
	testGlobal(10);

	Student s1;
	Student* s2;
	s2 = new Student();
	s2 = new Student[5];
	Student s3[5];
	Student* s4[5];
	Student** s5;
	Student s6();

	Student s7("Gigel");
	Student s8 = "Costel";
	int v[]{ 10,7,4 };
	Student s9("Marcel", 3, v, 150);

	//Student s10("Ana", 2, new int[] {10, 5}, 100);
	

	//int* v;
	//int x;
	//cout << x;
	//cout << s;
	//s.adaugaNota(10);
	//s += 10;
	//s.operator+=(10);
	
	return 0;
}