#pragma once
#include "cassert"
#include"ServicePictura.h"
#include <cstring>

class TestService{
private:
    void testGetAll();
    void testAddPictura();
    void testUpdate_DeletePictura();
    void testfiltreazaPicturiDupaId();
public:
    TestService();
    ~TestService();
    void testAll();
};

void TestService::testGetAll()
{
    RepoSTLTemplate<Pictura>repoSTL;
    ServicePictura service(repoSTL);
    service.setRepo(repoSTL);
//    int id, string& nume, string& pictor, string& stil,int pret);
    string nume="Ana",nume1="Sos",nume2="Marcel";
    string pictor="Dav",pictor1="Hm";
    string stil="v",stil1="m";


    Pictura g1(1,nume,pictor,stil,34);
    Pictura g2(2,nume1,pictor1,stil1,900);
    service.addEntitate(1,nume,pictor,stil,34);
    service.addEntitate(2,nume1,pictor1,stil1,900);
    vector<Pictura>picturi=service.getAll();
    assert(picturi.size()==2);
    assert(picturi[0]==g1);
    assert(picturi[1]==g2);

}

void TestService::testAddPictura() {
    RepoSTLTemplate<Pictura> repoSTL;
    ServicePictura service(repoSTL);
    string nume="Ana",nume1="Sos",nume2="Marcel";
    string pictor="Dav",pictor1="Hm";
    string stil="v",stil1="m";
    Pictura g(1,nume,pictor,stil,34);
    service.addEntitate(1,nume,pictor,stil,34);
    assert(service.getAll()[0] == g);
}

void TestService::testUpdate_DeletePictura() {
    RepoSTLTemplate<Pictura> repoSTL;
    ServicePictura service(repoSTL);

    string nume="Ana",nume1="Sos",nume2="Marcel";
    string pictor="Dav",pictor1="Hm";
    string stil="v",stil1="m";
    Pictura g1(1,nume,pictor,stil,34);
    Pictura g2(2,nume1,pictor1,stil1,900);

    service.addEntitate(1,nume,pictor,stil,34);
    service.addEntitate(2,nume1,pictor1,stil1,900);

    service.updateEntitateById(1, nume, pictor, stil,g2.getPret());
    assert(service.getAll()[0] == Pictura(1, nume, pictor, stil,g2.getPret()));
    service.updateEntitateById(2, nume1 , pictor1,stil1,g2.getPret());
    assert(service.getAll()[1] == Pictura(2, nume1 , pictor1,stil1,g2.getPret()));

    service.addEntitate(3,nume,pictor1,stil1,998);
    service.addEntitate(4,nume,pictor,stil,777);
    assert(service.returnrepo().getSize() == 4);
    service.deleteEntitateById(4);
    assert(service.returnrepo().getSize() == 3);

}
void TestService::testfiltreazaPicturiDupaId(){
    RepoSTLTemplate<Pictura> repoSTL;
    ServicePictura service(repoSTL);

    string nume="Ana",nume1="Sos";
    string pictor="Dav",pictor1="Hm";
    string stil="v",stil1="m";
    Pictura g1(1,nume,pictor,stil,34);
    Pictura g2(2,nume1,pictor1,stil1,900);

    service.addEntitate(1,nume,pictor,stil,34);
    service.addEntitate(2,nume1,pictor1,stil1,900);

    assert(service.filtreazaPicturiDupaId()[0]== g2);
}

TestService::TestService() {

}

TestService::~TestService()
{
}


void TestService::testAll() {
    this->testGetAll();
    this->testUpdate_DeletePictura();
    this->testAddPictura();
    this->testfiltreazaPicturiDupaId();
}