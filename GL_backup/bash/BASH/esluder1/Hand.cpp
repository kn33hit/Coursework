/****************************************************************              
 * File:    Hand.cpp                                                         
 * Project: CMSC 202 Project 2, Fall 2014                                    
 * Author:  Eric Sluder                                                        
 * Date:    10/11/14                                                           
 * Section: 1112 - Lecture, 1113 - Discussion                                  
 * E-mail:  esluder1@umbc.edu                                                  
 *                                                                             
 *   This file contains the workings for the Hand class.                     
 *   The class manages and implements the players' hands in a given instance
 *   of the Blackjack/21 program.                                        
 *                                                                             
 ****************************************************************/

#include "Hand.h"

//default no-arg constructor that just creates an instance of Hand object
Hand::Hand(){
   //do nothing
}

//adds the desired card to the Card vector
void Hand::AddToHand(Card m_inputCard){
   m_cards.push_back(m_inputCard);
}

//iterates through card vector to display rank/suit to the shell using Card
//function call OutputCard
void Hand::OutputPlayerHand(){
   for(unsigned i = 0; i < m_cards.size(); i++){
      m_cards.at(i).OutputCard();
      if(i < (m_cards.size()-1)){
	 cout << ", ";
      }
   }
}

//outputs the dealer's first card rank/suit, hole card displayed as
//[hidden card]
void Hand::OutputDealerHand(){
   for(unsigned i = 0; i < (m_cards.size()); i++){
      if(i == (m_cards.size()-1)){
	 cout << "[hidden card]";
      }
      else{
	 m_cards.at(i).OutputCard();
	 cout << ", ";
      }
   }
}

//resets total hand value to zero, and ace count to zero. iterates through
//cards to add sum values using the Card function GetBlackjackValue for each
//card. Uses the ace count to adjust the value of the hand to maximize value
//without causing a bust (ace is worth 1 or 11)
int Hand::ReturnHandValue(){
   m_handTotal = 0;
   m_aceCount = 0;
   for(int i = 0; i < m_cards.size(); i++){
      m_handTotal += m_cards.at(i).GetBlackjackValue();
      if(m_cards.at(i).GetRank() == 1){
	 m_aceCount++;
      }
   }

   //if the hand value is less than 11, aces should be considered 11, not 1,
   //to maximize hand value
   while(m_handTotal <= 11 && m_aceCount > 0){
      m_handTotal += 10;
      m_aceCount--;
   }

   //returns the ace-adjusted hand total
   return m_handTotal;
}

//gets and returns the size of the cards vector -- hand size
int Hand::ReturnHandSize(){
   m_handSize = m_cards.size();
   return m_handSize;
}

//clears the cards vector for new round (new deal and next round of hitting)
void Hand::ResetHand(){
   m_cards.clear();
}
