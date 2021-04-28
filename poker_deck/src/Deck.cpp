#include "..\include\Deck.h"

namespace Poker
{
	const PlayingCard Deck::m_playing_cards[MAX_PLAYING_CARDS] =
	{
		{Suit::CLUBS, Face::ACE},
		{Suit::CLUBS, Face::TWO},
		{Suit::CLUBS, Face::THREE},
		{Suit::CLUBS, Face::FOUR},
		{Suit::CLUBS, Face::FIVE},
		{Suit::CLUBS, Face::SIX},
		{Suit::CLUBS, Face::SEVEN},
		{Suit::CLUBS, Face::EIGHT},
		{Suit::CLUBS, Face::NINE},
		{Suit::CLUBS, Face::TEN},
		{Suit::CLUBS, Face::JACK},
		{Suit::CLUBS, Face::QUEEN},
		{Suit::CLUBS, Face::KING},

		{Suit::DIAMONDS, Face::ACE},
		{Suit::DIAMONDS, Face::TWO},
		{Suit::DIAMONDS, Face::THREE},
		{Suit::DIAMONDS, Face::FOUR},
		{Suit::DIAMONDS, Face::FIVE},
		{Suit::DIAMONDS, Face::SIX},
		{Suit::DIAMONDS, Face::SEVEN},
		{Suit::DIAMONDS, Face::EIGHT},
		{Suit::DIAMONDS, Face::NINE},
		{Suit::DIAMONDS, Face::TEN},
		{Suit::DIAMONDS, Face::JACK},
		{Suit::DIAMONDS, Face::QUEEN},
		{Suit::DIAMONDS, Face::KING},

		{Suit::HEARTS, Face::ACE},
		{Suit::HEARTS, Face::TWO},
		{Suit::HEARTS, Face::THREE},
		{Suit::HEARTS, Face::FOUR},
		{Suit::HEARTS, Face::FIVE},
		{Suit::HEARTS, Face::SIX},
		{Suit::HEARTS, Face::SEVEN},
		{Suit::HEARTS, Face::EIGHT},
		{Suit::HEARTS, Face::NINE},
		{Suit::HEARTS, Face::TEN},
		{Suit::HEARTS, Face::JACK},
		{Suit::HEARTS, Face::QUEEN},
		{Suit::HEARTS, Face::KING},

		{Suit::SPADES, Face::ACE},
		{Suit::SPADES, Face::TWO},
		{Suit::SPADES, Face::THREE},
		{Suit::SPADES, Face::FOUR},
		{Suit::SPADES, Face::FIVE},
		{Suit::SPADES, Face::SIX},
		{Suit::SPADES, Face::SEVEN},
		{Suit::SPADES, Face::EIGHT},
		{Suit::SPADES, Face::NINE},
		{Suit::SPADES, Face::TEN},
		{Suit::SPADES, Face::JACK},
		{Suit::SPADES, Face::QUEEN},
		{Suit::SPADES, Face::KING},
	};


	Deck::Deck()
	{
		initialize_deck();
	}

	void Deck::initialize_deck()
	{
		//Generate random deck of playing cards using available playing cards.
		std::unordered_set<int> random_indices;//Stores unique random indices.

		srand(time(0));
		while (random_indices.size() < MAX_PLAYING_CARDS) random_indices.insert(rand() % MAX_PLAYING_CARDS);

		for (const auto index : random_indices)
		{
			m_deck.push_back(std::make_unique<PlayingCard>(m_playing_cards[index]));
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
		for (int i = 0; i < n - 1; i++)
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
