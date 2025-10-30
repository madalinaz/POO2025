#include<iostream>
using namespace std;

class Produs {
	//to do home (denumire initializata cu Anonim)
	char* denumire = nullptr;
	int stoc = 0;
	double pret = 0;
	//camp constant?
	//camp static??

public:
	//constructori
	Produs() {

	}

	//DP Builder care ofera posibilitate de construire obj complexe
	Produs(const char* _denumire, int _stoc, double _pret) {
		if (strlen(_denumire) > 3) {
			this->denumire = new char[strlen(_denumire) + 1];
			strcpy_s(this->denumire, 
				strlen(_denumire) + 1, _denumire);
		}
		if (_stoc > 0) {
			this->stoc = _stoc;
		}
		if (_pret > 0) {
			this->pret = _pret;
		}
	}
	//constructor copiere
	//destructor
	//operator =
	//meth afisare
};

int main() {
	return 0;
}