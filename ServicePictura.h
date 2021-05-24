#pragma once
#include "Pictura.h"

class ServicePictura {
private:
    RepoSTLTemplate<Pictura> repo;
public:
    ServicePictura() = default;
    ServicePictura(RepoSTLTemplate<Pictura>& repo);
    ~ServicePictura();

    int indcheck(int i);
    void setRepo(RepoSTLTemplate<Pictura>& repo);

    vector<Pictura> getAll();
    RepoSTLTemplate<Pictura> returnrepo();
    void addEntitate(int i, string& nume, string& pictor, string& stil,int pret);
    void updateEntitateById(int id,string& nume, string& pictor, string& stil,int pret);
    vector<Pictura> filtreazaPicturiDupaId();
    vector<Pictura> AfisarePicturiInterval(int stanga ,int dreapta);
    void deleteEntitateById(int);
};

RepoSTLTemplate<Pictura> ServicePictura::returnrepo()
{
    return repo;
}

ServicePictura::ServicePictura(RepoSTLTemplate<Pictura>& repo)
{
    this->repo = repo;
}

ServicePictura::~ServicePictura()
{
}

void ServicePictura::setRepo(RepoSTLTemplate<Pictura>& repo)
{
    this->repo = repo;
}

vector<Pictura> ServicePictura::getAll()
{
    return this->repo.getAll();
}

void ServicePictura::addEntitate(int i, string& nume, string& pictor, string& stil,int pret)
{
    Pictura pictura(i,nume,pictor,stil,pret);
    this->repo.addElem(pictura);
}

void ServicePictura::updateEntitateById(int id,string& nume, string& pictor, string& stil,int pret) {
    Pictura pictura(id,nume,pictor,stil,pret);
    this->repo.updateElem(pictura);
}

void ServicePictura::deleteEntitateById(int id){
    repo.deleteElem(id);
}

int ServicePictura::indcheck(int i) {
    return this->repo.checkIDexists(i);
}

vector<Pictura> ServicePictura::filtreazaPicturiDupaId()
{
    vector<Pictura> picturi = this->repo.getAll();
    vector<Pictura> rezultat;

    for (int i = 0; i < picturi.size(); i++)
    {
        if ( picturi[i].getPret()>100)
        {
            rezultat.push_back(picturi[i]);
        }
    }
    return rezultat;
}

vector<Pictura> ServicePictura::AfisarePicturiInterval(int stanga ,int dreapta)
{
    vector<Pictura> picturi = this->repo.getAll();
    vector<Pictura> rezultat;
    if (stanga>dreapta)swap(stanga,dreapta);
    for (int i = 0; i < picturi.size(); i++)
    {
        if (picturi[i].getPret()>=stanga && picturi[i].getPret()<=dreapta)
        {
            rezultat.push_back(picturi[i]);
        }
    }
    return rezultat;
}