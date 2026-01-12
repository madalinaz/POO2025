#include<iostream>
#include<vector>
using namespace std;

class Angajat {
	string nume = "";
	float salariu = 0;

public:

	Angajat(string _nume, float _salariu) {
		this->nume = _nume;
		this->salariu = _salariu;
	}

	friend ostream& operator<<(ostream& out, const Angajat& a) {
		out << "\nNume: " << a.nume << ", salariu: " << a.salariu;
		return out;
	}
};

//clasa Concediu ->campuri la alegere

//colectie/relatie has a; clasa template
//o clasa care sa retina informatii pentru fiecare Angajat, o colectie de elemente generice (acea colectie/vector/lista -> un set de sporuri/ un set de concedii/.....)

//clasa template
//ColectieAngajati has a Angajat
class ColectieAngajati {
	//vector de pointeri la angajati
	//matrice de obj de tip generic T
	//
};

int main() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(15);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	vector<int>::iterator it;
	cout << endl;
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}

	vector<vector<int>> m; //matricea bi-dimensionala
	//adaugam pe prima linie din vector valoarea 10;
	m.push_back(vector<int>{});
	m[0].push_back(10);
	m.push_back(vector<int>{});
	m[1].push_back(20);
	m[1].push_back(100);
	m[1].push_back(30);
	m.push_back(vector<int>{});
	m[2].push_back(30);
	m[2].push_back(30);
	m.push_back(vector<int>{});
	m[3].push_back(20);
	m[3].push_back(20);
	m[3].push_back(20);

	cout << "\n**************\n";
	//o metoda/forma de afisare a matricei noastre
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[i].size(); j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}