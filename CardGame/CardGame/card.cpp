#include "card.h"
#include <iostream>

using namespace std;

Card::Card(const string& n, int m, Type t, Rarity r) : name(n), mana(m), type(t), rarity(r) {}

void Card::display() {
    cout << "Card: " << name << endl;
    cout << "Manna: " << mana << endl;
    cout << "Type: ";
    switch (type) {
        case Type::SPELL:
            cout << "Spell" << endl;
            break;
        case Type::MINION:
            cout << "Slave" << endl;
            break;
    }
    cout << "Rarity: ";
    switch (rarity) {
        case Rarity::COMMON:
            cout << "Common" << endl;
            break;
        case Rarity::RARE:
            cout << "Rare" << endl;
            break;
        case Rarity::EPIC:
            cout << "Epic" << endl;
            break;
        case Rarity::LEGENDARY:
            cout << "Legendary" << endl;
            break;
    }
}
