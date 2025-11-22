#include<iostream>
#include <exception>

using namespace std;

//to do
//relatie de compunere [1-m, 1-1, pointeri/obiecte, shallow/deep copy
//try-catch
//alti operatori


class Produs {
    string denumire = "Anonim";
    double pret = 0;

public:
    Produs() {}

    Produs(string _denumire, double _pret) {
        this->denumire = _denumire;
        this->pret = _pret;
    }

    Produs(const Produs& p) {
        this->denumire = p.denumire;
        this->pret = p.pret;
    }

    Produs& operator=(const Produs& p) {
        this->denumire = p.denumire;
        this->pret = p.pret;
        return *this;
    }

    void afisare() {
        cout << "\nDenumire: " << this->denumire << ", pret: " << this->pret;

    }
    friend ostream& operator<<(ostream& os, const Produs& p);
};

ostream& operator<<(ostream& os, const Produs& p) {
    os << "\nDenumire: " << p.denumire << ", pret: " << p.pret;
    return os;
}
class Wishlist2 {
    //vector static de Produs
    Produs lista[100];
    int nrProduse;
    double buget;
};

//de gestionat prin shallow copy, dar si prin deep copy pointerii la produse
//shallow copy, daca sterg din wishlist, mi se sterge tot obiectul (ex: copy)
class Wishlist3 {
    //vector dinamic de Produs*
    Produs** lista;
    int nrProduse;
    double buget;
};

class Wishlist4 {
    //vector static de Produs*
    Produs* lista[100];
    int nrProduse;
    double buget;
};

//relatie de 1-1
class Wishlist5 {
    Produs cadoulMeu;
    double buget;
};

class Wishlist6 {
    Produs* cadoulMeu; //pointer la un produs
    double buget;
};

class Wishlist7 {
    //pentru fiecare prieten, o lista de pointeri de cadouri
    int nrPrieteni;
    Produs*** lista;
    int* nrCadouri; //cadourile pentru fiecare prieten
    double buget;
};

class Wishlist8 {
    //pe principiul calendar advent (in fiecare zi 1-24 dec) imi ofer o lista de cadouri
    Produs* lista[24]; // pentru fiecare din cele 24 de zile, am un vector de produs
    int nrCadouri[24];
    double buget;
};

class Wishlist {
    //vector dinamic de Produs
    Produs* lista = nullptr;
    int nrProduse = 0;
    double buget = 0;
public:
    Wishlist() {}

    Wishlist(Produs* _lista, int _nrProduse, double _buget) {
        if (_nrProduse > 0 && _lista != nullptr) {
            this->nrProduse = _nrProduse;
            this->lista = new Produs[this->nrProduse]; // apel constructor fara param
            for (int i = 0; i < _nrProduse; ++i)
                this->lista[i] = _lista[i]; // operator = clasa Produse (deep copy)
        }
        this->buget = _buget;
    }

    Wishlist(const Wishlist& w) {
        if (w.lista != nullptr && w.nrProduse > 0) {
            this->nrProduse = w.nrProduse;
            this->lista = new Produs[this->nrProduse]; //apel constructor fara param din Produs
            for (int i = 0; i < this->nrProduse; i++) {
                this->lista[i] = w.lista[i]; //operator = clasa Produs
            }
        }
        this->buget = w.buget;
    }

    Wishlist& operator=(const Wishlist& w) {
        if (this != &w) {
            //destructor
            if (this->lista != nullptr) {
                delete[] this->lista;
                this->lista = nullptr;
            }
            //constructor de copiere
            if (w.lista != nullptr && w.nrProduse > 0) {
                this->nrProduse = w.nrProduse;
                this->lista = new Produs[this->nrProduse]; //apel constructor fara param din Produs
                for (int i = 0; i < this->nrProduse; i++) {
                    this->lista[i] = w.lista[i]; //operator = clasa Produs
                }
            }
            this->buget = w.buget;
        }

        return *this;
    }

    const Produs& operator[](int idx) {
        if (idx >= 0 && idx < this->nrProduse) {
            return this->lista[idx];
        }
        else {
            throw exception("Index-ul nu e valid");
        }
    }

    void afisare() {
        cout << "\n----------------------";
        cout << "\nnr produse: " << this->nrProduse;
        for (int i = 0; i < this->nrProduse; i++) {
            cout << this->lista[i];
        }
        cout << "\nBuget: " << this->buget;
        cout << "\n----------------------";
    }

    friend ostream& operator<<(ostream& os, const Wishlist& w);

    ~Wishlist() {
        delete[] this->lista;
        this->lista = nullptr;
    }
};

ostream& operator<<(ostream& os, const Wishlist& w) {
    os << "\n----------------------";
    os << "\nnr produse: " << w.nrProduse;
    for (int i = 0; i < w.nrProduse; i++) {
        os << w.lista[i];
    }
    os << "\nBuget: " << w.buget;
    os << "\n----------------------";
    return os;
}

int main() {
    Produs p1("Sosete", 15);
    Produs p2("Calculator", 5000);
    //cout << p1 << p2;
    //int x, y;
    //x = y = 2;

    Produs vProd[] = { p1,p2 };
    Wishlist w1(vProd, 2, 500);
    Wishlist w2 = w1;
    Wishlist w3;
    w3 = w1;
    cout << w1;
    //TO DO HOME: actualizarea try catch pentru a reintroduce indexul
    Produs p3;
    try {
        p3 = w2[15];
        cout << p3;
    }
    catch (exception err) {
        //TO DO : ce e nevoie in caz de index gresit
        cout << endl << err.what();
    }

    return 0;
}