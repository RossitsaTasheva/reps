// Fig. 8.27: main.cpp
// Card shuffling and dealing program.

#include "DeckOfCards.h"

int main() {
	DeckOfCards deckOfCards; // create DeckOfCards object
	deckOfCards.shuffle(); // разбъркване
	deckOfCards.deal(); // роздава 5 карти

	cout << endl;
	cout << endl;
	cout << "1 Има ли двоика : ";
	cout << endl << deckOfCards.isPair() << endl;
	cout << "2 Има ли две двоики.";
	cout << endl << deckOfCards.towPair() << endl;
	cout << "3 Определете дали ръката съдържа три от един вид";
	cout << endl << deckOfCards.threeOfKind() << endl;
	cout << "4 Определете дали ръката съдържа четири от един вид";
	cout << endl << deckOfCards.fourOfKind() << endl;
	cout << "5 Определете дали ръката съдържа флъш ";
	cout << endl << deckOfCards.flush() << endl;
	cout << "6 Определете дали съдържа стрейт ";
	cout << endl << deckOfCards.straight() << endl;

	return 0;
}
