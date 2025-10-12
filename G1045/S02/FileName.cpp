#include<iostream>
using namespace std;

//transfer prin referinta un pointer
void dublareUltimElem(int*& v, int& n) {
	//P1.calcul dimensiune noua
	int dim = n + 1;

	//P2.alocare z.m. pentru noul vector
	int* aux = new int[dim];

	//P3.se copiaza in noul vector tot ce este nevoie
	int k = 0;
	for (int i = 0; i < n; i++) {
		aux[k++] = v[i];
	}
	aux[dim - 1] = v[n - 1];

	//P4.se dezloca z.m. a vectorului initial
	delete[] v;

	//P5.vector vechi pointeaza spre vector nou + resetare dimensiune
	v = aux;
	n = dim;
}

void eliminarePrimElem(int*& v, int& n) {
	//P1.calcul dimensiune noua
	int dim = n - 1;

	//P2.alocare z.m. pentru noul vector
	int* aux = new int[dim];

	//P3.se copiaza in noul vector tot ce este nevoie
	int k = 0;
	for (int i = 1; i < n; i++) {
		aux[k++] = v[i];
	}

	//P4.se dezloca z.m. a vectorului initial
	delete[] v;

	//P5.vector vechi pointeaza spre vector nou + resetare dimensiune
	v = aux;
	n = dim;
}

int main() {
	int n;
	cin >> n;
	int* v;
	v = new int[n];
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << "\ndimensiune initiala: " << n;
	cout << "\nvector initial: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	//ex1. dubleaza aparitia ultimului elem din vector
	// v= 1 2 3 4 => v= 1 2 3 4 4
	dublareUltimElem(v, n);
	cout << "\ndimensiune dupa ex1: " << n;
	cout << "\nvector dupa ex1: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";

	//ex2. sterge primul element
	eliminarePrimElem(v, n);
	cout << "\ndimensiune dupa ex2: " << n;
	cout << "\nvector dupa ex2: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";

	//ex3. sterge toate elem pare dintr-un vector
	delete[] v;

	//o lista de nume de prieteni + dimensiunea sa
	//n=3
	//Popescu Ionel
	//Ionescu Maricela
	//Pop Ana
	//separat am un nume de sfant =>Ana
	//o functie care afiseaza numele prietenilor pe care ii voi suna de sf primit ca param
	//inca in char
	return 0;
}