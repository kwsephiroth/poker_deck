#pragma once
#include <vector>
#include <iostream>
#include <unordered_set>
#include "Constants.h"
#include "Utils.h"
#include "PlayingCard.h"

namespace Poker
{
	class Deck
	{
	public:
		Deck();
		inline size_t size() { return m_deck.size(); }
		inline size_t max_size() { return MAX_PLAYING_CARDS; }
		void shuffle();
		std::unique_ptr<PlayingCard> deal_card();

	private:
		void initialize_deck();
		void clear_deck();
		void print_deck();

		std::vector<std::unique_ptr<PlayingCard>> m_deck;
	};
}

