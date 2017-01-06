#include <cstdlib>
#include <iostream>
#include "Blackjack.h"

using namespace std;
const int MAX_NAME_LENGTH = 10;
const int default_funds = 100;
const int default_bet = 0;
Hand hand;

Blackjack::Blackjack(){
  vector<Player> players(1);
  Player p;
  char default_name[MAX_NAME_LENGTH] = "Jane";
  p.SetPlayerName(*default_name);
  p.SetPlayerBust(false);
  p.SetPlayerFunds(default_funds);
  p.SetPlayerHand(hand);
  p.SetPlayerBet(default_bet);
  players.push_back(Player(p));
  m_players = players;
  //m_players[0].SetPlayerName(*default_name);
}

Blackjack::Blackjack(char *names[], int numPlayers){
 
  vector<Player> players(numPlayers); // = new vector[numPlayers];
  for(int a = 1; a < numPlayers; a++){
    Player p;
    p.SetPlayerName(*names[a]);
    p.SetPlayerBust(false);
    p.SetPlayerFunds(default_funds);
    p.SetPlayerHand(hand);
    p.SetPlayerBet(default_bet);
    m_players[a-1] = p;
    a++;
  }

}

int Blackjack::GetNumPlayers(){
  int NumPlayers;
  NumPlayers = m_players.size();
  return NumPlayers;
}
//not sure if i need that star below
char Blackjack::*GetPlayerName(int player){
  char* name = m_players[player].GetPlayerName();
  return name;
}

int Blackjack::GetPlayerFunds(int player){
  int funds =  m_players[player].GetPlayerFunds();
  return funds;
}

void Blackjack::SetPlayerFunds(int player, int amt){
  m_players[player].SetPlayerFunds(amt);
  return;
}

bool Blackjack::SetPlayerBet(int player, int amt){
  if(amt > m_players[player].GetPlayerFunds()){
    return false;
  }
  else{
    m_players[player].SetPlayerBet(amt);
    return true;
  }

}

void Blackjack::NewDeal(){
  m_deck = Deck();
  m_deck.Shuffle();
}

void Blackjack::OutputPlayerHand(int player){
  char printHand = m_players[player].GetPlayerHand();
  cout << printHand;
}

void Blackjack::OutputDealerHand(){
  char dealerHand = m_dealer.GetPlayerHand();
  cout << dealerHand;
}

bool Blackjack::HitPlayer(int player){
  m_players[player].SetPlayerHand(Hand::AddHandCard((Deck::Deal_Card())));
  if (GetBlackjackValue < 22){
    return false;
  }
  else{
    return true;
  }
}

void Blackjack::DealerPlay(){
  Hand dealerHand;
  dealerHand.AddHandCard(Deck::Deal_Card());
  int dealerSum = GetBlackjackValue(m_dealer.GetPlayerHand());
  while (dealerSum < 17){
    dealerHand.AddHandCard(Deck::Deal_Card());
    dealerSum = GetBlackjackValue(m_dealer.GetPlayerHand());
  }
  if (dealerSum >21){
    m_dealer.SetPlayerBust = true;
  }
}

int Blackjack::SettlePlayerBet(int player){
  return 0;
}

