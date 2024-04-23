#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>

using namespace std;

class Deck {
private:
    vector<Card> cards;

public:
    Deck initialization();
    vector<Card>& getCards(); // Return a reference to the deck vector
};

#endif // DECK_H

