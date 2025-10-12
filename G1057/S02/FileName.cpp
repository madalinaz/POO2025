#include <iostream>
using namespace std;

void eliminareMin(int*& v, int& n) { //int *& reprezinta adresa unui pointer la int
	//p1: calcul noua dimensiune
	int min = v[0];
	int nra = 1;
	for (int i = 1; i < n; i++)
		if (v[i] < min)
		{
			min = v[i];
			nra = 1;
		}
		else if (v[i] == min)
			nra++;
	int dimNoua = n - nra;

	//p2:alocare zona de memorie vect aux cu dimNoua
	int* aux;
	aux = new int[dimNoua];

	//p3:copiem in vector aux tot ce ne trebuie
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] != min)
		{
			aux[k++] = v[i];

		}
	}
	//p4: dezaloc zona de mem veche
	delete[] v; //se fol paranteze atunci cand la aloc s-a aloc in format de vector
	//p5:vector vechi pointeaza spre vect nou + actualizare dimensiune
	v = aux;
	n = dimNoua;

}
void dublareUltimaAparitie(int*& vector, int& lungime)
{
	int* aux;
	aux = new int[lungime + 1];


	for (int i = 0; i < lungime; i++)
	{
		aux[i] = vector[i];
	}
	aux[lungime] = vector[lungime - 1];

	delete[] vector;
	vector = aux;

	lungime++;
}

int main() {
	int* v;
	int n;
	cin >> n;
	//v =(int*) malloc(n * sizeof(int)); //limbaj C 
	v = new int[n]; // n int-uri
	int* p;
	p = new int(n); //aloca zona de mem pt un int pe care il initializeaza cu n
	cout << *p;
	cout << endl << p[0];
	cout << endl << *(p + 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << endl;
	cout << "vector initial: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	//ex 1 functia care elimina val minima dintr-un vect indiferent de nr de aparitii
	eliminareMin(v, n);
	cout << endl;
	cout << "vector dupa ex 1: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";

	//ex 2 functia care dubleaza ap ultimului el din vector
	//ex: v=1 2 3 => 1 2 3 3
	dublareUltimaAparitie(v, n);
	cout << "Vector modificat: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;

	delete[] v;
	delete p;

	/*cout << "joaca pe for" << endl;
	int i;
	for (int ;i < n;)
	{
		cout << i << " ";
		i++;
	}*/

	return 0;
}
