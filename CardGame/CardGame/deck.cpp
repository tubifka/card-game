#include "deck.h"
#include <cstdlib>
#include <ctime>

Deck Deck::initialization() {
    // Arrays of possible names, mana values, and hit values
    string names[] = { "OCTAVIOUS", "DEMORGAN", "SHAPOCKLAK", "MIDPICKET", "LEVIANT" };
    int manaValues[] = { 1, 2, 3, 4, 5 };
    int hitValues[] = { 1, 2, 3, 4, 5 };

   
    int numNames = sizeof(names) / sizeof(names[0]);
    int numManaValues = sizeof(manaValues) / sizeof(manaValues[0]);
    int numHitValues = sizeof(hitValues) / sizeof(hitValues[0]);

    srand(static_cast<unsigned>(time(nullptr)));

    // Fill the deck with 20 random cards
    for (int i = 0; i < 30; ++i) {
       
        int nameIndex = rand() % numNames;
        int manaIndex = rand() % numManaValues;
        int hitIndex = rand() % numHitValues;

        // Create a card with the randomly selected values and add it to the deck
        cards.push_back(Card(names[nameIndex], manaValues[manaIndex], hitValues[hitIndex]));
    }

    return *this; 
}

vector<Card>& Deck::getCards() {
    return cards;
}
