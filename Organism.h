#pragma once
#include <iostream>

using namespace std;

class World;

class Organism {
protected:
    World* _world;
    int _oldX{};
    int _oldY{};
    int _newX{};
    int _newY{};
    int _initiative;
    int _strength;
    unsigned int _key{};

    Organism(World*, int, int);

    virtual void print(ostream& out) = 0;

    friend ostream& operator<<(ostream&, Organism*);

public:
    bool operator> (const Organism&) const;

    void addToWorld();

    virtual void action() = 0;

    virtual bool collision();

    int getX() const;

    int getY() const;

    int getOldX() const;

    int getOldY() const;

    void setKey(unsigned int);

    unsigned int getKey() const;

    int getInitiative() const;

    void setRandomLocation();

    void setRandomLocationNearby();
};