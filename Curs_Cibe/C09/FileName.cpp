#include<iostream>
using namespace std;

class Grupa {

};

//Serie has a colectie de grupe
class Serie1 {
	Grupa lista[10];//vector alocat static de obj de tip Grupa
	int nrGrupe;
};

class Serie2 {
	Grupa* lista;//vector alocat dinamic de obj de tip Grupa
	int nrGrupe;
};


string generareCNP() {
	return "123456789";
}

class Persoana {
	const string CNP;

protected:
	string nume = "-";
	int varsta = 0;

public:

	Persoana() :CNP(generareCNP()) {
		cout << "\nApel constructor fara param Persoana";
	}

	Persoana(string _nume, int _varsta) :CNP(generareCNP()) {
		cout << "\nApel constructor cu param Persoana";
		this->nume = _nume;
		this->varsta = _varsta;
	}

	Persoana(const Persoana& p) : CNP(p.CNP) {
		cout << "\nApel constructor copiere Persoana";
		this->nume = p.nume;
		this->varsta = p.varsta;
	}

	Persoana& operator=(const Persoana& p) {
		cout << "\nApel op= Persoana";
		this->nume = p.nume;
		this->varsta = p.varsta;
		return *this;
	}

	~Persoana() {
		cout << "\nApel destructor Persoana";
	}

	friend ostream& operator<<(ostream& out, const Persoana& p);

	bool operator==(const Persoana& p) const{
		return this->CNP == p.CNP;
	}
};

ostream& operator<<(ostream& out, const Persoana& p) {
	out << "\nCNP: " << p.CNP;
	out << "\nNume: " << p.nume;
	out << "\nVarsta: " << p.varsta;
	return out;
}

class Student:public Persoana {
	string facultate="-";

public:
	Student() {
		cout << "\nApel constructor fara param Student";
	}

	Student(string _nume, int _varsta, string _facultate):Persoana(_nume,_varsta) {
		cout << "\nApel constructor cu param Student";
		this->facultate = _facultate;
	}

	Student(Persoana p, string _facultate):Persoana(p) {
		cout << "\nApel constructor cu param 2 Student";
		this->facultate = _facultate;
	}

	//upcast de la s la un obj de tip Persoana
	Student(const Student& s):Persoana(s) {
		cout << "\nApel constructor copiere Student";
		this->facultate = s.facultate;
	}

	Student& operator=(const Student& s) {
		cout << "\nApel op= Student";
		if (this != &s) {
			Persoana::operator=(s);
			this->facultate = s.facultate;
		}
		return *this;
	}

	~Student() {
		cout << "\nApel destructor Student";
	}

	friend ostream& operator<<(ostream& out, const Student& s);

	bool operator==(const Student& s) {
		//return this->Persoana::operator==(s) && this->facultate == s.facultate;
		return (Persoana)*this==(Persoana)s && this->facultate == s.facultate;
	}
};

ostream& operator<<(ostream& out, const Student& s) {
	out << (Persoana&)s;//upcast explicit ->returneaza o copie
	out << "\nFacultate: " << s.facultate;
	return out;
}

class Persoana_extinsa :public Persoana {
	string adresa;

};

int main() {
	Student s1;
	Student s2("Gigel", 19, "CSIE");
	//Student s3(Persoana("Costel", 20), "FABIZ");
	Student s4(s2);
	s1 = s4;
	cout << "\n------------";
	cout << s1;
	cout << "\n------------";

	if (s1 == s4)
		cout << "\nStudentii au acelasi cnp si facultate";
	else
		cout << "\nInvers";
	return 0;
}