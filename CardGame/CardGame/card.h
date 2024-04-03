#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
public:
    enum class Type { // Додано тип карти
        SPELL,
        MINION
    };
    enum class Rarity { // Додано рідкість карти
        COMMON,
        RARE,
        EPIC,
        LEGENDARY
    };

    string name; // Ім'я карти
    int mana; // Мана карти
    Type type; // Тип карти
    Rarity rarity; // Рідкість карти

    Card(int mana, Type t, Rarity r):mana(mana), type(t), rarity(r){}
    Card(const string& n, int m, Type t, Rarity r);
    void display();
};

#endif
