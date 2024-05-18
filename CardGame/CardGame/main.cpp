#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h" // Підключаємо клас Player
#include "main.h"
#include "deck.h"

using namespace std;

const string RED = "\033[31m";
const string LightBLUE = "\033[96m";
const string RESET = "\033[0m";

void printStart() {
    cout << LightBLUE << "._____      =       .___.   .____.    ._____      =     ._      _. .____\n";
    cout << LightBLUE << "||        // \\    ||   ||  ||   ||   ||         // \\    ||      || || \n";
    cout << LightBLUE << "||       //   \\   ||___||  ||   ||   ||        //   \\   ||  \\// || ||---\n";
    cout << LightBLUE << "||      // === \\  ||\\      ||   ||   || ===   // === \\  ||      || ||---\n";
    cout << LightBLUE << "||____ //       \\ ||  \\    ||___||   ||___|| //       \\ ||      || ||___\n" << RESET;
    cout << endl;
  
}


bool winOp(Player& player) {
    if (player.getHealth() <= 0) {
        player.setHealth(10);
        cout << LightBLUE << " ___   . ___    . ___      ___  ._     _. .____  ._    _.   =====      .      .      .  ___   ._     _. ...\n";
        cout << LightBLUE << "||  || ||   ||  ||   ||  ||  ||  ||\\   || ||     ||\\   ||    ||        \\          //  ||  ||  ||\\   || | |\n";
        cout << LightBLUE << "||  || ||   ||  ||   ||  ||  ||  ||  \\ || ||---  ||  \\ ||    ||         \\  //\\   //   ||  ||  ||  \\ || | |\n";
        cout << LightBLUE << "||  || ||---    ||---    ||  ||  ||    \|| ||---  ||    \||    ||          \\//  \\ //    ||  ||  ||    \|| |_|\n";
        cout << LightBLUE << " ---   ||       ||        ---    ||    || ||___  ||    ||    -          -      -       ---   ||    || .\n" << RESET;
        return true;
    }
    else {
        return false;
    }
}

bool winPl(Player& opponent) {
    if (opponent.getHealth() <= 0) {
        opponent.setHealth(10);
        cout << LightBLUE << " . ---   --        --     \\      //  .____  .___.         .      .      .  ___   ._     _. ...\n";
        cout << LightBLUE << " ||   || ||      //  \\    \\    //   ||     ||   ||        \\          //  ||  ||  ||\\   || | |\n";
        cout << LightBLUE << " ||   || ||     //    \\     \||/     ||---  ||____||         \\  //\\   //   ||  ||  ||  \\ || | |\n";
        cout << LightBLUE << " ||---   ||    //------\\     ||      ||---  ||\\             \\//  \\ //    ||  ||  ||    \|| |_|\n";
        cout << LightBLUE << " ||      ||___//        \\    ||      ||___  ||  \\            -      -       ---   ||    || .\n" << RESET;

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
    cout << RED << "||___|| //       \\ ||      || ||___      ---     -     ||___  ||  \\ \n" << RESET;
}

void game(Player& player, Player& opponent, Deck& deck) {

    while (player.getHealth() > 0 && opponent.getHealth() > 0) {
        Card chosenCard = player.playerChooseCard(player, opponent);
        player.discardCard(player, opponent, chosenCard); // Pass player and opponent objects
        if (winPl(opponent)) {
            break;
        }

        player.addCardsFromDeck(deck);

        chosenCard = opponent.opponentChooseCard();
        opponent.discardCard(opponent, player, chosenCard); // Pass player and opponent objects     
        if (winOp(player)) {
            break;
        }

        opponent.addCardsFromDeck(deck);

        if (deck.getCards().empty()) {
            cout << RED << "NO CARDS LEFT " << RESET << endl;
            cout << RED << "._____   .___.         ___     __                __  \n";
            cout << RED << "||    \\ ||   \\     //   \\    \\      __      //   \n";
            cout << RED << "||    || ||___||    // ____\\    \\    //\\    // \n";
            cout << RED << "||    || ||  \\    //       \\    \\  //  \\  //  \n";
            cout << RED << "||___//  ||   \\  //         \\    \\//    \\//  \n" << RESET;
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

    printStart();
    cout << "Enter your name: ";
    cin >> name;
    cout << endl;
    player.setName(name);
    

    game(player, opponent, deck);

    return 0;
}
