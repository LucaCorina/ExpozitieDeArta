#pragma once
#include "cassert"
#include"ServiceInvitat.h"
#include <cstring>

class TestService1{
private:
    void testGetAll();
    void testAddInvitat();
    void testUpdate_DeleteInvitat();
    void TestListeazaInvitatiDupaId(string nume);
    void TestListeazaInvitatiDupaId1(string prenume);
public:
    TestService1();
    ~TestService1();
    void testAll11();
};

void TestService1::testGetAll()
{
    RepoSTLTemplate<Invitat>repoSTL;
    ServiceInvitat service(repoSTL);
    service.setRepo(repoSTL);
    string nume="Ana",nume1="Sos";
    string prenume="Dav",prenume1="Hm";

    Invitat g1(1,nume,prenume);
    Invitat g2(2,nume1,prenume1);
    service.addEntitate(1,nume,prenume);
    service.addEntitate(2,nume1,prenume1);
    vector<Invitat>invitati=service.getAll();
    assert(invitati.size()==2);
    assert(invitati[0]==g1);
    assert(invitati[1]==g2);

}

void TestService1::testAddInvitat() {
    RepoSTLTemplate<Invitat> repoSTL;
    ServiceInvitat service(repoSTL);
    string nume="Ana",nume1="Sos",nume2="Marcel";
    string prenume="Dav",prenume1="Hm";;
    Invitat g(1,nume,prenume1);
    service.addEntitate(1,nume,prenume1);
    assert(service.getAll()[0] == g);
}

void TestService1::testUpdate_DeleteInvitat() {
    RepoSTLTemplate<Invitat> repoSTL;
    ServiceInvitat service(repoSTL);

    string nume="Ana",nume1="Sos",nume2="Marcel";
    string prenume="Dav",prenume1="Hm";
    Invitat g1(1,nume,prenume);
    Invitat g2(2,nume1,prenume1);

    service.addEntitate(1,nume,prenume);
    service.addEntitate(2,nume1,prenume1);

    service.updateEntitateById(1, nume, prenume);
    assert(service.getAll()[0] == Invitat(1, nume, prenume));
    service.updateEntitateById(2, nume1 , prenume1);
    assert(service.getAll()[1] == Invitat(2, nume1 , prenume1));

    service.addEntitate(3,nume,prenume1);
    service.addEntitate(4,nume,prenume);
    assert(service.returnrepo().getSize() == 4);
    service.deleteEntitateById(4);
    assert(service.returnrepo().getSize() == 3);

}

void TestService1::TestListeazaInvitatiDupaId(string nume){
    RepoSTLTemplate<Invitat> repoSTL;
    ServiceInvitat service(repoSTL);
     nume="Casey";

     string prenume="Matatica";
     string penume1="HAh",penume2="Hh";
    Invitat g1(1,nume,prenume);
    Invitat g2(2,nume,penume1);
    Invitat g3(3,nume,penume2);

    service.addEntitate(1,nume,prenume);
    service.addEntitate(2,nume,penume1);
    service.addEntitate(3,nume,penume2);

    assert(service.returnrepo().getSize() == 3);
}

void TestService1::TestListeazaInvitatiDupaId1(string prenume){
    RepoSTLTemplate<Invitat> repoSTL;
    ServiceInvitat service(repoSTL);
    prenume="Casey";

    string nume="Matatica";
    string nume1="HAh",nume2="Hh";
    Invitat g1(1,nume,prenume);
    Invitat g2(2,nume1,prenume);
    Invitat g3(3,nume2,prenume);

    service.addEntitate(1,nume,prenume);
    service.addEntitate(2,nume,prenume);
    service.addEntitate(3,nume,prenume);

    assert(service.returnrepo().getSize() == 3);
}

TestService1::TestService1() {

}

TestService1::~TestService1()
{
}


void TestService1::testAll11() {
    this->testGetAll();
    this->testUpdate_DeleteInvitat();
    this->testAddInvitat();
    this->TestListeazaInvitatiDupaId("Casey");
    this->TestListeazaInvitatiDupaId1("Casey");
}