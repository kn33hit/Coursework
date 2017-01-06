/****************************************************************
 * File:    Player.h
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Madhurya Mahajan
 * Date:    3/23/14
 * Section: 16
 * E-mail:  mahajan3@umbc.edu
 *
 *   This file contains the declaration for the Player class.
 *   The class will keep track of all the information about a 
 *   single player: their name, their pool of betting funds, their
 *   bet on the current game, etc.
 *
 ****************************************************************/

#ifndef PLAYER_H
#define PLAYER_H
#include<vector>
#include "Hand.h"

class Player{
 public:
  /****************************************************************
   * Name: Player
   * Preconditions: none.
   * Postconditions:
   *   sets default name to Jane and default funds to 100
   ****************************************************************/

  Player();

  /****************************************************************
   * Name: Player
   * Preconditions: passes a name and an int for funds
   * Postconditions:
   *   sets the name to the name passed and funds to funds passed
   ****************************************************************/

  Player(char* name, int funds);

  /****************************************************************
   * Name: GetName
   * Preconditions: none.
   * Postconditions:
   *   returns value in name
   ****************************************************************/

  char* GetName();

  /****************************************************************
   * Name: GetFunds
   * Preconditions: none.
   * Postconditions:
   *   returns value in funds
   ****************************************************************/

  int GetFunds();

  /****************************************************************
   * Name: GetBet
   *   default (no-arg) constructor
   * Preconditions: none.
   * Postconditions:
   *   returns value in bet
   ****************************************************************/

  int GetBet();

  /****************************************************************
   * Name: SetBet
   * Preconditions: passes the about of bet
   * Postconditions:
   *   sets bet to the parameter passed to it
   ****************************************************************/

  void SetBet(int amt);

  /****************************************************************
   * Name: SetName
   * Preconditions: gets the name passed to the program
   * Postconditions:
   *   sets name to parameter passed to it
   ****************************************************************/

  void SetName(char* name);

  /****************************************************************
   * Name: SetFunds
   * Preconditions: gets amount the player has 
   * Postconditions:
   *   sets the funds to the parameter passed
   ****************************************************************/

  void SetFunds(int amt);

  /****************************************************************
   * Name: PrintCard()
   * Preconditions: none.
   * Postconditions:
   *   Prints out the hand
   ****************************************************************/

  void PrintCard();

  /****************************************************************
   * Name: InsertCardRef
   * Preconditions: passes a card
   * Postconditions:
   *   puts a card in the hand
   ****************************************************************/

  void InsertCardRef(Card c);

  /****************************************************************
   * Name: CheckSum
   * Preconditions: none.
   * Postconditions:
   *   Goes to the hand class and determintes if the sum > 21
   ****************************************************************/

  bool CheckSum();

  /****************************************************************
   * Name: GetSum
   * Preconditions: none.
   * Postconditions:
   *   gets the sum of the cards in the hand
   ****************************************************************/

  int GetSumRef();

 private:

  char *m_name;
  int m_funds;
  int m_bet;
  Hand m_hand;

};

#endif  // PLAYER_H
