#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <vector>
#include "deck.h"
#include "opponent.h"

using namespace std;

class Player {
public:
    vector<Card> playerDeck;
    int health;
    int manaNow;

    Player();
    Card chooseCard(Player& pl);
    void discardCard(Player& pl, Opponent& op, Card& chooseCard());
    void displayDeck();
    void addCardsFromDeck(Deck& mainDeck);
};

#endif

