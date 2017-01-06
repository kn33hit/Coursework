/*************************
**File:     Hand.cpp
**Project:  CMSC 202 Project 2, Spring 2014
**Author:   Bernard McNamee
**Date:     3/19/14
**Section:  11
**E-Mail:   bmcnam1@umbc.edu
 **
 **  This file contains the implementations for the functions defined in
 **Hand.h and are used in the Blackjack file
 *************************/

#include "Hand.h"
#include <vector>
#include <iostream>
using namespace std;
//Hand
//Constructor. Creates initializes a hand object
Hand::Hand(){
}

//PrintPlayerHand
//Will print out all the cards in a player's hand
void Hand::PrintPlayerHand(){
  Card c; 
  //loops throught the hand and prints the card
  for(int i = 0;i<(int)m_hand.size();i++){
    c = m_hand[i];
    //prints the card
    c.OutputCard();
    cout<<",  ";
  }
}

//GetTotalHand
//will add up the nummerical value of all the cards in the 
//hand and prints them out
int Hand::GetTotalHand(){
  Card c;
  int valueOne =0;
  int valueEleven = 0;
  //adds up the hand where the ace counts as a one
  for(int i= 0;i<(int)m_hand.size();i++){
    c = m_hand[i];
    switch(c.GetRank()) {
      case JACK:
      case QUEEN:
      case KING:
        valueOne += 10;
        break;
      default:
        valueOne += static_cast<int>(c.GetRank());  //Ace = 1;
      }
  }
  //adds up the hand where the ace counts as an 11
  for(int j =0;j<(int)m_hand.size();j++){
    c = m_hand[j];
    switch(c.GetRank()) {
    case JACK:
    case QUEEN:
    case KING:
      valueEleven += 10;
      break;
    case ACE:
      valueEleven += 11;
      break;
    default:
      valueEleven += static_cast<int>(c.GetRank());  //Does not include Ace;
    }

  }
  //there is no ace 
   if(valueEleven == valueOne){
      return valueEleven;
      //returns value with the ace as an 11
    }else if(valueEleven<=21){
      return valueEleven;
    }else{
     //returns the value with the ace as a 1
      return valueOne;
    }
}

//AddTohand
//Will push a card object onto the hand vector
void  Hand::AddToHand(Card c){
  m_hand.push_back(c);
}

//Clear hand 
//Will remove all cards from the hand vector
void Hand::ClearHand(){
  m_hand.clear();
}

//HasBlackJack
//will return true if the player's hand has only an ace and a 
//ten value card. Else it will return false
bool Hand::HasBlackjack(){
  if(GetTotalHand()== 21 && m_hand.size()== 2){
    return true;
  }else{
    return false;
  }
}
