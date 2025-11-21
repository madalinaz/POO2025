#include <iostream>

using namespace std;

enum TipObiect {
    AVION, NAVA, ROCA
};

class Obiect2D {
    TipObiect tip = TipObiect::AVION;
    int nivelViata = 100;
    int pozX = 0;
    int pozY = 0;

public:
    Obiect2D() {}

    Obiect2D(TipObiect _tip, int _pozX, int _pozY) {
        this->tip = _tip;
        this->nivelViata = 100;
        this->pozX = _pozX;
        this->pozY = _pozY;
    }

    void afisare() {
        cout << "Obiect " << this->tip << ", nivel viata: " << this->nivelViata << ", coordante ("
            << this->pozX << ", " << this->pozY << ")" << endl;
    }

};

//obiect vs referinta/pointer
//deep copy vs shallow copy

class Joc2 {
    string utilizator;
    int xMax;
    int yMax; //coordonatele maximale ale graficului/canvas-ului
    // o colectie de obiecte
    int nrObiecte;
    Obiect2D lista[100]; //vector static de Obiect2D

};

class Joc3 {
    string utilizator;
    int xMax;
    int yMax; //coordonatele maximale ale graficului/canvas-ului
    // o colectie de obiecte
    int nrObiecte;
    Obiect2D* lista[100]; //vector static de Obiect2D*

};

class Joc4 {
    string utilizator;
    int xMax;
    int yMax; //coordonatele maximale ale graficului/canvas-ului
    // o colectie de obiecte
    int nrObiecte;
    Obiect2D** lista; //vector dinamic de Obiect2D*(retin referintele)
};

//realtie de compunere de tipul 1-1
class Joc5 {
    string utilizator;
    int xMax;
    int yMax; //coordonatele maximale ale graficului/canvas-ului
    // o colectie de obiecte
    int nrObiecte;
    Obiect2D obiect; //un obiect de tipul Obiect2D
};

//realtie de compunere de tipul 1-1
class Joc6 {
    string utilizator;
    int xMax;
    int yMax; //coordonatele maximale ale graficului/canvas-ului
    // o colectie de obiecte
    int nrObiecte;
    Obiect2D* obiect; //un pointer la un obiect de tipul Obiect2D
};

// clasa Joc este in relatie de has a cu clasa Obiect 2D
class Joc {
    string utilizator = "";
    int xMax = 0;
    int yMax = 0; //coordonatele maximale ale graficului/canvas-ului
    // o colectie de obiecte
    int nrObiecte = 0;
    Obiect2D* lista = nullptr; //vector dinamic de Obiect2D

public:
    Joc() {}

    Joc(string _utilizator, int _xMax, int _yMax, int _nrObiecte, Obiect2D* _lista) {
        this->utilizator = _utilizator;
        this->xMax = _xMax;
        this->yMax = _yMax;

        if (_nrObiecte > 0 && _lista != nullptr) {
            this->nrObiecte = _nrObiecte;
            this->lista = new Obiect2D[this->nrObiecte];

            for (int i = 0; i < this->nrObiecte; i++)
                this->lista[i] = _lista[i];
        }
    }

    Joc(const Joc& j) {
        this->utilizator = j.utilizator;
        this->xMax = j.xMax;
        this->yMax = j.xMax;

        if (j.nrObiecte > 0 && j.lista != nullptr) {
            this->nrObiecte = j.nrObiecte;
            this->lista = new Obiect2D[this->nrObiecte];

            for (int i = 0; i < this->nrObiecte; i++)
                this->lista[i] = j.lista[i];
        }
    }

    Joc& operator=(const Joc& j) {
        if (this != &j) {
            if (this->lista != nullptr) {
                delete[] this->lista;
                this->lista = nullptr;
            }

            this->utilizator = j.utilizator;
            this->xMax = j.xMax;
            this->yMax = j.xMax;

            if (j.nrObiecte > 0 && j.lista != nullptr) {
                this->nrObiecte = j.nrObiecte;
                this->lista = new Obiect2D[this->nrObiecte];

                for (int i = 0; i < this->nrObiecte; i++)
                    this->lista[i] = j.lista[i];
            }
            else {
                this->nrObiecte = 0;
                this->lista = nullptr;
            }
        }

        return *this;
    }

    bool operator!() {
        return this->nrObiecte == 0;
    }

    Joc& operator*=(double _coeficient) {
        if (_coeficient > 0) {
            this->xMax *= _coeficient;
            this->yMax *= _coeficient;
        }

        return *this;
    }

    void afisare() {
        cout << "Utilizator: " << this->utilizator << endl;
        cout << "XMax: " << this->xMax << endl;
        cout << "YMax: " << this->yMax << endl;
        cout << "Nr obiecte: " << this->nrObiecte << endl;
        cout << "Lista: " << endl;
        for (int i = 0; i < this->nrObiecte; i++)
            this->lista[i].afisare();
        cout << endl;
    }

    ~Joc() {
        if (this->lista != nullptr) {
            delete[] this->lista;
            this->lista = nullptr;
        }
    }
};

int main() {
    Obiect2D ob1(TipObiect::NAVA, 10, 20);
    Obiect2D ob2(TipObiect::AVION, 30, 20);
    Obiect2D ob3(TipObiect::AVION, 30, 20);
    // ob1 = ob2;
    // ob1.afisare();
    Obiect2D v[]{ ob1, ob2, ob3 };
    Joc j("utilizator", 100, 100, 3, v);
    j.afisare();
    Joc j2 = j;
    j2.afisare();
    Joc j3;
    j3 = j;
    j3.afisare();

    if (!j3)
        cout << "j3 nu are obiecte" << endl;
    else
        cout << "invers";

    // j = j3 *= 1.1;
    j3 *= 1.1;
    j3.afisare();

    return 0;
}