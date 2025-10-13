#include<iostream>
using namespace std;

//int* v->pointer transferat prin valoare
//int n->int transfer prin valoare
//int& n ->int transferat prin referinta(specific c++)
//int*& v ->int* transferat prin referinta
void eliminarePrimulNr(int*& v, int& n) {
	//P1.se calculeaza noua dimensiune
	int dim = n - 1;
	//P2.se aloca z.m. pentru noul vector
	int* aux = new int[dim];
	//P3.se copiaza in noul vector ce este nevoie
	int k = 0;
	for (int i = 1; i < n; i++) {
		aux[k++] = v[i];
		//aux[i - 1] = v[i];
	}
	//P4.se dezaloca fostul vector
	delete[] v;
	v = nullptr;
	//P5.vector vechi pointeaza spre cel nou + 
	//actualizare dimensiune
	v = aux;
	n = dim;
}

int* eliminarePrimulNrReturn(int* v, int& n) {
	int dim = n - 1;
	int* aux = new int[dim];
	int k = 0;
	for (int i = 1; i < n; i++) {
		aux[k++] = v[i];
	}
	delete[] v;
	v = nullptr;
	n = dim;
	return aux;
}

void dublarePrimulMax(int*& v, int& n) {
	//P1.se calculeaza noua dimensiune
	int dim = n + 1;
	//P2.se aloca z.m. pentru noul vector
	int* aux = new int[dim];
	//P3.se copiaza in noul vector ce este nevoie
	int max = INT_MIN;
	int pozPrimMax = -1;
	for (int i = 0; i < n; i++) {
		if (v[i] > max) {
			max = v[i];
			pozPrimMax = i;
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		aux[k++] = v[i];
		if (i == pozPrimMax) {
			aux[k++] = v[i];
		}
	}
	//P4.se dezaloca fostul vector
	delete[] v;
	v = nullptr;
	//P5.vector vechi pointeaza spre cel nou + 
	//actualizare dimensiune
	v = aux;
	n = dim;
}

int main() {
	int* v;
	int n;
	cin >> n;
	v = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << "\nDimensiune initiala: " << n;
	cout << "\nVector initial: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	//ex1.sa se elimine primul elem din vector
	eliminarePrimulNr(v, n);
	//v = eliminarePrimulNrReturn(v, n);
	cout << "\nDimensiune dupa ex1: " << n;
	cout << "\nVector dupa ex1: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";

	//ex2.sa se dubleze doar prima aparitie a valorii
	//maxime dintr-un vector
	//v= 3 7 5 2 7 5 => 3 7 7 5 2 7 5 
	dublarePrimulMax(v, n);
	cout << "\nDimensiune dupa ex2: " << n;
	cout << "\nVector dupa ex2: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	delete[] v;
	return 0;
}