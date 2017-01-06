#include <vector>
#include "Blackjack.h"
#include <iostream>

using namespace std;

int const SOFT_SEVENTEEN = 17;
int const TWENTYONE = 21;
Blackjack::Blackjack()
{
  Player Jane;
  Jane.SetName("Jane");
  Jane.SetFund(100);
  m_player.push_back(Jane);
}
Blackjack:: Blackjack(char *names[], int numPlayers)
{
  m_numberOfPlayer = numPlayers;
  
  for(int i = 0; i < m_numberOfPlayer; i++)
    {
      Player tempPlayer;
      tempPlayer.SetName(names[i]);
      tempPlayer.SetFund(100);
      m_player.push_back(tempPlayer);
    }

}
int Blackjack::GetNumPlayers()
{
  return m_numberOfPlayer; 

}

char* Blackjack::GetPlayerName(int player)
{
  return (m_player[player]).GetName();
}

int Blackjack::GetPlayerFunds(int player)
{
  return (m_player[player]).GetFund();
}
void Blackjack::SetPlayerFunds(int player, int amt)
{
  (m_player[player]).SetFund(amt);
}

bool Blackjack::SetPlayerBet(int player, int amt)
{
  m_player[player].SetBet(amt);
  if(amt < (m_player[player]).GetFund())
    return true;
  else
    return false;
}
void Blackjack::NewDeal()
{
  // Make a new deal and makes a new deck and shuffels and deals two cards to player.
  m_deck = Deck();
  m_deck.Shuffle();
  m_dealer.SetBust(false);
  for(int i = 0; i < m_player.capacity();i++)
  {
    m_player[i].ClearHand();
  }
  m_dealer.ClearHand();
  int numCards(0);
  while(numCards != 2){
    for(int i = 0; i < m_player.capacity(); i++){
      m_player[i].HandHit(m_deck.DealCard());
    }
    m_dealer.DealerHit(m_deck.DealCard());
    numCards++;
  }
  
}
void Blackjack::OutputPlayerHand(int player)
{
  (m_player[player]).PrintHand();
}
void Blackjack::OutputDealerHand()
{
  m_dealer.DealerPrintHand();

}
bool Blackjack::HitPlayer(int player)
{
  //Hit the player with the cards under 21.
  Card tempCard = m_deck.DealCard();
  m_player[player].HandHit(tempCard);
  
  tempCard.OutputCard();

  cout << endl;

  if(m_player[player].PlayerBust())
    {
      return true;
    }
  else
    {
      return false;
    }
  
  
}
void Blackjack::DealerPlay()
{
  //Lets the dealer play.
  cout << "Dealer\'s turn: " << endl;
  cout << "Hand: ";
  m_dealer.DealerPrintHand();
  while(m_dealer.GetTotal() < SOFT_SEVENTEEN)
    {
      Card temp = m_deck.DealCard();
      if(m_dealer.GetTotal() < SOFT_SEVENTEEN)
	{
	  cout << endl;
	  cout << "Dealer\'s play: hit" << endl;
	  m_dealer.HandHit(temp);
	  cout << endl;
	  temp.OutputCard();
	  cout << endl;
	  if(m_dealer.PlayerBust())
	    {
	    cout << "Busted!" << endl;
	    }
	  else
	    {
	      cout << "Hand: ";
	      m_dealer.PrintHand(); 
	    }
	}
      else if(m_dealer.GetTotal() >=  SOFT_SEVENTEEN)
	{
	  cout << "Dealer\'s play: stay"  << endl;
	}
    }
  
  cout << endl;
  cout << endl;
  cout << "Dealer has: " << m_dealer.GetTotal() << endl;

  

  
}
int Blackjack::SettlePlayerBet(int player)
{
  // Winning: player has blackjack or their hand value is greater
  // Dealer Winning: both bust, dealer has blackjack, hand value is greater
  if(m_player[player].HasBlackjack() && !m_dealer.HasBlackjack() || m_player[player].GetTotal() > m_dealer.GetTotal())
    {
      if(m_player[player].HasBlackjack())
	{
	  cout << m_player[player].GetName() << " has blackjack--Dealer loses" << endl;
	  m_player[player].FundIncrease();
	}
      else
	{

	  cout << m_player[player].GetName() << " has " << m_player[player].GetTotal();
	  cout << "--Dealer loses" << endl;
	  m_player[player].FundIncrease();
	}

    }
  else if((m_player[player].PlayerBust() && m_dealer.PlayerBust()) ||
	  m_dealer.HasBlackjack() || m_dealer.GetTotal() > m_player[player].GetTotal())
    {
     
      
      if(m_dealer.HasBlackjack())
        {
          cout << m_player[player].GetName() << " has " << m_player[player].GetTotal();
	  cout << "--Dealer wins" << endl;
	  m_player[player].FundDecrease();
        }
      else
        {

          cout << m_player[player].GetName() << " has " << m_player[player].GetTotal();
          cout << "--Dealer wins" << endl;
          m_player[player].FundDecrease();
        }

    }
  else
    {
      
      cout << m_player[player].GetName() << " has " << m_player[player].GetTotal();
      cout << "--Dealer ties" << endl;
      m_player[player].Push();
      
    }
  m_dealer.ClearHand();
}
