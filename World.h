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

    bool containsOrganismAt(int, int);

    Organism* organismAt(int, int);

    int getSizeX() const;

    int getSizeY() const;

private:
    set<Organism*, Comparison> organisms;
    Organism*** board;
    int _initiativeShift;
    unsigned int _organismsLimit;
    int _sizeX;
    int _sizeY;

    void printWorld();

    void nextTurn();

    void assignKey(Organism*);

    friend void Organism::addToWorld();

    void addOrganism(Organism*);

    void moveOrganism(Organism*);

    void removeOrganism(Organism*);

    void runSimulation();
};