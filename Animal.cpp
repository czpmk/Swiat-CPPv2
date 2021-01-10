#include "Animal.h"
#include "World.h"
#include <iostream>
using namespace std;


Animal::Animal(int strength, int initiative)
	: Organism(strength, initiative) {}

void Animal::action() {
	setRandomLocationNearby();
	if (collision()) {
		attack(_world->organismAt(_newX, _newY));
	}
	if (this->_alive) {
		_world->moveOrganism(this);
	}
}

void Animal::defeat(Organism* aggressor) {
	_alive = false;
	if (this->_placed) {
		_world->removeOrganism(this);
	}
}

void Animal::victory(Organism* defender) {}