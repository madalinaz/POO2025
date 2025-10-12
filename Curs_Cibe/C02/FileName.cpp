#include<iostream>
using namespace std;
int global;
//transfer prin valoare ->se face o COPIE
void f1(int a, int b) {
	int aux;
	aux = a;
	a = b;
	b = aux;
}

//specific c++
//transfer prin referinta
void f2(int& a, int& b) {
	int aux;
	aux = a;
	a = b;
	b = aux;
}

//transfer prin pointer
void f3(int* a, int* b) {
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int main() {
	//printf("\nMesaj");
	//std::cout << std::endl << "Mesaj";//obj de tip ostream
	cout << endl << "Mesaj" << endl;
	int x = 10;
	cout << "x=" << x;
	cout << endl << "adresa lui x=" << &x;
	int y = 5;
	cout << endl << x << " " << y;
	//scanf_s("%d", &x); 
	cin >> x;
	cout << endl << "x=" << x;
	cin >> x >> y;

	//alocare si dezalocare
	cout << endl << "\n-----ALOCARE SI DEZALOCARE-----\n";
	int* p;
	//p este un pointer spre un elem de tip int
	/*p = (int*)malloc(sizeof(int));
	*p = 10;*/
	p = new int;//am alocat z.m. pentru un int
	*p = 10;
	cout << "\nAdresa lui p: " << &p;
	cout << "\nPointerul p(spre ce pointeaza p): " << p;
	cout << "\nContinutul adresei spre ce pointeaza: " << *p;
	delete p;

	p = new int(10);//aici aloca un int dar il si initializeaza cu 10
	delete p;//dangling pointer
	//p = NULL;
	p = nullptr;//pointer-ul null
	int val = NULL;//constanta 0

	//p = (int*)malloc(5*sizeof(int));
	p = new int[5];//p-ul este un vector alocat dinamic
	for (int i = 0; i < 5; i++) {
		p[i] = i + 2;
		//*(p + i) = i + 2;
	}
	cout << endl << "Afisare vector: ";
	for (int i = 0; i < 5; i++) {
		cout << p[i] << " ";
	}
	delete[] p;//daca p este alocat cu int[]
	p = nullptr;

	cout << endl << "\n-----TRANSFESUL PARAMETRILOR-----\n";
	int val1, val2;
	val1 = 10;
	val2 = 20;
	cout << endl << "val1= " << val1 << ", val2= " << val2;
	f1(val1, val2);
	cout << endl << "val1= " << val1 << ", val2= " << val2;
	f2(val1, val2);
	cout << endl << "val1= " << val1 << ", val2= " << val2;

	return 0;
}