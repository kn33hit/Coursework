/****************************************************************              
 * File:    Player.h                                                          
 * Project: CMSC 202 Project 2, Spring 2014                                    
 * Author:  Neh Patel                                                          
 * Date:    3/10/14                                                            
 * Section:                                                                    
 * E-mail:  npatel10@umbc.edu                                                  
 *                                                                            
 *     this file containt the protoypes for the Player class file             
 *  The hand is an object which is a subset under the Blackjack game.          
 *  The hand holds another object called hand and uses                
 *  functions accordingly.                                                     
 *                                                                            
 ****************************************************************/


#include "Hand.h"
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player {
  
 private:
  char* m_playerName;
  int m_playerFunds;
  int m_currentBet;
  Hand m_hand;
  bool m_busted;
  
 public:

 
  /*
    Player
       default contructor. name = Jane, funds = 100, busted = false;
    Preconditon:
       none
    Postcondition:
       none
  */
  Player();
  
  /*                                                                           
    Player(name)                                                                       contructor, creates a new player with given name and $100 funds 
        also is set to not busted yet 
    Preconditon:                                                               
        none                                                                  
    Postcondition:                                                            
        none                                                                  
  */
  Player(char* name);
  
  
  /*                                                                           
    GetPlayerName                                                                     gets the name of the player 
    Preconditon:                                                               
       none                                                                   
    Postcondition:                                                                    returns an array of characters which is the name of the player
  */
  char* GetPlayerName();
  
  /*                                                                           
    GetPlayerFunds
       gets the amount of funds the player has on them currently 
    Preconditon:                                                               
       none                                                                  
    Postcondition:                                                                    returns the funds of the player                                           */
  int GetPlayerFunds();
  
  /*                                                                           
    GetPlayerBet								      gets the amount the player has bet currently	      
    Preconditon:                                                               
       none                                                                   
    Postcondition:                                                             
       returns the amount the player has bet                                   
  */
  int GetPlayerBet();
  
  /*                                                                           
    SetPlayerFunds                                                                    setting the players funds         
    Preconditon:                                                               
       none                                                                  
    Postcondition:                                                             
       the funds are set to the entered value                                  
  */
  void SetPlayerFunds(int amt);
  
  /*                                                                           
    GetCurrentBet
       returns the value of the current bet 
    Preconditon:                                                               
       none                                                                   
    Postcondition:                                                             
       returns a value                                                       
  */
  int GetCurrentBet();

  /*                                                                           
    GetPlayerHand                                                                     returns a vector of cards, basically the entire hand       
    Preconditon:                                                              
       hand object must exist and must have cards in it                       
    Postcondition:                                                             
       returns a vector                                                       
  */
  vector<Card> GetPlayerHand();
  
  /*                                                                           
    GetPlayerBusted                                                                   gets if the player is busted or not         
    Preconditon:                                                              
       none                                                                   
    Postcondition:                                                             
       returns the vector                                                      
  */
  bool GetPlayerBusted();
  
  /*                                                                           
    GetBlackjackValue                                                                 returns the sum of the cards values that the player has in his hand    
    Preconditon:                                                               
       cards must exist in the hand                                           
    Postcondition:                                                             
       returns a numeric value                                                   */
  int GetBlackjackValue();
  

   

  /*                                                                           
    SetName                                                                           sets the name of the player. just a convention to have a mutator 
       this function wont be used at all according to the game
    Preconditon:                                                               
       player must exist                                                       
    Postcondition:                                                             
       sets the vairbale name to the given name                        
  */
  void SetName(char* name);
  
  /*                                                                           
    SetCurrentBet                                                                     sets the current bet      
    Preconditon:                                                               
       player class must exist 
    Postcondition:                                                             
       sets the variable current bet to the new given amount                   
  */
  void SetCurrentBet(int amt);
  
  /*                                                                           
    SetFundsAfterBet                                                                  subtracts the amount of bet from the funds          
    Preconditon:                                                               
       player object must exist and should have sufficient funds             
    Postcondition:                                                             
       changes the funds after the bet is entered                          
  */
  void SetFundsAfterBet(int amt);
  
  /*                                                                           
    SetPlayerBet                                                                      set the players bet entered        
    Preconditon:                                                              
       player object must exist                                               
    Postcondition:                                                             
       sets the variable to the entered amount                                
  */
  void SetPlayerBet(int amt);
  
  /*                                                                           
									       SetPlayerBusted                                                                      sets the entered boolean as the new busted variable. true if busted, 
      false if not    
    Preconditon:                                                              
      Player object must exist                                               
    Postcondition:                                                             
      sets the boolean variable to the passed boolean                        
  */
  void SetPlayerBusted(bool busted);
  
  /*                                                                           
    SetPlayerHand                                                                     adds another card to the hand object       
    Preconditon:                                                              
       card must be dealt from the deck                                   
    Postcondition:                                                             
       adds another card to the hand                                        
  */
  void SetPlayerHand(Card card);
  
  
  /*                                                                           
    ResetFunds                                                                       resets the funds to $100 if want to, just a random helper function if          wanted
    Preconditon:                                                               
      Player must exist                                                       
    Postcondition:                                                            
      resets the funds variable                                               
  */
  void ResetFunds();
  
  /*                                                                           
    OutputPlayerHand                                                                    outputs the entire hand of the player       
    Preconditon:                                                               
         cards must be in hand                                                 
    Postcondition:                                                             
         outputs all the cards in the players hand                         
  */
  void OutputPlayerHand();

  /* 
     OutputDealerHand
        outputs the dealers hand 
     precondition 
        2 cards in hand 
     postcondion 
        outputs a card and "hidden card"
  */
  void OutputDealerHand();
  /*                                                                           
    PrintLatestCard                                                                   prints the last card. Just another extra function but will be used             this time 
    Preconditon:                                                              
       card must be there in the hand                                          
    Postcondition:                                                             
       prints a card                              
  */
  void PrintLatestCard();

  /* 
     clearHand 
        clears out all the cards in the hand vector 
      preconditons
        cards must exist 
      postconditions 
         clears out the cards from the hand 
  */
   void ClearHand();
};
#endif 
