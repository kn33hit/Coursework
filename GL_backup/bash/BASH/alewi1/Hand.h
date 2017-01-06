/****************************************************************
 * File:    Hand.h
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Andrew Lewis
 * Date:    3/20/14
 * Section: 01
 * E-mail:  alewi1@umbc.edu 
 *
 *   This file contains the declaration for the Hand class.
 *   The class manages and implements a hand containing a set of 
 *   cards along with member functions that control the data therein
 *
 ****************************************************************/

#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>


class Hand { 

 public:
 /****************************************************************
     * Name: Hand
     *   default (no-arg) constructor
     * Preconditions: none.
     * Postconditions:
     *   Does nothing. 
     ****************************************************************/
	Hand();


/****************************************************************
     * SizeOf:
     * Preconditions:none
     * Postconditions:
     *   Returns: the current size of the hand
     ****************************************************************/
  int SizeOf();


/****************************************************************
     * SetCard:
     * Preconditions:
     *   card -- a card from the deck
     * Postconditions: none
     ****************************************************************/
  void SetCard(Card card);


/****************************************************************
     * OutputCard:
     * Preconditions:
     *   card -- the index of the card in the hand
     * Postconditions:
     *   prints the rank and suit of the card out to the user
     ****************************************************************/
  void OutputCard(int card);
  

/****************************************************************
     * ValueOf:
     * Preconditions:
     *   card -- the index of the card in the hand
     * Postconditions:
     *   Returns: the rank of the card in the hand 
     ****************************************************************/
  int ValueOf(int card);

 private: 

  std::vector<Card> m_cards;

};


#endif
