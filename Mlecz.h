#pragma once
#include "Plant.h"
class Mlecz : public Plant
{
public:
    Mlecz();
protected:
    void action() override;
    void print(std::ostream& out) override;
};

