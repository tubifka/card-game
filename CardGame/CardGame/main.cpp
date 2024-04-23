#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h" // Підключаємо клас Player
#include "opponent.h" // Підключаємо клас Opponent


#include "deck.h"

using namespace std;

int main() {
    Player player;
    Opponent opponent;
    Deck deck;
    deck.initialization();
    player.addCardsFromDeck(deck);
    opponent.addCardsFromDeck(deck);

    while (player.getHealth() > 0 && opponent.getHealth() > 0) {
        Card chosenCard = player.chooseCard();
        player.discardCard(player, opponent, chosenCard); // Pass player and opponent objects
        chosenCard = opponent.chooseCard();
        opponent.discardCard(player, opponent, chosenCard); // Pass player and opponent objects
    }
    return 0;
}
