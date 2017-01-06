/****************************************************************
 * File:    Player.cpp
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Aleksandr Tamarevskiy
 * Date:    10/19/14
 * Section: 3
 * E-mail:  atamar1@umbc.edu
 *
 *   This file contains the declaration for the Player class.
 *
 ****************************************************************/

#ifndef PLAYER_H
#define PLAYER_H
#include "Hand.h"

class Player {
 public:
  
  /****************************************************************
   *These functions set all private variables for the player
   ***************************************************************/

  void SetPlayerName(char name){
    p_name = name;
  }
  void SetPlayerBust(int bust){
    p_bust = bust;
  }
  void SetPlayerFunds(int funds){
    p_funds = funds;
  }
  void SetPlayerHand(Hand hand){
    p_hand = hand; //DEFINE THIS
  }
  
  void SetPlayerBet(int bet){
    p_bet = bet;
  }
  

  /****************************************************************
   * These functions return all private variables for the player
   *
   ***************************************************************/
  char GetPlayerName(){
    return p_name;
  }  
  bool GetPlayerBust(){
    return p_bust;
  }
  int GetPlayerFunds(){
    return p_funds;
  }
  Hand GetPlayerHand(){
    return p_hand;
  }
  char GetPlayerBet(){
    return p_bet;
  }


 private:
  char p_name;
  bool p_bust;
  int p_funds;
  Hand p_hand;
  int p_bet;
};


#endif //PLAYER_H
