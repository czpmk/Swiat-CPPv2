#pragma once
#include <iostream>

using namespace std;

class World;

class Organism {
public:
	int getX() const;
	int getY() const;
	int getOldX() const;
	int getOldY() const;
	int getStrength() const;
	void setStrength(int);
	unsigned int getKey() const;
	int getInitiative() const;
	void setLastLocation();

	friend World;
	friend class Animal;
	bool operator> (const Organism&) const;

protected:
	static World* _world;
	int _oldX;
	int _oldY;
	int _newX;
	int _newY;
	int _initiative;
	int _strength;
	unsigned int _key;
	bool _alive = true;
	bool _placed = false;

	Organism(int, int);
	virtual void print(ostream& out) = 0;
	virtual void defeat(Organism*) = 0;
	virtual void victory(Organism*) = 0;
	virtual void action() = 0;
	friend ostream& operator<<(ostream&, Organism*);
	virtual void attack(Organism*);
	virtual bool collision();
	void addToWorld();
	void setKey(unsigned int);
	void setRandomLocation();
	void setRandomLocationNearby();
	static void setPointerToWorld(World*);
	static Organism* getRandomAnimal();
};