#include<stdio.h>
#include<malloc.h>

int main() {
	int x;
	int y;
	int* p;//pointer la int
	printf("%d", sizeof(p));
	p = &x;//operator de referentiere
	x = 10;
	printf("%d", *p);//operator de dereferentiere

	p = (int*)malloc(sizeof(int));
	//*p = 17;
	p = &x;
	free(p);
	//afisare adresa variabilei p
	//printf("\n%p", &p);
	//afisare valoarea lui p(adresa spre care pointeaza)
	//printf("\n%p", p);
	//afisare continutul adresei spre care pointeaza p
	//printf("\n%d", *p);

	int v[100];
	int* v2 = (int*)malloc(10 * sizeof(int));
	return 0;
}