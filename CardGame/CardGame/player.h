#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "card.h"
#include <vector>
#include <iostream>

using namespace std;

class Player {
private:
    string name;
    int health;
    int manaNow;
    vector<Card> playerDeck;

public:
    Player();
    Card playerChooseCard(Player& player, Player& opponent);
    void discardCard(Player& pl, Player& op, Card chosenCard);
    void displayDeck(size_t selectedIndex, Player& player, Player& opponent);
    void addCardsFromDeck(Deck& mainDeck);
    void displayStats(Player& pl, Player& op);
    Card opponentChooseCard();
    int getHealth();
    int getManaNow();
    void setHealth(int newHealth);
    void setName(string name);
};

#endif // PLAYER_H