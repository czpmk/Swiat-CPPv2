#include "Plant.h"
#include "World.h"

Plant::Plant(int strength)
	: Organism(strength, 0) {}

void Plant::action() {}

void Plant::defeat(Organism* aggressor) {
	_alive = false;
	if (this->_placed) {
		_world->removeOrganism(this);
	}
}

void Plant::victory(Organism* defender) {}