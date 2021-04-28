#pragma once
#include "PlayingCard.h"
#include <string>

namespace Poker
{
	static std::string suit_to_string(const Suit suit)
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

	static std::string face_to_string(const Face face)
	{
		switch (face)
		{
		case Face::ACE:
			return "Ace";
		case Face::TWO:
			return "2";
		case Face::THREE:
			return "3";
		case Face::FOUR:
			return "4";
		case Face::FIVE:
			return "5";
		case Face::SIX:
			return "6";
		case Face::SEVEN:
			return "7";
		case Face::EIGHT:
			return "8";
		case Face::NINE:
			return "9";
		case Face::TEN:
			return "10";
		case Face::JACK:
			return "Jack";
		case Face::QUEEN:
			return "Queen";
		case Face::KING:
			return "King";
		default:
			return "Unknown";
		}
	}

	static std::ostream& operator<<(std::ostream& os, const PlayingCard& pc)
	{
		os << face_to_string(pc.m_face) << " of " << suit_to_string(pc.m_suit);
		return os;
	}
}
