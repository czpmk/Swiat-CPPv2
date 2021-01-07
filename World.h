#pragma once
#include <Windows.h>
#include <set>
#include "Comparison.h"
class Organism;

using namespace std;

class World {
public:
    explicit World(int sizeX = 20, int sizeY = 20);

    ~World();

    int getSizeX() const;

    int getSizeY() const;

    friend void Organism::addToWorld();

    friend bool Organism::collision();

    friend void Organism::defeat();

    friend class Animal;

private:
    set<Organism*, Comparison> organisms;
    Organism*** board;
    int _initiativeShift;
    unsigned int _organismsLimit;
    int _sizeX;
    int _sizeY;

    bool containsOrganismAt(int, int);

    Organism* organismAt(int, int);

    void printWorld();

    void nextTurn();

    void runSimulation();

    void assignKey(Organism*);

    void placeOnTheBoard(Organism*);

    void moveOrganism(Organism*);

    void removeOrganism(Organism*);
};