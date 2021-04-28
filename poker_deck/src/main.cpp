#include <iostream>
#include "../include/Deck.h"

int main()
{
	Poker::Deck deck;
	std::cout << "Starting Deck (size = " << deck.size() << "):\n";
	deck.print(); std::cout << "\n";
	deck.shuffle();
	std::cout << "Shuffled Deck (size = " << deck.size() << "):\n";
	deck.print(); std::cout << "\n";
	auto dealt_cards = deck.deal_cards(52);
	for (const auto& dealt_card : dealt_cards)
	{
		if(dealt_card)
			std::cout << "Dealt Card: " << *dealt_card << "\n";
	}
	std::cout << "\n";
	std::cout << "Deck After Dealing Cards (size = " << deck.size() << "):\n";
	deck.print(); std::cout << "\n";
	auto dealt_card = deck.deal_card();
	if (dealt_card)
	{
		std::cout << "Dealt Card: " << *dealt_card << "\n";
	}
	else
	{
		std::cout << "No more cards left in deck.\n";
	}

	return 0;
}