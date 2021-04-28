#pragma once
#include <PlayingCard.h>
#include <string>

namespace Poker
{
	static std::string to_string(const Suit suit)
	{
		switch (suit)
		{
		case Suit::CLUBS:
			return "Clubs";
		case Suit::DIAMONDS:
			return "Diamonds";
		case Suit::HEARTS:
			return "Hearts";
		case Suit::SPADES:
			return "Spades";
		default:
			return "Unknown";
		}
	}

	static std::string to_string(const Rank face)
	{
		switch (face)
		{
		case Rank::ACE:
			return "Ace";
		case Rank::TWO:
			return "2";
		case Rank::THREE:
			return "3";
		case Rank::FOUR:
			return "4";
		case Rank::FIVE:
			return "5";
		case Rank::SIX:
			return "6";
		case Rank::SEVEN:
			return "7";
		case Rank::EIGHT:
			return "8";
		case Rank::NINE:
			return "9";
		case Rank::TEN:
			return "10";
		case Rank::JACK:
			return "Jack";
		case Rank::QUEEN:
			return "Queen";
		case Rank::KING:
			return "King";
		default:
			return "Unknown";
		}
	}

	static std::ostream& operator<<(std::ostream& os, const PlayingCard& pc)
	{
		os << to_string(pc.m_rank) << " of " << to_string(pc.m_suit);
		return os;
	}
}
