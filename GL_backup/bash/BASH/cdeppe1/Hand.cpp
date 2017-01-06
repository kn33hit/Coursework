/****************************************************************
 * File:    Hand.cpp
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Chandler Deppe
 * UMBC ID: OQ44374
 * Date:    3/22/14
 * Section: 05
 * E-mail:  cdeppe1@umbc.edu
 *
 *   This file contains the implementation for the Hand class.
 *
 ****************************************************************/

#include <iostream>
#include "Hand.h"

using namespace std;

//Hand
//default constructor, does nothing
Hand::Hand() {
}

//DisplayHand
//outputs the players hand to th screen
void Hand::DisplayHand(bool dealer) {
   int size = m_cards.size();

   //if dealer is false
   if(!dealer) {
      for(int i = 0; i < size; i++) {
	 m_cards[i].OutputCard();
	 if(i < size - 1)
	    cout << ", ";
      }
   }

   //dealer is true
   else {
      for(int i = 0; i < (size - 1); i++) {
	 m_cards[i].OutputCard();
	 if(i < size - 1)
	    cout << ", ";
      }
      cout << "[hidden card]";
   }
}

//AddCardToHand
//adds a card to the vector m_cards
void Hand::AddCardToHand(Card card) {
   m_cards.push_back(card);
}

//Clear
//clears the vector m_cards
void Hand::Clear() {
   m_cards.clear();
}

//CountHand
//counts a players total score from their hand
int Hand::CountHand() {
   //set up needed variables
   int aceCount = 0, score = 0, size = m_cards.size();
   
   for(int i = 0; i < size; i++) {
      if(m_cards[i].GetBlackjackValue() == 1) {
	 //when there is an ace add 1 first and up aceCount
         aceCount++;
	 score++;
      }
      else
         score+=m_cards[i].GetBlackjackValue();
   }

   //if they can do an entire ace (11 points) then this adds ten
   //  to their score, otherwise the loop exits
   for(int i = 0; i < aceCount; i++) {
     if(score + 10 <= 21)
       score+=10;
   }  

   return score;
}

//CheckBlackjack
//determines if a player has blackjack and returns accordingly
bool Hand::CheckBlackjack(int score) {
   //appropriate criteria for blackjack
   bool sizeCriteria = false, scoreCriteria = false, aceCriteria = false;

   //test each criteria
   //amount of cards must be 2
   if(m_cards.size() == 2)
      sizeCriteria = true;
   //must have atleast one ace
   if(m_cards[1].GetBlackjackValue() == 1 || m_cards[2].GetBlackjackValue() == 1)
      aceCriteria = true;
   //must have a score of 21
   if(score == 21)
      scoreCriteria = true;

   //if all criteria are true then the player has blackjack
   if(sizeCriteria && scoreCriteria && aceCriteria)
      return true;
   else
     return false;
}
