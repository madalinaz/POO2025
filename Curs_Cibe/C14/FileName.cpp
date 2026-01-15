#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>
using namespace std;

class Angajat {
	string nume = "Anonim";
	float salariu = 0;

public:
	Angajat() {

	}

	Angajat(string _nume, float _salariu) {
		this->nume = _nume;
		this->salariu = _salariu;
	}

	bool operator<(const Angajat& a) const{
		return this->salariu < a.salariu;
	}

	operator float() {
		return this->salariu;
	}

	friend ostream& operator<<(ostream& out, const Angajat& a) {
		out << "\nNume: " << a.nume << ", salariu: " << a.salariu;
		return out;
	}
};

//1-M
//1-1
class Companie {
	Angajat* lista = nullptr;
	int nrAngajat=0;
};

class Companie2 {
	vector<Angajat> lista;
};

int main() {
	//STL ->standard template library
	//faciliteaza lucrul cu structuri de date
	//vector, matrice
	//lista simplu sau dublu inlantuite
	//stiva, coada
	//arbori, grafuri

	//vector
	vector<int> vInt;
	cout << endl << vInt.size();
	vInt.push_back(20);
	vInt[0] = 10;
	vInt.push_back(123);
	cout << "\nAfisare vector: ";
	for (int i = 0; i < vInt.size(); i++) {
		cout << vInt[i] << " ";
	}
	//parcurgere folosind iterator
	vector<int>::iterator it;
	cout << "\nAfisare vector cu it: ";
	for (it = vInt.begin(); it != vInt.end(); it++) {
		cout << *it << " ";
	}

	//lista
	list<string> listString;
	listString.push_back("Costel");
	listString.push_front("Maria");
	listString.push_back("Maria");

	cout << "\nAfisare lista: ";
	list<string>::iterator itList;
	for (itList = listString.begin(); itList != listString.end(); itList++) {
		cout << *itList << " ";
	}
	cout << "\nAfisare lista invers: ";
	list<string>::reverse_iterator itListR;
	for (itListR = listString.rbegin(); itListR != listString.rend(); itListR++) {
		cout << *itListR << " ";
	}

	//set
	set<float> setFloat;
	setFloat.insert(12.5);
	setFloat.insert(10);
	setFloat.insert(15);
	setFloat.insert(12.5);

	cout << "\nAfisare set: ";
	set<float>::iterator itSet;
	for (itSet = setFloat.begin(); itSet != setFloat.end(); itSet++) {
		cout << *itSet << " ";
	}

	set<Angajat> setAng;
	setAng.insert(Angajat("A", 1200));
	setAng.insert(Angajat("F", 1100));
	setAng.insert(Angajat("A", 1500));
	setAng.insert(Angajat("C", 1200));

	cout << "\nAfisare set de Angajati: ";
	set<Angajat>::iterator itSet2;
	for (itSet2 = setAng.begin(); itSet2 != setAng.end(); itSet2++) {
		cout << *itSet2 << " ";
	}

	Angajat a1("A", 1200);
	Angajat a2("B", 900);
	Angajat a3("B", 1100);
	Angajat a4("AA", 100);
	//map
	map<int, Angajat> m;
	//int este cheie
	//Angajat este elem stocat/informatia utila
	m[0] = a1;//lui a1 i-am acordat cheia 0
	m[1235] = a2;
	m[13] = a1;
	m[0] = a4;//retine ultima valoare adaugata
	map<int, Angajat>::iterator itM;
	for (itM = m.begin(); itM != m.end(); itM++) {
		cout << itM->first << " " << itM->second;
	}

	itM = m.find(a2);
	if (itM != m.end()) {
		cout << endl << "S-a gasit elem cautat";
		cout << itM->second;
	}
	else {
		cout << "\nNu s-a gasit elem cautat";
	}
	return 0;
}