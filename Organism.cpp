#include "Organism.h"
#include "World.h"
#include "Wilk.h"
#include "Owca.h"
#include "Zolw.h"
#include "Lew.h"
#include "Koliber.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
World* Organism::_world = nullptr;

Organism::Organism(int strength, int initiative) {
	_strength = strength;
	_initiative = initiative;
}

bool Organism::operator>(const Organism& right) const {
	return (this->_key > right.getKey());
}

std::ostream& operator<<(std::ostream& out, Organism* organism) {
	organism->print(out);
	return out;
}

void Organism::attack(Organism* defender) {
	try {
		//Zwierzeta s¹ tego samego gatunku
		if (typeid(*this) == typeid(*defender)) {
			if (!this->_placed) {
				_alive = false;
			}
			else {
				this->setLastLocation();
			}
		}
		else {
			//Atak
			if (this->_strength >= defender->getStrength()) {
				this->victory(defender);
				defender->defeat(this);
			}
			else {
				if (!this->_placed) {
					_alive = false;
				}
				else {
					this->setLastLocation();
					defender->victory(this);
					this->defeat(defender);
				}
			}
		}
	}
	catch (int n) {
		//Lokacja niedostepna
		if (n == 1) {
			this->setLastLocation();
		}
		else {
			throw "Nieobslugiwany wyjatek";
		}
	}
}

bool Organism::collision() {
	return _world->containsOrganismAt(_newX, _newY);
}

void Organism::addToWorld() {
	this->setRandomLocation();
	if (collision()) {
		attack(_world->organismAt(_newX, _newY));
	}
	if (this->_alive) {
		_world->placeOnTheBoard(this);
		_placed = true;
	}
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
	//niz poprzednie
	while (true) {
		_newX = startX + rand() % rangeX;
		_newY = startY + rand() % rangeY;
		if (_newX != _oldX || _newY != _oldY) break;
	}
}

void Organism::setPointerToWorld(World* world) {
	_world = world;
}

Organism* Organism::getRandomAnimal() {
	int n = 1 + rand() % 8;
	switch (n) {
	case 1:
		return new Wilk();
	case 2:
		return new Owca();
	case 3:
		return new Zolw();
	case 4:
		return new Lew();
	case 5:
		return new Koliber();
	case 6:
		return new Trawa();
	case 7:
		return new Mlecz();
	case 8:
		return new Guarana();
	}
}


void Organism::setLastLocation() {
	_newX = _oldX;
	_newY = _oldY;
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

void Organism::setStrength(int newStrength) {
	this->_strength = newStrength;
}