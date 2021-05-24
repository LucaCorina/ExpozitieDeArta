#pragma once
#include "Expozitie.h"
using namespace std;

class Invitat: public Expozitie{
private:
    string prenume;
    string nume;
public:;
    Invitat()=default;
    Invitat(int id, string& prenume, string& nume);
    Invitat(const Invitat& g);
    ~Invitat()=default;
    string getPrenume();
    string getNume();
    void set_prenume(string& prenume);
    void set_nume(string& nume);
    void set_id(int id);

    Invitat& operator=(const Invitat& sb);
    bool operator==(const Invitat& sb);
    friend istream& operator>>(istream& is, Invitat& sb);
    friend ostream& operator<<(ostream& os, Invitat& sb);


};


Invitat::Invitat(int id ,string& prenume, string& nume)
{
    this->id_expozitie=id;
    this->prenume=prenume;
    this->nume = nume;
}

Invitat::Invitat(const Invitat& g) : Expozitie(g)
{
    this->id_expozitie=g.id_expozitie;
    this->prenume=g.prenume;
    this->nume = g.nume;

}
string Invitat::getNume()
{
    return this->nume;
}
void Invitat::set_nume(string& nume) {
    this->nume = nume;
}
void Invitat::set_prenume(string& prenume)
{
    this->prenume = prenume;
}
string Invitat::getPrenume()
{
    return this->prenume;
}

Invitat& Invitat::operator=(const Invitat& g)
{
    Expozitie::operator=(g);
    this->nume = g.nume;
    this->prenume=g.prenume;
    return *this;
}

bool Invitat::operator==(const Invitat& g)
{
    return this->nume == g.nume && this->prenume == g.prenume ;
}

istream& operator>>(istream& is, Invitat& g)
{
    int id;
    string prenume;
    string nume;
    if (&is == &cin)
    {   cout<<"Dati id-ul";
        cout<<"Dati prenume";
        cout << "Dati numele: ";


    }
    is >>id>>prenume>>nume;
    g.set_nume(nume);
    g.set_prenume(prenume);
    return is;
}

ostream& operator<<(ostream& os, Invitat& g)
{
    os << g.id_expozitie<< " " << g.prenume << " "<<g.nume<<"\n";
    return os;
}

