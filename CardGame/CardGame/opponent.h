#ifndef OPPONENT_H
#define OPPONENT_H

#include "card.h" // Підключаємо клас Card

#include <vector>

using namespace std;

class Opponent {
public:
    vector<Card> deck; // Колода суперника
    int health; // Здоров'я суперника

    Opponent();
    void discardCard();
};

#endif
