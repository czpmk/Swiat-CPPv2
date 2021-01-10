#include "Mlecz.h"
#include <iostream>

Mlecz::Mlecz() : Plant(0) {
}

void Mlecz::action() {
    for (int i = 0; i < 3; i++) {
        if (this->_alive) {
            this->Plant::action();
        }
        else {
            break;
        }
    }
}

void Mlecz::print(std::ostream& out) {
    out << 'M';
}