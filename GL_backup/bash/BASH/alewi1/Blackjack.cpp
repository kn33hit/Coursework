/****************************************************************
 * File:    Blackjack.cpp
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Andrew Lewis
 * Date:    3/20/14
 * Section: 01
 * E-mail:  alewi1@umbc.edu 
 *
 *   This file makes use of the class function declarations in 
 *   Blackjack.h and implements their functions for use in Proj2.cpp
 ****************************************************************/

#include "Blackjack.h"
#include<iostream>

#define DEFAULT_FUNDS 100 //Default fund initializer value


using namespace std;



Blackjack::Blackjack() { //No args constructor

  //creates player "Jane" with $100 initial funds
  m_players.push_back(Player((char*)"Jane", DEFAULT_FUNDS));

  //Default number of players
  m_numPlayers = 1;
}


Blackjack::Blackjack(char* names[], int numPlayers) {


  for (int i = 0; i < numPlayers; i++) {
    //creates new player for each command line arg passed
    m_players.push_back(Player(names[i], DEFAULT_FUNDS));
  }
  // sets value for number of players in game
  m_numPlayers = numPlayers; 
}


int Blackjack::GetNumPlayers() {
  return m_numPlayers;

}



char* Blackjack::GetPlayerName(int player) {
  return m_players[player].GetName();
}


int Blackjack::GetPlayerFunds(int player) {
  return m_players[player].GetFunds();
}


void Blackjack::SetPlayerFunds(int player, int amt) {
  m_players[player].SetFunds(amt);
}

bool Blackjack::SetPlayerBet(int player, int amt) {

  //amount can only be < or = available funds
  if(amt <= m_players[player].GetFunds() ) {
    m_players[player].SetPlayerBet(amt);
    return true;
  }
  else {
    return false;
  }
}


void Blackjack::NewDeal() {
  
  int firstDeal = 2; //used to deal two cards to each user

  //creates a new deck and shuffles it
  m_deck = Deck();
  m_deck.Shuffle();

  //resets player hands
  for (int i = 0; i < m_numPlayers; i++) {
    m_players[i].ResetHand();
    m_players[i].SetBlackjack(false);
  }
  
  //resets dealer hand
  m_dealer.ResetHand();
  m_dealer.SetBlackjack(false);

 
  // loops through twice giving card to player each time
  for (int i = 0; i < firstDeal; i++) {

    for (int j = 0; j < m_numPlayers; j++) {
      
      if (m_deck.CardsLeft() ) {
      	m_players[j].SetCard(m_deck.DealCard());
      }
      // checks if hand contains A & 10 rank card in newly dealt hand for players
      if(m_players[j].HandValue() == 21) {
	m_players[j].SetBlackjack(true);
      }

    }
    //inside first for loop, deals total of two cards to dealer
    if(m_deck.CardsLeft() ) {
      m_dealer.SetCard(m_deck.DealCard());
    }

  }
 
  //checks if dealer has blackjack 
 if(m_dealer.HandValue() == 21) {
    m_dealer.SetBlackjack(true);
  }

  
  

}


void Blackjack::OutputPlayerHand(int player) {
  m_players[player].DisplayCards();
}

void Blackjack::OutputDealerHand() {
  //displays first dealer card and hides the second
  m_dealer.DisplayDealerCards();
}


bool Blackjack::HitPlayer(int player) {

  //exits HitPlayer if player is already busted
  if (m_players[player].IsBusted() ) {
    cout << "True";
    return true;
  }
  
  //checks if cards are in deck and sets card to hand and displays it
  if (m_deck.CardsLeft() ) {
   
    m_players[player].SetCard(m_deck.DealCard() );
    m_players[player].DisplayLastCard();

  }
  else{
    //occurs when no more cards are available from deck
    cout << "No more cards!\n";
    return false;
  }

  //checks if new card busted the player
  if(m_players[player].IsBusted() ) {
    return true;
  }
  else {
    return false;
  }

  
}


void Blackjack::DealerPlay() {

  cout << "Dealers Turn:\n";

  //dealer stays on hand of > or = 17
  if (m_dealer.HandValue() >= 17) {
    cout << "Hand: ";
    m_dealer.DisplayCards();
    cout << endl;
  }

  //loops until dealer has 17 or greater
  while(m_dealer.HandValue() < 17) {
    cout << "Hand: ";
    m_dealer.DisplayCards();
    cout << "\nDealer's Play: hit\n";
    m_dealer.SetCard(m_deck.DealCard() );
    m_dealer.DisplayLastCard();
    cout << endl;

  }
    cout << "\nDealer's Play: stay\n\n";
    cout << "Dealer has " << m_dealer.HandValue() << endl;
}




int Blackjack::SettlePlayerBet(int player) {


  //This section checks if player or dealer busted
  if(m_players[player].IsBusted()) {
    cout << m_players[player].GetName() << " has busted--Dealer wins\n";
    m_players[player].LostBet();
  }

  //when dealer busts and player did not
  else if (m_dealer.IsBusted() && !(m_players[player].IsBusted())) {
    cout << "Dealer has busted--"<< m_players[player].GetName() << " wins!\n"; 
    m_players[player].WonBet();
  }


  //This section compares hand values of Dealer and Player to determine winner
  else if (m_players[player].HandValue() == m_dealer.HandValue()) {

    //sub if conditionals 
    //tie if both players have blackjack
    if(m_dealer.HasBlackjack() && m_players[player].HasBlackjack()){
      cout << m_players[player].GetName() << " has Blackjack--";
      return 0;
    }

    //when both players have 21 but player does not have blackjack
    else if (m_dealer.HasBlackjack() && !(m_players[player].HasBlackjack())) {
      cout << "Dealer has blackjack--Dealer wins!\n";
      m_players[player].LostBet();
      return 0;
    }

    //when player has blackjack and dealer doesn't
    else if (m_players[player].HasBlackjack() && !(m_dealer.HasBlackjack())) {
      cout << m_players[player].GetName() << " has Blackjack--";
      cout << m_players[player].GetName() << " wins!\n";
      m_players[player].WonBet();
      return 0;
    }
    //when neither dealer nor player have blackjack but same hand value
    else {
      cout << "tie\n";
    }
  }


  //when player has smaller hand then dealer
  else if (m_players[player].HandValue() < m_dealer.HandValue() ) {

    //alternate output when dealer has blackjack
    if(m_dealer.HasBlackjack()) {
      cout << "Dealer has blackjack--";
    }
    else{
      cout << m_players[player].GetName() << " has ";
      cout << m_players[player].HandValue() << "--";
    }

    cout <<"Dealer wins!\n";
    m_players[player].LostBet();
  }


  //when player has larger hand
  else if (m_players[player].HandValue() > m_dealer.HandValue() ) {

    if(m_players[player].HasBlackjack()) {
      cout << m_players[player].GetName() << " has blackjack--";
    }
    else {
      cout << m_players[player].GetName() << " has ";
      cout << m_players[player].HandValue() << "--";
    }    

    cout << m_players[player].GetName() << " wins!\n";
    m_players[player].WonBet();
  }

  

  return 0;

}

