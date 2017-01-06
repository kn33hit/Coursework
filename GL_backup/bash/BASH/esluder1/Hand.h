/****************************************************************              
 * File:    Hand.h                                                           
 * Project: CMSC 202 Project 2, Fall 2014                                    
 * Author:  Eric Sluder                                                        
 * Date:    10/11/14                                                           
 * Section: 1112 - Lecture, 1113 - Discussion                                 
 * E-mail:  esluder1@umbc.edu                                                 
 *                                                                            
 *   This file contains the declarations for the Hand class.            
 *   The class manages and implements the players' hands in a given instance   
 *   of the Blackjack/21 program.                                              
 *                                                                            
 ****************************************************************/

#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include "Deck.h"
#include <vector>
#include <iostream>
using namespace std;

class Hand{
  public:
   //constructors
   /****************************************************************
    * Name: Hand
    *   Default constructor
    * Preconditions:
    *   N/A
    * Postconditions:
    *   establishes a Hand object, with no values
    ****************************************************************/
   Hand();


   //accessors
    /****************************************************************
    * Name: OutputPlayerHand
    *   Iterates through the hand (Card vector), and calls the Card function
    *   OutputCard to display each card
    * Preconditions:
    *   Card vector has cards in it
    * Postconditions:
    *   All cards in hand are displayed to the shell
    ****************************************************************/
   void OutputPlayerHand();

    /****************************************************************
    * Name: OutputDealerHand
    *   Iterates through the hand (Card vector), and calls the Card function
    *   OutputCard to display the first card in the hand. Keeps the hole card
    *   hidden for play purposes. Used only for the dealer in the first showing
    *   of hands after a new deal
    * Preconditions:
    *   Card vector has cards in it
    * Postconditions:
    *   All cards in hand are displayed to the shell, either actual rank/suit
    *   or [hidden card]
    ****************************************************************/
   void OutputDealerHand();
   
   /****************************************************************
    * Name: ReturnHandValue
    *   Collects the value of each card in the hand and adds the values to the
    *   current sum (beginning at 0). Aces are naturally counted as 1, but are
    *   adjusted to 11 depending on the value of the rest of the cards in the
    *   hand (non-ace). The adjusted value is returned
    * Preconditions:
    *   Card vector has cards in it
    * Postconditions:
    *   Hand total is adjusted for ace and hand values, and returned
    ****************************************************************/
   int ReturnHandValue();

   /****************************************************************
    * Name: ReturnHandSize
    *   Gathers and returns the the size of the Player's hand
    * Preconditions:
    *   Card vector exists
    * Postconditions:
    *   Hand size is returned to the calling function
    ****************************************************************/
   int ReturnHandSize();


   //mutators
   /****************************************************************
    * Name: AddToHand
    *   Puts the input card into the Player's hand, at the back
    * Preconditions:
    *   Card vector exists
    * Postconditions:
    *   Card is put at the back of the Player's hand
    ****************************************************************/
   void AddToHand(Card m_inputCard);

   /****************************************************************
    * Name: ResetHand
    *   Clear's all cards from the Player's hand
    * Preconditions:
    *   Card vector exists
    * Postconditions:
    *   The Player's hand is emptied, no cards remain
    ****************************************************************/
   void ResetHand();

  private:
   Card m_inputCard;      //desired new card for adding to hand
   vector<Card> m_cards;  //vector holding all the cards in the hand
   int m_handTotal;       //total value of the cards in the hand
   int m_handSize;        //size of the hand, number of cards in m_cards
   int m_aceCount;        //number of aces the player holds
};

#endif
