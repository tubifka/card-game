#include "opponent.h"
#include <iostream>

Opponent :: Opponent() {
    health = 20;
    manaNow = 10;
}

Card Opponent::chooseCard() {
    // Display the player's deck
    displayDeck();

    // Ask the player to choose a card index
    size_t index;
    index = rand() % 5;

    // Validate the input
        while (index >= opponentDeck.size() || opponentDeck[index].mana <= manaNow) {
            index = rand() % 5;
        }
    // Return the chosen card
    return opponentDeck[index];
}

void Opponent::discardCard(Player& pl, Opponent& op, Card choosenCard) {
    if (!opponentDeck.empty()) {
        Card discardedCard = choosenCard;
        discardedCard = opponentDeck.back();
        opponentDeck.pop_back();
        op.manaNow -= discardedCard.mana;
        cout << "Player threw a card: " << discardedCard.name << endl;
        pl.health -= discardedCard.hit;
        if (op.manaNow < 10) {
            op.manaNow += 3;
        }
    }
}

void Opponent::displayDeck() {
    cout << "Player deck:" << endl;
    for (auto& card : opponentDeck) {
        card.display();
    }
}

void Opponent::addCardsFromDeck(Deck& mainDeck) {
    // Add cards from the main deck to the player's deck until it reaches 5 cards or the main deck is empty
    while (opponentDeck.size() < 5 && !mainDeck.getCards().empty()) {
        opponentDeck.push_back(mainDeck.getCards().back());
        mainDeck.getCards().pop_back();
    }
}
