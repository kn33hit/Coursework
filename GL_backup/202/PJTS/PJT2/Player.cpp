/****************************************************************              
 * File:    Player.cpp                                                         
 * Project: CMSC 202 Project 2, Spring 2014                                    
 * Author:  Neh Patel                                                          
 * Date:    3/10/14                                                            
 * Section:                                                                    
 * E-mail:  npatel10@umbc.edu                                                  
 *                                                                             
 *     this file containt the functions for the Player class file              
 *  The hand is an object which is a subset under the Blackjack game.          
 *  The hand holds another object called hand and uses                         
 *  functions accordingly.                                                     
 *                                                                             
 ****************************************************************/

#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
  m_playerName = "Jane";
  m_playerFunds = 100;
  m_busted = false;  // all players not busted by default 
}

Player::Player(char* name)
{
  m_playerName = name;
  m_playerFunds = 100;
  m_busted = false;
}

char* Player::GetPlayerName()
{
  return m_playerName;
}
int Player::GetPlayerFunds()
{
  return m_playerFunds;
}

int Player::GetCurrentBet()
{
  return m_currentBet;
}

void Player::SetName(char* name)
{ 
  m_playerName = name;
}

void Player::SetPlayerFunds(int amt)
{
  m_playerFunds = amt;  // if the funds are set manually 
} 

void Player::SetPlayerBet(int amt)
{
  m_currentBet = amt;  // sets player's bet 
}

void Player::SetFundsAfterBet(int amt)
{
  m_playerFunds -= amt;  // funds after the bet is placed 
}

void Player::SetPlayerHand(Card card)
{
  m_hand.SetHand(card);  // adds the card onto the hand 
}

vector<Card> Player::GetPlayerHand()
{
  return m_hand.GetHand();
}
void Player::OutputPlayerHand()
{
  m_hand.ShowHand();
}

void Player::PrintLatestCard()
{
  m_hand.PrintLastCard();
}

void Player::OutputDealerHand()
{
 
  m_hand.PrintLastCard();
  cout << ", [hidden card]" << endl;
    
}
void Player::SetPlayerBusted(bool busted)
{
  m_busted = busted;
}

bool Player::GetPlayerBusted()
{
  return m_busted;
}

int Player::GetBlackjackValue()
{
  return m_hand.HandValue();
}

void Player::ClearHand()
{
  m_hand.Clear();
}
