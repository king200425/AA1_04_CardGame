#include<iostream>
#include "Card.h"

using std::cout;
using std::endl;

int main() {
    cout << "=== TEST DE CARTAS ===" << endl;

    // Crear un par de cartas para probar
    Card c1 = { Suit::HEART, 10 };
    Card c2 = { Suit::SPADE, 10 };
    Card c3 = { Suit::CLUB, 12 };

    // Probar el operador << (Magia pura!)
    cout << "Carta 1: " << c1 << endl;
    cout << "Carta 2: " << c2 << endl;
    cout << "Carta 3: " << c3 << endl;

    // Probar el operador < (Lógica de empate)
    cout << "\n=== TEST DE COMPARACION ===" << endl;
    if (c2 < c1) {
        cout << c2 << " es menor que " << c1 << " (Funciona el desempate por palo!)" << endl;
    }

    if (c1 < c3) {
        cout << c1 << " es menor que " << c3 << " (Funciona la comparacion por valor!)" << endl;
    }

}