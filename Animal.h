#pragma once
#include "Organism.h"

class Animal : public Organism
{
protected:
	Animal(int strength, int initiative);
	void action() override;
	void defeat(Organism*) override;
	void victory(Organism*) override;
};

