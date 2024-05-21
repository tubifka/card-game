#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h" // Include the Player class
#include "main.h"
#include "deck.h"

using namespace std;

const string RED = "\033[31m";
const string LightBLUE = "\033[96m";
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string YELLOW = "\033[33m";

void printStart() {
    cout << LightBLUE << "._____      =       .___.   .____.    ._____      =     ._      _. .____\n";
    cout << LightBLUE << "||        // \\    ||   ||  ||   ||   ||         // \\    ||      || || \n";
    cout << LightBLUE << "||       //   \\   ||___||  ||   ||   ||        //   \\   ||  \\// || ||---\n";
    cout << LightBLUE << "||      // === \\  ||\\      ||   ||   || ===   // === \\  ||      || ||---\n";
    cout << LightBLUE << "||____ //       \\ ||  \\    ||___||   ||___|| //       \\ ||      || ||___\n" << RESET;
    cout << endl;
}

void showInstructions() {
    cout << LightBLUE << "     _     _   _____  .      .     .   ======= _____      . ___   _           --  \\       //\n";
    cout << LightBLUE << "    | |   | | ||   || \\          //      ||   ||   ||    ||   || ||          //\\   \\     //\n";
    cout << LightBLUE << "    | | _ | | ||   ||  \\  //\\   //       ||   ||   ||    ||   || ||         //  \\   \\   //\n";
    cout << LightBLUE << "    |   -   | ||   ||   \\//  \\ //        ||   ||   ||    ||   || ||        //----\\    \||/\n";
    cout << LightBLUE << "    | |   | | ||   ||    \/    \//         ||   ||   ||    ||---   ||       //      \\   ||\n";
    cout << LightBLUE << "    |_|   |_|  _____    -      -         -     _____     ||      ||===== //        \\  || \n" << RESET;
    cout << endl;
    cout << YELLOW << "-" << RESET<<" Each player starts with a certain amount of health and a deck of cards.\n";
    cout << YELLOW << "-" << RESET<<" Each turn, players select a card using" << RED << " UP" << RESET << " or " << RED << "DOWN" << RESET << " on the keyboard.\n";
    cout << YELLOW << "-" << RESET << " The chosen card affects the health of the opponent based on the card's power.\n";
    cout << YELLOW << "-" << RESET<<" After playing a card, the player draws new cards from the deck.\n";
    cout << YELLOW << "-" << RESET << " The game continues until one player's health drops to zero, declaring the other player the winner.\n" ;

    cout << endl;
    cout << "To start the game enter " << RED << "YOUR NAME " << RESET << "and press " << RED << "ENTER" << RESET << endl;
    cin.ignore(); // Ignore any previous input
    cin.get(); // Wait for the user to press Enter

}

bool winOp(Player& player) {
    if (player.getHealth() <= 0) {
        player.setHealth(10);
        cout << LightBLUE << " ___   . ___    . ___      ___  ._     _. .____  ._    _.   =====      .      .      .  ___   ._     _. ...\n";
        cout << LightBLUE << "||  || ||   ||  ||   ||  ||  ||  ||\\   || ||     ||\\   ||    ||        \\          //  ||  ||  ||\\   || | |\n";
        cout << LightBLUE << "||  || ||   ||  ||   ||  ||  ||  ||  \\ || ||---  ||  \\ ||    ||         \\  //\\   //   ||  ||  ||  \\ || | |\n";
        cout << LightBLUE << "||  || ||---    ||---    ||  ||  ||    \|| ||---  ||    \||    ||          \\//  \\ //    ||  ||  ||    \|| |_|\n";
        cout << LightBLUE << " ---   ||       ||        ---    ||    || ||___  ||    ||    -           -      -       ---   ||    || .\n" << RESET;
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
        auto chosenCard = player.playerChooseCard(player, opponent);
        player.discardCard(player, opponent, chosenCard.second); // Pass player and opponent objects
        if (winPl(opponent)) {
            break;
        }

        player.addCardsFromDeck(deck);

        chosenCard = opponent.opponentChooseCard();
        opponent.discardCard(opponent, player, chosenCard.second); // Pass player and opponent objects
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

    showInstructions();
    printStart();
    cout << "Enter your name: ";
    cin >> name;
    cout << endl;
    player.setName(name);

    game(player, opponent, deck);

    return 0;
}