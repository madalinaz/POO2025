#include<iostream>
#include<list>
#include<set>
#include<map>
using namespace std;

//destructor virtual
//stl

class Angajat {
	string nume = "";
	float salariu = 0;

public:
	bool operator<(const Angajat& a) const{
		return this->salariu < a.salariu;
	}

	/*operator float() const{
		return this->salariu;
	}*/

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
	set<double> sD;
	sD.insert(12.5);
	sD.insert(10);
	sD.insert(15);
	sD.insert(12.5);
	cout << "\nSet double: ";
	set<double>::iterator it2;
	for (it2 = sD.begin(); it2 != sD.end(); it2++) {
		cout << *it2 << " ";
	}

	set<Angajat> sA;
	sA.insert(Angajat("A", 1100));
	sA.insert(Angajat("Z", 1200));
	sA.insert(Angajat("A", 900));
	sA.insert(Angajat("CA", 1300));
	sA.insert(Angajat("C", 900));

	cout << "\nSet Angajat: ";
	set<Angajat>::iterator it3;
	for (it3 = sA.begin(); it3 != sA.end(); it3++) {
		cout << *it3 << " ";
	}

	it3 = sA.find(Angajat("CB", 1300));
	if (it3 != sA.end()) {
		cout << "\nS-a gasit";
	}
	else {
		cout << "\nNU s-a gasit";
	}

	//map
	map<int, Angajat> m;
	//int este cheia
	//Angajat este informatia utila

	Angajat a1("A", 1100);
	Angajat a2("Z", 1200);
	Angajat a3("A", 900);
	
	m[0] = a1;
	m[1278] = a2;
	m[0] = a3;//in map se stocheaza ultima valoare
	m[3] = a1;//info utila se poate repeta pe chei diferite

	map<int, Angajat>::iterator it5;
	for (it5 = m.begin(); it5 != m.end(); it5++) {
		cout << it5->first << " " << it5->second;
	}

	return 0;
}