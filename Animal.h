#pragma once
#include "Organism.h"

class Animal : public Organism
{
protected:
	Animal(World* world, int strength, int initiative);
public:
	void action() override;
	void attack(Organism*) override;
};


