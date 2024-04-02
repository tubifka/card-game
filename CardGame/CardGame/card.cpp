#include "card.h"
#include <iostream>

using namespace std;

Card::Card(const string& n, int m, Type t, Rarity r) : name(n), mana(m), type(t), rarity(r) {}

void Card::display() {
    cout << "Карта: " << name << endl;
    cout << "Мана: " << mana << endl;
    cout << "Тип: ";
    switch (type) {
        case Type::SPELL:
            cout << "Заклинання" << endl;
            break;
        case Type::MINION:
            cout << "Слуга" << endl;
            break;
    }
    cout << "Рідкість: ";
    switch (rarity) {
        case Rarity::COMMON:
            cout << "Звичайна" << endl;
            break;
        case Rarity::RARE:
            cout << "Рідка" << endl;
            break;
        case Rarity::EPIC:
            cout << "Епічна" << endl;
            break;
        case Rarity::LEGENDARY:
            cout << "Легендарна" << endl;
            break;
    }
}
