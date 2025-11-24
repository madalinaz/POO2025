#include<iostream>
using namespace std;

class Student {
	const int id;
	string nume;
	int nrNote=0;
	int* note=nullptr;
	static int notaTrecere;

public:
	Student(int _id):id(_id) {
	}

	Student(int _id, string _nume, int _nrNote, int* _note):id(_id) {
		this->nume = _nume;
		if (_nrNote > 0 && _note != nullptr) {
			this->nrNote = _nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = _note[i];
		}
	}

	Student(const Student& s):id(s.id) {
		this->nume = s.nume;
		if (s.nrNote > 0 && s.note != nullptr) {
			this->nrNote = s.nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = s.note[i];
		}
	}

	Student& operator=(const Student& s) {
		if (this != &s) {
			//destructor
			if (this->note != nullptr) {
				delete[] this->note;
				this->note = nullptr;
				this->nrNote = 0;
			}
			//constructor copiere
			this->nume = s.nume;
			if (s.nrNote > 0 && s.note != nullptr) {
				this->nrNote = s.nrNote;
				this->note = new int[this->nrNote];
				for (int i = 0; i < this->nrNote; i++)
					this->note[i] = s.note[i];
			}
		}
		return *this;
	}

	~Student() {
		if (this->note != nullptr) {
			delete[] this->note;
			this->note = nullptr;
			this->nrNote = 0;
		}
	}


};

int Student::notaTrecere = 5;

operator<<()

int main() {
	int note[] = {10,6,4,8,3};
	Student s1(12, "Gigel", 5, note);
	cout << s1;//ostream << Student
	return 0;
}