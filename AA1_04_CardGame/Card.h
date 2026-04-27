#pragma once
#include<iostream>

enum class Suit {
	CLUB = 1,
	SPADE = 2,
	DIAMOND = 3,
	HEART = 4
};

struct Card {
	Suit suit;  // Palo
	int value;  // Valor de 1 a 13
	bool operator<(const Card& other) const;
};

std::ostream& operator<<(std::ostream& os, const Card& card); #pragma once
