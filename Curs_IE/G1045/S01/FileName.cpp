#include<stdio.h>
#include<malloc.h>

//transfer prin valoare
void f1(int a, int b) {
	int aux;
	aux = a;
	a = b;
	b = aux;
}

//transfer prin pointer/adresa
void f2(int* a, int* b) {
	int aux;
	aux = *a;//operatie de dereferentiere
	*a = *b;
	*b = aux;
}

//transfer prin pointer/adresa
void f3(int* a, int* b) {
	int* aux;
	aux = a;
	a = b;
	b = aux;
}

//tranfer prin referinta (limbaj c++)
void f4(int& a, int& b) {
	int aux;
	aux = a;
	a = b;
	b = aux;
}

int main() {
	int x, y;

	//gasiti un mecanism de "sablonare" a codului
	printf("\n---------Meth1-----");
	x = 10;
	y = 20;
	printf("\nx=%d, y=%d", x, y);
	f1(x, y);
	printf("\nx=%d, y=%d", x, y);

	printf("\n---------Meth2-----");
	x = 10;
	y = 20;
	printf("\nx=%d, y=%d", x, y);
	f2(&x, &y);
	printf("\nx=%d, y=%d", x, y);

	printf("\n---------Meth3-----");
	x = 10;
	y = 20;
	printf("\nx=%d, y=%d", x, y);
	f3(&x, &y);
	printf("\nx=%d, y=%d", x, y);

	printf("\n---------Meth4-----");
	x = 10;
	y = 20;
	printf("\nx=%d, y=%d", x, y);
	f4(x, y);
	printf("\nx=%d, y=%d", x, y);

	int* v;
	v = (int*)malloc(5 * sizeof(int));
	free(v);
	int* v2;
	v2 = (int*)malloc(5 * sizeof(int));
	//v2 = &x;
	free(v2);
	return 0;
}