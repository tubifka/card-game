#include "player.h"
#include <iostream>

using namespace std;

Player::Player() {
    health = 20;
}

void Player::discardCard() {
    if (!deck.empty()) {
        Card discardedCard = deck.back();
        deck.pop_back();
        health -= discardedCard.mana;
        cout << "Гравець викидає карту: " << discardedCard.name << endl;
    }
}

void Player::displayDeck() {
    cout << "Колода гравця:" << endl;
    for (const auto& card : deck) {
        card.display();
    }
}


void Player::addCard(const string& name, int mana, Card::Type type, Card::Rarity rarity) {
    deck.push_back(Card(name, mana, type, rarity));
}
