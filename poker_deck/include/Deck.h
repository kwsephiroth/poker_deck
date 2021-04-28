#pragma once
#include <vector>
#include <deque>
#include <iostream>
#include <unordered_set>
#include <Constants.h>
#include <Utils.h>
#include <PlayingCard.h>

namespace Poker
{
	class Deck
	{
	public:
		Deck();
		inline size_t max_size() { return MAX_PLAYING_CARDS; }
		size_t size() const { return m_deck.size(); }
		bool empty() const { return m_deck.empty(); }
		void shuffle();
		std::unique_ptr<PlayingCard> deal_card();
		std::vector<std::unique_ptr<PlayingCard>> deal_cards(const unsigned int number_of_cards);
		std::unique_ptr<PlayingCard> deal_card_from_bottom();
		std::unique_ptr<PlayingCard> deal_card_from_position(const unsigned int position);
		void replace_card(std::unique_ptr<PlayingCard> playing_card);//Place card on top of deck.
		void replace_cards(std::vector<std::unique_ptr<PlayingCard>>& playing_cards);
		void place_card_on_bottom(std::unique_ptr<PlayingCard> playing_card);
		void place_card_in_position(std::unique_ptr<PlayingCard> playing_card, const unsigned int position);
        void print();
	
	private:
		void initialize();
		void clear();
	
		std::deque<std::unique_ptr<PlayingCard>> m_deck;
	};
}

