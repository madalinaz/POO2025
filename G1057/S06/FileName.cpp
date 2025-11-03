#include<iostream>
using namespace std;

class Student {
	string nume;
	int nrNote;
	int* note;
	double buget;


public:
	Student() {
		cout << "\nApel constructor fara param";
		this->nume = "Anonim";
		this->nrNote = 0;
		this->note = nullptr;
		this->buget = 0;
	}

	Student(double _buget) {
		cout << "\nApel constructor cu 1 param";
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

	Student(const char* _nume, int _nrNote,
		int* _note, double _buget) {
		cout << "\nApel constructor cu toti param";
		if (strlen(_nume) >= 3) {
			this->nume = _nume;
		}
		else {
			this->nume = "Anonim";
		}
		if (_nrNote > 0 && _note != nullptr) {
			this->nrNote = _nrNote;
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

	//home ->chiar daca e const, ce nu este protejat din s?
	Student(const Student& s) {
		cout << "\nApel constructor copiere";
		this->nume = s.nume;
		if (s.nrNote > 0 && s.note != nullptr) {
			this->nrNote = s.nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++) {
				this->note[i] = s.note[i];
			}
		}
		else {
			this->nrNote = 0;
			this->note = nullptr;
		}
		this->buget = s.buget;
	}

	void setNote(int* _note, int _nrNote) {
		if (_note != nullptr && _nrNote > 0) {
			delete[] this->note;
			this->note = nullptr;
			this->nrNote = 0;

			this->nrNote = _nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++) {
				this->note[i] = _note[i];
			}
		}
		else {
			
		}
	}

	void setNota(int _nota, int _index) {
		if (_index >= 0 && _index < this->nrNote) {
			if (_nota >= 1 && _nota <= 10) {
				this->note[_index] = _nota;
			}
		}
	}

	int getNota(int _index) {
		if (_index >= 0 && _index < this->nrNote) {
			return this->note[_index];
		}
	}

	int getNrNote() {
		return this->nrNote;
	}

	void afisare() const {
		cout << "\n-------------";
		cout << "\nNume: " << this->nume;
		cout << "\nNr note: " << this->nrNote;
		cout << "\nNote: ";
		for (int i = 0; i < this->nrNote; i++) {
			cout << this->note[i] << " ";
		}
		cout << "\nBuget: " << this->buget;
		cout << "\n-------------";
	}

	~Student() {
		cout << "\nApel destructor";
		if (this->note != nullptr) {
			delete[] this->note;
			this->note = nullptr;
		}
	}
};

int main() {
	int note[]{ 10,7,4 };
	Student s1("Gigel", 3, note, 120);
	s1.afisare();
	//constructor copiere
	Student s2 = s1;
	Student s3(s1);
	s2.afisare();

	//op =
	//destructor



	return 0;
}