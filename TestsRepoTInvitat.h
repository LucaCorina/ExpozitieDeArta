#pragma once
#include "RepoT.h"
#include "Invitat.h"
#include "Pictura.h"
#include <cassert>
using namespace std;
void TestRepo(RepoSTLTemplate<Invitat>& repotest){
    string nume="yy",nume1="dap";
    string prenume="oo",prenume1="aa";
    Invitat e1(1,prenume,nume);
    Invitat e2(2,prenume1,nume1);
    Invitat e3(3,prenume,nume);
    Invitat e4(4,prenume1,nume1);


    repotest.addElem(e1);
    repotest.addElem(e2);
    repotest.addElem(e3);
    repotest.addElem(e4);
    assert(repotest.getAll()[0]==e1);
    assert(repotest.getAll()[1]==e2);
    assert(repotest.getAll()[2]==e3);
    assert(repotest.getAll()[3]==e4);


    repotest.deleteElem(2);
    repotest.addElem(e3);
    assert(repotest.getAll()[3]==e3);

    //int id, string& nume, string& pictor, string& stil,int pret



}