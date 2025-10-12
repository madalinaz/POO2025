#include<iostream>
using namespace std;

void elimPare(int*& v, int& n) {
	//P1. se calculeaza noua dimensiune
	int dim = 0;
	for (int i = 0; i < n; i++)
		if (v[i] % 2 == 1)
			dim++;
	//P2. se aloca z.m. pentru noul vector(aux)
	int* aux = new int[dim];

	//P3. se copiaza in noul vector 
	// tot ce trebuie
	int k = 0;
	for (int i = 0; i < n; i++)
		if (v[i] % 2 == 1) {
			aux[k++] = v[i];
		}
	//P4. dezalocam fostul vector
	delete[] v;
	//P5. vector vechi pointeaza spre vector nou
	// + copiere noua dimensiune
	v = aux;
	n = dim;
}

void elimUltimMinim(int*& v, int& n) {
	//P1. se calculeaza noua dimensiune
	int dim = n - 1;
	//P2. se aloca z.m. pentru noul vector(aux)
	int* aux = new int[dim];

	//P3. se copiaza in noul vector 
	// tot ce trebuie
	int min = v[n - 1];
	int pozMin = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] < min) {
			min = v[i];
			pozMin = i;
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++)
		if (i != pozMin) {
			aux[k++] = v[i];
		}
	//P4. dezalocam fostul vector
	delete[] v;
	//P5. vector vechi pointeaza spre vector nou
	// + copiere noua dimensiune
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
	cout << "\nVector init: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	//ex1. elimina valorile pare din vector
	//elimPare(v, n);
	cout << "\nVector dupa ex1: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";

	//ex2. eliminare ultim min din vector
	elimUltimMinim(v, n);
	cout << "\nVector dupa ex2: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	return 0;
}