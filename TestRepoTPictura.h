#pragma once
#include "RepoT.h"
#include "Invitat.h"
#include "Pictura.h"

void TestRepo1(RepoSTLTemplate<Pictura>& repotest1){
    string nume="yy",nume1="dap";
    string pictor="oo",pictor1="aa";
    string stil="abs",stil1="modern";
    Pictura e2(2,nume1,pictor1,stil,345);
    Pictura e1(1,nume,pictor,stil,534);
    Pictura e3(3,nume,pictor1,stil1,345);
    Pictura e4(4,nume1,pictor,stil1,567);


    repotest1.addElem(e1);
    repotest1.addElem(e2);
    repotest1.addElem(e3);
    repotest1.addElem(e4);
    assert(repotest1.getAll()[0]==e1);
    assert(repotest1.getAll()[1]==e2);
    assert(repotest1.getAll()[2]==e3);
    assert(repotest1.getAll()[3]==e4);


    repotest1.deleteElem(2);
    repotest1.addElem(e3);
    assert(repotest1.getAll()[3]==e3);
}