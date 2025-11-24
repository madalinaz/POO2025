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

	int operator[](int _index) {
		if (_index >= 0 && _index < this->nrNote) {
			return this->note[_index];
		}
		else {
			throw new exception("Indexul NU este valid");
		}
	}

	//primul student este this iar cel de-al doilea este s
	Student operator+(const Student& s) const{
		Student rez = *this;
		//adaug notele din s in rez
		rez.nrNote = this->nrNote + s.nrNote;
		if (rez.nrNote == 0)
			rez.note = nullptr;
		else {
			//daca rez are note din cauza lui this
			if (rez.note != nullptr) {
				delete[] rez.note;
				rez.note = nullptr;
			}
			rez.note = new int[rez.nrNote];
			int k = 0;
			for (int i = 0; i < this->nrNote; i++)
				rez.note[k++] = this->note[i];
			for (int i = 0; i < s.nrNote; i++)
				rez.note[k++] = s.note[i];
		}
		return rez;
	}

	//forma post-fixata
	Student operator--(int) {
		Student copie = *this;
		for (int i = 0; i < this->nrNote; i++) {
			if (this->note[i] > 1)
				this->note[i]--;
		}
		return copie;//returnam starea obj de dinainte de decrementare
	}

	//forma pre-fixata
	Student& operator--() {
		for (int i = 0; i < this->nrNote; i++) {
			if (this->note[i] > 1)
				this->note[i]--;
		}
		return *this;//returnam versiunea obiectului de dupa decrementare
	}

	friend ostream& operator<<(ostream& out, const Student& s);
	friend istream& operator>>(istream& in, Student& s);
};

int Student::notaTrecere = 5;

//TO DO HOME
//de regestionat operatorul >> astfel incat la adaugarea de noi note sa se apeleze operatorul += care adauga cate o noua nota
//in acest caz, mecanismul de try-catch este gestionat in functia care supraincarca operatorul>>

istream& operator>>(istream& in, Student& s) {
	//obj s deja exista
	if (s.note != nullptr) {
		delete[] s.note;
		s.note = nullptr;
		s.nrNote = 0;
	}
	cout << "\nIntroduceti nume: ";
	in >> s.nume;
	cout << "\nIntroduceti nr note: ";
	in >> s.nrNote;
	if (s.nrNote <= 0) {
		s.nrNote = 0;
		s.note = nullptr;
	}
	else {
		s.note = new int[s.nrNote];
		cout << "Introduceti note: ";
		for (int i = 0; i < s.nrNote; i++)
			in >> s.note[i];
	}
	return in;
}

ostream& operator<<(ostream& out, const Student& s) {
	out << "\nId: " << s.id;
	out << "\nNume: " << s.nume;
	out << "\nNr note: " << s.nrNote;
	out << "\nNote: ";
	for (int i = 0; i < s.nrNote; i++)
		out << s.note[i] << " ";
	return out;
}


int main() {
	int note[] = {10,6,4,8,3};
	Student s1(12, "Gigel", 5, note);
	cout << s1;//ostream << Student

	cout << "\n------ operator [] ---------";
	int nota;
	try {
		nota = s1[-3];//Student [] int
		cout << endl << nota;
	}
	catch (exception* ex) {
		cout << endl << ex->what();
		delete ex;
	}

	cout << "\n------ operator + ---------";
	int note2[] = { 10,9 };
	Student s2(13, "Maria", 2, note2);
	Student s3(14);
	s3 = s1 + s2;//returneaza un obj Student care are numele primului operand iar notele concatenarea celor 2 vectori
	cout << s3;

	//TO DO HOME
	//s2 = s1 + 10;//returneaza un obj plecand de la s1 la care adaugam la sfarsit o nota nota
	//daca nota nu e valida, aruncam exceptie

	//s2 = s1 - 5;//returneaza un obj plecand de la s1 si elimina toate notele de 5

	//s2 += 10;//adauga o noua nota(lucram direct pe this)

	cout << "\n------ operator >> ---------";
	Student s4(19);
	//cin >> s4;// istream >> Student
	cout << s4;

	cout << "\n------ operator -- pre ---------";
	cout << s4 << s3;
	s4 = --s3;//fiecare nota scade cu un punct, daca se poate
	cout << s4 << s3;

	cout << "\n------ operator -- post ---------";
	cout << s4 << s3;
	s4 = s3--;//fiecare nota scade cu un punct, daca se poate
	cout << s4 << s3;
	return 0;
}