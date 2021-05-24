#include <iostream>
#include"Expozitie.h"
#include"Exceptie.h"
#include"Pictura.h"
#include "Invitat.h"
#include "RepoT.h"
#include "ServicePictura.h"
#include "ServiceInvitat.h"
#include "TestsRepoTInvitat.h"
#include "TestRepoTPictura.h"
#include "TestsServicePictura.h"
#include "TestsServiceInvitat.h"
#include "UI.h"
int main() {
    RepoSTLTemplate<Invitat> repoTI;
    ServiceInvitat serviceI(repoTI);

    RepoSTLTemplate<Pictura> repoTP;
    ServicePictura serviceP(repoTP);

    TestService testService;
    testService.testAll();

    TestService1 testService1;
    testService1.testAll11();

    UI ui(serviceP,serviceI);
    ui.runMenu();

    return 0;
}
