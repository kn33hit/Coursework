/****************************************************************              
 * File:    Player.h                                                         
 * Project: CMSC 202 Project 2, Fall 2014                                    
 * Author:  Eric Sluder                                                        
 * Date:    10/11/14                                                           
 * Section: 1112 - Lecture, 1113 - Discussion                                 
 * E-mail:  esluder1@umbc.edu                                                  
 *                                                                             
 *   This file contains the declarations for the Player class.            
 *   The class manages and implements the players in a given instance of       
 *   the Blackjack/21 program.                                                 
 *                                                                             
 ****************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Hand.h"

class Player {
  public: 
   //constructors
   /****************************************************************
    * Name: SettlePlayerbet
    *   At end of round, settle bet for given player:
    *   Compare player's hand to dealer's hand, decide who wins,
    *   then settle bet accordingly by updating the player's funds
    *   based on their bet, outputting results.
    *   Should also zero out the bet in preparation for the next round.
    * Preconditions:
    *   player -- the index of the requested player
    * Postconditions:
    *   Updates the player's funds, by adding or subtracting bet.
    *   Print out player's card total (number, "busted", or "blackjack"),
    *     and the winner ("Joe wins" or "Dealer wins" or "tie").
    *     Examples:
    *       "Joe has busted--Dealer wins", or
    *       "Sally has 21--Sally wins", or
    *     or "Sally has blackjack--tie" if dealer also had blackjack.
    *   Clears the bet amount.
    *   Returns: 0  (return value not really used yet)
    ****************************************************************/

   /****************************************************************
    * Name: Player
    *   Default (no-argument) constructor. Used to create the dealer player
    *   for the game.
    * Preconditions:
    *   N/A
    * Postconditions:
    *   Creates a Player object for the dealer, with name "Dealer" and
    *   funds of 0. The dealer never bets, so funds are not necessary.
    ****************************************************************/
   Player();

    /****************************************************************
    * Name: Player
    *   Standard constructor that takes in name from the command line arguments
    *   and uses a default fund value passed into the constructor. Creates a
    * Preconditions:
    *   m_inputName -- C-string (array) of that player's name
    *   m_Fund -- value of starting funds
    * Postconditions:
    *   Creates Player class with the specified name and funds, and a bust
    *   check that is false
    ****************************************************************/
   Player(char *m_inputName, int m_Fund);
   

   //accessors
    /****************************************************************
    * Name: GetPlayerName
    *   Simple return function -- returns the player name, m_name
    * Preconditions:
    *   Player object has been created -- name has been generated
    * Postconditions:
    *   returns m_name, a C-string of the player's name
    ****************************************************************/
   char *GetPlayerName();

    /****************************************************************
    * Name: GetPlayerFunds
    *   Simple return function -- returns the player funds, m_funds
    * Preconditions:
    *   Player object has been created -- funds have been generated
    * Postconditions:
    *   returns m_funds, an int of the player's funds
    ****************************************************************/
   int GetPlayerFunds();

    /****************************************************************
    * Name: OutputPlayerHand
    *   Displays the Player's hand -- accesses the Hand object associated with
    *   the player
    * Preconditions:
    *   Player object has been created -- cards have been dealt and a
    *   hand generated for the player
    * Postconditions:
    *   calls the Hand class function OutputPlayerHand
    ****************************************************************/
   void OutputPlayerHand();

    /****************************************************************
    * Name: OutputDealerHand
    *   Displays the Dealer's hand -- accesses the Hand object associated with
    *   the dealer
    * Preconditions:
    *   Player (dealer) object has been created-- cards have been dealt and a
    *   hand generated for the dealer
    * Postconditions:
    *   calls the Hand class function OutputDealerHand
    ****************************************************************/
   void OutputDealerHand();

    /****************************************************************
    * Name: IsBust
    *   Returns the value of a bust check for the Player object
    * Preconditions:
    *   Typically, but not necessarily: Player object has been created -- cards
    *   have been dealt and the value of the hand is checked against the rules
    *   of the game (Blackjack/21)
    * Postconditions:
    *   returns the value of the bust check bool
    ****************************************************************/
   bool IsBust();

    /****************************************************************
    * Name: ReturnHandValue
    *   Returns the value of the player's hand. Calls Hand class functions to
    *   sum the hand values and perform basic logic for ACE value determination
    * Preconditions:
    *   Player class created, cards dealt and added to hand
    * Postconditions:
    *   returns the value of the player's hand as an int
    ****************************************************************/
   int ReturnHandValue();

    /****************************************************************
    * Name: ReturnHandSize
    *   Returns the size of the player's hand. Calls Hand class functions to
    *   count the number of cards in the hand
    * Preconditions:
    *   Player class created, cards dealt and added to hand
    * Postconditions:
    *   returns the size of the player's hand as an int
    ****************************************************************/
   int ReturnHandSize();


   //mutators
    /****************************************************************
    * Name: SetPlayerFunds
    *   Sets the player's funds to the amount specified
    * Preconditions:
    *   Player class created, input amount passed in. Input amount is given
    *   at the command line
    * Postconditions:
    *   sets the fund variable to the input amount, m_funds
    ****************************************************************/
   void SetPlayerFunds(int m_inputAmt);

    /****************************************************************
    * Name: SetPlayerBet
    *   Sets the player's bet to the amount specified
    * Preconditions:
    *   Player class created, bet provided from user input prompt at shell
    * Postconditions:
    *   sets the amount the player wants to bet -- the m_bet variable
    ****************************************************************/
   bool SetPlayerBet(int m_inputBet);

    /****************************************************************
    * Name: AddToHand
    *   Adds the input card to the hand of the player in the Hand object
    *   associated to the player
    * Preconditions:
    *   Player class created, card dealt from the deck to the player and input
    *   to the function call
    * Postconditions:
    *   adds the dealt card to the player's hand
    ****************************************************************/
   void AddToHand(Card m_inputCard);

    /****************************************************************
    * Name: HitPlayer
    *   Deals the next card in the deck to the player's hand, updates the bust
    *   check if the new hand value is over 21
    * Preconditions:
    *   Player class and deck created, deck passed to the function
    * Postconditions:
    *   deals the next card in the deck to the player, calls AddToHand
    *   to put it in the player's hand
    ****************************************************************/
   bool HitPlayer(Deck &m_deck);

    /****************************************************************
    * Name: AlterFunds
    *   Changes the player's funds based on the win/lose/tie conditions
    * Preconditions:
    *   Players have bet, played the round, and win/lose/tie outcome
    *   determined and passed into function
    * Postconditions:
    *   Changes the m_funds variable to reflect the win/loss condition
    *   or leave m_funds the same for a tie
    ****************************************************************/
   void AlterFunds(bool m_playerLose, bool m_playerTie);

    /****************************************************************
    * Name: ResetBet
    *   Resets the current player bet value to 0 in preparation for the next
    *   round of betting/play
    * Preconditions:
    *   Play for current is over, win/lose/tie condition determined, and
    *   funds altered appropriately
    * Postconditions:
    *   Changes m_bet to 0
    ****************************************************************/
   void ResetBet();

    /****************************************************************
    * Name: ResetHand
    *   Resets the player's hand to a null-vector ready for a new deal
    *   and new cards to be added if the player hits
    * Preconditions:
    *   Play for current is over, win/lose/tie condition determined,
    *   funds altered appropriately, and the hand contents and value printed
    *   to the shell
    * Postconditions:
    *   Changes m_hand to a null-vector
    ****************************************************************/
   void ResetHand();

  private:
   char *m_name;     //C-string that holds the player's name
   int m_funds;      //holds the player's current available funds
   int m_bet;        //holds the player's current bet
   bool m_validBet;  //holds the check if a bet is valid based on current funds
   Hand m_hand;      //Hand object for individual Player - cards etc. internal
   bool m_isBust;    //check for if the player has busted
   int m_handValue;  //value of all the cards in the player's hand
   Card m_newCard;   //temp var used to hold cards dealt to the player on hit
   int m_handSize;   //value of the hand size

};

#endif
