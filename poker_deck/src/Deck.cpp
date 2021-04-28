#include "..\include\Deck.h"

namespace Poker
{
	Deck::Deck()
	{
		initialize_deck();
	}

	void Deck::initialize_deck()
	{
		//Generate random deck of playing cards using available playing cards.
		std::unordered_set<int> random_suit_indices;
		std::unordered_set<int> random_rank_indices;

		static const Suit suits[MAX_SUITS] = { Suit::CLUBS, Suit::DIAMONDS, Suit::HEARTS, Suit::SPADES };
		static const Rank ranks[MAX_RANKS] = { Rank::ACE, Rank::TWO, Rank::THREE, Rank::FOUR, Rank::FIVE, Rank::SIX, 
										Rank::SEVEN, Rank::EIGHT, Rank::NINE, Rank::TEN, Rank::JACK, Rank::QUEEN, Rank::KING };

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

	void Deck::clear_deck()
	{
		m_deck.clear();
	}

	void Deck::print_deck()
	{
		for (const auto& playing_card : m_deck)
		{
			std::cout << *playing_card << std::endl;
		}
	}

	void Deck::shuffle()
	{
		auto n = m_deck.size();
		for (size_t i = 0; i < n - 1; i++)
		{
			// generate a random number `j` such that `i <= j < n` and
			// swap the element present at index `j` with the element
			// present at current index `i`
			int j = i + rand() % (n - i);
			std::swap(m_deck[i], m_deck[j]);
		}
		print_deck(); std::cout << "\n";
	}

	std::unique_ptr<PlayingCard> Deck::deal_card()
	{
		std::unique_ptr<PlayingCard> dealt_card = nullptr;
		
		if (!m_deck.empty())
		{
			dealt_card = std::move(m_deck.front());
			m_deck.erase(m_deck.begin());
		}

		return dealt_card;
	}
}
