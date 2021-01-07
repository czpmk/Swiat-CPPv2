#pragma once
#include "Animal.h"
#include <iostream>

class Lion : public Animal
{
protected:
    void print(std::ostream& out) override;
public:
    // losowe miejsce
    explicit Lion(World*);
};