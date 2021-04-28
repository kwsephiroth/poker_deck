#include "..\include\Deck.h"

namespace Poker
{
	Deck::Deck()
	{
		initialize();
	}

	void Deck::initialize()
	{
		//Generate random deck of playing cards using available playing cards.
		std::unordered_set<int> random_suit_indices;
		std::unordered_set<int> random_rank_indices;

		static const Suit suits[MAX_SUITS] = { Suit::CLUBS, Suit::DIAMONDS, Suit::HEARTS, Suit::SPADES };
		static const Rank ranks[MAX_RANKS] = { Rank::ACE, Rank::TWO, Rank::THREE, Rank::FOUR, Rank::FIVE, Rank::SIX, Rank::SEVEN,
										       Rank::EIGHT, Rank::NINE, Rank::TEN, Rank::JACK, Rank::QUEEN, Rank::KING };

		//Compile sets of unique indices
		srand(time(0));
		while (random_suit_indices.size() < MAX_SUITS) random_suit_indices.insert(rand() % MAX_SUITS);
		while (random_rank_indices.size() < MAX_RANKS) random_rank_indices.insert(rand() % MAX_RANKS);

		for (const auto suit_index : random_suit_indices)
		{
			for (const auto rank_index : random_rank_indices)
			{
				m_deck.emplace_back(std::make_unique<PlayingCard>(suits[suit_index], ranks[rank_index]));
			}
		}
	}

	void Deck::clear()
	{
		m_deck.clear();
	}

	void Deck::print()
	{
		for (const auto& playing_card : m_deck)
		{
			std::cout << *playing_card << std::endl;
		}
	}

	void Deck::shuffle()//using Fisher–Yates shuffle algorithm
	{
		auto n = m_deck.size();
		for (size_t i = 0; i < n - 1; i++)
		{
			int j = i + rand() % (n - i);
			std::swap(m_deck[i], m_deck[j]);
		}
	}

	std::unique_ptr<PlayingCard> Deck::deal_card()
	{
		std::unique_ptr<PlayingCard> dealt_card = nullptr;
		
		if (!m_deck.empty())
		{
			dealt_card = std::move(m_deck.front());
			m_deck.pop_front();
		}

		return dealt_card;
	}

	std::vector<std::unique_ptr<PlayingCard>> Deck::deal_cards(const unsigned int number_of_cards)
	{
		unsigned int card_count = 0;
		if (number_of_cards >= m_deck.size())
			card_count = m_deck.size();
		else
			card_count = number_of_cards;

		std::vector<std::unique_ptr<PlayingCard>> dealt_cards;
		for (unsigned int i = 0; i < card_count; ++i)
		{
			dealt_cards.push_back(deal_card());
		}
	
		return dealt_cards;
	}

	std::unique_ptr<PlayingCard> Deck::deal_card_from_bottom()
	{
		std::unique_ptr<PlayingCard> dealt_card = nullptr;

		if (!m_deck.empty())
		{
			dealt_card = std::move(m_deck.back());
			m_deck.pop_back();
		}

		return dealt_card;
	}

	std::unique_ptr<PlayingCard> Deck::deal_card_from_position(const unsigned int position)
	{
		if (position >= m_deck.size() || m_deck.empty())
			return nullptr;

		std::unique_ptr<PlayingCard> dealt_card = std::move(m_deck.at(position));
		m_deck.erase(m_deck.begin() + position);

		return dealt_card;
	}
	
	void Deck::replace_card(std::unique_ptr<PlayingCard> playing_card)
	{
		if (m_deck.size() < max_size())
			m_deck.push_front(std::move(playing_card));
	}

	void Deck::replace_cards(std::vector<std::unique_ptr<PlayingCard>>& playing_cards)
	{
		if (m_deck.size() < max_size())
		{
			for(auto itr = playing_cards.begin(); itr != playing_cards.end();)
			{
				m_deck.push_front(std::move(*itr));
				itr = playing_cards.erase(itr);//remove replaced card from hand
				if (m_deck.size() >= max_size())
					return;
			}
		}
	}

	void Deck::place_card_on_bottom(std::unique_ptr<PlayingCard> playing_card)
	{
		if(m_deck.size() < max_size())
			m_deck.push_back(std::move(playing_card));
	}

	void Deck::place_card_in_position(std::unique_ptr<PlayingCard> playing_card, const unsigned int position)
	{
		if (position >= m_deck.size())
			return;

		if (m_deck.size() < max_size())
			m_deck.insert(m_deck.begin() + position, std::move(playing_card));
	}
}
