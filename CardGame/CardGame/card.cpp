#include "card.h"
#include <iostream>

using namespace std;

Card::Card(const string& n, int m, int h) : name(n), mana(m), hit(h){}

void Card::display() {
    cout << "Card: " << name << endl;
    cout << "Manna: " << mana << endl;
    cout << "Hit: " << hit << endl;
}
