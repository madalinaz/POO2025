#include<iostream>
using namespace std;

//returneaza suma elem din cadrul vectorului din intervalul i1-i2
int calculSuma(int* v, int n, int i1, int i2) {
	if (v != nullptr && n > 0) {
		if (i1 >= 0 && i2 < n) {
			if (i1 <= i2) {
				int s = 0;
				for (int i = i1; i <= i2; i++)
					s += v[i];
				return s;
			}
		}
	}
}

//propuneti home motive pentru care vrem astfel de custom exception
// (>=3)
//clasa exception custom
class exceptieVectorGol :exception {
public:
	exceptieVectorGol(const char* mesaj):exception(mesaj) {

	}
};

class exceptieIndecsi :exception {

};

class exceptieOrdine :exception {

};

int calculSumaNew(int* v, int n, int i1, int i2) {
	if (v == nullptr || n <= 0) {
		throw exceptieVectorGol("vector gol");
	}
	if (i1 < 0 || i2 >= n) {
		throw exception("indecsi gresiti");
	}
	if (i1 > i2) {
		throw exception("ordine gresita");
	}
	
	int s = 0;
	for (int i = i1; i <= i2; i++)
		s += v[i];
	return s;
}

int main() {
	return 0;
}