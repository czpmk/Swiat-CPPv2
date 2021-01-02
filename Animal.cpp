#include "Lion.h"
#include <iostream>

Lion::Lion(World* swiat) : Animal(swiat, 10, 5) {
}

void Lion::print(std::ostream& out) {
    out << 'L';
}

