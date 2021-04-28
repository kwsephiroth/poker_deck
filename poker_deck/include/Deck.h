#pragma once
#include "Constants.h"
#include <vector>
#include <iostream>

namespace Poker
{
	enum class Suit
	{
		UNKNOWN = 0,
		HEARTS,
		SPADES,
		CLUBS,
		DIAMONDS
	};

	enum class Face
	{
		UNKNOWN = 0,
		ACE = 1,
		TWO = 2,
		THREE = 3,
		FOUR = 4,
		FIVE = 5,
		SIX = 6,
		SEVEN = 7,
		EIGHT = 8,
		NINE = 9,
		TEN = 10,
		JACK = 11,
		QUEEN = 12,
		KING = 13
	};

	struct PlayingCard
	{
		Suit m_suit = Suit::UNKNOWN;
		Face m_face = Face::UNKNOWN;
	};

	class Deck
	{
	public:
		Deck() = default;

		//TODO: Shuffle returns no value, but results in the cards in the deck being randomly permuted.Do not
		//use a library - provided shuffle function.You may use library - provided random number
		//generators.
		void shuffle();

		//TODO: this function should return one card from the deck to the caller.
		PlayingCard deal_card();

	private:
		void initialize_deck();
		void clear_deck();

		static const PlayingCard m_playing_cards[MAX_PLAYING_CARDS];
	};
}

