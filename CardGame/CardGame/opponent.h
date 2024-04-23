#ifndef OPPONENT_H
#define OPPONENT_H

#include "deck.h"
#include "player.h"
#include "card.h"
#include <vector>
#include <iostream>

class Opponent {
private:
    int health;
    int manaNow;
    std::vector<Card> opponentDeck;

public:
    Opponent();
    Card chooseCard();
    void discardCard(Player& pl, Opponent& op, Card chosenCard);
    void displayDeck();
    void addCardsFromDeck(Deck& mainDeck);
    int getHealth();
    int getManaNow();
    void setHealth(int newHealth);
};

#endif // OPPONENT_H
