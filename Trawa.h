#pragma once
#include "Plant.h"
class Trawa :
    public Plant
{
public:
    Trawa();
protected:
    void print(std::ostream& out) override;
};

