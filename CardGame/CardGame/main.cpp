#include <iostream>
#include <cstdlib>
#include <ctime>

#include "main.h" // Підключаємо заголовний файл main.h
 
 using namespace std;

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    Player player;
    Opponent opponent;

    // Гра триває, поки один з гравців має здоров'я більше 0
    while (player.health > 0 && opponent.health > 0) {
        // Хід гравця
        player.discardCard();
        // Хід суперника
        opponent.discardCard();
    }

    // Визначення переможця
    if (player.health <= 0 && opponent.health <= 0) {
        cout << "Нічия!" << endl;
    } else if (player.health <= 0) {
        cout << "Суперник переміг!" << endl;
    } else {
        std::cout << "Гравець переміг!" << endl;
    }

    return 0;
}
