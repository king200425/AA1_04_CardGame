#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

class Player {
private:
	// Atributos privados
	std::string name;
	std::vector<Card> hand;

public:
	// Constructor y m¨¦todos p¨²blicos
	Player(std::string playerName);

	// M¨¦todos para manejar las cartas del jugador
	void ReceiveCard(const Card card);

	// Devuelve la carta m¨¢s alta de la mano del jugador
	Card GetCard();

	Card GetCard(const Suit& suit);

	void SortCards();

	// Sobrecarga del operador de salida para imprimir la informaci¨®n del jugador
	friend std::ostream& operator<<(std::ostream& os, const Player& player);
};