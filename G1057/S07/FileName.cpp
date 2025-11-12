#include <iostream>

using namespace std;

//Sa se implementeze clasa masina care detine numar inmatriculare si are un constructor
//care primeste un numar preferential
//constant este serie_sasiu, are si campul numar inmatriculare

class Abonat {
    const int id; // se genereaza, nu se primeste ca param
    string detinator = "Anonim";
    int nrContacte = 0;
    string* contacte = nullptr;
    static int generatorID; // folosit pentru a genera automat id, primul id este 101
public:
    //home: sa se implementeze o metoda de generare de id-uri dupa o regula
    //ex1: id este numar prim  > 100
    //ex2 : id-ul este dintr-o lista predefinita
    Abonat() :id(++Abonat::generatorID) {}
    Abonat(const string& _detinator, int _nrContacte, string* _contacte)
        :detinator(_detinator), id(++Abonat::generatorID) { // :: -> operator rezolutie
        if (_nrContacte > 0) {
            this->nrContacte = _nrContacte;
            this->contacte = new string[this->nrContacte];
            for (int i = 0; i < this->nrContacte; ++i) {
                this->contacte[i] = _contacte[i];
            }
        }
    }
    Abonat(const Abonat& ab) :id(++Abonat::generatorID), detinator(ab.detinator) { // : -> lista de initializare
        if (ab.nrContacte > 0 && ab.contacte != nullptr) {
            this->nrContacte = ab.nrContacte;
            this->contacte = new string[this->nrContacte];
            for (int i = 0; i < this->nrContacte; ++i) {
                this->contacte[i] = ab.contacte[i];
            }
        }
    }

    Abonat& operator=(const Abonat& ab) {
        if (this != &ab) {
            delete[] this->contacte;
            this->contacte = nullptr;
            if (ab.nrContacte > 0 && ab.contacte != nullptr) {
                this->nrContacte = ab.nrContacte;
                this->contacte = new string[this->nrContacte];
                for (int i = 0; i < this->nrContacte; ++i) {
                    this->contacte[i] = ab.contacte[i];
                }
            }
            else {
                this->nrContacte = 0;
                this->contacte = nullptr;
            }
            return *this;
        }
    }

    bool operator==(const string& numeCautat) const {
        for (int i = 0; i < this->nrContacte; ++i) {
            if (numeCautat == this->contacte[i])
                return true;
        }
        return false;
    }

    void afisare() const {
        cout << "\n=====================\n";
        cout << "ID: " << this->id << endl;
        cout << "Detinator: " << this->detinator << endl;
        cout << "Nr Contacte: " << this->nrContacte << endl;
        cout << "Numele contactelor: " << endl;
        for (int i = 0; i < nrContacte; ++i) {
            cout << contacte[i] << " ; ";
        }
        cout << "\n=====================\n";
    }

    ~Abonat() {
        delete[] this->contacte;
        this->contacte = nullptr;
    }

};
int Abonat::generatorID = 100;

int main() {

    Abonat ab1;
    ab1.afisare();
    string agenda[] = { "Firicel Ion", "Pastorescu Ion", "Manescu Mirela" };
    Abonat a2("Popa Catalin", 3, agenda);
    a2.afisare();
    Abonat* pab3;
    pab3 = new Abonat;
    delete pab3; // apel destructor
    Abonat a3 = a2;
    a3.afisare();
    a3 = a2;
    a3.afisare();
    if (a3 == "Manescu Mirela") {
        cout << "Manescu Mirela este in lista de contacte pentru a3" << endl;
    }
    else {
        cout << "Manescu Mirela nu este in lista de contacte pentru a3" << endl;
    }
    return 0;
}