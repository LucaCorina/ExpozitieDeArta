#pragma once
#include "ServicePictura.h"
#include "ServiceInvitat.h"
#include "Exceptie.h"

class UI {
private:
    ServicePictura serviceP;
    ServiceInvitat serviceI;

    void displayMenu();
    void uiAddPictura();
    void uiUpdatePicturaById();
    void uiDeletePicturaById();
    void uiShowPicturi();
    int isnumber(const string &s);

    void uiAddinvitat();
    void uiUpdateInvitatById();
    void uiDeleteInvitatById();
    void uiShowInvitati();

   void  ListeazaPicturiPret();
   void showPicturipp(vector<Pictura>picturi);
   void showInvitatii(vector<Invitat>invitati);
   void  ListeazaInvitatiNume();
   void ListeazaInvitatiPrenume();
   void UIPrintInterval();
   void Afiseazainformatiistiluri();

public:
    UI();
    UI(ServicePictura& servicePictura,ServiceInvitat& serviceInvitat);
    ~UI();
    void runMenu();
};

using namespace std;

void UI::displayMenu()
{   cout<<"************CRUD---TABLOU**************"<<endl;
    cout << "1. Adauga tablou " << endl;
    cout << "2. Modifica tablou " << endl;
    cout<<  "3. Sterge tablou dupa id"<<endl;
    cout<<  "4. Filtrarea tablourilor (cele cu pretul mai mare de 100)"<<endl;
    cout<<  "4*. Afisarea tablourilor cu pretul intr un interval dat de la tastatura"<<endl;
    cout<<  "t. Afiseaza toate tablourile"<<endl;
    cout<<endl;
    cout<<"************CRUD---INVITAT**************"<<endl;
    cout << "5. Adauga invitat " << endl;
    cout << "6. Modifica invitat " << endl;
    cout<<  "7. Sterge invitat dupa id"<<endl;
    cout<<  "8. Cautare dupa prenume"<<endl;
    cout<<  "9. Cautare dupa nume"<<endl;
    cout<<  "i. Afiseaza toti invitatii"<<endl<<endl;
    cout<<  "inf.Informatii despre stiluri (:("<<endl;


    cout << "x. Iesire" << endl;
    cout<<"**************************************************************"<<endl;
}

void UI::uiAddPictura()
{   try{
    cout<<"\ngimme parametrii pt add\n";
    string i, pret;
    string nume,pictor,stil;
    cout<<"Dati id: "<<endl;
    cin>>i;
        if (!isnumber(i))throw Exceptie("ATENTIE!! Id ul trebuie sa fie int!");
        if (this->serviceP.indcheck(stoi(i))) throw Exceptie("ATENTIE!! Id ul pe care l-ai introdus exista deja!");
    cout<<"Dati numele tabloului "<<endl;
    cin>>nume;
    if (isnumber(nume) == 1)throw Exceptie("ATENTIE!! Numele trebuie sa fie string!");
    cout<<"Dati numele pictorului "<<endl;
    cin>>pictor;
    if (isnumber(pictor) == 1)throw Exceptie("ATENTIE!! Pictorul trebuie sa fie string!");
    cout<<"Dati stilul tabloului (baroc/cubism/expresionism)"<<endl;
    cin>>stil;
    if (isnumber(stil) == 1)throw Exceptie("ATENTIE!! Stilul trebuie sa fie string!");
    if (stil!="baroc"&&stil!="cubism"&&stil!="expresionism")throw Exceptie("ATENTIE!! Stilul trebuie sa fie unul dintre: baroc/cubism/expresionism!");
    cout<<"Dati pretul tabloului "<<endl;
    cin>>pret;
    if (!isnumber(pret))throw Exceptie("ATENTIE!! Pretul trebuie sa fie int!");
    this->serviceP.addEntitate(stoi(i),nume,pictor,stil,stoi(pret));}
    catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}
}

void UI::uiUpdatePicturaById() {
    try{
        cout << "\nDati id pt update++\n";
        string  pret;
        string id;
        string nume, pictor, stil;
        cout << "Dati id: " << endl;
        cin >> id;
        if (!isnumber(id))throw Exceptie("ATENTIE!! Id ul trebuie sa fie int!");
        if (!this->serviceP.indcheck(stoi(id))) throw Exceptie("ATENTIE!! Id ul pe care l-ai introdus nu exista!");
        cout << "Dati numele tabloului (nou) " << endl;
        cin >> nume;
        if (isnumber(nume) == 1)throw Exceptie("ATENTIE!! Numele trebuie sa fie string!");
        cout << "Dati numele pictorului (nou)" << endl;
        cin >> pictor;
        if (isnumber(nume) == 1)throw Exceptie("ATENTIE!! Prenumele trebuie sa fie string!");
        cout << "Dati stilul tabloului (nou)" << endl;
        cin >> stil;
        if (isnumber(nume) == 1)throw Exceptie("ATENTIE!! Stilul trebuie sa fie string!");
        if (stil!="baroc"&&stil!="cubism"&&stil!="expresionism")throw Exceptie("ATENTIE!! Stilul trebuie sa fie unul dintre: baroc/cubism/expresionism!");
        cout << "Dati pretul tabloului (nou)" << endl;
        cin >> pret;
        if (!isnumber(pret))throw Exceptie("ATENTIE!! Pretul trebuie sa fie int!");

        this->serviceP.updateEntitateById(stoi(id), nume, pictor, stil, stoi(pret));}
        catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}

}
int UI:: isnumber(const string &s){
    for(char c:s)
    {if(!isdigit(c)){return 0;}}
    return 1;
}

