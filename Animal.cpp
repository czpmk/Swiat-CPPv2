#include "Animal.h"
#include "World.h"
#include <iostream>
using namespace std;


Animal::Animal(World* world, int strength, int initiative)
	: Organism(world, strength, initiative) {}

void Animal::action() {
	setRandomLocationNearby();
	if (collision()) {
		attack(_world->organismAt(_newX, _newY));
	}
	if (this->_alive) {
		_world->moveOrganism(this);
	}
}

void Animal::attack(Organism* defender) {
	if (this->_strength >= defender->getStrength()) {
		defender->defeat();
	}
	else {
		this->defeat();
	}
}
