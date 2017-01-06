#ifndef HAND_H
#define HAND_H
#include<vector>

#include <iostream>
#include "Card.h"

class Hand{
 public:

  /****************************************************************
   * Name: Hand
   * Preconditions: none.
   * Postconditions:
   *   Default no-args constructor
   ****************************************************************/

  Hand();

  /****************************************************************
   * Name: InsertCards
   * Preconditions: passes the function a card
   * Postconditions:
   *   inserts a card in the card vector
   ****************************************************************/

  void InsertCard(Card card);

  /****************************************************************
   * Name: PrintHand
   * Preconditions: none.
   * Postconditions:
   *   Prints out a user friendly version of a hand
   ****************************************************************/

  void PrintHand();

  /****************************************************************
   * Name: ClearHand
   * Preconditions: none.
   * Postconditions:
   *   Clears the hand
   ****************************************************************/

  void ClearHand();

  /****************************************************************
   * Name: SumOfCards
   * Preconditions: none.
   * Postconditions:
   *   finds the sum of the cards in the deck
   ****************************************************************/

  int SumOfCards();

  /****************************************************************
   * Name: GetSum
   * Preconditions: none.
   * Postconditions:
   *   returns the sum of cards
   ****************************************************************/

  int GetSum();

 private:
  std :: vector<Card> m_cards;
  int m_sum;
};


#endif
