/****************************************************************              
 * File:    Hand.cpp                                                          
 * Project: CMSC 202 Project 2, Spring 2014                                    
 * Author:  Neh Patel                                                          
 * Date:    3/10/14                                                            
 * Section:                                                                    
 * E-mail:  npatel10@umbc.edu                                                  
 *                                                                            
 *     This file contains the fucntions for the hand class file                
 *  The hand is an object which is a subset under the player                   
 *  object. The hand holds another object called cards and uses               
 *  functions accordingly                                                      
 *                                                                             
 ****************************************************************/


#include "Hand.h"
#include <iostream>
using namespace std;
#include <vector>

Hand::Hand(Card card)
{
  m_hand.push_back(card);
}
Hand::Hand()
{
  //deos nothing 
}
void Hand::ShowHand()
{ 
  for(int i = 0; i < ((int) m_hand.size() - 1); i++)
    {
      m_hand[i].OutputCard(); // takes each card and outputs it 
      cout << " ,";
    }
  PrintLastCard(); // did it so the semi-colon is not there after the last card
  cout << endl;

}

int Hand::HandValue()
{
  bool aceExist = false;
  int cardValue = 0;  // always intialize it to zero 
  for(int i = 0; i < (int)m_hand.size(); i++)
    {
      if(m_hand[i].GetRank() == ACE)
	{
	  aceExist = true; // to see if ace is there to account for it later
	  continue; // skip over for now
	}
      cardValue += m_hand[i].GetBlackjackValue(); // adds up all the values 
      if(i == ((int)m_hand.size() - 1)) // when its the last step in the loop
    	{
    	  if(aceExist == true) // if an ace existed in the loop
     	    {
     	      if(cardValue < 11) // if value is less than 11, use 11
     		{
     		  cardValue = cardValue + 11;
    		}
    	      else{  // if 11 or over, use 1
    		cardValue++;
    	      }
    	    }
   	}
    }
  return cardValue;
}

vector<Card> Hand::GetHand()
{
  return m_hand;
}
void Hand::SetHand(Card card)
{
  m_hand.push_back(card);  // just adds onto the vector (bad naming, 
  // but now too late to find it and change it everywhere 
}

void Hand::PrintLastCard()
{
  m_hand[m_hand.size() - 1].OutputCard();// size minus one is the last index
  cout << endl;
}

void Hand::Clear()
{
  m_hand.clear(); // clears out the vector 
}
