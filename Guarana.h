#pragma once
#include "Plant.h"
class Guarana : public Plant
{
public:
    Guarana();
protected:
    void defeat(Organism*) override;
    void print(std::ostream& out) override;
};

