#include<iostream>
#include<list>
#include<set>
using namespace std;

//destructor virtual
//stl

class Angajat {
	string nume = "";
	float salariu = 0;

public:
	Angajat() {

	}

	Angajat(string _nume, float _salariu) {
		this->nume = _nume;
		this->salariu = _salariu;
	}

	friend ostream& operator<<(ostream& out, const Angajat& a) {
		out << "\nNume: " << a.nume << ", salariu: " << a.salariu;
		return out;
	}
};

class Baza {
public:
	virtual ~Baza() {
		cout << "\nDestructor Baza";
	}
};

class Derivata : public Baza {
public:
	~Derivata() {
		cout << "\nDestructor Derivata";
	}
};

int main() {
	/*Baza b;
	Derivata d;
	Baza* pb = new Derivata();
	delete pb;
	cout << 1;*/

	//STL
	list<string> l;
	l.push_back("Ana");
	l.push_front("Maria");
	l.push_back("Ana");

	cout << "\nAfisare list of string: ";
	list<string>::iterator it;
	for (it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}

	cout << "\nAfisare list of string reverse: ";
	list<string>::reverse_iterator itR;
	for (itR = l.rbegin(); itR != l.rend(); itR++) {
		cout << *itR << " ";
	}

	//set
	set<Angajat> 
	return 0;
}