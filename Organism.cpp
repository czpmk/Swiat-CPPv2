#include "Organism.h"
#include "World.h"


Organism::Organism(World* world, int strength, int initiative) {
	_world = world;
	_strength = strength;
	_initiative = initiative;
}

std::ostream& operator<<(std::ostream& out, Organism* organism) {
	organism->print(out);
	return out;
}

bool Organism::operator>(const Organism& right) const {
	return (this->_key > right.getKey());
}

void Organism::addToWorld() {
	this->setRandomLocation();
	if (collision()) {
		this->attack(_world->organismAt(_newX, _newY));
	}
	if (this->_alive) {
		_world->assignKey(this);
		_world->placeOnTheBoard(this);
		_placed = true;
	}
}

bool Organism::collision() {
	return _world->containsOrganismAt(_newX, _newY);
}

void Organism::defeat() {
	_alive = false;
	if (this->_placed) {
		_world->removeOrganism(this);
	}
}

int  Organism::getX() const {
	return this->_newX;
}

int  Organism::getY() const {
	return this->_newY;
}

int Organism::getOldX() const {
	return this->_oldX;
}

int Organism::getOldY() const {
	return this->_oldY;
}

void Organism::setKey(unsigned int key) {
	_key = key;
}

unsigned int Organism::getKey() const {
	return this->_key;
}

int Organism::getInitiative() const {
	return _initiative;
}

int Organism::getStrength() const {
	return this->_strength;
}

void Organism::setRandomLocation() {
	_newX = rand() % _world->getSizeX();
	_newY = rand() % _world->getSizeY();
}

void Organism::setRandomLocationNearby() {
	_oldX = _newX;
	_oldY = _newY;
	int rangeX = 3, rangeY = 3;
	int startX = _oldX - 1;
	int startY = _oldY - 1;
	//Sprawdzenie dolnych granic
	if (_oldX == 0) {
		startX++;
		rangeX--;
	}
	if (_oldY == 0) {
		startY++;
		rangeY--;
	}
	//Sprawdzenie gornych granic
	if (_oldX == (_world->getSizeX() - 1)) rangeX--;
	if (_oldY == (_world->getSizeY() - 1)) rangeY--;
	//Losowanie nowego polozenia, tak dlugo az bedzie inne
	//niz podane w argumentach
	while (true) {
		_newX = startX + rand() % rangeX;
		_newY = startY + rand() % rangeY;
		if (_newX != _oldX || _newY != _oldY) break;
	}
}




