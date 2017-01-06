/****************************************************************
 * File:    Player.cpp
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Chandler Deppe
 * UMBC ID: OQ44374
 * Date:    3/22/14
 * Section: 05
 * E-mail:  cdeppe1@umbc.edu
 *
 *   This file contains the implementation for the Player class.
 *
 ****************************************************************/

#include <iostream>
#include <vector>
#include "Player.h"

const int TWENTY_ONE = 21;

using namespace std;

//Player
//default constructor, does nothing
Player::Player() {
}

//Player
//standard constructor, sets up the player with the given name and sets
//  it's data members to starting values
Player::Player(char *name) {
   m_name = name;
   m_busted = false;
   m_funds = 100;
   m_blackjack = false;
}

//GetName
//returns the player's name
char* Player::GetName() {
   return m_name;
}

//GetFunds
//returns the player's funds
int Player::GetFunds() {
   return m_funds;
}

//SetFunds
//sets the player's funds
void Player::SetFunds(int amt) {
   m_funds = amt;
}

//SetBet
//sets the player's current bet
bool Player::SetBet(int amt) {
   if(m_funds < amt)
      return false;
   else {
      m_currentBet = amt;
      return true;
   }
}

//ModifyHand
//adds a card to the player's hand object
void Player::ModifyHand(Card card) {
   m_hand.AddCardToHand(card);
}

//ShowHand
//displays a player's hand to the screen
void Player::ShowHand(bool dealer) {
   m_hand.DisplayHand(dealer);
}

//GetBusted
//returns the player's busted status
bool Player::GetBusted() {
   return m_busted;
}

//CheckBusted
//check the players score and returns if they busted
bool Player::CheckBusted() {
   //get the player's so that m_score is up to date
   GetScore();
   if(m_score <= TWENTY_ONE) {
      SetBusted(false);
      return false;
   }
   else {
      SetBusted(true);
      return true;
   }
}

//SetBusted
//set a player's busted status manually
void Player::SetBusted(bool busted) {
   m_busted = busted;
}

//GetScore
//calculate the player's current score and return it
int Player::GetScore() {
   m_score = m_hand.CountHand();
   return m_score;
}

//GetBlackjack
//returns the player's blackjack status
bool Player::GetBlackjack() {
   return m_blackjack;
}

//DetermineBlackjack
//sets the player's blackjack status by determining if they
//  have blackjack
void Player::DetermineBlackjack() {
   m_blackjack = m_hand.CheckBlackjack(m_score);
}

//ModifyFunds
//modifies the players funds according to whether they've won or not
void Player::ModifyFunds(bool pWin) {
   if(pWin)
      m_funds += m_currentBet;
   else
      m_funds -= m_currentBet;
}

//ClearHand
//clear the player's hand
void Player::ClearHand() {
  m_hand.Clear();
}
