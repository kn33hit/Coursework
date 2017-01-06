#include <iostream>
#include "Player.h"
using namespace std;

Player :: Player(){
  m_name = "Jane";
  m_funds = 100;
}

Player :: Player(char* name, int funds){
  m_name = name;
  m_funds = funds;
}

char* Player :: GetName(){
  return m_name;
}

int Player :: GetFunds(){
  return m_funds;
}

int Player :: GetBet(){
  return m_bet;
}

void Player :: SetBet(int amt){
  m_bet = amt;
}

void Player :: SetName(char* name){
  m_name = name;
}

void Player :: SetFunds(int amt){
  m_funds = amt;
}

void Player :: PrintCard(){
  m_hand.PrintHand();
}

void Player :: InsertCardRef(Card c){
  m_hand.InsertCard(c);
}

bool Player :: CheckSum(){
  bool flag = true;
  if(m_hand.GetSum() > 21){
    flag = false;
  }
  return flag;
}

int Player :: GetSumRef(){
  return  m_hand.GetSum();
}
