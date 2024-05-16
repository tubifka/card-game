#include "deck.h"
#include <cstdlib>
#include <ctime>

Deck Deck::initialization() {
    // Arrays of possible names, mana values, and hit values
    string names[] = { "CARD1", "CARD2", "CARD3", "CARD4", "CARD5" };
    int manaValues[] = { 1, 2, 3, 4, 5 };
    int hitValues[] = { 1, 2, 3, 4, 5 };

    // Get the size of each array
    int numNames = sizeof(names) / sizeof(names[0]);
    int numManaValues = sizeof(manaValues) / sizeof(manaValues[0]);
    int numHitValues = sizeof(hitValues) / sizeof(hitValues[0]);

    // Seed the random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    // Fill the deck with 20 random cards
    for (int i = 0; i < 30; ++i) {
        // Generate random indices for selecting values from arrays
        int nameIndex = rand() % numNames;
        int manaIndex = rand() % numManaValues;
        int hitIndex = rand() % numHitValues;

        // Create a card with the randomly selected values and add it to the deck
        cards.push_back(Card(names[nameIndex], manaValues[manaIndex], hitValues[hitIndex]));
    }

    return *this; // Return the initialized deck
}

vector<Card>& Deck::getCards() {
    return cards;
}
