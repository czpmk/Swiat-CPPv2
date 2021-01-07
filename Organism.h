#pragma once
#include <iostream>

using namespace std;

class World;

class Organism {
protected:
	World* _world;
	int _oldX = -1;
	int _oldY = -1;
	int _newX;
	int _newY;
	int _initiative;
	int _strength;
	unsigned int _key;
	bool _alive = true;
	bool _placed = false;

	Organism(World*, int, int);

	virtual void print(ostream& out) = 0;

	friend ostream& operator<<(ostream&, Organism*);

public:
	virtual void action() = 0;

	virtual void attack(Organism*) = 0;

	bool operator> (const Organism&) const;

	void addToWorld();

	virtual bool collision();

	void defeat();

	int getX() const;

	int getY() const;

	int getOldX() const;

	int getOldY() const;

	void setKey(unsigned int);

	unsigned int getKey() const;

	int getInitiative() const;

	int getStrength() const;

	void setRandomLocation();

	void setRandomLocationNearby();
};


