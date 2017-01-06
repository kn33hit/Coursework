#ifndef HAND_H
#define HAND_H

#include <vector>
#include <iostream>
#include "Card.h"
int const SOFT_SEVENTEEN = 17;
int const TWENTYONE = 21;
class Hand
{
  /*The Hand class will manage the cards a single player has been dealt so far, and will provide member functions for printing out the cards in the hand, determining the total value of the cards in the hand, etc.
  */
  
 private:
  std::vector<Card> m_card;
  int m_total;
  int m_numCards;
  //Card m_card;
 public:
  Hand();
  void Dealer(Card dcard); //deals the cards to dealer
  void AddCard(Card card); //deals the cards to player array
  void PrintCard(); //prints the cards.
  void DeleteTotal(); //clears the total.
  bool Bust(); //checks if hand bust
  void DealerPrintHand(); //prints the player hand
  int FindTotal(); //gets the total of the players.
  int NumCards();

};
#endif //HAND_H
