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
    Card chooseCard();
    void discardCard(Player& pl, Opponent& op, Card choosenCard);
    void displayDeck();
    void addCardsFromDeck(Deck mainDeck);
};

#endif

