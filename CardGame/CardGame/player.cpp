#include "player.h"
#include <iostream>
#include <conio.h>
#include "main.h"

#define KEY_UP 72
#define KEY_DOWN 80

const string RED = "\033[31m";
const string LightBLUE = "\033[96m";
const string RESET = "\033[0m";


void Player::setHealth(int newHealth) {
    health = newHealth;
}

int Player::getHealth() {
    return health;
}

int Player::getManaNow() {
    return manaNow;
}

void Player::setName(string newName) {
    name = newName;
}

Player::Player() : health(20), manaNow(10) {
}

Card Player::playerChooseCard(Player& player, Player& opponent) {
    size_t index = 0;


    while (true) {
        // Clear the screen or move cursor to show only updated parts
        system("CLS"); // Note: This is platform dependent, and might need alternatives for non-Windows systems.
        printStart();
        displayDeck(index, player, opponent);


        // Get user input
        int c = _getch(); // Using _getch() to get arrow keys

        if (c == 224) { // Arrow keys are returned as two codes, first is 224
            c = _getch(); // Get the actual key code

            switch (c) {
            case KEY_UP:
                if (index > 0) {
                    index--; // Move up in the deck
                }
                break;
            case KEY_DOWN:
                if (index < playerDeck.size() - 1) {
                    index++; // Move down in the deck
                }
                break;
            }
        }
        else if (c == '\r') { // Enter key is pressed
            if (playerDeck[index].mana <= manaNow) {
                // Return the chosen card if valid
                return playerDeck[index];
            }
            else {
                cout << "Insufficient mana for the selected card. Choose another card." << endl;
            }
        }
    }
}


void Player::discardCard(Player& pl, Player& op, Card chosenCard) {
    if (!playerDeck.empty()) {
        Card discardedCard = playerDeck.back();
        playerDeck.pop_back();
        pl.manaNow -= chosenCard.mana;
        op.health -= chosenCard.hit;
        if (op.health < 0) {
            op.health = 0;
        }
        if (pl.manaNow < 10) {
            pl.manaNow += 3;
            if (pl.manaNow > 10) {
                pl.manaNow = 10;
           }
        }
    }
}

void Player::displayDeck(size_t selectedIndex, Player& player, Player& opponent) {
   
    displayStats(player, opponent);
    if (playerDeck.empty()) {
        cout << "Empty" << endl;
        return;
    }
    for (size_t i = 1; i < playerDeck.size(); ++i) {
        if (i == selectedIndex) {
            cout << "\n" << i << ": ";
            playerDeck[i].display(true);
        }
        else {
            cout << "\n" << i << ": ";
            playerDeck[i].display(false);
        }
    }
}

void Player::displayStats(Player& pl, Player& op) {
    cout << pl.name << endl;
    cout << "Health: " << pl.health << endl;
    cout << "Mana: " << pl.manaNow << endl;

    cout << "Opponent" << endl;
    cout << "Health: " << op.health << endl;
    cout << "Mana: " << op.manaNow << endl;
}

void Player::addCardsFromDeck(Deck& mainDeck) {
    // Add cards from the main deck to the player's deck until it reaches 5 cards or the main deck is empty
    while (playerDeck.size() < 6 && !mainDeck.getCards().empty()) {
        playerDeck.push_back(mainDeck.getCards().back());
        mainDeck.getCards().pop_back();
    }
}

Card Player::opponentChooseCard() {
    size_t index = 0;



}
