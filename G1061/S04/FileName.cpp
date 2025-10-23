#include<iostream>
using namespace std;

class Student {
	string nume; //char* nume; char nume[21];
	int nrNote;
	int* note;
	double buget;

public:
	//constructori
	//constructori cu param
	Student() {
		cout << "\nApel constructor fara param";
		this->nume = "Anonim";
		this->nrNote = 0;
		this->note = nullptr;
		this->buget = 0;
	}

	Student(double _buget) {
		this->nume = "Anonim";
		this->nrNote = 0;
		this->note = nullptr;
		if (_buget > 0) {
			this->buget = _buget;
		}
		else {
			this->buget = 0;
		}
	}

	Student(string _nume, int _nrNote, 
		int* _note, double _buget) {
		if (_nume.length()>=2) {
			this->nume = _nume;
		}
		else {
			this->nume = "Anonim";
		}
		if (_nrNote > 0 && _note != nullptr) {
			this->nrNote = _nrNote;
			//v1 (shallow copy)
			//this->note = _note;
			//v2 (deep copy)
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++) {
				this->note[i] = _note[i];
			}
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

	//meth de prelucrare ->afisare
	void afisare(){
		cout << "\nNume: " << this->nume;
		cout << "\nNr note: " << this->nrNote;
		cout << "\nNote: ";

		for (int i = 0; i < this->nrNote; i++) {
			cout << this->note[i] << " ";
		}
		cout << "\nBuget: " << this->buget;
	}

	//meth accesor (get si set)
	void setNote(int _nrNote, int* _note) {
		//to do home
		//!!!!obj this deja exista
	}

	void setNota(int _nota, int _index) {
		//to do home
		//plus validari
	}

	int* getNote() {
		//to do home
		return nullptr;
	}

	int getNota(int _index) {
		//to do home
		return 0;
	}

	int getNrNote() {
		//to do home
		return 0;
	}

	//meth prelucrare
	//meth care sterge prima nota
	//meth care sterge ultima nota
	//meth care sterge toate notele sub medie
	//meth care dubleaza ultima nota
	//meth care adauga o noua nota la sfarsitul vectorului

	//supraincarcare operatori

	//destructor
};

int main() {
	Student s;
	/*s.afisare();
	cout << s;
	s.adaugaNota(9);
	s += 9;*/

	Student s1;
	s1.afisare();
	Student* s2;
	s2 = new Student();
	s2 = new Student[5];
	s2 = new Student;
	Student s3[5];
	Student* s4[5];
	Student** s5;
	Student s6(25);
	Student s7 = 25;
	Student s8();
	return 0;
}