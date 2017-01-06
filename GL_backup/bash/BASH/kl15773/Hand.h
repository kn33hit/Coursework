#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>

class Hand
{
 public:
  // prints the cards in the hand
  void PrintHand();

  // calculates the total value of hand
  int TotalValue();

  // adds a card to the hand
  void AddCard(Card card);

 private:
  std::vector<Card> m_card;
};
