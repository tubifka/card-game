#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h" // Підключаємо клас Player
#include "main.h"
#include "deck.h"

using namespace std;

const string RED = "\033[31m";
const string LightBLUE = "\033[96m";

bool winOp(Player& player) {
    if (player.getHealth() <= 0) {
        player.setHealth(10);
        cout << LightBLUE << " ___   . ___    . ___      ___  ._     _. .____  ._    _.   =====      .      .      .  ___   ._     _. ...\n";
        cout << LightBLUE << "||  || ||   ||  ||   ||  ||  ||  ||\\   || ||     ||\\   ||    ||        \\          //  ||  ||  ||\\   || | |\n";
        cout << LightBLUE << "||  || ||   ||  ||   ||  ||  ||  ||  \\ || ||---  ||  \\ ||    ||         \\  //\\   //   ||  ||  ||  \\ || | |\n";
        cout << LightBLUE << "||  || ||---    ||---    ||  ||  ||    \|| ||---  ||    \||    ||          \\//  \\ //    ||  ||  ||    \|| |_|\n";
        cout << LightBLUE << " ---   ||       ||        ---    ||    || ||___  ||    ||    -          -      -       ---   ||    || .\n";
        return true;
    }
    else {
        return false;
    }
}

bool winPl(Player& opponent) {
    if (opponent.getHealth() <= 0) {
        opponent.setHealth(10);
        cout << LightBLUE << "Player has won ";

        return true;
    }
    else {
        return false;
    }
}

void endGame() {
    cout << RED << "._____      =      ._      _. .____      ___ .      .  .____   .___. \n";
    cout << RED << "||         // \\    ||      || ||       ||  || \\    //  ||     ||   ||\n";
    cout << RED << "||        //   \\   ||  \\// || ||---    ||  ||  \\  //   ||---  ||___|| \n";
    cout << RED << "|| ===   // === \\  ||      || ||---    ||  ||   \\//    ||---  ||\\\n";
    cout << RED << "||___|| //       \\ ||      || ||___      ---     -     ||___  ||  \\ \n";
}

void game(Player& player, Player& opponent, Deck& deck) {
    while (player.getHealth() > 0 && opponent.getHealth() > 0) {
        Card chosenCard = player.playerChooseCard(opponent);
        player.discardCard(player, opponent, chosenCard); // Pass player and opponent objects
        cout << "Player hit with: " << chosenCard.hit << endl;
        cout << "Opponent hp: " << opponent.getHealth() << endl;
        cout << "Player mana: " << player.getManaNow() << endl;
        if (winPl(opponent)) {
            break;
        }

        player.addCardsFromDeck(deck);

        chosenCard = opponent.playerChooseCard(player);
        opponent.discardCard(opponent, player, chosenCard); // Pass player and opponent objects     
        cout << "Opponent hit with: " << chosenCard.hit << endl;
        cout << "Player hp: " << player.getHealth() << endl;
        cout << "Opponent mana: " << opponent.getManaNow() << endl;
        if (winOp(player)) {
            break;
        }

        opponent.addCardsFromDeck(deck);

        if (deck.getCards().empty()) {
            cout << "No more cards left " << endl;
            cout << "Draw" << endl;
            break;
        }
    }
}

int main() {
    Player player;
    Player opponent;
    Deck deck;
    string name;
    deck.initialization();
    player.addCardsFromDeck(deck);
    opponent.addCardsFromDeck(deck);

    cout << "Enter your name: ";
    cin >> name;
    cout << endl;

    player.setName(name);

    game(player, opponent, deck);

    return 0;
}
