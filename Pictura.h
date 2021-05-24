#pragma once
#include "Expozitie.h"
using namespace std;

class Pictura: public Expozitie
        {
private:
    int pret;
    string nume;
    string pictor;
    string stil;
public:;
    Pictura()=default;
    Pictura(int id, string& nume, string& pictor, string& stil,int pret);
    Pictura(const Pictura& g);
    ~Pictura()=default;
    int getPret();
    string getNume();
    string getPictor();
    string getStil();
    void set_pret(int pret);
    void set_nume(string nume);
    void set_id(int id);
    void set_pictor(string pictor);
    void set_stil(string stil);

    Pictura& operator=(const Pictura& sb);
    bool operator==(const Pictura& sb);
    friend istream& operator>>(istream& is, Pictura& sb);
    friend ostream& operator<<(ostream& os, Pictura& sb);


};


Pictura::Pictura(int id, string& nume, string& pictor, string& stil,int pret)
{
    this->id_expozitie=id;
    this->nume = nume;
    this->pictor=pictor;
    this->stil=stil;
    this->pret=pret;

}

Pictura::Pictura(const Pictura& g) : Expozitie(g)
{
    this->id_expozitie=g.id_expozitie;
    this->nume = g.nume;
    this->pictor=g.pictor;
    this->stil=g.stil;
    this->pret=g.pret;;

}
string Pictura::getNume()
{
    return this->nume;
}
void Pictura::set_nume(string nume) {
    this->nume = nume;
}
void Pictura::set_pret(int pret)
{
    this->pret = pret;
}
int Pictura::getPret()
{
    return this->pret;
}
string Pictura::getPictor()
{
    return this->pictor;
}
void Pictura::set_pictor(string pictor) {
    this->pictor = pictor;}

string Pictura::getStil()
{
    return this->stil;
}
void Pictura::set_stil(string stil) {
    this->stil = stil;}

Pictura& Pictura::operator=(const Pictura& g)
{
    Expozitie::operator=(g);
    this->nume = g.nume;
    this->pictor=g.pictor;
    this->stil=g.stil;
    this->pret=g.pret;;
    return *this;
}

bool Pictura::operator==(const Pictura& g)
{
    return this->nume == g.nume && this->pictor == g.pictor
    && this->stil == g.stil && this->pret == g.pret;
}

istream& operator>>(istream& is, Pictura& g)
{
    int id;
    int pret;
    string pictor;
    string stil;
    string nume;
    if (&is == &cin)
    {   cout<<"Dati id-ul";
        cout <<"Dati numele: ";
        cout<<"Dati pictor";
        cout<<"Dati stil";
        cout<<"Dati pretul";
        }
    is >>id>>nume>>pictor>>stil>>pret;
    g.set_nume(nume);
    g.set_pictor(pictor);
    g.set_stil(stil);
    g.set_pret(pret);
    return is;
}

ostream& operator<<(ostream& os, Pictura& g)
{
    os << g.id_expozitie<< " " << " "<<g.nume<<" "<<g.pictor<<" "<<g.stil<<" "<<g.pret<<"\n";
    return os;
}