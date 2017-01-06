/****************************************************************
 * File:    Blackjack.cpp
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Denmark Luceriaga
 * Date:    3/18/14
 * Section:
 * E-mail:  dlu1@umbc.edu
 *
 *   This file contains the definitions for the Blackjack class.
 *   The class manages and implements the mechanics for a multi-player
 *   version of the Blackjack/21 program, including bets.
 *
 ****************************************************************/


#include <vector>
#include "Player.h"
#include "Hand.h"
#include "Deck.h"
#include "Blackjack.h"

#define BLACKJACK_21 21 // Max winning value
#define DEALER_INI 17 // Value dealer needs to stop hitting at

using namespace std;




Blackjack::Blackjack() // Default, useless constructor
{
  Player m_jane;
  m_jane.SetPlayerName((char*)"Jane");
  m_jane.SetPlayerFunds(100);

  Player m_dealer;
  m_dealer.SetPlayerName((char*)"Dealer");
  m_dealer.SetPlayerFunds(100);

}



Blackjack::Blackjack(char *names[], int numPlayers)
{
  int defaultFunds = 100;
  for(int i = 0; i < numPlayers; i++) // Loop to create players
    {
      m_players.push_back(Player());
      SetPlayerFunds(i, defaultFunds);
      m_players[i].SetPlayerName(names[i]);
    }
  m_dealer.SetPlayerName((char*)"Dealer"); // Create dealer

  m_dealer.SetPlayerFunds(defaultFunds);
}



int Blackjack::GetNumPlayers()
{
  int numPlayers; 
  numPlayers = m_players.size(); // size of vector is number of players
  return numPlayers;
}



char* Blackjack::GetPlayerName(int player)
{
  char* playerName;
  playerName = m_players[player].GetPlayerName(); // Use accessor
  return playerName;
}




int Blackjack::GetPlayerFunds(int player)
{
  int playerFunds;
  playerFunds = m_players[player].GetPlayerFunds(); // Use accessor
  return playerFunds;
}



void Blackjack::SetPlayerFunds(int player, int amt)
{
  m_players[player].SetPlayerFunds(amt); // Use mutator
}





bool Blackjack::SetPlayerBet(int player, int amt)
{
  m_players[player].SetPlayerBet(amt); 
  if(amt > m_players[player].GetPlayerFunds())
    {
      return false;
    }
  else
    {
      return true;
    }
}




void Blackjack::NewDeal()
{
  int numPlayers = m_players.size();
  m_deck.Shuffle();

  for(int k = 0; k < numPlayers; k++) { // Clear all players hands
    m_players[k].ClearPlayerHand();
  }
  m_dealer.ClearPlayerHand(); // Clear dealer's hand
  for(int j = 0; j < 2 ; j++) // Deal two cards each player
    {
      for(int i = 0; i < numPlayers ; i++)
	{
	  Card newCard;
	  newCard = m_deck.DealCard();
	  m_players[i].TakeCard(newCard);
	}
      m_dealer.TakeCard(m_deck.DealCard());
    }
}



void Blackjack::OutputPlayerHand(int player) {
  for(int i = 0; i < m_players[player].LookAtHand() ; i++) {
    m_players[player].LookAtHand(i); // Use Accessors
    cout << ", ";
  }
  //  cout << endl;
}


void Blackjack::OutputDealerHand() { // For outputting dealer's hand first time
  m_dealer.LookAtHand();
  cout << ", [hidden card]\n";
 }




void Blackjack::OutputDealerHand(bool dealerTurn) { // All other times outputting dealer's hand
  if(dealerTurn) {
    for(int i = 0; i < m_dealer.LookAtHand() ; i++) {
      m_dealer.LookAtHand(i);
      cout << ", ";     
    }
    //  cout << endl;
  }
}



bool Blackjack::HitPlayer(int player)
{
  Card hit = m_deck.DealCard();
  m_players[player].TakeCard(hit);
  hit.OutputCard();
  cout << endl;
  int playerHandValue = m_players[player].GetHandValueAccess();

  if(playerHandValue > BLACKJACK_21) { // Determine if player busted from hit
    m_players[player].SetPlayerBust(true);
    return true;
  }
  else {
    return false;
  }
}

 
 

void Blackjack::DealerPlay() { // Mimics player turn
  cout << ">> Dealer's turn:\n";
  int dealerHandValue = m_dealer.GetHandValueAccess();

  while(dealerHandValue < DEALER_INI) // Must have at least 17 to stay
	  {
	  cout << "Hand: ";
	  bool dealerTurn = true;
	  OutputDealerHand(dealerTurn);
	  cout << endl;
	  cout << "Dealer's play: hit" << endl;
	  Card hit = m_deck.DealCard();
	  m_dealer.TakeCard(hit);
	  dealerHandValue = m_dealer.GetHandValueAccess();
	  }

  if(dealerHandValue > BLACKJACK_21) {
    cout << "Busted!\n";
    m_dealer.SetPlayerBust(true);
  }
  else {
    cout << "Hand: ";
    bool dealerTurn = true;
    OutputDealerHand(dealerTurn);
    cout << endl;
    cout << "Dealer's play: stay" << endl;
  }

  cout << endl;

  if(m_dealer.GetPlayerBust() == false) {
    cout << "Dealer has " << dealerHandValue << endl;
  }
  else {
    cout << "Dealer has busted\n";
  }

}



int Blackjack::SettlePlayerBet(int player) {
  int dealerHandValue = m_dealer.GetHandValueAccess();


  int playerHandValue = m_players[player].GetHandValueAccess();
  bool win = false;
  // Logic for all possible outocmes of game
  if(m_players[player].GetPlayerBust() == false) {
    cout << m_players[player].GetPlayerName() << " has " << playerHandValue << "--";
    if(playerHandValue > dealerHandValue || m_dealer.GetPlayerBust() == true) {
      cout << m_players[player].GetPlayerName() << " wins\n";
      win = true;
      m_players[player].UpdateFunds(player, m_players[player].GetPlayerBet(), win);
    }
    else if(playerHandValue < dealerHandValue && m_dealer.GetPlayerBust() == false) {
      cout << "Dealer wins\n";
      win = false;
      m_players[player].UpdateFunds(player, m_players[player].GetPlayerBet(), win);
    }
    else if(playerHandValue == dealerHandValue) {
      if(m_players[player].GetPlayerBJHandAccess() == false && m_dealer.GetPlayerBJHandAccess() == false) {
	cout << "Push\n";
      }
      else if(m_players[player].GetPlayerBJHandAccess() == true && m_dealer.GetPlayerBJHandAccess() == false) {
	cout << m_players[player].GetPlayerName() << " wins\n";
	win = true;
	m_players[player].UpdateFunds(player, m_players[player].GetPlayerBet(), win);
      }
      else if(m_players[player].GetPlayerBJHandAccess() == false && m_dealer.GetPlayerBJHandAccess() == true) {
	cout << "Dealer wins\n";
	win = false;
	m_players[player].UpdateFunds(player, m_players[player].GetPlayerBet(), win);
      }
    }
  }
  else {
    cout << m_players[player].GetPlayerName() << " has busted--"; 
    if(m_dealer.GetPlayerBust() == false) {
      cout << "Dealer wins\n";
      win = false;
      m_players[player].UpdateFunds(player, m_players[player].GetPlayerBet(), win);
    }
    else {
      cout << "Push\n";
    }
  }
  return 0;
}



 


