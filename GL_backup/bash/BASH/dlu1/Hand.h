/****************************************************************
 * File:    Hand.h
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Denmark Luceriaga
 * Date:    3/20/14
 * Section:
 * E-mail:  dlu1@umbc.edu
 *
 *   This file contains the declaration for the Hand class.
 *   This class will manage the cards a single player has been
 *   dealt so far, and will provide member functions for printing
 *   out the cards in the hand, determining the total value of
 *   the cards in the hand, etc.
 ****************************************************************/

#ifndef HAND_H
#define HAND_H

#include <vector>

//#include "Blackjack.h"
//#include "Player.h"
#include "Deck.h"
#include "Card.h"

using namespace std;

class Hand {
 public:

  Hand();
  /****************************************************************
   * GetHandValue:
   *     Computes numerical value player's current hand
   * Preconditions: int player is current player's index
   * Postconditions: none, just display's player's hand
   ****************************************************************/
  int GetHandValue();

  /****************************************************************
   * GetHandSize:
   *     Computes size of hand
   * Preconditions: none.
   * Postconditions: size of vector m_cards is returned
   ****************************************************************/
  int GetHandSize();

  /****************************************************************
   * PutCardIntoHand:
   *     Puts card into player's hand
   * Preconditions: Card is a fresh card
   * Preconditions: Card is added to vector m_cards
   ****************************************************************/
  void PutCardIntoHand(Card);

  /****************************************************************
   * LookAtCards:
   *     Outputs card
   * Preconditions: none.
   * Preconditions: Outputs card
   ****************************************************************/
  void LookAtCards(int);

  /****************************************************************
   * ClearHand:
   *     Clears player's hand
   * Preconditions: none.
   * Preconditions: Clears vector m_cards
   ****************************************************************/
  void ClearHand();

  /****************************************************************
   * GetPLayerBJHand:
   *     Retrieves player's status of having the special hand
   * Preconditions: none.
   * Preconditions: Returns bjhand
   ****************************************************************/
  bool GetPlayerBJHand();

 private:
  vector<Card> m_cards;
  bool bjhand;
  bool m_newHand;

};

#endif
