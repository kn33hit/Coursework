/****************************************************************
* File:    Player.h
* Project: CMSC 202 Project 2, Spring 2014
* Author:  Jacob Lutz
* Date:    3/28/14
* Section: 08
* E-mail:  jlutz1@umbc.edu
*
*   This file contains the declaration for the Player class.
*   The class manages the statistics for a given player, including
*   the player's name, funds, and current bet.
*
****************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"

class Player
{

public:

    /****************************************************************
    * Name: Player
    *   Default Constructor
    * Preconditions: 
    *   None
    * Postconditions:
    *   Creates a player with name "A lone wanderer" with no funds
    *   (funds to be set by the BlackJack class)
    ****************************************************************/
    Player();

    /****************************************************************
    * Name: Player
    *   Standard Constructor
    * Preconditions:
    *   name -- a string specifying the player's intended name
    * Postconditions:
    *   Creates a player with the specified name
    ****************************************************************/
    Player(char name[]);

    /****************************************************************
    * Name: Player
    *   Standard Constructor
    * Preconditions:
    *   name  -- a string specifying the player's intended name
    *   funds -- a nonnegative integer representing the amount of money
    *            the player can bet
    * Postconditions:
    *   Creates a player with the specified name and funding
    ****************************************************************/
    Player(char name[], int funds);

    /****************************************************************
    * Name: GetName
    *   Returns the player's name
    * Preconditions:
    *   None
    * Postconditions:
    *   Returns the player's name as a string
    ****************************************************************/
    char* GetName();

    /****************************************************************
    * Name: GetFunds
    *   Returns the amount of money a player has available to bet
    * Preconditions:
    *   None
    * Postconditions:
    *   Returns the funding as an int
    ****************************************************************/
    int GetFunds();

    /****************************************************************
    * Name: GetCurrentBet
    *   Returns the amount of money the player has bet for the 
    *   current game of Blackjack
    * Preconditions:
    *   None
    * Postconditions:
    *   Returns the current bet amount as an int
    ****************************************************************/
    int GetCurrentBet();

    /****************************************************************
    * Name: GetHandValue
    *   Accesses GetHandValue() in m_playerHand
    * Preconditions:
    *   None
    * Postconditions:
    *   Returns the current hand's blackjack value as an int
    ****************************************************************/
    int GetHandValue();

    /****************************************************************
    * Name: IsBust
    *   Determines whether the player is bust
    * Preconditions:
    *   None
    * Postconditions:
    *   Returns true if player's hand value is over 21
    *   Returns false if hand value is not
    ****************************************************************/
    bool IsBust();

    /****************************************************************
    * Name: SetFunds
    *   Sets the player's available money to the specified amount
    * Preconditions:
    *   amt -- the amount of money to add to the player's funds
    * Postconditions:
    *   New value stored in m_funds
    ****************************************************************/
    void SetFunds(int amt);

    /****************************************************************
    * Name: SetCurrentBet
    *   Sets the specified amount of money as the player's bet
    * Preconditions:
    *   amt -- nonnegative integer, the amount to place as a bet
    *   Player's funds must be greater or equal to the bet amount
    * Postconditions:
    *   Subtracts the amount from the m_funds and stores the
    *   amount in m_currentBet
    *   returns true if bet is allowed, false if not
    ****************************************************************/
    bool SetCurrentBet(int amt);

    /****************************************************************
    * Name: WinGame
    *   Handles the payout if the player wins the game
    * Preconditions:
    *   Player has won the game
    * Postconditions:
    *   Adds to m_funds twice the amount of m_currentBet
    *   resets m_currentBet to default value of 0
    *   clears player's hand
    ****************************************************************/
    void WinGame();

    /****************************************************************
    * Name: TieGame
    *   Handles the returns if the player and the dealer tie
    * Preconditions:
    *   Player and Dealer have faced a tie game
    * Postconditions:
    *   restores m_funds by the amount specified in m_currentBet
    *   resets m_currentBet to default value of 0
    *   clears player's hand
    ****************************************************************/
    void TieGame();

    /****************************************************************
    * Name: Reset
    *   Reset's the player's or dealer's 
    *   ALso handles the losses if the player loses the game
    * Preconditions:
    *   Player has lost the game
    *   or function called for dealer
    * Postconditions:
    *   resets m_currentBet to default value of 0
    *   clears player's or dealer's hand
    ****************************************************************/
    void Reset();

    /****************************************************************
    * Name: OutputHandValue
    *   Accesses PrintHand() or PrintDealerHand() in m_playerHand
    * Preconditions:
    *   isDealer -- true if the player is the dealer, false if not
    * Postconditions:
    *   if isDealer is true, prints dealer's hand
    *   if isDealer is false, prints player's hand
    ****************************************************************/
    void OutputHand(bool isDealer);

    /****************************************************************
    * Name: OutputHandValue
    *   Accesses PrintNewCard() in m_playerHand
    * Preconditions:
    *   None
    * Postconditions:
    *   Prints out the newest card in the player's hand
    ****************************************************************/
    void OutputNewCard();

    /****************************************************************
    * Name: AddCardToHand
    *   Accesses AddCard() in m_playerHand
    * Preconditions:
    *   cardToAdd -- the card to add to the player's hand
    * Postconditions:
    *   Adds the card to the player's hand
    ****************************************************************/
    void AddCardToHand(Card cardToAdd);

private:

    char m_name[80];    //the name of the player, needn't be changed
    int m_funds;        //the player's funds, can be increased and decreased
    int m_currentBet;   //the player's current bet
    Hand m_playerHand;  //the player's current hand

};

#endif