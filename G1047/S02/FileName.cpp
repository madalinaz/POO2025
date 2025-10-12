#include<iostream>
using namespace std;

void elim_prim_par(int*& v, int& n) {
	//p1 - se calculeaza noua dimensiune
	int poz = -1;//pozitia primului par
	for (int i = 0; i < n && poz == -1; i++) {
		if (v[i] % 2 == 0) {
			poz = i;
		}
	}
	int dim;
	if (poz != -1)
		dim = n - 1;
	else
		dim = n;
	//p2 - se aloca zona de memorie ptr noul vector
	int* aux;
	aux = new int[dim];
	//p3 - se copiaza in aux ce este nevoie
	int k = 0;
	for (int i = 0; i < n; i++)
		if (i != poz)
			aux[k++] = v[i];
	//p4 - dezalocam fostul vector
	delete[] v;
	//p5 - vector vechi pointeaza spre vector nou
	// + actualizare dimensiunea
	v = aux;
	n = dim;
}

void elim_primul(int*& v, int& n) {
	//p1 - se calculeaza noua dimensiune
	int dim = n - 1;
	//p2 - se aloca zona de memorie ptr noul vector
	int* aux;
	aux = new int[dim];
	//p3 - se copiaza in aux ce este nevoie
	int k = 0;
	for (int i = 1; i < n; i++)
		aux[k++] = v[i];
	//p4 - dezalocam fostul vector
	delete[] v;
	//p5 - vector vechi pointeaza spre vector nou
	// + actualizare dimensiunea
	v = aux;
	n = dim;
}

int main() {
	int* v;
	int n;
	cin >> n;
	v = new int[n];  //vectorul cu n int-uri
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << endl << "vector initial: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
	//exercitiul 1) Functia care elimina 
	// primul elem dintr-un vector
	elim_primul(v, n);
	cout << endl << "vector dupa ex1: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	//exercitiul 2) Functie care primeste 
	// un vector si elimina prima valoare 
	// para daca exista
	elim_prim_par(v, n);
	cout << endl << "vector dupa ex2: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";

	delete[] v;
	return 0;
}