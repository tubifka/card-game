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

void Card::display(bool selected) {
    const int frameWidth = 20;
    const string color = selected ? GREEN : RESET;

    // top frame
    cout << "\n" << ".";
    cout << color << string(frameWidth - 3, '-') << ".\n";

    // centered title
    int center = (frameWidth - 2) / 2;
    cout << color << "|";
    cout << setw(center) << right << PURPLE; // change color
    cout << "CARD";
    cout << color; // reset to standard
    cout << setw(center) << " ";
    cout << "|\n";
   
    // middle frame
    cout << "." << string(frameWidth - 3, '-') << ".\n";

    // cards
    cout << "| Name: " << BLUE << setw(frameWidth - 10) << left << name  << RESET << color << "|\n";
    cout << "| Mana: " << setw(frameWidth - 10) << left << mana << "|\n";
    cout << "| Hit: "  << setw(frameWidth - 9) << left << hit << "|\n";

    // lower frame
    cout << "." << string(frameWidth - 3, '-') << ".\n";
    cout << RESET;
}
