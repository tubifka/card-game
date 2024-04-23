#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "opponent.h"
#include "card.h"
#include <vector>
#include <iostream>

using namespace std;

class Player {
private:
    int health;
    int manaNow;
    vector<Card> playerDeck;

public:
    Player();
    Card chooseCard();
    void discardCard(Player& pl, Opponent& op, Card chosenCard);
    void displayDeck();
    void addCardsFromDeck(Deck& mainDeck);
    int getHealth();
    int getManaNow();
    void setHealth(int newHealth);
};

#endif // PLAYER_H