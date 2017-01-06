/****************************************************************
 * File:    Hand.h
 * Project: CMSC 202 Project 2, Fall 2014
 * Author:  Aleksandr Tamarevskiy
 * Date:    10/19/14
 * Section: 3
 * E-mail:  atamar1@umbc.edu
 *
 *   This file contains the declaration for the Hand class
 **************************************************************/
#ifndef HAND_H
#define HAND_H
#include <cstdlib>
#include <vector>
#include "Card.h"
using namespace std;

class Hand {
 public:
  //adds card to hand
  void AddHandCard(Card card){
    vector<Card> hand;
    hand.push_back(card);
    m_hand = hand;
  }
  


 private:
  vector<Card> m_hand;

};
#endif //HAND_H


