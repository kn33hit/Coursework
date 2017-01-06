/*****************************************
** File: Player.h
** Project: CMSC 202 Project 2, Fall 2014
** Author: Gregory Rossman ** Date: 10/19/14
** Section: 12
** E-mail: grossm1@umbc.edu
**
** This file contains the declaration of Player class for Blackjack class
** in Proj2 program to use.  The class defines players in a blackjack
** game, who have hands (of cards), current funds and bet levels,
** and names (or rather pointers to names).  Class also handles
** indirectly the outputting of hand info.
**
**
***********************************************/




#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"

class Player
{
  public:

    //-------------------------------------------------------
    // Name: Player (default constructor)
    // PreCondition: none
    // PostCondition: constructs "dummy" player, with no data values set
    //---------------------------------------------------------
    Player();

    //-------------------------------------------------------
    // Name: Player (standard constructor)
    // PreCondition: char *name and int funds must not be null and
    //     char *name must point to a valid c-string
    // PostCondition: constructs a player with m_name that points to the
    //     c-string/name found at char *name, and m_funds set to funds
    //---------------------------------------------------------
    Player(char *name, int funds = 0);

    //-------------------------------------------------------
    // Name: GetName
    // PreCondition: this player's m_name must not be null (so this
    //     player must have been constructed with standard constructor)
    // PostCondition: returns pointer to name of player
    //---------------------------------------------------------
    char *GetName() const;

    //-------------------------------------------------------
    // Name: GetFunds
    // PreCondition: this player's m_funds must not be null (so either
    //     this player must have been constructed with standard
    //     constructor OR SetFunds was used prior to give m_funds value)
    // PostCondition: returns player's current funds
    //---------------------------------------------------------
    int GetFunds() const;

    //-------------------------------------------------------
    // Name: SetFunds
    // PreCondition: newFunds param must not be null
    // PostCondition: sets player's funds (m_funds) equal to newFunds
    //---------------------------------------------------------
    void SetFunds(int newFunds = 0);

    //-------------------------------------------------------
    // Name: SetBet
    // PreCondition: amt param must not be null
    // PostCondition: sets player's current bet (m_betThisRound) to equal
    //     amt, and if the bet exceeds current funds, returns false,
    //     otherwise returns true
    //---------------------------------------------------------
    bool SetBet(int amt = 0);

    //-------------------------------------------------------
    // Name: AddCardToHand
    // PreCondition: card and displayCard must not be null and pre-
    //     conditions of Hand class's AddCard method must be met
    // PostCondition: Hand class's AddCard method is called on the
    //     hand object had by this player and value of that method is
    //     returned by this method. this should add card to
    //     vector of cards in hand, change Hand object's m_busted value
    //     to true if player had now busted, or keep it false otherwise,
    //     print the card to screen neatly formatted if displayCard true
    //     and returns true if player is now busted, false otherwise
    //---------------------------------------------------------
    bool  AddCardToHand(Card card, bool displayCard = true);

    //-------------------------------------------------------
    // Name: OutputHand
    // PreCondition: must meet pre-conditions of Hand::OutputHand
    //     currently none)
    // PostCondition: Hand::OutputHand method is called on this player's
    //     hand, so hand is printed via cout neatly as a list
    //---------------------------------------------------------
    void OutputHand();

    //-------------------------------------------------------
    // Name: OutputHandExceptSecondCard
    // PreCondition: must meet pre-conditions of
    //     Hand::OutputHandExceptSecondCard (currently none)
    // PostCondition: Hand::OutputHandExceptSecondCard is called on this
    //     player's hand, so hand is printed via cout neatly as a list,
    //     but with second card in hand hidden in printing
    //---------------------------------------------------------
    void OutputHandExceptSecondCard();

    //-------------------------------------------------------
    // Name: GetBustedValue
    // PreCondition: must meet pre-conditions of Hand::GetBustedValue
    //     (currently none)
    // PostCondition: Hand::GetBustedValue is called on this player's
    //     hand, and it's value is returned by this method (true if
    //     player already busted, false otherwise)
    //---------------------------------------------------------
    bool GetBustedValue() const;

    //-------------------------------------------------------
    // Name: GetHandValue
    // PreCondition: must meet pre-conditions of Hand::GetHandValue
    //     (currently none)
    // PostCondition: Hand::GetHandValue is called on this player's
    //     hand, and it's value is returned by this function- so zero
    //     should be returned if player has blackjack, or otherwise: if
    //     it is possible to not bust, the highest possible non-bust
    //     value of hand is returned. if impossible to not bust, the
    //     lowest possible valuation of hand is returned (counting any
    //     aces as 1)
    //---------------------------------------------------------
    int GetHandValue();

    //-------------------------------------------------------
    // Name: IncreaseFundsBy
    // PreCondition: increase param must not be null
    // PostCondition: player's funds (m_funds) increased by given amount
    //---------------------------------------------------------
    void IncreaseFundsBy(int increase = 0);

    //-------------------------------------------------------
    // Name: GetAndResetBet
    // PreCondition: m_betThisRound must already have a value (which
    //     only happens if SetBet has been used prior)
    // PostCondition: the player's current bet amount for this round
    //     (m_betThisRound) is set back to zero, and it's value from
    //     before it was reset to zero is returned.
    //---------------------------------------------------------
    int GetAndResetBet();

    //-------------------------------------------------------
    // Name: ClearHand
    // PreCondition: none
    // PostCondition: player's hand (m_hand) reinitialized/emptied
    //---------------------------------------------------------
    void ClearHand();



  private:
    char *m_name;
    int m_funds;
    int m_betThisRound;
    Hand m_hand;
};



#endif
