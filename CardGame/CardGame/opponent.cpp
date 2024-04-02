#include "opponent.h"
#include <iostream>
using namespace std;

Opponent::Opponent() {
    health = 20; // Початкове здоров'я
    // Створення початкової колоди з 20 картами
    for (int i = 0; i < 20; ++i) {
        int mana = rand() % 10 + 1; // Генерація випадкової мани від 1 до 10
        deck.push_back(Card(mana));
    }
}

void Opponent::discardCard() {
    if (!deck.empty()) {
        Card discardedCard = deck.back();
        deck.pop_back();
        health -= discardedCard.mana; // Зменшення здоров'я суперника на ману карти
        cout << "Суперник викидає карту з маною " << discardedCard.mana << endl;
    }
}
