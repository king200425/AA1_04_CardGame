#include<iostream>
#include <ctime>
#include <cstdlib>
#include "Card.h"
#include "Player.h"

using std::cout;
using std::endl;

int main() {
	// Semilla para generar n¨²meros aleatorios
    std::srand(static_cast<unsigned>(time(nullptr)));

    cout << "=== TEST DE JUGADOR Y STL VECTOR ===" << endl;

	// Crear un jugador con un nombre espec¨ªfico
    Player p1("Yikai");

	// Mostrar el estado inicial del jugador
    cout << "> Repartiendo cartas..." << endl;
    p1.ReceiveCard({ Suit::CLUB, 5 });
    p1.ReceiveCard({ Suit::HEART, 10 });
    p1.ReceiveCard({ Suit::SPADE, 10 });
    p1.ReceiveCard({ Suit::DIAMOND, 13 });
    p1.ReceiveCard({ Suit::HEART, 2 });

	// Mostrar el estado del jugador despu¨¦s de recibir las cartas
    cout << "\n> Estado del jugador tras recibir las cartas:" << endl;
    cout << p1 << endl;

	// Probar el m¨¦todo GetCard() para obtener una carta aleatoria
    cout << "\n> El jugador tira una carta aleatoria..." << endl;
    Card randomCard = p1.GetCard();
    cout << "Carta tirada: " << randomCard << endl;
    cout << p1 << " (Fijate que ya no tiene la carta tirada!)" << endl;

	// Probar el m¨¦todo GetCard(Suit) para obtener la carta m¨¢s alta de un palo espec¨ªfico
    cout << "\n> Pidiendo la carta mas alta de HEART..." << endl;
    Card bestHeart = p1.GetCard(Suit::HEART);
    cout << "Carta entregada: " << bestHeart << endl;
    cout << p1 << " (Fijate que se le resto a la mano!)" << endl;

}