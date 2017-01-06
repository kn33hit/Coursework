/****************************************************************
 * File:    Player.cpp
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Denmark Luceriaga
 * Date:    3/18/14
 * Section:
 * E-mail:  dlu1@umbc.edu
 *
 *   This file contains the definitions for the Player class.
 *   This class will keep track of the information about a
 *   single player: their name, their pool of betting funds,
 *   their bet on the current game, etc.
 *
 ****************************************************************/

#include <iostream>
#include <vector>
#include "Player.h"
//#include "Blackjack.h"

using namespace std;

// CONSTRUCTORS

Player::Player() // Sets up player
{
  m_funds = 100;

  m_bet = 0;
  m_bust = false;
}



// ACCESSORS

void Player::UpdateFunds(int player, int bet, bool win)
{
  if(win == true) { // Adds or subtracts bet if winner lost/won
    m_funds = m_funds + bet;
  }
  else {
    m_funds = m_funds - bet;
  }
}

char* Player::GetPlayerName() {
  return m_name;
}

int Player::GetPlayerFunds() {
  return m_funds;
}


int Player::GetPlayerBet() {
  return m_bet;
}

bool Player::GetPlayerBust() {
  return m_bust;
}


bool Player::GetPlayerBJHandAccess() {
 return m_hand.GetPlayerBJHand();
}
// MUTATORS

void Player::SetPlayerName(char* name)
{
  m_name = name;
}

void Player::SetPlayerFunds(int amt) {
  m_funds = amt;
}


void Player::SetPlayerBet(int amt) {
  m_bet = amt;
}

void Player::SetPlayerBust(bool bust) {
  m_bust = bust;
}


// FACILITATORS

void Player::TakeCard(Card newCard) {
  m_hand.PutCardIntoHand(newCard);
}


int Player::LookAtHand() {
  return m_hand.GetHandSize();
}

void Player::LookAtHand(int i) {
  m_hand.LookAtCards(i);
}

void Player::ClearPlayerHand() {
  m_hand.ClearHand();
}

int Player::GetHandValueAccess() {
  return m_hand.GetHandValue();
}
