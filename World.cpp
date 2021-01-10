#include <iostream>
#include "World.h"
#include "Organism.h"

using namespace std;

World::World(int sizeX, int sizeY) {
	_initiativeShift = sizeof(unsigned int) * 8 - 4;
	_organismsLimit = UINT_MAX >> 4;
	_sizeX = sizeX;
	_sizeY = sizeY;
	Organism::setPointerToWorld(this);
	board = new Organism * *[_sizeY];
	for (int i = 0; i < _sizeY; i++) {
		board[i] = new Organism * [_sizeX];
		for (int j = 0; j < _sizeX; j++) {
			board[i][j] = nullptr;
		}
	}
	printWorld();
}

World::~World() {
	for (int i = 0; i < _sizeY; i++) {
		delete[] board[i];
	}
	delete[] board;
	auto organism = organismSet.begin();
	while (organism != organismSet.end()) {
		delete* organism;
		organism = organismSet.erase(organism);
	}
}

void World::placeOrganisms(int n) {

	for (int i = 0; i < n; i++) {
		Organism* org = Organism::getRandomAnimal();
		org->addToWorld();
	}

	printWorld();
	Sleep(300);
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
	cout << "Projekt swiata, Michal Czapiewski [156221]" << endl;
	cout << "Ilosc organizmow na planszy: " << organismSet.size() << endl;
	cout << "[ENTER] - nastepna tura, [ESCAPE] - zakoncz" << endl;
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
}

void World::nextTurn() {
	auto organism = organismSet.begin();
	while (organism != organismSet.end()) {
		if ((*organism)->_alive) {
			(*organism)->action();
		}
		organism++;
	}
	cleanOrganismSet();
}

void World::runSimulation() {
	while (true) {
		if (GetAsyncKeyState(VK_RETURN)) {
		this->nextTurn();
		this->printWorld();
		}
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
	assignKey(organism);
	board[organism->getY()][organism->getX()] = organism;
	organismSet.insert(organism);
}

void World::moveOrganism(Organism* organism) {
	board[organism->getY()][organism->getX()] = organism;
	board[organism->getOldY()][organism->getOldX()] = nullptr;
}

void World::removeOrganism(Organism* organism) {
	board[organism->getY()][organism->getX()] = nullptr;
}

void World::cleanOrganismSet() {
	auto organism = organismSet.begin();
	while (organism != organismSet.end()) {
		if (!(*organism)->_alive) {
			delete* organism;
			organism = organismSet.erase(organism);
		}
		else {
			organism++;
		}
	}
}