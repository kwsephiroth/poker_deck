#include <iostream>
#include <Deck.h>

int main()
{
	Poker::Deck deck;

	std::cout << "Starting Deck (size = " << deck.size() << "):\n";
	deck.print();

	deck.shuffle();
	std::cout << "\nShuffled Deck (size = " << deck.size() << "):\n";
	deck.print();

	std::cout << "\nDealing 52 cards to Hand...\n";
	auto hand = deck.deal_cards(52);//Executes 52 calls to deal_card function on this deck.
	std::cout << "\nHand (size = " << hand.size() << "):\n";
	for (const auto& card : hand)
	{
		if(card)
			std::cout << *card << "\n";
	}

	std::cout << "\nDeck After Dealing Cards (size = " << deck.size() << "):\n";
	deck.print();

	std::cout << "\nDealing 1 card to Hand.\n";
	auto dealt_card = deck.deal_card();//Executes the 53rd call to deal_card function on this deck.

	if (dealt_card)
	{
		hand.push_back(std::move(dealt_card));
		std::cout << "\nHand (size = " << hand.size() << "):\n";
		for (const auto& card : hand)
		{
			if (card)
				std::cout << *card << "\n";
		}
	}
	else
	{
		std::cout << "\nNo more cards left in deck.\n";
	}

	//deck.replace_cards(hand);
	//std::cout << "\nDeck After Replacing Cards (size = " << deck.size() << "):\n"; 
	//deck.print();

	//std::cout << "\nHand (size = " << hand.size() << "):\n";
	//for (const auto& dealt_card : hand)
	//{
	//	if (dealt_card)
	//		std::cout << "Dealt Card: " << *dealt_card << "\n";
	//}

	return 0;
}