#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
public:
    string name; // Ім'я карти
    int mana; // Мана карти
    int hit; //сила карти

    Card(const string& n, int m, int h);
    void display();
};

#endif