void UI::uiDeletePicturaById(){
    try{
    string id;
    cout<<"Dati id care se sterge";
    cin>>id;
        if (!isnumber(id))throw Exceptie("ATENTIE!! Id ul trebuie sa fie int!");
        if (!this->serviceP.indcheck(stoi(id))) throw Exceptie("ATENTIE!! Id ul pe care l-ai introdus nu exista!");
        this->serviceP.deleteEntitateById(stoi(id));}
    catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}

};

void UI::uiShowPicturi()
{
    vector<Pictura> picturi = this->serviceP.getAll();
    for (int i = 0; i < picturi.size(); i++)
    {
        cout << picturi[i];
    }
}
UI::UI()
{
}

UI::UI(ServicePictura& servicePictura,ServiceInvitat& serviceInvitat)
{
    this->serviceP = servicePictura;
    this->serviceI=serviceInvitat;
}
UI::~UI()
{
}
void UI::uiAddinvitat()
{   try{
    cout<<"\ngimme parametrii pt add\n";
    string i;
    string nume,prenume;
    cout<<"Dati id: "<<endl;
    cin>>i;
        if (!isnumber(i))throw Exceptie("ATENTIE!! Id ul trebuie sa fie int!");
        if (this->serviceI.indcheck(stoi(i))) throw Exceptie("ATENTIE!! Id ul pe care l-ai introdus exista deja!");
    cout<<"Dati numele invitatului "<<endl;
    cin>>nume;
    if (isnumber(nume) == 1)throw Exceptie("ATENTIE!! Numele trebuie sa fie string!");
    cout<<"Dati prenumele invitatului "<<endl;
    cin>>prenume;
    if (isnumber(nume) == 1)throw Exceptie("ATENTIE!! Prenumele trebuie sa fie string!");
    this->serviceI.addEntitate(stoi(i),nume,prenume);}
    catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}
}

void UI::uiUpdateInvitatById()
{   try{
    cout<<"\nDati id pt update++\n";
    string id;
    string nume,prenume;
    cout<<"Dati id: "<<endl;
    cin>>id;
        if (!isnumber(id))throw Exceptie("ATENTIE!! Id ul trebuie sa fie int!");
        if (!this->serviceI.indcheck(stoi(id))) throw Exceptie("ATENTIE!! Id ul pe care l-ai introdus nu exista!");
        cout<<"Dati numele invitatului (nou) "<<endl;
    cin>>nume;
    if (isnumber(nume) == 1)throw Exceptie("ATENTIE!! Numele trebuie sa fie string!");
    cout<<"Dati prenumele invitatului (nou)"<<endl;
    cin>>prenume;
    if (isnumber(nume) == 1)throw Exceptie("ATENTIE!! Prenumele trebuie sa fie string!");
    this->serviceI.updateEntitateById(stoi(id),nume,prenume);}
    catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}
}


void UI::uiDeleteInvitatById(){
    try{
        string id;
    cout<<"Dati id care se sterge";
    cin>>id;
        if (!isnumber(id))throw Exceptie("ATENTIE!! Id ul trebuie sa fie int!");
        if (!this->serviceI.indcheck(stoi(id))) throw Exceptie("ATENTIE!! Id ul pe care l-ai introdus nu exista!");
        this->serviceI.deleteEntitateById(stoi(id));}
    catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}

};


void UI::uiShowInvitati() {
    vector<Invitat> inv = this->serviceI.getAll();
    for (int i = 0; i < inv.size(); i++) {
        cout << inv[i];
    }
}
void UI::ListeazaPicturiPret() {
    try{
    vector<Pictura> p = this->serviceP.filtreazaPicturiDupaId();
    this->showPicturipp(p);}
    catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}
}

void UI::showPicturipp(vector<Pictura>picturi){
    for (int i = 0; i < picturi.size(); i++)
    {
        cout << picturi[i] << endl;
    }
}

void UI::showInvitatii(vector<Invitat>invitati){
    for (int i = 0; i < invitati.size(); i++)
    {
        cout << invitati[i] << endl;
    }
}

void UI::ListeazaInvitatiNume(){
    try{
    string nume;
    cout<<"Dati numele";
    cin>>nume;
    if (isnumber(nume) == 1)throw Exceptie("ATENTIE!! Numele trebuie sa fie string!");
    vector<Invitat>inv=this->serviceI.ListeazaInvitatiDupaId(nume);
    this->showInvitatii(inv);}
    catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}

}

