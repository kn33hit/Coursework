/****************************************************************
 * File:    Blackjack.cpp
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Michael Huff                                                                    
 * Date:    3/10/14                                                                                                                                   
 * Section: all                                                                                                                                       
 *
 * This file contains the implimentation of the blackjack class
 ****************************************************************/


#include "Blackjack.h"
using namespace std;

Blackjack::Blackjack(){
  m_players.insert(m_players.end(), Player());
}

Blackjack::Blackjack(char *names[], int numPlayers){
  for (int i = 0; i < numPlayers; i++){
    m_players.insert(m_players.end(), Player(names[i]));
  }
}

int Blackjack::GetNumPlayers(){
  return m_players.size();
}

char *Blackjack::GetPlayerName(int player){
  return m_players[player].GetName();
}

int Blackjack::GetPlayerFunds(int player){
  return m_players[player].getCash();
}

void Blackjack::SetPlayerFunds(int player, int amt){
  m_players[player].setCash(amt);
}

bool Blackjack::SetPlayerBet(int player, int amt){
    
  if(m_players[player].getCash() < amt){
    return false;
  }
  else {
    m_players[player].setBet(amt);
  }
  return true;
}

void Blackjack::NewDeal(){
  m_deck=Deck();
  m_deck.Shuffle();
  m_dealer.resetHand();
  for(int i = 0; i < 2; i++){
    for(int ii = 0; ii < m_players.size(); ii++){
      m_players[ii].addCard(m_deck.DealCard());
    }
    m_dealer.addCard(m_deck.DealCard());
  }
}

void Blackjack::OutputPlayerHand(int player){
  m_players[player].printHand();
}

void Blackjack::OutputDealerHand(){
  m_dealer.printDealerHand();
}

bool Blackjack::HitPlayer(int player){
  Card topCard = m_deck.DealCard();
  if(m_players[player].isBust()==false){
    m_players[player].addCard(topCard);
    topCard.OutputCard();
    cout << "\n";
    if(m_players[player].isBust()){
      return true;
    }
    else
      return false;
  }
  return false;
}

void Blackjack::DealerPlay(){
  cout << "Dealer has: ";
  Card temp = m_deck.DealCard();
  while(m_dealer.getHandValue() < 17){
    m_dealer.addCard(temp);
    temp = m_deck.DealCard();
  }
  m_dealer.printHand();
  cout << "\n";
}

int Blackjack::SettlePlayerBet(int player){
  if((m_dealer.getHandValue() > m_players[player].getHandValue() && m_dealer.isBust() == false) || m_players[player].isBust())
    m_players[player].lost();

  else if(m_dealer.getHandValue() == m_players[player].getHandValue())
    m_players[player].tied();
  else
    m_players[player].won();

  m_players[player].resetHand();
  return 0;
}
