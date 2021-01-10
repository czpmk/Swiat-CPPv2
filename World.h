#pragma once
#include <Windows.h>
#include <set>
#include "Comparison.h"
class Organism;
class Animal;
class Plant;

using namespace std;

class World {
public:
    explicit World(int = 20, int = 20);

    void placeOrganisms(int);

    void runSimulation();

    ~World();

    int getSizeX() const;

    int getSizeY() const;

    friend Organism;

    friend Animal;

    friend Plant;

private:
    set<Organism*, Comparison> organismSet;
    Organism*** board;
    int _initiativeShift;
    unsigned int _organismsLimit;
    int _sizeX = 20;
    int _sizeY = 20;

    bool containsOrganismAt(int, int);

    Organism* organismAt(int, int);

    void printWorld();

    void nextTurn();

    void assignKey(Organism*);

    void placeOnTheBoard(Organism*);

    void moveOrganism(Organism*);

    void removeOrganism(Organism*);

    void cleanOrganismSet();
};