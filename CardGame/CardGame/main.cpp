#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h" // Include the Player class
#include "main.h"
#include "deck.h"
#include <conio.h>
#include <iomanip>

using namespace std;

#define KEY_RIGHT 77
#define KEY_LEFT 75

const string RED = "\033[31m";
const string LightBLUE = "\033[96m";
const string RESET = "\033[0m";
const string YELLOW = "\033[33m";
const string GREEN = "\033[32m";

void printStart() {
    cout << LightBLUE << "._____      =       .___.   .____.    ._____      =     ._      _. .____\n";
    cout << LightBLUE << "||        // \\    ||   ||  ||   \\     ||         // \\    ||      || || \n";
    cout << LightBLUE << "||       //   \\   ||___||  ||    ||   ||        //   \\   ||  \\// || ||---\n";
    cout << LightBLUE << "||      // === \\  ||\\      ||    ||   || ===   // === \\  ||      || ||---\n";
    cout << LightBLUE << "||____ //       \\ ||  \\    ||___//    ||___|| //       \\ ||      || ||___\n" << RESET;
    cout << endl;
}

void showInstructions() {
    cout << endl;
    cout << "LETS START!" << endl;
    cout << endl;
    cout << "* before playing read the rules * " << endl;
    cout << LightBLUE << "     _     _   _____  .            .   ======= _____      . ___   _           --  \\       //\n";
    cout << LightBLUE << "    | |   | | ||   || \\          //      ||   ||   ||    ||   || ||          //\\   \\     //\n";
    cout << LightBLUE << "    | | _ | | ||   ||  \\  //\\   //       ||   ||   ||    ||   || ||         //  \\   \\   //\n";
    cout << LightBLUE << "    |   -   | ||   ||   \\//  \\ //        ||   ||   ||    ||   || ||        //----\\    \||/\n";
    cout << LightBLUE << "    | |   | | ||   ||    \/    \//         ||   ||   ||    ||---   ||       //      \\   ||\n";
    cout << LightBLUE << "    |_|   |_|  _____    -      -         -     _____     ||      ||===== //        \\  || \n" << RESET;
    cout << endl;
    cout << "-" << YELLOW << " Each player starts with a certain amount of health and a deck of cards.\n" << RESET;
    cout << "-" << YELLOW << " Each turn, players select a card using" << RED << " UP" << RESET << YELLOW << " or " << RESET << RED << "DOWN + ENTER" << RESET << YELLOW <<" on the keyboard.\n" << RESET;;
    cout << "-" << YELLOW << " The chosen card affects the health of the opponent based on the card's power.\n" << RESET;
    cout << "-" << YELLOW << " After playing a card, the player draws new cards from the deck.\n" << RESET;
    cout << "-" << YELLOW << " The game continues until one player's health drops to zero, declaring the other player the winner.\n" << RESET;;

    cout << endl;
    cout << RED << "Press Enter to start game!" << RESET << endl;
    cin.get(); 

}

bool winOp(Player& player) {
    if (player.getHealth() <= 0) {
        player.setHealth(10);
        cout << LightBLUE << " .___. . ___    . ___     .___. ._     _. .____  ._    _.   =====      .            .  .___.  ._    _. ...\n";
        cout << LightBLUE << "||  || ||   ||  ||   ||  ||  ||  ||\\   || ||     ||\\   ||    ||        \\          //  ||  ||  ||\\   || | |\n";
        cout << LightBLUE << "||  || ||   ||  ||   ||  ||  ||  ||  \\ || ||---  ||  \\ ||    ||         \\  //\\   //   ||  ||  ||  \\ || | |\n";
        cout << LightBLUE << "||  || ||---    ||---    ||  ||  ||    \|| ||---  ||    \||    ||          \\//  \\ //    ||  ||  ||    \|| |_|\n";
        cout << LightBLUE << " ---   ||       ||        ---    ||    || ||___  ||    ||    -           -      -      ---    ||    ||  .\n" << RESET;
        return true;
    }
    else {
        return false;
    }
}

bool winPl(Player& opponent) {
    if (opponent.getHealth() <= 0) {
        opponent.setHealth(10);
        cout << LightBLUE << " . ---   --        --     \\     //   .____  .___.         .            .  .___.  ._    _. ...\n";
        cout << LightBLUE << " ||   || ||      //  \\     \\   //   ||     ||   ||        \\          //  ||  ||  ||\\   || | |\n";
        cout << LightBLUE << " ||   || ||     //    \\      \||/    ||---  ||____||        \\  //\\   //   ||  ||  ||  \\ || | |\n";
        cout << LightBLUE << " ||---   ||    //------\\     ||     ||---  ||\\              \\//  \\ //    ||  ||  ||    \|| |_|\n";
        cout << LightBLUE << " ||      ||___//        \\    ||     ||___  ||  \\            -      -      ---    ||    ||  .\n" << RESET;
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

bool chooseMenu() {
    int index = 0; // Initialize the index to 0
    while (true) {
        system("CLS"); // Clear the screen
        printStart();
        
        cout << YELLOW << "~~~ Welcome to the CARD GAME ~~~" << RESET << endl;
        cout << endl;
        cout << "What do you want to do?" << endl;
        cout << endl;
        // Display menu options
        cout << (index == 0 ? GREEN : RESET) << "START" << RESET << setw(10);
        cout << (index == 1 ? RED : RESET) << "QUIT" << RESET << endl;

        // Get user input
        int c = _getch(); // Using _getch() to get arrow keys

        if (c == 224) { // Arrow keys are returned as two codes, first is 224
            c = _getch(); // Get the actual key code

            switch (c) {
            case KEY_LEFT:
                index = (index == 0) ? 1 : 0; // Toggle between 0 and 1
                break;
            case KEY_RIGHT:
                index = (index == 1) ? 0 : 1; // Toggle between 0 and 1
                break;
            }
        }
        else if (c == '\r') { // Enter key is pressed
        // Return true if "Start Game" is selected, false if "Exit" is selected
            if (index==0)
            {
                return (index == 0);
            }
            else
            {
                cout << endl;
                cout <<RED<< "BYE!"<<RESET << endl;
                system("pause");
            }
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

    if (chooseMenu() == false) {
        return 0;
    }
    showInstructions();
    printStart();
    cout << "Enter your name: ";
    cin >> name;
    cout << endl;
    player.setName(name);

    game(player, opponent, deck);

    return 0;
}
