//#include "opponent.h"
//#include "player.h"
//#include <iostream>
//
//void Opponent::setHealth(int newHealth) {
//    health = newHealth;
//}
//
//int Opponent::getHealth() {
//    return health;
//}
//
//int Opponent::getManaNow() {
//    return manaNow;
//}
//
//Opponent::Opponent() : health(20), manaNow(10) {
//}
//
//Card Opponent::chooseCard() {
//    // Display the opponent's deck
//    displayDeck();
//
//    // Choose a random card index
//    size_t index = rand() % opponentDeck.size();
//
//    // Validate the chosen card index
//    while (index >= opponentDeck.size() || opponentDeck[index].mana > manaNow) {
//        index = rand() % opponentDeck.size();
//    }
//
//    // Return the chosen card
//    return opponentDeck[index];
//}
//
//void Opponent::discardCard(Player& pl, Opponent& op, Card chosenCard) {
//    if (!opponentDeck.empty()) {
//        Card discardedCard = chosenCard;
//        discardedCard = opponentDeck.back();
//        opponentDeck.pop_back();
//        op.manaNow -= discardedCard.mana;
//        std::cout << "Opponent threw a card: " << discardedCard.name << std::endl;
//        pl.setHealth(pl.getHealth() - discardedCard.hit); // Modify using getter and setter
//        if (op.manaNow < 10) {
//            op.manaNow += 3;
//        }
//    }
//}
//
//void Opponent::displayDeck() {
//    std::cout << "Opponent deck:" << std::endl;
//    for (auto& card : opponentDeck) {
//        card.display();
//    }
//}
//
//void Opponent::addCardsFromDeck(Deck& mainDeck) {
//    // Add cards from the main deck to the opponent's deck until it reaches 5 cards or the main deck is empty
//    while (opponentDeck.size() < 5 && !mainDeck.getCards().empty()) {
//        opponentDeck.push_back(mainDeck.getCards().back());
//        mainDeck.getCards().pop_back();
//    }
//}