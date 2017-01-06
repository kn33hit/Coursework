//File: Blackjack.cpp
#include <iostream>
#include "Blackjack.h"

//This is the Blackjack class 
//which will consists of the methods for the gameplay
using namespace std;

Blackjack::Blackjack()
{
}
Blackjack::Blackjack(char *names[], int numPlayers)
{
  for (int  i = 0; i<numPlayers; i++)
    {
      Player new_player(names[i]);
      m_players.push_back(new_player);
    }
}

int Blackjack::GetNumPlayers()
{
  int numPlayers = m_players.size();
  return numPlayers;	
}

char *Blackjack::GetPlayerName(int player)
{
  return m_players[player].GetName();
}

int Blackjack::GetPlayerFunds(int player)
{
  int fund_player = m_players[player].GetFunds();
  return fund_player;
}

void Blackjack::SetPlayerFunds(int player, int amt)
{
   m_players[player].SetFunds(amt);   			
}

bool Blackjack::SetPlayerBet(int player, int amt)
{
  int fund = m_players[player].GetFunds();
  if(amt < fund)
    {
      m_players[player].SetBet(amt);
      return true;
    }
  else
    {
      return false;
    } 
}

void Blackjack::NewDeal()
{  
  m_deck = Deck();
  m_deck.Shuffle();
  Card tempcard;
  for(int j = 0; j < 2; j++)
    {
      for (int i = 0; i < int(m_players.size()); i++)
	{ 
	  tempcard = m_deck.DealCard();
	  m_players[i].takeCard(tempcard);
	  tempcard = m_deck.DealCard();
	  m_dealer.takeCard(tempcard);
	}      
    }
}
//******************************************
void Blackjack::OutputPlayerHand(int player)
{
  m_players[player].CurrentHand();
}
//**********************************
void Blackjack::OutputDealerHand()
{
  m_dealer.GetDealerHand();	
  cout<<", [hidden card]";
}

bool Blackjack::HitPlayer(int player)
{
  int bustValue = 21;
  //deal the card
  Card tempCard = m_deck.DealCard();
  //put into player's hand
  m_players[player].takeCard(tempCard);
  //output the card
  m_players[player].GetCard();
  cout<<endl;
  //calculate total value of hand
  int totalValue = m_players[player].GetValue();

  if(totalValue < bustValue)
    {
      return false;
    }
	else if(totalValue == bustValue)
	{
		return false;
	}
  else
    {
      m_players[player].SetBust();
      return true;
    }
}

void Blackjack::DealerPlay()
{
  int bustValue = 17;
  int totalValue = m_dealer.GetValue();
  bool bust = true;
  cout<<"Dealer's turn:"<<endl;
  Card tempCard;
  while(bust)
    {
      totalValue = m_dealer.GetValue();
      if (totalValue > 21)
	{
	  m_dealer.SetBust();
	  cout << "Hand: ";
	  m_dealer.CurrentHand();
	  cout << endl;
	  cout << "Busted!\n";
	  bust = false;
	}
      else if(totalValue >= bustValue)
	{
	  cout << "Hand: ";
	  m_dealer.CurrentHand();
	  cout << endl;
	  cout << "Dealer's play: stay "<<endl;
	  bust = false;
	}
      else
	{
	  tempCard = m_deck.DealCard();
	  m_dealer.takeCard(tempCard);
	}
    }
}

int Blackjack::SettlePlayerBet(int player)
{
	int PValue;
	int DValue = m_dealer.GetValue();
	cout<<"\nDealer has "<<DValue<<endl;
 
	PValue = m_players[player].GetValue();
	if (PValue > DValue)
	{
		bool check1 = m_players[player].GetBust();
		if (check1 == false)
		{
			cout<<m_players[player].GetName()<<" has busted--";
			cout<<"Dealer wins";
		}
		else
		{
			cout<<m_players[player].GetName()<<" has "<<PValue<<"--";
			cout<<"Dealer wins\n";
		}
	}
  
}
