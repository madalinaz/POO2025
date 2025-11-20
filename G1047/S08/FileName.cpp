#include<iostream>
using namespace std;

enum TipObiect {
	AVION, NAVA, ROCA, BARCA
};

class Obiect2D {
	int nivelViata=100;
	TipObiect tip=TipObiect::AVION;
	int pozX=0;
	int pozY=0;

public:
	Obiect2D(){ }

	Obiect2D(TipObiect _tip, int _pozX, int _pozY) {
		this->tip = _tip;
		this->pozX = _pozX;
		this->pozY = _pozY;
	}

	Obiect2D(const Obiect2D& o) {
		this->nivelViata = o.nivelViata;
		this->tip = o.tip;
		this->pozX = o.pozX;
		this->pozY = _pozY;
	}
};

int main() {
	return 0;
}