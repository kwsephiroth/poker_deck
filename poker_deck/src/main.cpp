#include <iostream>
#include "../include/Deck.h"

int main()
{
	Poker::Deck deck;
	deck.shuffle();
	deck.shuffle();
	deck.shuffle();

	for (int i = 0; i < 53; ++i)
	{
		auto dealt_card = deck.deal_card();
		if(dealt_card)
			std::cout << "Dealt Card = " << *dealt_card << std::endl;
	}
	return 0;
}