#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "player.cpp"
#include "opponent.h"

#include "deck.h"

using namespace std;

int main() {
    
    Player player;
    Opponent opponent;
    Deck deck;
    deck.initialization();
    player.addCardsFromDeck(deck);
    opponent.addCardsFromDeck(deck);

    while (player.health > 0 && opponent.health > 0) {
        Card chosenCard = player.chooseCard();
        player.discardCard(player, opponent, chosenCard);
        chosenCard = opponent.chooseCard();
        opponent.discardCard(player, opponent, chosenCard);
    }
    return 0;
}
