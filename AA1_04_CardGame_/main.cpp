#include<iostream>
#include <ctime>
#include <cstdlib>
#include "Game.h"

using std::cout;
using std::endl;

int main() {
	// Semilla para generar n¨²meros aleatorios
    std::srand(static_cast<unsigned>(time(nullptr)));

    cout << "=== TEST DE JUGADOR Y STL VECTOR ===" << endl;

	Game myGame(3); // Creamos un juego con 3 jugadores

	// Imprimimos el estado inicial del juego
	myGame.PrintGameState();
}