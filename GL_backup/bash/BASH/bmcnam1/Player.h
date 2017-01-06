/****************************************************************
 * File:    Player.h
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Bernard McNamee
 * Date:    3/19/14
 * Section: 11
 * E-mail:  bmcnam1@umbc.edu
 *
 *   This file contains the declaration for the Player class.
 *   The class implements a 'Player' including member functions for
 *   Setting and getting the name funds, and betting amounts. An 
 *   Note: Player inherets member functions from the hand class including
 *   adding to hand , adding player's hand, printing the hand etc.
 *
 ****************************************************************/

#ifndef PLAYER_H
#define PLAYER_H
#include "Hand.h"

#include <vector>

class Player : public Hand{
 public:
  /*********************************
   *Name: Player
   *  default (no-arg) constructor,
   *Preconditions: none.
   *Postconditions:Creates a player with no name or initial funds
   ********************************/
  Player();

  /*********************************
   *Name: Player
   * Player overloaded constructor
   *Preconditions: none.
   *Postconditions:Creates a player with a name and a set of initial funds
   ********************************/
  Player(char *name, int money);

  /*********************************
   *Name: SetName
   * Sets the name of the Player.
   *Preconditions: Name char pinter
   *Postconditions:Returns nothing. But the name is passed by refference
   *so it gets 'passed' back to the Blackjack class then the main
   ********************************/
  void SetName(char *name);

  /*********************************
   *Name: SetFund
   *Sets the amount of money the player stats with.
   *Preconditions: Integer amount of money
   *Postconditions:Returns void
   ********************************/
  void SetFund(int fund);

  /*********************************
   *Name: SetBetAmount
   * Sets the amount of money the player wishes to bet
   *Preconditions: Amount the player wants to bet
   *Postconditions:Returns void
   ********************************/
  void SetBetAmount(int bet);  

  /*********************************
   *Name: GetName
   * Returns the name of the player
   *Preconditions: the index of the player vector
   *Postconditions:Returns the name of the player in the vector at
   *at the provided index
   ********************************/
  char *GetName();

  /*********************************
   *Name: GetFund
   * Returns the amount of money the user has
   *Preconditions: Given the index integer of the player vector
   *Postconditions:Returns the amount of money for the player in the 
   * in the vector at the index provided
   ********************************/
  int GetFund();

  /*********************************
   *Name: GetBetAmount
   * Will return the amount the player wants to bet
   *Preconditions: None
   *Postconditions:Returns the amount bet amount of the user
   ********************************/
  int GetBetAmount();
  
 private:
  char *m_name; //the player's name
  int m_fund; //Player's amount of money
  int m_bet;  // How much the player bets
  
  

};

#endif // PLAYER_H
