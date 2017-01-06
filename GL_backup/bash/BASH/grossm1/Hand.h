/*****************************************
** File: Hand.h
** Project: CMSC 202 Project 2, Fall 2014
** Author: Gregory Rossman ** Date: 10/19/14
** Section: 12
** E-mail: grossm1@umbc.edu
**
** This file contains the declaration of Hand class for Player class
** in Proj2 program to use.  The class defines the card hands of
** blackjack players and has methods to deal/add new cards, to output
** the current hand neatly, and to assess and return  the blackjack value
** of the hand currently.
**
**
***********************************************/




#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand
{
  public:

    //-------------------------------------------------------
    // Name: Hand
    // PreCondition: none
    // PostCondition: Constructs a hand with 0 cards, 0 aces, not busted
    //---------------------------------------------------------
    Hand();

    //-------------------------------------------------------
    // Name: AddCard
    // PreCondition: card and displayCard must not be null
    // PostCondition: The card passed in will be added to this Hand's
    //     vector of cards, m_numCards incremented 1, m_numAces
    //     incremented 1 if it was an Ace. if player busted m_busted
    //     set true. if busted method returns true, otherwise false
    //     If displayCard param true, "card" is sent to cout, neatly
    //     formatted, with no white space before and one "\n" after it
    //---------------------------------------------------------
    bool AddCard(Card card, bool displayCard = true);

    //-------------------------------------------------------
    // Name: OutputHand
    // PreCondition: none
    // PostCondition: if any cards in hand, they are all printed as a
    //     neat list via cout,  with no white space before or after.
    //     Example: 3 of Spades, Ace of Clubs
    //---------------------------------------------------------
    void OutputHand();

    //-------------------------------------------------------
    // Name: OutputHandExceptSecondCard
    // PreCondition: none
    // PostCondition: if any cards in hand, they are all printed as a
    //     neat list via cout, except for the second card (if present)
    //     that was added to hand- this card is replaced with "[hidden]"
    //     Example 3 of Spades, [hidden]
    //     with no white space before or after list
    //---------------------------------------------------------
    void OutputHandExceptSecondCard();

    //-------------------------------------------------------
    // Name: GetHandValue
    // PreCondition: none
    // PostCondition: If hand is blackjack, zero is returned. Otherwise:
    //     If it is possible to count up total blackjack value of hand
    //     (counting aces as either 1 or 11 as needed) without busting,
    //     then the highest possible total value (that is short of
    //     busting) is returned. If impossible to not bust,the lowest
    //     possible evaluation/value for the hand is returned.
    //---------------------------------------------------------
    int GetHandValue();

    //-------------------------------------------------------
    // Name: GetBustedValue
    // PreCondition: none
    // PostCondition: returns m_busted (true if this hand has already
    //     busted by having a higher total value than m_bustLimit,
    //     false otherwise)
    //---------------------------------------------------------
    bool GetBustedValue() const;


  private:
    std::vector<Card> m_cards; // cards in Hand
    int m_numCards; // number of cards in hand
    bool m_busted; // to store true if hand is bust, false otherwise
    int m_numAces; // num of aces in this hand
    static const int m_bustLimit = 21; // hand value higher than this
                                       // then hand is a bust
    static const int m_aceBaseValue = 1; // value of ace given by Card
                        // class when GetBlackJackValue called for ace
};



#endif
