#pragma once
#include "Invitat.h"
#include <string.h>

class ServiceInvitat {
private:
    RepoSTLTemplate<Invitat> repo;
public:
    ServiceInvitat() = default;
    ServiceInvitat(RepoSTLTemplate<Invitat>& repo);
    ~ServiceInvitat();

    int indcheck(int i);
    void setRepo(RepoSTLTemplate<Invitat>& repo);

    vector<Invitat> getAll();
    RepoSTLTemplate<Invitat> returnrepo();
    void addEntitate(int i, string& prenume, string& nume);
    void updateEntitateById(int id, string& prenume, string& nume);
    void deleteEntitateById(int);
    vector<Invitat>  ListeazaInvitatiDupaId(string nume);
    vector<Invitat> ListeazaInvitatiDupaPren(string prenume);
};

RepoSTLTemplate<Invitat> ServiceInvitat::returnrepo()
{
    return repo;
}

ServiceInvitat::ServiceInvitat(RepoSTLTemplate<Invitat>& repo)
{
    this->repo = repo;
}

ServiceInvitat::~ServiceInvitat()
{
}

void ServiceInvitat::setRepo(RepoSTLTemplate<Invitat>& repo)
{
    this->repo = repo;
}

vector<Invitat> ServiceInvitat::getAll()
{
    return this->repo.getAll();
}

void ServiceInvitat::addEntitate(int i, string& prenume, string& nume)
{
    Invitat invitat(i,prenume,nume);
    this->repo.addElem(invitat);
}

void ServiceInvitat::updateEntitateById(int id, string& prenume, string& nume) {
    Invitat invitat(id,prenume,nume);
    this->repo.updateElem(invitat);
}

void ServiceInvitat::deleteEntitateById(int id){
    repo.deleteElem(id);
}

int ServiceInvitat::indcheck(int i) {
    return this->repo.checkIDexists(i);
}


vector<Invitat> ServiceInvitat::ListeazaInvitatiDupaId(string nume)
{
    vector<Invitat> invitati = this->repo.getAll();
    vector<Invitat> rezultat;

    for (int i = 0; i < invitati.size(); i++)
    {
        if (invitati[i].getNume()==nume)
        {
            rezultat.push_back(invitati[i]);
        }
    }
    return rezultat;
}

vector<Invitat> ServiceInvitat::ListeazaInvitatiDupaPren(string prenume)
{
    vector<Invitat> invitati = this->repo.getAll();
    vector<Invitat> rezultat;

    for (int i = 0; i < invitati.size(); i++)
    {
        if (invitati[i].getPrenume()==prenume)
        {
            rezultat.push_back(invitati[i]);
        }
    }
    return rezultat;
}