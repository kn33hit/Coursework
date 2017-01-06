/****************************************************************
 * File:    Hand.cpp
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Denmark Luceriaga
 * Date:    3/20/14
 * Section:
 * E-mail:  dlu1@umbc.edu
 *
 *   This file contains the definitions for the Hand class.
 *   This class will manage the cards a single player has been
 *   dealt so far, and will provide member functions for printing
 *   out the cards in the hand, determining the total value of
 *   the cards in the hand, etc.
 ****************************************************************/


#include <iostream>
#include <vector>
//#include "Player.h"
//#include "Blackjack.h"
#include "Hand.h"

using namespace std;


Hand::Hand()
{
  m_newHand = true;
}

// ACCESSORS

int Hand::GetHandValue()
{
  int handValue = 0;
  int numCards = m_cards.size();
  for(int i = 0; i < numCards; i++) { // Loops through each card
    int card = m_cards[i].GetBlackjackValue();
    handValue = handValue + card;
  }
  if((m_cards.size() == 2) && (handValue == 21)) {
    bjhand = true;
  }
  return handValue;
}

int Hand::GetHandSize() {
  return m_cards.size();
}

bool Hand::GetPlayerBJHand() {
  return bjhand;
}

// MUTATORS

void Hand::PutCardIntoHand(Card newCard) {
  m_cards.push_back(newCard); // Adds card to vector
}


// FACILITATORS

void Hand::LookAtCards(int i) {
  m_cards[i].OutputCard();
}

void Hand::ClearHand() {
  m_cards.clear();
}
