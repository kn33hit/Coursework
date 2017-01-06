/****************************************************************
* File:    Hand.cpp
* Project: CMSC 202 Project 2, Spring 2014
* Author:  Jacob Lutz
* Date:    3/28/14
* Section: 08
* E-mail:  jlutz1@umbc.edu
*
*   This file contains the implementation of the Hand class.
*   The class manages the cards held by an individual player.
*
****************************************************************/

#include "Hand.h"
#include "Card.h"
#include <vector>
#include <iostream>
using namespace std;

// Hand
// Default Constructor
Hand::Hand()
{
    m_handValue = 0;
}

// AddCard
// Adds a new card to the player's hand
void Hand::AddCard(Card newCard)
{
    m_currentHand.push_back(newCard); 

    // check for ace
    // if new card is an ace, determine value to add in player's favor
    if (newCard.GetRank() == ACE) {
        if (m_handValue + ACE_ALT > BLACKJACK)
            m_handValue++;
        else
            m_handValue += ACE_ALT;
    }
    else
        m_handValue += newCard.GetBlackjackValue();
}

// PrintHand
// Prints out the player's current hand
void Hand::PrintHand()
{
    for (unsigned int card = 0; card < (m_currentHand.size() - 1); card++) {
        m_currentHand[card].OutputCard();
        cout << ", ";
    }
    // print most recent card separate
    // to prevent comma after last card
    PrintNewCard();
}

// PrintNewCard
// Prints out the player's newest card
void Hand::PrintNewCard()
{
    m_currentHand[m_currentHand.size() - 1].OutputCard();
}

// PrintDealerHand
// Prints out every card but the final
void Hand::PrintDealerHand()
{
    for (unsigned int card = 0; card < (m_currentHand.size() - 1); card++) {
        m_currentHand[card].OutputCard();
        cout << ", ";
    }
    cout << "[hidden card]";
}

// GetHandValue
// Returns the Blackjack value of a player's hand
int Hand::GetHandValue()
{
    return m_handValue;
}

// ClearHand
// Empties the player's current hand
void Hand::ClearHand()
{
    m_currentHand.clear();
    m_handValue = 0;
}