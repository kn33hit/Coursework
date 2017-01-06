/****************************************************************                                                                                     
 * File:    Blackjack.cpp                                                                                                                             
 * Project: CMSC 202 Project 2, Spring 2014                                                                                                           
 * Author:  Michael Huff                                                                                                                              
 * Date:    3/10/14                                                                                                                                   
 * Section: all                                                                                                                                       
 *                                                                                                                                                    
 * This file contains the implimentation of the Player class       
 ****************************************************************/


#include "Player.h"

using namespace std;

Player::Player(){
  m_cash = 100;
  strcpy(m_name,"Jane");
}

Player::Player(string name){
  m_cash = 100;
  strcpy(m_name, name.c_str());
}

Player::Player(string name, int cash){
  m_cash = cash;
  strcpy(m_name, name.c_str());
}

char *Player::GetName(){
  return m_name;
}

int Player::getCash(){
  return m_cash;
}

void Player::setCash(int cash){
  m_cash = cash;
}

void Player::addCard(Card newCard){
  m_hand.addCard(newCard);
}

void Player::setBet(int bet){
  m_currentBet = bet;
}

void Player::won(){
  m_cash+=m_currentBet;
  m_currentBet = 0;
  if(m_hand.handValue() <21)
    cout << m_name << " has " << m_hand.handValue() <<"--"<< m_name << " wins"<<endl;
  else
    cout << m_name << " has Blackjack--"<<m_name<<"  wins"<<endl;

}

void Player::tied(){
  m_currentBet = 0;
  if(m_hand.handValue() <21)
    cout << m_name << " has " << m_hand.handValue() << "--tie"<<endl;
  else if (m_hand.handValue() == 21){
    cout << m_name << " has Blackjack--tie"<<endl;
  }
  else
    cout << m_name << " has busted--tie"<<endl;

}

void Player::lost(){
  m_cash-=m_currentBet;
  m_currentBet = 0;
  if(m_hand.handValue() <=21)
    cout << m_name << " has " << m_hand.handValue() << "--Dealer wins"<<endl;
  else
    cout << m_name << " has busted--Dealer wins"<<endl;
}

void Player::printHand(){
  m_hand.printCards();
}

void Player::printDealerHand(){
  m_hand.printDealerCards();
}

bool Player::isBust(){
  if(m_hand.handValue() > 21){
    return true;
  }
  else{
    return false;
  }
}

void Player::resetHand(){
  m_hand = Hand();
}

int Player::getHandValue(){
  return m_hand.handValue();
}
