#include "Owca.h"
#include <iostream>

Owca::Owca() : Animal(4, 4) {
}

void Owca::print(std::ostream& out) {
    out << 'O';
}