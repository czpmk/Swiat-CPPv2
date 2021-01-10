#include "Lew.h"
#include <iostream>

Lew::Lew() : Animal(11, 7) {
}

void Lew::print(std::ostream& out) {
    out << 'L';
}

void Lew::victory(Organism* defender) {
    // Czy zolw przegral gdy atakowal
    if (defender == this) {
        // Czy napastnik jest slabszy niz 5
        if (defender->getStrength() < 5) {
            throw 1;
        }
        else {
            this->Animal::victory(defender);
        }
    }
    else {
        this->Animal::victory(defender);
    }
}