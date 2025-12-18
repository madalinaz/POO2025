#include<iostream>
#include<fstream>
using namespace std;

//HOME1 - virtualizare citire fisier binar
//HOME2 - principii clean code

class Eveniment {
	int id;
	string denumire;
	char* coordonator;
	int nrEtape;
	float* bugetEtape;
	bool areMancare;

public:
	Eveniment() {
		this->id = 0;
		this->denumire = "-";
		this->coordonator = nullptr;
		this->nrEtape = 0;
		this->bugetEtape = nullptr;
		this->areMancare = false;
	}

	Eveniment(int _id, string _denumire, const char* _coordonator, int _nrEtape, float* _bugetEtape, bool _areMancare) {
		this->id = _id;
		this->denumire = _denumire;
		this->coordonator = new char[strlen(_coordonator) + 1];
		strcpy_s(this->coordonator, strlen(_coordonator) + 1, _coordonator);
		this->nrEtape = _nrEtape;
		this->bugetEtape = new float[this->nrEtape];
		for (int i = 0; i < this->nrEtape; i++)
			this->bugetEtape[i] = _bugetEtape[i];
		this->areMancare = _areMancare;
	}

	Eveniment(const Eveniment& e) {
		this->id = e.id;
		this->denumire = e.denumire;
		this->coordonator = new char[strlen(e.coordonator) + 1];
		strcpy_s(this->coordonator, strlen(e.coordonator) + 1, e.coordonator);
		this->nrEtape = e.nrEtape;
		this->bugetEtape = new float[this->nrEtape];
		for (int i = 0; i < this->nrEtape; i++)
			this->bugetEtape[i] = e.bugetEtape[i];
		this->areMancare = e.areMancare;
	}

	Eveniment& operator=(const Eveniment& e) {
		if (this != &e) {
			if (this->coordonator != nullptr) {
				delete[] this->coordonator;
				this->coordonator = nullptr;
			}
			if (this->bugetEtape != nullptr) {
				delete[] this->bugetEtape;
				this->bugetEtape = nullptr;
			}
			this->id = e.id;
			this->denumire = e.denumire;
			this->coordonator = new char[strlen(e.coordonator) + 1];
			strcpy_s(this->coordonator, strlen(e.coordonator) + 1, e.coordonator);
			this->nrEtape = e.nrEtape;
			this->bugetEtape = new float[this->nrEtape];
			for (int i = 0; i < this->nrEtape; i++)
				this->bugetEtape[i] = e.bugetEtape[i];
			this->areMancare = e.areMancare;
		}
		return *this;
	}

	~Eveniment() {
		if (this->coordonator != nullptr) {
			delete[] this->coordonator;
			this->coordonator = nullptr;
		}
		if (this->bugetEtape != nullptr) {
			delete[] this->bugetEtape;
			this->bugetEtape = nullptr;
		}
	}

	friend ostream& operator<<(ostream& out, const Eveniment& e) {
		out << "\nId: " << e.id;
		out << "\nDenumire: " << e.denumire;
		out << "\nCoordonator: " << e.coordonator;
		out << "\nNr etape: " << e.nrEtape;
		out << "\nBuget etape: ";
		for (int i = 0; i < e.nrEtape; i++)
			out << e.bugetEtape[i] << " ";
		out << "\nMancare?: " << e.areMancare;
		return out;
	}

	friend istream& operator>>(istream& in, Eveniment& e) {
		if (e.coordonator != nullptr) {
			delete[] e.coordonator;
			e.coordonator = nullptr;
		}
		if (e.bugetEtape != nullptr) {
			delete[] e.bugetEtape;
			e.bugetEtape = nullptr;
		}

		cout << "\nIntroduceti id: ";
		in >> e.id;
		cout << "Introduceti denumire: ";
		in >> e.denumire;
		string buffer;
		cout << "Introduceti coordonator: ";
		in >> buffer;
		e.coordonator = new char[buffer.length() + 1];
		strcpy_s(e.coordonator, buffer.length() + 1, buffer.data());
		cout << "Introduceti nr etape: ";
		in >> e.nrEtape;
		e.bugetEtape = new float[e.nrEtape];
		cout << "Introduceti buget etape: ";
		for (int i = 0; i < e.nrEtape; i++) {
			in >> e.bugetEtape[i];
		}
		cout << "Are mancare?: ";
		in >> e.areMancare;
		return in;
	}

