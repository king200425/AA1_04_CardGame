#include "Game.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using std:: cout;
using std::endl;

Game::Game(int numberOfPlayers) {
	// Validamos el n¨²mero de jugadores, asegurando que est¨¦ entre 2 y 8
	if (numberOfPlayers < 2) numPlayers = 2;
	// Aseguramos que haya al menos 2 jugadores
	else if (numberOfPlayers > 8) numPlayers = 8; // Limitamos a un m¨¢ximo de 8 jugadores
	else numPlayers = numberOfPlayers;

	for(int i = 0; i < numPlayers; ++i) {
		players.emplace_back("Player_ " + std::to_string(i + 1)); // Creamos jugadores con nombres "Player 1", "Player 2", etc.
	}

	// Inicializamos la baraja de cartas
	Suit suits[] = { Suit::HEART, Suit::DIAMOND, Suit::SPADE, Suit::CLUB };
	for (Suit s : suits) {
		for (int value = 1; value <= 13; ++value) {
			deck.push_back({ s, value });
		}
	}

	// Semilla para la generaci¨®n de n¨²meros aleatorios
	std::random_shuffle(deck.begin(), deck.end()); // Barajamos la baraja de cartas

	for(int round = 0; round < 10; ++round) { // Repartimos 10 cartas a cada jugador
		for(int i = 0; i < numPlayers; ++i) {
			if (!deck.empty()) {
				Card drawnCard = GetNewCard(); // Obtenemos una carta de la baraja
				players[i].ReceiveCard(drawnCard); // La damos al jugador	
			}
		}
	}
}

Card Game::GetNewCard() {
	if (deck.empty()) {
		return { Suit::CLUB, 0 };
	}

	Card topCard = deck.back();
	deck.pop_back(); // La removemos de la baraja
	return topCard;
}

// M¨¦todo para descartar una carta en la pila de descarte
void Game::DiscardCard(const Card& card) {
	discarded.push_back(card);
}

void Game::PrintDiscarded() const {
	if (discarded.empty()) {
				std::cout << "[INFO] El pilon de descartes esta vacio."<<endl;
	}
	else {
		std::cout << "[DESCARTADA] La ultima carta jugada es: " << discarded.back() << endl;
	}
}

// M¨¦todo para mostrar el estado actual del juego, incluyendo los jugadores y sus cartas
void Game::PrintGameState() const {
	cout << "\n================ ESTADO DEL JUEGO ================"<<endl;
	cout << "Cartas restantes en el mazo: " << deck.size() << endl;
	cout << "Cartas en el pilon de descartes: " << discarded.size() << endl;
	PrintDiscarded();
	cout << "--------------------------------------------------"<<endl;
	for (const auto& player : players) {
		cout << player << endl;
	}
	cout << "==================================================\n";
}