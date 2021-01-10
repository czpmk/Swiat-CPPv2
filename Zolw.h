#pragma once
#include "Animal.h"

class Zolw : public Animal
{
public:
    Zolw();
protected:
    void print(std::ostream& out) override;
    void action() override;
    void defeat(Organism*) override;
};

