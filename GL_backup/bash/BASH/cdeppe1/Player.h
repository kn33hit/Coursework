/****************************************************************
 * File:    Player.h
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Chandler Deppe
 * UMBC ID: OQ44374
 * Date:    3/21/14
 * Section: 05
 * E-mail:  cdeppe1@umbc.edu
 *
 *   This file contains the declaration for the Player class.
 *   The class manages and implements the Player class which oversees
 *   a player's name, funds, bet, and whether they've busted.
 *
 ****************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Deck.h"
#include "Card.h"

class Player {
  public:
    /****************************************************************
     * Name: Player
     *   default (no-arg) constructor, does nothing
     * Preconditions: none
     * Postconditions: none
     ****************************************************************/
    Player();

    /****************************************************************
     * Name: Player
     *   Standard constructor
     * Preconditions: name -- a char pointer that contains the players name
     * Postconditions: name is assigned to m_name
     *   m_busted is set to false
     *   m_funds is set to 100
     *   m_blackjack is set to false
     ****************************************************************/
    Player(char *name);

    /****************************************************************
     * Name: GetName
     * Preconditions: none
     * Postconditions: 
     *   returns: the name of the player
     ****************************************************************/
    char *GetName();

    /****************************************************************
     * Name: GetFunds
     * Preconditions: none
     * Postconditions: 
     *   returns: the players current amount of funds
     ****************************************************************/
    int GetFunds();

    /****************************************************************
     * Name: SetFunds
     *   initializes a players funds
     * Preconditions: 
     *   amt -- the amount of money player's funds should be set to
     * Postconditions:
     *   sets the players funds to the given amount
     ****************************************************************/
    void SetFunds(int amt);

    /****************************************************************
     * Name: SetBet
     *   sets the players bet for that round
     * Preconditions:
     *   amt -- the amount that a players bet is set too;
     *     this amount is compared to the players funds and if
     *     they are sufficient then the bet is set, otherwise 
     *     the amt is rejected
     * Postconditions:
     *     returns: true if the bet is accepted, false otherwise
     ****************************************************************/
    bool SetBet(int amt);

    /****************************************************************
     * Name: ModifyHand
     * Preconditions: card -- a card object that is dealt from the deck
     * Postconditions: the card is added to the current players hand
     ****************************************************************/
    void ModifyHand(Card card);

    /****************************************************************
     * Name: ShowHand
     * Preconditions: 
     *   dealer -- determines whether to hide the second card
     * Postconditions: the players hand is outputted to the screen
     ****************************************************************/
    void ShowHand(bool dealer);

    /****************************************************************
     * Name: GetBusted
     * Preconditions: none
     * Postconditions:
     *   returns: m_busted
     ****************************************************************/
    bool GetBusted();

    /****************************************************************
     * Name: CheckBusted
     * Preconditions: none
     * Postconditions:
     *   calls GetScore to calculate the current score and then
     *   compares it to 21 to determine if the player has busted.
     *   if the player is above 21 then busted is set to false and
     *   and is returned, otherwise it is set to true and is returned 
     ****************************************************************/
    bool CheckBusted();

    /****************************************************************
     * Name: SetBusted
     * Preconditions: busted -- sets the players busted status
     * Postconditions: m_busted is set to busted's value
     ****************************************************************/
    void SetBusted(bool busted);

    /****************************************************************
     * Name: GetScore
     * Preconditions: none
     * Postconditions:
     *   returns: m_score which is calculated beforehand by calling
     *     CountHand, a method of the Hand class
     ****************************************************************/
    int GetScore();

    /****************************************************************
     * Name: GetBlackjack
     * Preconditions: none
     * Postconditions:
     *   returns: m_blackjack
     ****************************************************************/
    bool GetBlackjack();

    /****************************************************************
     * Name: DetermineBlackjack
     * Preconditions: none
     * Postconditions:
     *   sets m_blackjack by calling the Hand method CheckBlackjack
     ****************************************************************/
    void DetermineBlackjack();

    /****************************************************************
     * Name: ModifyFunds()
     * Preconditions:
     *   pWin - a bool that tells whether the player has won against
     *            the dealer
     * Postconditions:
     *   modifies funds accordingly with the status of pWin by either
     *     adding or subtracting the player's current bet from the
     *     player's current funds
     ****************************************************************/
    void ModifyFunds(bool pWin);

    /****************************************************************
     * Name: ClearHand()
     * Preconditions: none
     * Postconditions: 
     *   calls the Hand method clear to clear the player's current hand
     ****************************************************************/
    void ClearHand();

  private:
    char *m_name;
    bool m_busted, m_blackjack;
    int m_funds, m_currentBet, m_score;

    //m_hand - the players 'hand'
    Hand m_hand;
};

#endif
