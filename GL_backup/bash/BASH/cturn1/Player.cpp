#include "Player.h"

Player::Player(){
  m_name = (char *) "Jane";
  m_funds = 100;
  m_bet = 0;

}

Player::Player(char *name, int funds){
  m_name = name;
  m_funds = funds;
  m_bet = 0;
  m_hasBusted = false;
  
}

char *Player::GetName(){
  return m_name;
}

void Player::SetName(char *name){
  m_name = name;
}

int Player::GetFunds(){
  return m_funds;
}

void Player::SetFunds(int funds){
  m_funds = funds;
}

int Player::GetBet(){
  return m_bet;
}

void Player::SetBet(int bet){
  m_bet = bet;
}

Hand &Player::GetHand(){
  Hand &hand =  m_hand;
  return hand;
}
bool Player::HasBusted(){
  return m_hasBusted;
}
void Player::SetHasBusted(bool bustorno){
  m_hasBusted = bustorno;
}
