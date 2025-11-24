#include<iostream>
using namespace std;

class Student {
	const int id;
	string nume;
	int nrNote = 0;
	int* note = nullptr;
	static int notaTrecere;

public:
	Student(int _id) :id(_id) {
	}

	Student(int _id, string _nume, int _nrNote, int* _note) :id(_id) {
		this->nume = _nume;
		if (_nrNote > 0 && _note != nullptr) {
			this->nrNote = _nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = _note[i];
		}
	}

	Student(const Student& s) :id(s.id) {
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

	friend ostream& operator<<(ostream& out, const Student& s);

	friend istream& operator>>(istream& in, Student& s);

	Student& operator--() {
		for (int i = 0; i < this->nrNote; ++i)
			if (this->note[i] > 1)
				this->note[i]--;
		return *this; // returnam obiectul de dupa modificare
	}

	//FORMA DE REUTILIZARE A CODULUI DIN OPERATOR-- PRE-FIXAT
	//FORMAT POST-FIXATA
	Student operator--(int) {
		Student aux = *this;
		// --*this ; propunere de reutilizare a codului din celalalt operator
		for (int i = 0; i < aux.nrNote; ++i)
			if (aux.note[i] > 1)
				this->note[i]--;
		return aux; //returnam obiectul de dinainte de modificare
	}

	Student operator+(const Student& s) const {
		Student rez = *this;
		if (rez.note != nullptr) {
			delete[] rez.note;
			rez.note = nullptr;
			rez.nrNote = 0;
		}
		if (this->nrNote + s.nrNote > 0) {
			rez.nrNote = this->nrNote + s.nrNote;
			rez.note = new int[rez.nrNote];
			int k = 0;
			for (int i = 0; i < this->nrNote; ++i) {
				rez.note[k++] = this->note[i];
			}
			for (int i = 0; i < s.nrNote; ++i) {
				rez.note[k++] = s.note[i];
			}
		}
		return rez;
	}
	//cast la char*
	operator char* () {
		char* rez = new char[this->nume.length() + 1];
		strcpy(rez, this->nume.data());
		return rez;
	}

	//cast la int
	explicit operator int() {

		return this->nrNote;
	}

	//operator functie
	Student operator()()const {
		Student rez = *this;
		delete[] rez.note;
		rez.note = nullptr;
		rez.nrNote = 0;
		return rez;
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

ostream& operator<<(ostream& out, const Student& s) {
	out << "\nId: " << s.id;
	out << "\nNume:" << s.nume;
	out << "\nNr Note: " << s.nrNote;
	out << "\nNote ";
	for (int i = 0; i < s.nrNote; ++i) {
		out << s.note[i] << ' ';
	}
	return out;
}

//EXTENSIE TO DO HOME
//v1 : sa cereti reintroducerea valorilor(nrnote si note pana sunt valide)
//v2 : sa apelati operatorul += care adauga cate o nota de fiecare data
//operatorul += va arunca o exceptie care trebuie aici tratata

istream& operator>>(istream& in, Student& s) {
	//obj s deja exista
	if (s.note != nullptr) {
		delete[] s.note;
		s.note = nullptr;
		s.nrNote = 0;
	}
	// s.~Student(); de testat acasa
	cout << "\n Introduceti numele: ";
	in >> s.nume;
	cout << "Introduceti nr note: ";
	in >> s.nrNote;
	if (s.nrNote <= 0) {
		s.nrNote = 0;
		s.note = nullptr;
	}
	else {
		s.note = new int[s.nrNote];
		cout << "Introduceti note: ";
		for (int i = 0; i < s.nrNote; ++i)
			in >> s.note[i];
	}
	return in;
}


int main() {
	int note[] = { 10,6,8,4,1,9 };
	Student s1(12, "Gigel", 6, note);
	cout << s1;
	cout << "\n------------------ operator >> ------------------";
	Student s2(13);
	// cin >> s2;
	cout << s2;
	cout << "\n------------------ operator --(pre) ------------------";
	cout << s2 << s1;
	s2 = --s1;
	cout << s2 << s1;
	cout << "\n------------------ operator --(post) ------------------";
	cout << s2 << s1;
	s2 = s1--;
	cout << s2 << s1;

	cout << "\n------------------ operator + ------------------";
	//obj + int => returneaza un obj nou plecand de la I operand, la care adauga o noua nota
	//int + obj => acelasi context, dar ca sa permitem si comutativitatea (fara friend ca sa reutilizam implementarea obj+int)
	Student s3(1);
	s3 = s2 + s1; //returneaza un obj plecand de la s2 si completand cu toate notele lui s1
	cout << s3;

	cout << "\n------------------ operator cast/conversie ------------------";
	char* nume = s2; //extrage char* din nume
	cout << endl << nume;
	delete[] nume;
	//double notaMedie = s2; // returneaza media tuturor notelor
	if ((int)s1 != 10) {
		cout << "\nStudentul nu are 10 note (evaluarea se face pe baza castului la int";
	}
	else {
		cout << "\nInvers";
	}

	cout << "\n------------------ operator functie ------------------";
	// s3 = s2(1,4); // retruneaza un nou student doar cu notele dintre indecsii 1-4
	// s3=s2(3);// returneaza un student cu primele 3 note
	Student* v[5]; //
	int n = 5;
	//bool gasit = s2(v,n);//returneaza true daca exista s2 i  vectorul primit ca parametru
	s3 = s2();//returneaza un student din care am golit notele
	cout << s3;

	//TO DO HOME
	//s3 += 10; // adauga o noua nota la final + aruncat de exceptie si tratarea ei in main
	//!!!!!!!!!!!!!! se pot arunca si pointeri de exception
	return 0;
}