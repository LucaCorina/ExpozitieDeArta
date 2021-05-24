#pragma once
#include "Exceptie.h"

using namespace std;

class Expozitie {
protected:
    int id_expozitie;
public:
    Expozitie();
    explicit Expozitie(int);
    int get_id() const;
    virtual void String()const;
};

Expozitie::Expozitie() {
    this->id_expozitie = 0;
}

Expozitie::Expozitie(int id) {
    this->id_expozitie = id;
}

int Expozitie::get_id() const {
    return this->id_expozitie;
}

void Expozitie::String()const {
    printf("Entitatea cu id-ul %d", this->id_expozitie);

}
