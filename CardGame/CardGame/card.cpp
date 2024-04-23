#include "card.h"
#include <iostream>
#include <iomanip>

using namespace std;

// ANSI-codes for colors
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string BLUE = "\033[34m";
const string PURPLE = "\033[95m";
const string RESET = "\033[0m"; // reset standart color

Card::Card(const string& n, int m, int h) : name(n), mana(m), hit(h) {}

void Card::display() {
    const int frameWidth = 20;

    // top frame
    cout << "\n" << ".";
    cout << string(frameWidth - 3, '-') << ".\n";

    // centered tittle
    int center = (frameWidth - 2) / 2;
    cout << "|";
    cout << setw(center) << right << PURPLE; // change color
    cout << "CARD";
    cout << RESET; //reset to standart
    cout << setw(center) << " ";
    cout << "|\n";

    //middle frame
    cout << "." << string(frameWidth - 3, '-') << ".\n";

    // cards
    cout << "| Name: " << GREEN << setw(frameWidth - 10) << left << name << RESET << "|\n";
    cout << "| Mana: " << RED << setw(frameWidth - 10) << left << mana << RESET << "|\n";
    cout << "| Hit: " << RED << setw(frameWidth - 9) << left << hit << RESET << "|\n";

    //lower frame
    cout << "." << string(frameWidth - 3, '-') << ".\n";
}
