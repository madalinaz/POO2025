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

    friend ostream& operator<<(ostream& out, const Obiect2D& o);

};

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

    ~Joc() {
        if (this->lista != nullptr) {
            delete[] this->lista;
            this->lista = nullptr;
        }
    }
};

ostream& operator<<(ostream& out, const Obiect2D& o) {
    out << "Obiect " << o.tip << ", nivel viata: " << o.nivelViata << ", coordante ("
        << o.pozX << ", " << o.pozY << ")" << endl;
    return out;
}

int main() {
    Obiect2D obj1(TipObiect::AVION, 10, 10);
    Obiect2D obj2(TipObiect::AVION, 25, 30);
    Obiect2D obj3(TipObiect::ROCA, 20, 25);
    cout << obj1;

    return 0;
}