/*****************************************
** File: Hand.cpp
** Project: CMSC 202 Project 2, Fall 2014
** Author: Gregory Rossman ** Date: 10/19/14
** Section: 12
** E-mail: grossm1@umbc.edu
**
** This file contains the implementation of Hand class for Player class
** in Proj2 program to use.  The class defines the card hands of
** blackjack players and has methods to deal/add new cards, to output
** the current hand neatly, and to assess and return  the blackjack value
** of the hand currently.
**
**
***********************************************/






#include "Hand.h"
#include <iostream>

// Hand constructor
// initialize Hand with zero cards / zero aces in it, not busted yet
Hand::Hand()
    :m_numCards(0), m_busted(false), m_numAces(0)
{
}



// AddCard
// add given card to this hand's vector of cards
// if causes a bust, return true, otherwise false
bool Hand::AddCard(Card card, bool displayCard)
{
    // add card to hand's vector of cards
    m_numCards++;
    m_cards.push_back(card);

    // cout this card neatly, if displayCard true
    if(displayCard)
    {
	card.OutputCard();
	std::cout << std::endl;
    }

    // if this was an Ace, increment num of aces in hand
    if(card.GetBlackjackValue() == m_aceBaseValue)
	m_numAces++;

    // if player went bust, remember this fact, and return true
    if(GetHandValue() >  m_bustLimit )
    {
	m_busted = true;
	return true;
    }

    return false;
}



// OutputHand
// Neatly cout entire hand, listed, per instructions
// Example: "3 of Spades, Ace of Clubs" (no new line)
void Hand::OutputHand()
{
    // go through all cards in hand
    for(int i = 0; i < m_numCards; i++)
    {
	// if not the first card, put a comma & space before it
        if(i > 0)
	    std::cout << ", ";

	// cout the card, neatly, with no spaces before or after
	m_cards[i].OutputCard();
    }
}






// OutputHandExceptSecondCard
// cout all cards currently in hand, neatly listed per instructions,
// but hide second card with "[hidden card]"
// Example: "3 of Spades, [hidden card]"
void Hand::OutputHandExceptSecondCard()
{
    // go through all cards in hand
    for(int i = 0; i < m_numCards; i++)
    {
	// if not the first card, put a comma & space before it
        if(i > 0)
	    std::cout << ", ";


	// if second card, then hide it, otherwise
	// cout the card neatly, with no spaces/end-lines
	if(i==1)
	{
	    std::cout << "[hidden card]";
	}
	else
	{
	    m_cards[i].OutputCard();
	}
    }
}





// GetHandValue
// return the highest value possible for this hand without busting
// if it is impossible to not bust, then return lowest evaluation
// of hand.  if hand is blackjack, instead return zero
int Hand::GetHandValue()
{
    // add up all cards in hand, count Aces as 1,
    // to get minimum possible sum
    int sum = 0;
    for(int i = 0; i < m_numCards; i++)
    {
	sum += m_cards[i].GetBlackjackValue();
    }

    // if there's no way to not bust, return hand's min value
    if(sum > m_bustLimit)
	return sum;

    // For each ace in this hand...
    for(int j = 0; j < m_numAces; j++)
    {
	// add 10 to hand value to see what hand is worth if that
	// ace counted as 11 instead of 1
        sum += 10;

	// if busted, backtrack, count ace as 1, stop going thru aces
	if(sum > m_bustLimit)
	{
	    sum -= 10;
	    j = m_numAces;
	}
    } // sum is now the highest possible evaluation of hand without bust


    // if hand is blackjack, return 0
    if(m_numCards == 2 && m_numAces == 1 && sum == 21)
	return 0;

    // since hand wasn't blackjack and wasn't a bust
    return sum;
}













// GetBustedValue
// return m_busted to say whether player is busted or not
bool Hand::GetBustedValue() const
{
    return m_busted;
}
