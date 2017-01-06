/****************************************************************              
 * File:    Blackjack.cpp                                                      
 * Project: CMSC 202 Project 2, Spring 2014                                    
 * Author:  Neh Patel                                                       
 * Date:    3/10/14                                                          
 * Section:                                                                 
 * E-mail:  npatel10@umbc.edu                                                 
 *                                                                             
 *   This file contains the implementation of the funcitons for the Blackjack
 *   class.
 *   y                                                                    
 ****************************************************************/




#include "Blackjack.h"
#include "Player.h"
#include <iostream>
#include "Hand.h"
#include "Deck.h"
#include "Card.h"
using namespace std;
#include <string>
#include <vector>

// CONSTRUCTORS                                                                
Blackjack::Blackjack()
{
  Player p;
  players.push_back(p);  
}

Blackjack::Blackjack(char *names[], int numPlayers)
{
  
  for(int i = 0; i < numPlayers; i++)
    {
      Player p(names[i]);
      players.push_back(p);
    }
}

int Blackjack::GetNumPlayers()
{
  return players.size();
}

char* Blackjack::GetPlayerName(int player)
{
  return players[player].GetPlayerName();
  
}

int Blackjack::GetPlayerFunds(int player)
{
  return players[player].GetPlayerFunds();
}

void Blackjack::SetPlayerFunds(int player, int amt)
{
  players[player].SetPlayerFunds(amt);
}

bool Blackjack::SetPlayerBet(int player, int amt)
{
  int funds = players[player].GetPlayerFunds();
  players[player].SetPlayerBet(amt);
  funds -= amt;
  if(funds < 1)
    { 
      return false;
    }
  players[player].SetFundsAfterBet(amt);
  return true;
  // STILL NEED TO FIX THIS 
}

void Blackjack::NewDeal()
{
  m_deck = Deck();  // make deck
  m_deck.Shuffle();  // shuffle deck
  if(m_deck.CardsLeft() > 0) // checking if there are still cards in the deck
  {
    int n = 1; // to deal two cards to each player and the dealer
    while(n <= 2) // just run twice loop
      {
	for(int i = 0; i < (int)players.size(); i++)  // for each player
	  {
	    players[i].SetPlayerHand(m_deck.DealCard());  // deal 2 cards
	  }
	m_dealer.SetPlayerHand(m_deck.DealCard());
	n++; 
      }
  }
  else{
    cout << "Not enough cards in the deck" << endl;
  }
}

void Blackjack::OutputPlayerHand(int player)
{
  players[player].OutputPlayerHand();
}

void Blackjack::OutputDealerHand()
{
  m_dealer.OutputDealerHand();   // MAKE A NEW FUNCTION!! 
}

bool Blackjack::HitPlayer(int player)
{
  if(players[player].GetPlayerBusted() == false) // if player is not busted 
    {
      if(players[player].GetBlackjackValue() > 22)
	{     // if value gets over 21 player is busted 
	  players[player].SetPlayerBusted(true);
	  return true;
	}
      else{
      players[player].SetPlayerHand(m_deck.DealCard());
      players[player].PrintLatestCard();
      return false;
      }
    }
  return true;
}

void Blackjack::DealerPlay()
{
  cout << "Dealer's turn:" << endl;
  cout << "Hand: ";
  m_dealer.OutputPlayerHand();
  while(m_dealer.GetBlackjackValue() < 17) // loop and hit till dealer is above
    // 17
    {
      cout << "Dealer's play: hit" << endl;
      m_dealer.SetPlayerHand(m_deck.DealCard());
      m_dealer.PrintLatestCard();
    }
  if(m_dealer.GetBlackjackValue() >= 17)
    {
      cout << "Dealer's play: stay" << endl;
    }
}

int Blackjack::SettlePlayerBet(int player)
{
  int funds = players[player].GetPlayerFunds();
  int bet = players[player].GetCurrentBet();
  
  if(players[player].GetPlayerBusted() == false)
    {
  if(players[player].GetBlackjackValue() > m_dealer.GetBlackjackValue())
    {
      players[player].SetPlayerFunds(funds + bet * 2);
      cout << players[player].GetPlayerName() << " has " << players[player].\
	GetBlackjackValue() << "--Dealer loses" << endl;
    }
  if(players[player].GetBlackjackValue() < m_dealer.GetBlackjackValue())
	   {
	     cout << m_dealer.GetPlayerName() << " has " <<	   \
	     m_dealer.GetBlackjackValue() << "--Dealer wins"<< endl;
	   }
  if(players[player].GetBlackjackValue() == m_dealer.GetBlackjackValue())
    {
      cout << "Its a tie" << endl;
      players[player].SetPlayerFunds(funds + bet);
    }
    }
  if(m_dealer.GetPlayerBusted() == true && players[player].GetPlayerBusted() ==false)
    {
      cout << "Dealer has busted--" << players[player].GetPlayerName() << \
	" wins";
      players[player].SetPlayerFunds(funds + bet * 2);
    }

  if(m_dealer.GetPlayerBusted() == false && players[player].GetPlayerBusted() == true)
    {
      cout << players[player].GetPlayerName() <<" has busted--Dealer wins";
    }

  players[player].SetPlayerBet(0);
  m_dealer.SetPlayerBet(0);
  players[player].SetPlayerBusted(false);
  m_dealer.SetPlayerBusted(false);
  players[player].ClearHand();  // empties the players hands
  m_dealer.ClearHand(); // empties the dealers hands 
  return 0;
}
