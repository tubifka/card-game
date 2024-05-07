#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h" // Підключаємо клас Player

#include "deck.h"

using namespace std;
const string RED = "\033[31m";
const string LightBLUE = "\033[96m";

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
            cout << LightBLUE << " ___   . ___    . ___      ___  ._     _. .____  ._    _.   =====      .      .      .  ___   ._     _. ...\n";
            cout << LightBLUE << "||  || ||   ||  ||   ||  ||  ||  ||\\   || ||     ||\\   ||    ||        \\          //  ||  ||  ||\\   || | |\n";
            cout << LightBLUE << "||  || ||   ||  ||   ||  ||  ||  ||  \\ || ||---  ||  \\ ||    ||         \\  //\\   //   ||  ||  ||  \\ || | |\n";
            cout << LightBLUE << "||  || ||---    ||---    ||  ||  ||    \|| ||---  ||    \||    ||          \\//  \\ //    ||  ||  ||    \|| |_|\n";
            cout << LightBLUE << " ---   ||       ||        ---    ||    || ||___  ||    ||    -          -      -       ---   ||    || .\n";

            break;
        }
        if (deck.getCards().empty()) {
            cout << "No more cards left " << endl;
            cout << "Draw" << endl;
            break;
        }
    }


    cout << RED << "._____      =      ._      _. .____      ___ .      .  .____   .___. \n";
    cout << RED << "||         // \\    ||      || ||       ||  || \\    //  ||     ||   ||\n";
    cout << RED << "||        //   \\   ||  \\// || ||---    ||  ||  \\  //   ||---  ||___|| \n";
    cout << RED << "|| ===   // === \\  ||      || ||---    ||  ||   \\//    ||---  ||\\\n";
    cout << RED << "||___|| //       \\ ||      || ||___      ---     -     ||___  ||  \\ \n";
    return 0;
}
