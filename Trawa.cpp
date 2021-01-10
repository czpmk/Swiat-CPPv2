#include "Trawa.h"
#include <iostream>

Trawa::Trawa() : Plant(0) {
}

void Trawa::print(std::ostream& out) {
    out << 'T';
}