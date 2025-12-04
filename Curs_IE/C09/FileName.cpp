#include<iostream>
using namespace std;

string generareCNP() {
	return "123456789";
}

class Persoana {
public:
	const string CNP;
protected:
	string nume="-";
private:
	int varsta=0;

public:
	Persoana():CNP(generareCNP()) {
		cout << "\nApel constructor fara param Persoana";
	}

	Persoana(string _nume, int _varsta):CNP(generareCNP()) {
		cout << "\nApel constructor cu param Persoana";
		this->nume = _nume;
		this->varsta = _varsta;
	}

	Persoana(const Persoana& p): CNP(p.CNP){
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
};

ostream& operator<<(ostream& out, const Persoana& p) {
	out << "\nCNP: " << p.CNP;
	out << "\nNume: " << p.nume;
	out << "\nVarsta: " << p.varsta;
	return out;
}

class Student: public Persoana {
	string facultate;

public:
	Student() {

	}

	Student(string _nume, int _varsta, string _facultate):Persoana(_nume,_varsta) {
		this->facultate = _facultate;
	}
};

int main() {
	Persoana p1("Costachescu Marcel",40);
	cout << p1;
	Student s1("Gigel", 19, "CSIE");
	Persoana p2 = s1;//upcast
	Student s2 = p1;
	p2 = s1;
	s2 = p1;

	Student* ps = new Student();
	ps = &s1;
	Persoana* pp = new Persoana();
	pp = &p1;
	ps = &p1;
	pp = &s1;
	return 0;
}