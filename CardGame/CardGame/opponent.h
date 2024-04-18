#ifndef OPPONENT_H
#define OPPONENT_H

#include "card.h"
#include <vector>
#include "deck.h"
#include "player.h"

using namespace std;

class Opponent {
public:
    vector<Card> opponentDeck;
    int health;
    int manaNow;

    Opponent();
    Card chooseCard(Opponent& op);
    void discardCard(Player& pl, Opponent& op, Card& chooseCard());
    void displayDeck();
    void addCardsFromDeck(Deck& mainDeck);
};
#endif
