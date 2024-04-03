#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <vector>

using namespace std;

class Player {
public:
    vector<Card> deck;
    int health;

    Player();
    void discardCard();
    void displayDeck();
    void addCard(const string& name, int mana, Card::Type type, Card::Rarity rarity);
};

#endif

