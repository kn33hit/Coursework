#include <iostream>
#include "Blackjack.h"
using namespace std;

/* Deck m_deck;
 *std :: vector <Player> m_players;
 *Player m_dealer;
 *int Hit(Player &player);
 */

Blackjack :: Blackjack(){
  m_players.push_back(Player("Jane", 100));
}

Blackjack :: Blackjack (char *names[], int numPlayers){
  for (int i = 0; i < numPlayers; i++){
    m_players.push_back(Player(names[i], 100));
  }
}

int Blackjack :: GetNumPlayers(){
  return m_players.size();
}

char* Blackjack :: GetPlayerName(int player){
  return m_players[player].GetName();
}

int Blackjack :: GetPlayerFunds(int player){
  return m_players[player].GetFunds();
}

void Blackjack :: SetPlayerFunds(int player, int amt){
  m_players[player].SetFunds(amt);
}

bool Blackjack :: SetPlayerBet(int player, int amt){
  bool flag = true;
  m_players[player].SetBet(amt);
  if(m_players[player].GetFunds() < amt){
    flag = false;
  }
  return flag;
}

void Blackjack :: NewDeal(){
  m_deck = Deck();
  m_deck.Shuffle();
  int i = m_players.size();
  for (int a = 0; a < 2 && m_deck.CardsLeft() != 0; a++){
    for(int b = 0; b < i; b++){
      m_players[b].InsertCardRef(m_deck.DealCard());
    }
    m_dealer.InsertCardRef(m_deck.DealCard());
  }
}

void Blackjack :: OutputPlayerHand(int player){
  m_players[player].PrintCard();
}

void Blackjack :: OutputDealerHand(){
  m_dealer.PrintCard();
}

bool Blackjack :: HitPlayer(int player){
  if(m_players[player].CheckSum()){
    Card temp = m_deck.DealCard();
    m_players[player].InsertCardRef(temp);
    temp.OutputCard();
    bool flag = false;
    if(m_players[player].CheckSum() == false){
      flag = true;
    }
    return flag;
  }
}

void Blackjack :: DealerPlay(){
  Card temp;
  while (m_dealer.GetSumRef() < 17){
    temp = m_deck.DealCard();
    temp.OutputCard();
    cout << "Dealer has " << m_dealer.GetSumRef() << endl;
    if(m_dealer.GetSumRef() < 17){
	cout << "Dealer's Play: " << "hit"  << endl;
    }else if(m_dealer.GetSumRef() > 17){
      cout << "Dealer's Play: " << "stay" << endl;
    }
  }
}

int Blackjack :: SettlePlayerBet(int player){
  if(m_players[player].GetSumRef() > 21){
    m_players[player].SetFunds(m_players[player].GetFunds() - m_players[player].GetBet());
    cout << m_players[player].GetName() << " has busted--Dealer wins" << endl;

  }else if (m_players[player].GetSumRef() == 21){
    m_players[player].SetFunds(m_players[player].GetFunds() + m_players[player].GetBet());
    cout <<  m_players[player].GetName() << " has Blackjack" << endl;

  }else if  (m_players[player].GetSumRef() < 21){

    if (m_dealer.GetSumRef() < m_players[player].GetSumRef()){
    m_players[player].SetFunds(m_players[player].GetFunds() + m_players[player].GetBet());
    cout <<  m_players[player].GetName() << " has " << m_players[player].GetSumRef() << "--" << m_players[player].GetName() << " wins" << endl;

    }else if(m_dealer.GetSumRef() == m_players[player].GetSumRef()){
      cout <<  m_players[player].GetName() << " has " << m_players[player].GetSumRef() << "--Tie" << endl;
    
    }else if(m_dealer.GetSumRef() > m_players[player].GetSumRef()){
      m_players[player].SetFunds(m_players[player].GetFunds() - m_players[player].GetBet());
      cout <<  m_players[player].GetName() << " has " << m_players[player].GetSumRef() << "--Dealer wins" << endl;
    }
  }
}
