/****************************************************************                                                                                     
 * File:    Player.h                                                                                                                           
 * Project: CMSC 202 Project 2, Spring 2014                                                                                                           
 * Author:  Michael Huff                                                                                                                              
 * Date:    3/10/14                                                                                                                                  
 *                                                                                                                                                    
 * This file contains the definition of the Player class                                                                                       
 ****************************************************************/



#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include "Hand.h"
#include "Card.h"

using namespace std;

class Player { 
 public:
  /*
    Player()
    default constructor, creates a player name jane with 100 dollars
  */
  Player();
  /* Player(string name)
     constructs a player with the given name and 100 dollars
  */
  Player(string name);
  /* Player(string name, int cash)
     constructs a player with given values for name and money
  */
  Player(string name, int cash);
  /*
    char *getName()
    returns the name of the player as a null terminated string
  */
  char *GetName();
  /*
    int getCash()
    returns the amount of money a player has
  */
  int getCash();
  /*
    void setCash(int cash)
    sets a players amount of money to the specified value
  */
  void setCash(int cash);
  /*
    void addCard(Card newCard)
    adds the specified card to the player's hand
  */
  void addCard(Card newCard);
  /*                                                                                                                                                  
    void setBet(int bet)
    sets the player's current bet                                                                                                     
  */
  void setBet(int bet);
  /*
    void won()
    resets the players hand and bet,
    adds the current bet to total cash,
    prints match results
  */
  void won();
  /*
    void lost();
    resets the players hand and bet,                                                                                                                  
    subtracts the current bet to total cash,                                                                                                          
    prints match results                                                                                                                              
  */
  void lost();
  /*                                                                                                                                                  
    void tied();                                                                                                                                      
    resets the players hand and bet,                                                                                                                 
    prints match results                                                                                                                    
  */
  void tied();
  /*
    void printHand()
    prints the player's current hand
  */
  void printHand();
  /*
    void printDealerHand()
    prints the player's hand with the last card hidden
  */
  void printDealerHand();
  /*
    bool isBust()
    returns true if the player has busted, false otherwise
  */
  bool isBust();
  /*
    void resetHand()
    gives the player a new, empty hand
  */
  void resetHand();
  /*
    void getHandValue()
    returns the blackjack value of the player's hand
  */
  int getHandValue();
 private:
  Hand m_hand;
  int m_cash;
  int m_currentBet;
  char m_name[100];
};
#endif
