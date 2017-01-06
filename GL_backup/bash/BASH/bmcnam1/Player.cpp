/*************************
 **File:     Player.cpp
 **Project:  CMSC 202 Project 2, Spring 2014
 **Author:   Bernard McNamee
 **Date:     3/19/14
 **Section:  11
 **E-Mail:   bmcnam1@umbc.edu
 **
 **  This file contains the implementations for the functions defined in
 **Player.h 
 *************************/

#include "Player.h"
#include <vector>
#include <iostream>
using namespace std;

//Player
//Default constructor. No args. Creates a player 
//with no name or funds
Player:: Player(){
  char defaultName[20] = "Jane";
  char *name = defaultName; 
  // char *name ="Jane";
  Player(name, 100);
}

//Player
//constructor. Creates a player and sets the name and the 
//total funds
Player::Player(char *name, int money){
  SetName( name );
  SetFund( money );
}

//SetName
//Given the pointer to the name, this will set the 
//player's name to the given name
void Player::SetName(char *name ){ 
  m_name = name; 
  
}

//SetFund
//Given an int value of money, this sets the funds for the player
void Player::SetFund(int money){
    m_fund = money;
}

//SetBetAmount
//given the amount of money the player wants to bet
// this will set the player's bet to the number given
void Player::SetBetAmount(int bet){
   m_bet = bet;
}

//GetName
//This function will return the pointer to the
// name of the player
char *Player::GetName(){
  return m_name;
}

//GetFund
//Returns the total fund of the player
int Player::GetFund(){
  return m_fund;
}

//GetBetAmount
//returns the amount the player wants to bet
int Player::GetBetAmount(){
  return m_bet;
}

