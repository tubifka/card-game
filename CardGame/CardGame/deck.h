#include <iostream>
#include <vector>
#include "card.h"


class Deck {
private:
    vector<Card> cards;

public:
    Deck();
    vector<Card> getCards();
    Deck initialization();
};