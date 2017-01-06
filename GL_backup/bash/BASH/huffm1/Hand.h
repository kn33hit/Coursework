
/****************************************************************                                                                                     
 * File:    Hand.h                                                                                                                             
 * Project: CMSC 202 Project 2, Spring 2014                                                                                                           
 * Author:  Michael Huff                                                                                                                              
 * Date:    3/10/14                                                                                                                                   
 *                                                                                                                                                    
 * This file contains the definition of the Hand class                                                                                               
 ****************************************************************/


#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Deck.h"
#include "Card.h"

class Hand {
public:
  /*
    Hand()
    default constructer, creates an empty hand
  */
  Hand();
  /*
    void addCard(Card newCard)
    adds the specified card to the hand
  */
  void addCard(Card newCard);
  /*
    void printCards()
    neatly prints all the cards in the hand
  */
  void printCards();
  /*
    int handValue()
    returns best possible blackjack value of the hand
  */
  int handValue();
  /*
    void printDealerCards()
    prints the hand with the last card hidden
  */
  void printDealerCards();

private:
  std::vector<Card> m_cards;
};

#endif
