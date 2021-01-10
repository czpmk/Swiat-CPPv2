#include "Guarana.h"
#include <iostream>

Guarana::Guarana() : Plant(0) {
}

void Guarana::defeat(Organism* aggressor) {
    if (this != aggressor) {
        aggressor->setStrength(aggressor->getStrength() + 3);
    }
    this->Plant::defeat(aggressor);
}

void Guarana::print(std::ostream& out) {
    out << 'G';
}