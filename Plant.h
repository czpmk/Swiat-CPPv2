#pragma once
#include "Organism.h"
class Plant :  public Organism
{
protected:
	Plant(int strength);
		void action() override;
	void defeat(Organism*) override;
	void victory(Organism*) override;
};

