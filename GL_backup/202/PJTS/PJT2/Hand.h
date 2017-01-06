/****************************************************************              
 * File:    Hand.h                                                        
 * Project: CMSC 202 Project 2, Spring 2014                                    
 * Author:  Neh Patel                                                          
 * Date:    3/10/14                                                            
 * Section:                                                           
 * E-mail:  npatel10@umbc.edu                                                
 *                                                                             
 *     This file contains the protoypes for the hand class file
 *  The hand is an object which is a subset under the player 
 *  object. The hand holds another object called cards and uses 
 *  functions accordingly                                                       *                    
 ****************************************************************/


#include "Card.h"
#include <vector>
#ifndef HAND_H
#define HAND_H
using namespace std;

class Hand{
 public:
  //CONSTRUCTORS
  
  /* 
     Hand 
        - Deafult constructor does nothing 
     No Preconditions or post conditions 
  */
  Hand();
  
  /*
    Hand(card)
      creates a hand with a given card
    Preconditions: 
        a card object must be created and dealt from the deck
    Postconditions:
        Creates a vector with a card in it 
  */
  Hand(Card card);
  
  //ACCESSOR
  /* 
     GetHand
        returns a vector Cards 
     No PRE or POST conditions 
  */
  vector<Card> GetHand();
  
  //MUTATORS (kind of)
  /* 
     SetHand 
        adds another card into the the hand 
     Precondition:
        none 
     Postconditon:
        a card object is added to the hand vector 
  */
  void SetHand(Card card);  
  

  //FACILITATORS 
  
  /* 
     ShowHand
        prints out all the cards in the hand 
     Preconditon: 
        Should have a card in the hand
     Postcondition:
        prints out the cards usinf the card object function 
  */
  void ShowHand();
  
  /* 
     HandValue 
         returns an integer that represents the total value of all the cards 
     Precondition:
         Must have a card in the hand 
     Postcondition:
         returns a numerical value, which is the sum of all the cards values 
  */
  int HandValue();
  
  /* 
     PrintLastCard
         prints out the very last card that was dealt to the hand 
     Precondition:
         must have a card in the hand 
     Postcondition:
         prints out the last card 
  */ 
  void PrintLastCard(); 
  
  /*
    Clear 
       clears out the cards in the hand 
    precondition: 
       none 
    postconditons
       the vector is empty 
  */
  void Clear();


 private:

  vector <Card> m_hand; // creates a vector that holds cards

};

#endif
