#include "Koliber.h"
#include <iostream>

Koliber::Koliber() : Animal(1, 6) {
}

void Koliber::print(std::ostream& out) {
    out << 'K';
}

void Koliber::action() {
    this->Animal::action();
    if (this->_alive) {
        this->Animal::action();
    }
}

void Koliber::attack(Organism* defender) {
    if (!this->_placed) {
        _alive = false;
    }
    else {
        this->setLastLocation();
    }
}