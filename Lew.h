#pragma once
#include "Animal.h"


class Lew : public Animal
{
public:
    Lew();
protected:
    void print(std::ostream& out) override;
    void victory(Organism*) override;
};