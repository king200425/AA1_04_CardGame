#include "Player.h"
#include <algorithm>
#include<cstdlib>

// Constructor del jugador, asigna el nombre
Player::Player(std::string playerName) {
    name = playerName;
}

// M¨¦todo para obtener la carta m¨¢s alta de un palo espec¨ªfico
void Player::SortCards() {
    std::sort(hand.begin(), hand.end());
}

// M¨¦todo para recibir una carta y agregarla a la mano del jugador
void Player::ReceiveCard(const Card card) {
	hand.push_back(card);  // Agregamos la carta a la mano del jugador
	SortCards(); // Ordenamos la mano despu¨¦s de recibir una nueva carta
}

// M¨¦todo para obtener la carta m¨¢s alta de la mano del jugador
Card Player::GetCard() {
	if (hand.empty()) {
        return { Suit::CLUB, 0 }; // Protecci¨®n por si no hay cartas
    }

    // Elegir un ¨ªndice aleatorio
    int randomIndex = std::rand() % hand.size();
    Card selectedCard = hand[randomIndex];

    // Borrar la carta de la mano usando su iterador
    hand.erase(hand.begin() + randomIndex);

    return selectedCard;
}

Card Player::GetCard(const Suit& suit) {
	// Buscar la carta m¨¢s alta del palo especificado
    for (int i = 0; i < hand.size(); ++i) {
        if (hand[i].suit == suit) {
            Card highestCard = hand[i];
            hand.erase(hand.begin() + i);
            return highestCard;
        }
    }
	return { Suit::CLUB, 0 };  // Si no se encuentra una carta del palo especificado, devolver una carta "vac¨ªa"
}

// Imprimir por pantalla el ID del jugador y sus cartas
std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Jugador: [" << player.name << "] \nMano: ";
    for (const auto& card : player.hand) {
        os << card << " ";
    }
    return os;
}

