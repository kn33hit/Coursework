#ifndef HAND_H
#define HAND_H
#include<vector>
#include "Card.h"

class Hand
{
 public:
  /****************************************************************
   * Name: Hand
   * Preconditions: none
   * Postconditions:
   *   none-default constructor
   ****************************************************************/
  Hand(); 
  /****************************************************************
   * Name: DisplayCards
   * Preconditions: none
   * Postconditions:
   *   Prints out the cards of the player's hand
   ****************************************************************/
  void DisplayCards();
  /****************************************************************
   * Name: DealerCard
   * Preconditions: none
   * Postconditions:
   *   Prints out cards of the Dealer's hand
   ****************************************************************/
  void DealerCard();
  /****************************************************************
   * Name: addCard
   * Preconditions: 
   *card- Takes in Card type object to be added to hand's
   *collection
   * Postconditions:
   *   Card object is added to the current hand of cards
   ****************************************************************/
  void addCard(Card card);
  /****************************************************************
   * Name: GetDealerValue
   * Preconditions: none
   * Postconditions:
   *   Returns: 
   ****************************************************************/
  void GetDealerValue();
  /****************************************************************
   * Name: sizeOfHand
   * Preconditions: none
   * Postconditions:
   *   Returns: 
   ****************************************************************/
  int sizeOfHand();
  void CurrentCard();
  /****************************************************************
   * Name: TotalValue
   * Preconditions: none
   * Postconditions:
   *   Returns: Total value of the cards in a given player's hand
   ****************************************************************/
  int TotalValue();
 private:
  std::vector<Card> m_currentCards;
  
};
#endif //HAND_H
