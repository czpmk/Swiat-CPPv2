#include "Wilk.h"
#include <iostream>

Wilk::Wilk() : Animal(9, 5) {
}

void Wilk::print(std::ostream& out) {
    out << 'W';
}