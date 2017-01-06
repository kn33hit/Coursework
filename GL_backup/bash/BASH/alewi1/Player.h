/****************************************************************
 * File:    Player.h
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Andrew Lewis
 * Date:    3/20/14
 * Section: 01
 * E-mail:  alewi1@umbc.edu
 *
 *   This file contains the declaration for the Player class.
 *   The class creates a player with the functions necessary
 *   to hold and manipulate cards in a hand
 *
 ****************************************************************/


#ifndef PLAYER_H
#define PLAYER_H

#include<vector>
#include "Card.h"
#include "Hand.h"

class Player {

 public: 

 
 /****************************************************************
     * Name: Player
     *   default (no-arg) constructor
     * Preconditions: none.
     * Postconditions:
     *   does nothing
     ****************************************************************/
  Player();


   
/****************************************************************
     * Name: Player
     *   Standard constructor
     * Preconditions:
     *   player -- the name of the player 
     *   amt -- the amount of money the player has
     * Postconditions:
     *   initializes the player instance and gives the player a name and
     *   an initial amount of money
     ****************************************************************/
  Player(char *player, int amt);



/****************************************************************
     * GetAmount:
     * Preconditions: none.
     * Postconditions:
     *   Returns: the amount of funds the player has
     ****************************************************************/
  int GetAmount();



 /****************************************************************
     * GetName:
     * Preconditions: none
     * Postconditions:
     *   Returns: the given player's name
     ****************************************************************/
  char *GetName();



/****************************************************************
     * GetFunds
     *   Return the player's  available funds
     * Preconditions: none
     * Postconditions:
     *   Returns: The amount of funds the player currently holds
     ****************************************************************/
  int GetFunds();



/****************************************************************
     * GetCard:
     *  
     * Preconditions:
     *   player -- the index of the requested player
     * Postconditions:
     *   Returns: The amount of funds the player currently has remaining
     ****************************************************************/
 Card getCard();



 /****************************************************************
     * SetCard:
     *  Takes a card and adds it to the player hand 
     * Preconditions:
     *  card -- a card from the deck
     * Postconditions:
     *  adds the card to the end of the deck
     ****************************************************************/
  void SetCard(Card card);

 /****************************************************************
     * SetFunds:
     *   changes the betting funds for the player
     * Preconditions:
     *   amt -- the amount the funds will be changed to 
     * Postconditions:
     *   changes the amount of funds to the passed value
     ****************************************************************/
  void SetFunds(int amt);


 /****************************************************************
     * SetPlayerBet:
     *   Set how much the player wants to bet in current round.
     * Preconditions:
     *   amt -- the amount of money player wants to bet
     * Postconditions:
     *   amount of bet is recorded for the player
     ****************************************************************/
  void SetPlayerBet(int amt);



/****************************************************************
     * DisplayCards:
     *   prints the player's hand of cards to the user
     * Preconditions: none
     * Postconditions: outputs the suit and rank of each card in hand
     ****************************************************************/
  void DisplayCards();


/****************************************************************
     * DisplayDealerCards:
     *   similar to DisplayCards, but hides the 2nd card drawn 
     * Preconditions: none
     * Postconditions:
     *    The dealers starter hand is printed, 2nd card hidden
     ****************************************************************/
  void DisplayDealerCards();


/****************************************************************
     * DisplayLastCard:
     *   Return the given player's pool of available funds
     * Preconditions: none
     * Postconditions:
     *   Outputs the card at the rightmost position in the hand
     ****************************************************************/
  void DisplayLastCard();


/****************************************************************
     * SetBlackjack:
     *   sets whether the player hit blackjack during current round
     * Preconditions: status, true if blackjack, else false
     * Postconditions:
     *   stores that user either did or did not hit blackjack after draw
     ****************************************************************/
  void SetBlackjack(bool status);


/****************************************************************
     * HasBlackjack:
     *   returns whether the player hit blackjack this round
     * Preconditions: none.
     * Postconditions:
     *   Returns: true if blackjack, else false
     ****************************************************************/
  bool HasBlackjack();



/****************************************************************
     * IsBusted:
     *   checks to see if sum of cards in hand is <=21
     * Preconditions: none.
     * Postconditions:
     *   
     ****************************************************************/
  bool IsBusted();


/****************************************************************
     * HandValue:
     *   determines the value of the cards in the hand
     * Preconditions: none
     * Postconditions:
     *   returns the rank sum of cards in the hand
     ****************************************************************/
  int HandValue();


/****************************************************************
     * ResetHand:
     *   removes all the cards from the hand
     * Preconditions: none.
     * Postconditions:
     *   pops all cards out of the hand vector
     ****************************************************************/
  void ResetHand();


/****************************************************************
     * WonBet:
     *   called when player wins bet, adds bet amount to total funds
     * Preconditions: none.
     * Postconditions:
     *   funds are increased by bet amount
     ****************************************************************/
  void WonBet();


/****************************************************************
     * LostBet:
     *   Called when player loses bet, bet is deducted from funds
     * Preconditions: none.
     * Postconditions:
     *   Player loses amount of money that they bet
     ****************************************************************/
  void LostBet();
  

  

 private:
  
  char* m_player;
  int m_betAmt;
  int m_funds;
  Hand m_hand;
  bool m_hasBlackjack;

};
 
#endif
