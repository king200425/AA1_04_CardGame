#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Card.h"

class Game {
private:
	int numPlayers;           // N¨²mero de jugadores en el juego
	std::vector<Player> players; // Vector de jugadores en el juego
	std::vector<Card> deck;      // Baraja de cartas
	std::vector<Card> discarded; // Pila de descarte

public:
	Game(int numberOfPlayers); // Constructor para inicializar el juego con un n¨²mero espec¨ªfico de jugadores

	Card GetNewCard(); // M¨¦todo para obtener una nueva carta de la baraja

	void DiscardCard(const Card& card);// M¨¦todo para descartar una carta en la pila de descarte

	void PrintDiscarded() const; // M¨¦todo para mostrar las cartas descartadas

	void PrintGameState() const; // M¨¦todo para mostrar el estado actual del juego, incluyendo los jugadores y sus cartas
};