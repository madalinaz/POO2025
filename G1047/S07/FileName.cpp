#include <iostream>
#include <string>

using namespace std;

//tema 1 (const + static)
//de modelat clasa Masina(VIN, nr_de_inmatriculare + extra)
//VIN -> constant si unic
//nr de inmatriculare -> unic dar NU este constant
//cumparare masina (ori VIN este primit sau generat)
//vanzare masina(cand se schimba sau nu nr de inmatriculare)
//posibilitatatea de nr preferntial sau generat automat
//modelati nr de inmatricular asa cum puteti

class Echipa {
    const int id; //generat automat, unic

    int nrMembri = 0;
    string* membri = nullptr;
    double buget = 0;
    static int generatorID;

public:
    Echipa() : id(Echipa::generatorID++) {}

    Echipa(int _nrMembri, string* _membri, double _buget) : Echipa() {
        if (_nrMembri > 0 && _membri != nullptr) {
            this->nrMembri = _nrMembri;
            this->membri = new string[this->nrMembri];

            for (int i = 0; i < _nrMembri; i++)
                this->membri[i] = _membri[i];
        }

        if (_buget > 0)
            this->buget = _buget;
    }

    //motiv transfer prin referinta
    //1. ocolire copiere(eficienta)
    //2. sa facem modificari
    Echipa(const Echipa& other) : Echipa() {
        if (other.nrMembri > 0 && other.membri != nullptr) {
            this->nrMembri = other.nrMembri;
            this->membri = new string[this->nrMembri];

            for (int i = 0; i < other.nrMembri; i++)
                this->membri[i] = other.membri[i];
        }

        if (other.buget > 0)
            this->buget = other.buget;
    }

    Echipa& operator=(const Echipa& other) {
        if (this != &other) {
            if (this->membri != nullptr) {
                delete[] this->membri;
                this->membri = nullptr;
                this->nrMembri = 0;
            }
            if (other.nrMembri > 0 && other.membri != nullptr) {
                this->nrMembri = other.nrMembri;
                this->membri = new string[this->nrMembri];
                for (int i = 0; i < other.nrMembri; i++)
                    this->membri[i] = other.membri[i];
            }
            else {
                this->nrMembri = 0;
                this->membri = nullptr;
            }
            if (other.buget > 0)
                this->buget = other.buget;
        }
        return *this;
    }

    bool operator!=(const string& _x) const {
        for (int i = 0; i < this->nrMembri; i++)
            if (this->membri[i] == _x)
                return true;

        return false;
    }


    void afisare() {
        cout << "Id: " << this->id << endl;
        cout << "Nr membri: " << this->nrMembri << endl;
        cout << "Membri: ";
        for (int i = 0; i < this->nrMembri; i++)
            cout << this->membri[i] << ' ';

        cout << endl;
        cout << "Buget: " << this->buget << endl;
        cout << endl;
    }

    ~Echipa() {
        if (this->membri != nullptr) {
            delete[] this->membri;
            this->membri = nullptr;
        }
    }
};

int Echipa::generatorID = 1000;

int main() {
    string v[] = { "Stefan", "Alex", "Maria" };
    Echipa e;
    e.afisare();

    Echipa e1(3, v, 949.3);
    e1.afisare();

    Echipa e2(e1);
    e2.afisare();


    Echipa e3;
    e3.afisare();
    e2 = e1;
    e2.afisare();

    if (e2 != "Stefan")
        cout << "\ne2 il contine pe Stefan";
    else
        cout << "invers";

    return 0;
}
