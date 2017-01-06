/****************************************************************
* File:    Hand.h
* Project: CMSC 202 Project 2, Spring 2014
* Author:  Jacob Lutz
* Date:    3/28/14
* Section: 08
* E-mail:  jlutz1@umbc.edu
*
*   This file contains the declaration for the Hand class.
*   The class manages the cards held by an individual player.
*
****************************************************************/

#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"
using namespace std;

// global constants
const int BLACKJACK = 21;   // value of blackjack                                                                                                                   
const int ACE_ALT   = 11;   // alternate value of ace (either 1 or 11)

class Hand
{

public:

    /****************************************************************
    * Name: Hand
    *   Default Constructor
    * Preconditions:
    *   None
    * Postconditions:
    *   Creates a new empty hand
    ****************************************************************/
    Hand();

    /****************************************************************
    * Name: AddCard
    *   Adds a card to the player's hand
    * Preconditions:
    *   newCard -- the card object which will be added to m_currentHand
    * Postconditions:
    *   stores newCard as a new entry in m_currentHand
    ****************************************************************/
    void AddCard(Card newCard);

    /****************************************************************
    * Name: PrintHand
    *   Prints the current hand to the screen
    * Preconditions:
    *   None
    * Postconditions:
    *   Prints every card in m_currentHand
    ****************************************************************/
    void PrintHand();

    /****************************************************************
    * Name: PrintHand
    *   Prints the most recent card to the screen
    * Preconditions:
    *   None
    * Postconditions:
    *   Prints the newest card in m_currentHand
    ****************************************************************/
    void PrintNewCard();

    /****************************************************************
    * Name: PrintDealerHand
    *   Print's the dealer's current hand to the screen
    * Preconditions:
    *   None
    * Postconditions:
    *   Prints every card in m_currentHand except for the last one
    ****************************************************************/
    void PrintDealerHand();

    /****************************************************************
    * Name: GetHandValue
    *   Returns the current Blackjack value of the hand
    * Preconditions:
    *   None
    * Postconditions:
    *   returns the value as an int
    ****************************************************************/
    int GetHandValue();

    /****************************************************************
    * Name: ClearHand
    *   Empties the player's hand
    * Preconditions:
    *   None
    * Postconditions:
    *   m_currentHand will contain no elements
    ****************************************************************/
    void ClearHand();

private:

    vector<Card> m_currentHand; // a collection of the player's current cards
    int m_handValue;            // the total Blackjack value of the hand

};

#endif
