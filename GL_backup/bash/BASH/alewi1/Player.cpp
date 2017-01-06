/****************************************************************
 * File:    Player.cpp
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Andrew Lewis
 * Date:    3/20/14
 * Section: 01
 * E-mail:  alewi1@umbc.edu 
 *
 *   This file contains all of the function definitions for the 
 *   Player class. It allows the Blackjack class to create an 
 *   array of players for a blackjack game and perform certain 
 *   useful functions with the player objects
 ****************************************************************/


#include "Player.h"
#include "Hand.h"
#include <cstring>
#include <iostream>
#include<cstdlib>

const int INDEX_SHIFT = 1; //used to shift index 1 to the left

using namespace std;

//default constructor, does nothing
Player::Player() {

}


Player::Player(char *player, int amt) {
  m_player = player;
  m_funds = amt;
  m_hasBlackjack = false; //default is false 
}


int Player::GetAmount() {
  return m_funds;
}


char* Player::GetName() {
  return m_player;
}


int Player::GetFunds() {
  return m_funds;
}

void Player::SetFunds(int amt) {
  m_funds = amt;
}

void Player::SetPlayerBet(int amt) {
  m_betAmt = amt;
}


void Player::SetCard(Card card) {
  m_hand.SetCard(card);
}



void Player::DisplayCards() {

  for (int i = 0; i < m_hand.SizeOf(); i++) {
    m_hand.OutputCard(i);

    //SizeOf()-1 is index of last card in hand
    if(i != m_hand.SizeOf() - INDEX_SHIFT) {
      cout << ", ";
    }
  }
}


void Player::DisplayDealerCards() {

  for (int i = 0; i < m_hand.SizeOf() - INDEX_SHIFT; i++) {
    m_hand.OutputCard(i);
    cout << ", ";

  }
  cout << "[hidden card]";
}


void Player::DisplayLastCard() {
  
  int lastIndex = (m_hand.SizeOf() - INDEX_SHIFT);
  m_hand.OutputCard(lastIndex);
  cout << endl;
}


void Player::SetBlackjack(bool status) {
  //status is whether blackjack was hit or not
  m_hasBlackjack = status;
}

bool Player::HasBlackjack() {
 return m_hasBlackjack;
}


bool Player::IsBusted() {
  
  int counter = 0; //accumulates sum of ranks in hand

  for (int i = 0; i < m_hand.SizeOf(); i++) {
    counter += m_hand.ValueOf(i);
  }
  
  
  if (counter > 21) { //i.e. if player busted
    return true;
  }


  return false;
}



void Player::ResetHand() {
  
  
  m_hasBlackjack = false;
  //resets hand
  m_hand = Hand(); 

}




int Player::HandValue() {
  int counter = 0;
  bool containsAce; //used for adding 10 to hand value if needed
  
  for (int i = 0; i < m_hand.SizeOf(); i++) {
    //increments counter by rank of each card in hand 
    counter += m_hand.ValueOf(i);   

    //if conditional checks if an ace is in hand, Ace has rank 1
    if (m_hand.ValueOf(i) == 1)  {

      containsAce = true;
    }
  }
  
  //the condition in which it is beneficial for player to have higher value ace
  if (counter <= 11 && containsAce) {

    counter += 10;
  }


  return counter;

}

void Player::WonBet() {
  m_funds += m_betAmt;
  
}

void Player::LostBet() {
  m_funds -= m_betAmt; 

} 




