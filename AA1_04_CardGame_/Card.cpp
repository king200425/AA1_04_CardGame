#include "Card.h"

bool Card::operator<(const Card& other) const {
	//Primero comparamos el valor (n¨²mero)
	if (this->value != other.value) {
		return this->value < other.value;
	}
	//Si hay empate, comparamos el palo
	return this->suit < other.suit;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
	os << "[" << card.value << ", ";

	//Imprimir el nombre del palo en texto
	switch (card.suit) {
	case Suit::HEART:os << "HEART"; break;
	case Suit::DIAMOND:os << "DIAMOND"; break;
	case Suit::SPADE:os << "SPADE"; break;
	case Suit::CLUB:os << "CLUB"; break;
	}
	os << "]";

	return os;
}