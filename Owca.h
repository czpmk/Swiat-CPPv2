#pragma once
#include "Animal.h"
class Owca : public Animal
{
public:
    Owca();
protected:
    void print(std::ostream& out) override;
};