	friend ifstream& operator>>(ifstream& in, Eveniment& e) {
		if (e.coordonator != nullptr) {
			delete[] e.coordonator;
			e.coordonator = nullptr;
		}
		if (e.bugetEtape != nullptr) {
			delete[] e.bugetEtape;
			e.bugetEtape = nullptr;
		}

		in >> e.id;
		in >> e.denumire;
		string buffer;
		in >> buffer;
		e.coordonator = new char[buffer.length() + 1];
		strcpy_s(e.coordonator, buffer.length() + 1, buffer.data());
		in >> e.nrEtape;
		e.bugetEtape = new float[e.nrEtape];
		for (int i = 0; i < e.nrEtape; i++) {
			in >> e.bugetEtape[i];
		}
		in >> e.areMancare;
		return in;
	}

	//serializare
	void writeToFile(fstream& f) {
		//scriere int (id)
		f.write((char*) & this->id, sizeof(int));

		//scriere string
		//1.scriere lg sir
		int lg = this->denumire.length()+1;
		f.write((char*) & lg, sizeof(int));
		//2.scriere sir efectiv
		f.write(this->denumire.data(), lg);

		//scriere char* (coordonator)
		//1.scriere lg sir
		lg = strlen(this->coordonator)+1;
		f.write((char*)&lg, sizeof(int));
		//2.scriere sir efectiv
		f.write(this->coordonator, lg);

		//scriere int (nr Etape)
		f.write((char*)&this->nrEtape, sizeof(int));

		//scriere vector dinamic de float
		for (int i = 0; i < this->nrEtape; i++) {
			f.write((char*)&this->bugetEtape[i], sizeof(float));
		}

		//scriere bool
		f.write((char*)&this->areMancare, sizeof(bool));
	}

	void readFromFile(fstream& f) {
		//citire int (id)
		f.read((char*)&this->id, sizeof(int));

		//citire string
		int lg;
		f.read((char*)&lg, sizeof(int));
		char buffer[100];
		f.read(buffer, lg);
		this->denumire = buffer;

		//citire char*
		f.read((char*)&lg, sizeof(int));
		this->coordonator = new char[lg];
		f.read(this->coordonator, lg);

		//citire nr etape (int)
		f.read((char*)&this->nrEtape, sizeof(int));

		this->bugetEtape = new float[this->nrEtape];
		for (int i = 0; i < this->nrEtape; i++) {
			f.read((char*)&this->bugetEtape[i], sizeof(float));
		}

		//citire bool
		f.read((char*)&this->areMancare, sizeof(bool));
	}
};

int main() {
	float bugetEtape[] = { 100,200,300.5 };
	Eveniment e1(12, "Eveniment", "Gigel", 3, bugetEtape, true);
	cout << e1;

	cout << "\n---------FISIERE TEXT--------";
	//ofstream g("eveniment.txt");
	//g << e1;//ofstream is a ostream
	//g.close();

	Eveniment e2;
	ifstream f("eveniment.txt");
	f >> e2;//ifstream is a istream
	cout << e2;
	f.close();

	cout << "\n---------FISIERE BINARE--------";
	//fstream fOut("colectie.bin", ios::out | ios::binary);
	//e1.writeToFile(fOut);
	//fOut.close();

	fstream fIn("colectie.bin", ios::in | ios::binary);
	Eveniment e3;
	e3.readFromFile(fIn);
	cout << e3;
	fIn.close();
	return 0;
}