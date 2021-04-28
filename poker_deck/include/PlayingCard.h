#pragma once
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

		friend std::ostream& operator<<(std::ostream& os, const PlayingCard& pc);
	};
}

