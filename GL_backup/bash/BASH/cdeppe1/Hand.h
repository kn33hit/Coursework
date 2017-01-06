/****************************************************************
 * File:    Hand.h
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Chandler Deppe
 * UMBC ID: OQ44374
 * Date:    3/22/14
 * Section: 05
 * E-mail:  cdeppe1@umbc.edu
 *
 *   This file contains the declaration for the Hand class.
 *   The class manages and implements the Hand class which oversees
 *   a hand which is a vector of cards.
 *
 ****************************************************************/

#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
  public:
    /****************************************************************
     * Name: Hand
     *   default (no-arg) constructor, does nothing
     * Preconditions: none
     * Postconditions: none
     ****************************************************************/
    Hand();

    /****************************************************************
     * Name: DisplayHand
     * Preconditions: 
     *   dealer--used to decide whether to hide the 2nd card
     * Postconditions: 
     *   the hand is outputted to the screen with the 2nd card hidden
     *     if dealer is true
     ****************************************************************/
    void DisplayHand(bool dealer);

    /****************************************************************
     * Name: AddCardToHand
     * Preconditions: card--a card object with a particular value and suit
     * Postconditions: the card is added to m_cards
     ****************************************************************/
    void AddCardToHand(Card card);

    /****************************************************************
     * Name: Clear
     * Preconditions: none
     * Postconditions: m_cards is cleared and size set to 0
     ****************************************************************/
    void Clear();

    /****************************************************************
     * Name: CountHand
     * Preconditions: none
     * Postconditions:
     *   returns: the score from the hand
     ****************************************************************/
    int CountHand();

    /****************************************************************
     * Name: CheckBlackjack
     * Preconditions: score - a players score
     * Postconditions: 
     *   returns: whether or not a player has blackjack
     ****************************************************************/
    bool CheckBlackjack(int score);
  private:

    std::vector<Card> m_cards;
    bool m_blackjack;
};

#endif
