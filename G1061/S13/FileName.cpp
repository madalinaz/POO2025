#include<iostream>
#include<fstream>
using namespace std;

//o clasa la alegere care sa contina cel putin un camp numeric (constructor cu param, ostream)
//o clasa tip container de obiecte (alocare statica sau dinamica)
//un fisier text
//generare raport text pe baza unei colectii de obiecte de tipul clasei care sa contina top n obiecte in functie de campul numeric ales

class Student {
	string nume="Anonim";

public:
	friend ostream& operator<<(ostream& out, const Student& s);
};

ostream& operator<<(ostream& out, const Student& s) {
	out << s.nume << endl;
	return out;
}

//Grupa has a Student
class Grupa {
	Student v[10];//alocare statica
	int nr;

	//Student* vDinamic;
	//int nrDinamic;

	////daca dorim retinerea prin actualizari a obiectelor, atunci folosim pointeri
	//Student* v2[10];
	//int nr2;

	//Student** v3;//dinamic stochez pointeri la student
	//int nr3;
public:
	void generareFisierText(string numeFisier, int ct) {
		ofstream fOut(numeFisier);
		//sortare pe vector de Student
		for (int i = 0; i < ct; i++)
			fOut << this->v[i];
		fOut.close();
	}
};

int main() {
	//fisiere text
	Student s;
	cout << s;
	ofstream g("fisier.txt");
	g << s;//ofstream is a ostream
	g.close();

	Grupa gr;
	//gr.generareFisierText("top.txt", 3);
	return 0;
}