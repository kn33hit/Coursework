/****************************************************************
 * File:    Hand.h
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Bernard McNamee
 * Date:    3/19/14
 * Section: 11
 * E-mail:  bmcnam1@umbc.edu
 *
 *   This file contains the declaration for the Hand class.
 *   The class implements a Hand of playing cards, including
 *   member functions for clearing, getting the total of the hand,
 *   addign cards to the hand, seeing if the hand has Blackjack, and printing hand
 *
 ****************************************************************/
#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand{
 public:
  /****************************************************************
   * Name: Hand
   *   default (no-arg) constructor
   * Preconditions: none.
   * Postconditions: Creates an empty hand
   ****************************************************************/
  Hand();

  /****************************************************************
   * Name: PrintPlayer Hand
   * Loops though the card in the hand and prints them out
   * Preconditions: none.
   * Postconditions: Prints each card object in the hand
   ****************************************************************/
  void PrintPlayerHand();

  /****************************************************************
   * Name: GetTotal Hand
   * will add the nummerical value of each card in the hand. For Aces,
   *it will count as a one if it would go bust as an 11. else it will count 
   *as an 11
   * Preconditions: none.
   * Postconditions: returns the nummerical value of the player's hand
   ****************************************************************/
  int GetTotalHand();

  /****************************************************************
   * Name: AddToHand
   * Takes a card object and will push it onto the 'hand'  vector of cards
   * Preconditions: takes a card object as a argument
   * Postconditions: returns void
   ****************************************************************/
  void AddToHand(Card c);

  /****************************************************************
   * Name: ClearHand
   * Removes all the cards form the hand vector
   * Preconditions: none.
   * Postconditions: returns void
   ****************************************************************/
  void ClearHand();

  /****************************************************************
   * Name: HasBlackject
   * If the player's hand has only an ace and a ten (value) card it will 
   * return true. else it will return false
   * Preconditions: none.
   * Postconditions: returns true or false
   ****************************************************************/
  bool HasBlackjack(); 
 private:
  std::vector<Card>m_hand;// vecort of card objects

};

#endif