void UI::ListeazaInvitatiPrenume(){
    try{
    string prenume;
    cout<<"Dati prenumele";
    cin>>prenume;
    if (isnumber(prenume) == 1)throw Exceptie("ATENTIE!! Prenumele trebuie sa fie string!");
    vector<Invitat>inv=this->serviceI.ListeazaInvitatiDupaPren(prenume);
    this->showInvitatii(inv);}
    catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}

}


void UI::UIPrintInterval() {
    try{
    string stanga,dreapta;
    cout<<"Dati marginea stanga: ";
    cin>>stanga;
    if (!isnumber(stanga))throw Exceptie("ATENTIE!! Marginea din stanga trebuie sa fie int!");
    cout<<"Dati marginea dreapta: ";
    cin>>dreapta;
    if (!isnumber(dreapta))throw Exceptie("ATENTIE!! Marginea din dreapta trebuie sa fie int!");
    this->showPicturipp(this->serviceP.AfisarePicturiInterval(stoi(stanga),stoi(dreapta)));}
    catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}

}

void UI::Afiseazainformatiistiluri(){
    try {
        string s;
        cout << "Dati stilul despre care vreti sa va interesati (baroc,cubism,expresionism) ";
        cout << endl;
        cin >> s;
        if (s!="baroc"&&s!="cubism"&&s!="expresionism")throw Exceptie("ATENTIE!! Stilul trebuie sa fie unul dintre: baroc/cubism/expresionism!");
        if (s == "baroc")
        cout << "Barocul este un stil si o epoca de arta caracterizata de aristocratie, contrast,"
                    " imagini dinamice, detalii simple în imaginea abundenței, tensiunii, dramei, luxului,"
                    " fuziunii realitatii si iluziei. Acest stil a apărut în Italia în 1600 si sa raspandit in"
                    " intreaga Europa. Caravaggio si Rubens sunt cei mai proeminenti reprezentanti ai sai. Barocul"
                    " este adesea comparat cu expresionismul, insa, spre deosebire de acesta, nu are efecte prea repulsive. "
                    "Picturile acestui stil astazi sunt caracterizate de complexitatea liniilor si abundenta ornamentelor."
                 << endl;
        else if (s == "cubism")
            cout << "Cubismul este o miscare de arta avangardista care a aparut in secolul al XX-lea. Creatorul sau"
                    " este Pablo Picasso. Cubismul a facut o adevarata revolutie în sculptura si pictura din Europa,"
                    " inspirand crearea de tendinte similare în arhitectura, literatura și muzica. Pictura in arta în"
                    " acest stil este caracterizată prin obiecte recombinate, rupte care au o forma abstracta. Imaginea "
                    "lor foloseste multe puncte de vedere." << endl;
        else if (s == "expresionism")
            cout
                    << "Expresionismul este o altă zona importanta a artei moderne, care a aparut în Germania în prima jumatate "
                       "a secolului al XX-lea."
                       " La început a acoperit doar poezia ai pictura și apoi sa răspândit in alte zone ale artei."
                       "Expresionistii nu sunt deloc interesati de "
                       "realitatea materiala, picturile lor sunt pline de semnificatii profunde si de experiente emotionale."
                    << endl;
    }
    catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}

}

void UI::runMenu()
{

    char cmd[20];
    while (true) {
        this->displayMenu();
        cin >> cmd;
        if (strcmp(cmd, "1") == 0)
        {
            this->uiAddPictura();
        }
        else if (strcmp(cmd, "2") == 0)
        {
            this->uiUpdatePicturaById();
        }
        else if (strcmp(cmd,"3")==0)
        {
            this->uiDeletePicturaById();
        }
        else if (strcmp(cmd,"4")==0)
        {
            this->ListeazaPicturiPret();
        }
        else if (strcmp(cmd,"4*")==0)
        {
            this->UIPrintInterval();
        }
        else if (strcmp(cmd, "t")==0)
        {
            this->uiShowPicturi();
        }
        else if (strcmp(cmd, "5")==0)
        {
            this->uiAddinvitat();
        }
        else if (strcmp(cmd, "6")==0)
        {
            this->uiUpdateInvitatById();
        }
        else if (strcmp(cmd, "7")==0)
        {
            this->uiDeleteInvitatById();
        }
        else if (strcmp(cmd, "8")==0)
        {
            this->ListeazaInvitatiNume();
        }
        else if (strcmp(cmd, "9")==0)
        {
            this->ListeazaInvitatiPrenume();
        }
        else if (strcmp(cmd, "i")==0)
        {
            this->uiShowInvitati();
        }
        else if (strcmp(cmd, "inf")==0)
        {
            this->Afiseazainformatiistiluri();
        }
        else if (strcmp(cmd, "x") == 0)
        {cout<<"(._.) ( l: ) ( .-. ) ( :l ) (._.)";
            return;
        }
        else {
            cout << "Optiune gresita, reincercati! ";
        }
    }
}