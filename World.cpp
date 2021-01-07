#include <iostream>
#include "World.h"
#include "Organism.h"
#include "Lion.h"
using namespace std;

World::World(int sizeX, int sizeY) {
	_initiativeShift = sizeof(unsigned int) * 8 - 4;
	_organismsLimit = UINT_MAX >> 4;
	_sizeX = sizeX;
	_sizeY = sizeY;
	board = new Organism * *[_sizeY];
	for (int i = 0; i < _sizeY; i++) {
		board[i] = new Organism * [_sizeX];
		for (int j = 0; j < _sizeX; j++) {
			board[i][j] = nullptr;
		}
	}
	printWorld();
	for (int i = 0; i < 30; i++) {
		Organism* o = new Lion(this);
		o->addToWorld();
		printWorld();
		Sleep(300);
	}
	runSimulation();
}

World::~World() {
	for (int i = 0; i < _sizeY; i++) {
		delete[] board[i];
	}
	delete[] board;
}

bool World::containsOrganismAt(int x, int y) {
	return (board[y][x] != nullptr);
}

Organism* World::organismAt(int x, int y) {
	return board[y][x];
}

int World::getSizeX() const {
	return this->_sizeX;
}

int  World::getSizeY() const {
	return this->_sizeY;
}

void World::printWorld() {
	system("CLS");
	int i = 0, j = 0;
	cout << '#' << ' ';
	while (i < _sizeX) {
		cout << i % 10 << ' ';
		i++;
	}
	cout << endl;
	while (j < _sizeY) {
		i = 0;
		cout << j % 10 << ' ';
		while (i < _sizeX) {
			if (board[j][i] == nullptr) {
				cout << char(176) << ' ';
			}
			else {
				cout << board[j][i] << ' ';
			}
			i++;
		}
		cout << endl;
		j++;
	}
	cout << "Ilosc organizmow na planszy: " << organisms.size() << endl;
}

void World::nextTurn() {
	for (auto organism : organisms) {
		organism->action();
	}
}

void World::runSimulation() {
	while (true) {
		//if (GetAsyncKeyState(VK_RETURN)) {
			this->nextTurn();
			this->printWorld();
		//}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			this->printWorld();
			cout << "---KONIEC GRY---\n\n";
			break;
		}
		Sleep(300);
	}
}

void World::assignKey(Organism* organism) {
	unsigned int newKey = (organism->getInitiative() << _initiativeShift) + _organismsLimit;
	_organismsLimit--;
	organism->setKey(newKey);
}

void World::placeOnTheBoard(Organism* organism) {
	board[organism->getY()][organism->getX()] = organism;
	organisms.insert(organism);
}

void World::moveOrganism(Organism* organism) {
	board[organism->getY()][organism->getX()] = organism;
	board[organism->getOldY()][organism->getOldX()] = nullptr;
}

void World::removeOrganism(Organism* organism) {
	board[organism->getY()][organism->getX()] = nullptr;
	organisms.erase(organism);
}