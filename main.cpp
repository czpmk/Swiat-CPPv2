#include "World.h"
#include <iostream>

int main() {
    World w = World(40, 20);
    int n = -1;
    while (true) {
        cout << "Prosze podac liczbe organizmow <0, 200> >> ";
        cin >> n;
        cout << endl;
        if (n > 0 && n < 201) break;
    }
    w.placeOrganisms(n);
    w.runSimulation();
}