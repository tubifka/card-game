#include "player.h"
#include <iostream>

void Player::setHealth(int newHealth) {
    health = newHealth;
}

int Player::getHealth() {
    return health;
}

int Player::getManaNow() {
    return manaNow;
}

Player::Player() : health(20), manaNow(10) {
}

Card Player::chooseCard() {
    // Display the player's deck
    displayDeck();

    // Ask the player to choose a card index
    cout << "Choose a card index: ";
    size_t index;
    cin >> index;

    // Validate the input
    while (index >= playerDeck.size() || playerDeck[index].mana > manaNow) {
        cout << "Invalid index or insufficient mana. Choose a valid card index: ";
        cin >> index;
    }

    // Return the chosen card
    return playerDeck[index];
}

void Player::discardCard(Player& pl, Player& op, Card chosenCard) {
    if (!playerDeck.empty()) {
        Card discardedCard = playerDeck.back();
        playerDeck.pop_back();
        pl.manaNow -= discardedCard.mana;
        cout << "Player threw a card: " << discardedCard.name << endl;
        op.setHealth(op.getHealth()-discardedCard.hit);
        if (pl.manaNow < 10) {
            pl.manaNow += 3;
        }
    }
}

void Player::displayDeck() {
    cout << "Player deck:" << endl;
    if (playerDeck.empty()) {
        cout << "Empty" << endl;
        return;
    }
    for (size_t i = 0; i < playerDeck.size(); ++i) {
        cout << i << ": ";
        playerDeck[i].display();
    }
}

void Player::addCardsFromDeck(Deck& mainDeck) {
    // Add cards from the main deck to the player's deck until it reaches 5 cards or the main deck is empty
    while (playerDeck.size() < 5 && !mainDeck.getCards().empty()) {
        playerDeck.push_back(mainDeck.getCards().back());
        mainDeck.getCards().pop_back();
    }
}
