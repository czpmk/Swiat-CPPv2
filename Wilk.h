#pragma once
#include "Animal.h"

class Wilk : public Animal
{
public:
    Wilk();
protected:
    void print(std::ostream& out) override;
};

