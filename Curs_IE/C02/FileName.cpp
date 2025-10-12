#include<iostream>
using namespace std;

void test(int& n) {
	cout << "\nSunt in functia test";
}

int main() {
	cout << "\n-----CIN + COUT-----\n";
	int x = 5;
	//cin >> x;
	cout << "x= " << x;
	cout << "\n-----NEW + DELETE-----\n";
	int* p;
	//p = (int*)malloc(sizeof(int));
	p = new int;//alocare 1 int
	*p = 10;
	p[0] = 20;
	*(p + 0) = 30;
	cout << endl << &p;//de pe stiva
	cout << endl << p;//de pe heap
	cout << endl << *p;
	delete p;

	p = new int(15);//aloca 1 int pe care il si init cu 15
	delete p;

	//p = (int*)malloc(10*sizeof(int));
	p = new int[10];//alocare de 10 int-uri
	for (int i = 0; i < 10; i++)
		p[i] = i + 10;
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << p[i] << " ";
	delete[] p;

	cout << "\n-----NULL + nullptr-----\n";
	int val1 = NULL;//NULL este constanta 0;
	char c = NULL;
	//int* pointer = NULL;
	int* pointer = nullptr;
	//int val2 = nullptr; NU SE POATE

	cout << "\n-----DANGLING POINTERS + nullptr-----\n";
	int* ptr;//pointer neinit => 0xCCCCC
	ptr = nullptr; //ox00000
	ptr = new int[5];
	for (int i = 0; i < 5; i++)
		ptr[i] = i;
	//folosesc ptr pentru ce trebuie
	delete[] ptr;
	ptr = nullptr;
	//mai trece ceva timp....

	if (ptr != nullptr) {
		cout << "\nTentativa accesare elem din vector: ";
		for (int i = 0; i < 5; i++)
			cout << ptr[i] << " ";
	}
	else {
		cout << "\nNo can do!!!";
	}

	cout << "\n-----CONST-----\n";
	const int z = 13;
	cout << z;
	//z = 10;
	//test(z);
	int a = 123;
	const int* px1;//pointer spre continut constant
	//*px1 = 123;
	px1 = &a;

	int const* px4;//pointer spre continut constant
	//*px4 = 123;
	px4 = &a;

	int* const px2 = &a;//pointer constant
	*px2 = 123;
	//px2 = &a;

	const int* const px3 = &a;//pointer constant spre continut constant
	//*px3 = 123;
	//px3 = &a;


	return 0;
}
