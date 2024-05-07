#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h" // Підключаємо клас Player

#include "deck.h"

using namespace std;



int main() {
    Player player;
    Player opponent;
    Deck deck;
    deck.initialization();
    player.addCardsFromDeck(deck);
    opponent.addCardsFromDeck(deck);

    while (player.getHealth() > 0 && opponent.getHealth() > 0) {
        Card chosenCard = player.chooseCard();
        player.discardCard(player, opponent, chosenCard); // Pass player and opponent objects
        cout << "Player hit with: " << chosenCard.hit << endl;
        cout << "Opponent hp: " << opponent.getHealth() << endl;
        cout << "Player mana: " << player.getManaNow() << endl;
        if (opponent.getHealth() <= 0) {
            cout << "Player has won" << endl;
            break;
        }

        chosenCard = opponent.chooseCard();
        opponent.discardCard(opponent, player, chosenCard); // Pass player and opponent objects     
        cout << "Opponent hit with: " << chosenCard.hit << endl;
        cout << "Player hp: " << player.getHealth() << endl;
        cout << "Opponent mana: " << opponent.getManaNow() << endl;
        if (player.getHealth() <= 0) {
            cout << "Opponent has won" << endl;
            break;
        }
        if (deck.getCards().empty()) {
            cout << "No more cards left " << endl;
            cout << "Draw" << endl;
            break;
        }
    }
    return 0;
}
