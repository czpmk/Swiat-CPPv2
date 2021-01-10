#include "Zolw.h"
#include <iostream>

Zolw::Zolw() : Animal(2, 1) {
}

void Zolw::print(std::ostream& out) {
    out << 'Z';
}

void Zolw::action() {
    int n = rand() % 4;
    if (n == 3) {
        this->Animal::action();
    }
}

void Zolw::defeat(Organism* aggressor) {
    // Czy zolw byl napastnikiem
    if (aggressor != this) {
        // Czy napastnik jest slabszy niz 5
        if (aggressor->getStrength() < 5) {
            throw 1;
        }
        else {
            this->Animal::defeat(aggressor);
        }
    }
    else {
        this->Animal::defeat(aggressor);
    }
}