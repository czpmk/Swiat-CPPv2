#pragma once
#include "Animal.h"

class Koliber : public Animal
{
public:
    Koliber();
protected:
    void print(std::ostream& out) override;
    void action() override;
    void attack(Organism*) override;
};


