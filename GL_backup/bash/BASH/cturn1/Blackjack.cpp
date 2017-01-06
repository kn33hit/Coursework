//blackjack.cpp
//christopher turner
//ft93935
//this will be the logic for the black jack class 
#include <iostream>
#include "Blackjack.h"
using namespace std;
const int initHandLen = 2;
Blackjack::Blackjack(){
  //Initialize the dealer
  Player dealer((char *) "Dealer", 100);
  m_dealer = dealer;

  // Initialize a player 'Jane' with 100 funds
  Player player((char *) "Jane", 100);
  m_players.push_back(player);
}

Blackjack::Blackjack(char *names[], int numPlayers){
  // Initialize the dealer
  Player dealer((char *) "Dealer", 100);
  m_dealer = dealer;

  // Loop through all passed player names
  for(int i = 0; i < numPlayers; i++){
      // Initialize a player 'names[i]' with 100 funds
      Player player(names[i], 100);
      m_players.push_back(player);
    }
}
int Blackjack::GetNumPlayers(){
  // Returns the length of the players vector
  return m_players.size();
}

char *Blackjack::GetPlayerName(int player){
  // Returns the player's name from the vector
  return m_players[player].GetName();
}

int Blackjack::GetPlayerFunds(int player){
  // Return the requested player's funds
  return m_players[player].GetFunds();
}

void Blackjack::SetPlayerFunds(int player, int amt){
  // Set the requested player's funds
  m_players[player].SetFunds(amt);
}

bool Blackjack::SetPlayerBet(int player, int amt){ 
  // If the player has insufficient funds
  if(m_players[player].GetFunds() < amt){
      // Return false
      return false;
    }

  // Subtract the amount from the player funds
  m_players[player].SetFunds(m_players[player].GetFunds() - amt);
  // Add the amount to the player bet
  m_players[player].SetBet(amt);
  // Return true
  return true;
}

void Blackjack::NewDeal(){
  // Create a new unsorted 52 card deck
  Deck deck;
  // Initialize m_deck to the new deck
  m_deck = deck;
  // Shuffle m_deck
  m_deck.Shuffle();

  // 2 cards for dealer, 2 cards for each player
  int cardsToDeal = initHandLen + (initHandLen * m_players.size());

  // While we still have cards to deal
  while(cardsToDeal > 0){
      // Deal to each player
      for(unsigned int i = 0; i < m_players.size(); i++){
	//std::cout << "Deal Player Card" << std::endl;
	// Deal one card to the player
	m_players[i].GetHand().AddCard(m_deck.DealCard());
	// Decrement the number of cards to deal
	cardsToDeal--;
      }

      //std::cout << "Deal Dealer Card" << endl;
      // Deal the dealer one card
      m_dealer.GetHand().AddCard(m_deck.DealCard());
      // Decrement the number of cards to deal
      cardsToDeal--;
    }
}

void Blackjack::OutputPlayerHand(int player){
  //cout << "Player Output Card." << endl;
  for(int i = 0; i<m_players[player].GetHand().Size(); i++){
    m_players[player].GetHand().GetCard(i).OutputCard();
  }
}

void Blackjack::OutputDealerHand(){
  m_dealer.GetHand().GetCard(0).OutputCard();
  cout <<", [hidden card]"; 
}

//if the player busts return true
//else deal them another card
bool Blackjack::HitPlayer(int player){
  Hand curhand = m_players[player].GetHand();
  int handSize = curhand.Size();
  int decksize = m_deck.CardsLeft();
  int numaces = 0;
  bool playerbust = m_players[player].HasBusted();
  // if hasbusted is true then the player can get cards
  //if has busted is false then the player has over 21 cards
  if((decksize>1)&&(playerbust == false)){
    Card dealtcard = m_deck.DealCard();
    dealtcard.OutputCard();
    m_players[player].GetHand().AddCard(dealtcard);
    int curscore = 0;
    for(int i = 0; i<=m_players[player].GetHand().Size(); i++){
      //set the players score
      curscore = curscore+ m_players[player].GetHand().GetCard(i).GetBlackjackValue();
    }
    if(curscore>21){
      m_players[player].SetHasBusted(true);
    }
    //check to see if this card made the player bust
  }
  else{
    return true;
  }
  
}

void Blackjack::DealerPlay(){
  cout << "Dealer's turn:"<<endl;
  int curscore = m_dealer.GetHand().GetCard(0).GetBlackjackValue()+m_dealer.GetHand().GetCard(1).GetBlackjackValue();
  while(curscore<17){
    int numcards = 2;
    Card dealingcard = m_deck.DealCard();
    dealingcard.OutputCard();
    m_dealer.GetHand().AddCard(dealingcard);
    cout<< "hand: ";
    for (int i = 0; i<numcards; i++){
      m_dealer.GetHand().GetCard(i).OutputCard();
      cout<< ", ";
    }
  }
  int totscore = 0;
  for (int p = 0; p < m_dealer.GetHand().Size(); p++){
    int value = m_dealer.GetHand().GetCard(p).GetBlackjackValue();
    totscore =totscore + value; 
  }
  if (totscore>21){
    cout<< "dealer busted";
  }
  else {
    cout<< "dealer score is: "<< totscore<< endl; 
  }
}

int Blackjack::SettlePlayerBet(int player){
  int dealerscore = 0;
  for (int b = 0; b<m_dealer.GetHand().Size(); b++){
    dealerscore = dealerscore + m_dealer.GetHand().GetCard(b).GetBlackjackValue();
  }
  for (int i = 0; i<m_players.size(); i++){
    int score = 0;
    for(int j = 0; j<m_players[i].GetHand().Size();j++){
      
      int cardval = m_players[i].GetHand().GetCard(j).GetBlackjackValue();
      score = score+ cardval;
    }
    
    if(score > dealerscore){
      //check what the returns should be
      m_players[i].SetFunds(m_players[i].GetFunds()+(m_players[i].GetBet()*2));
      //return something
      return -1;
    }
    else if (score < dealerscore){
      m_players[i].SetFunds(m_players[i].GetFunds() - m_players[i].GetBet());
      //return something
      return -1;
    }
    else{
      m_players[i].SetFunds(m_players[i].GetFunds()+m_players[i].GetBet());
      //return something
      return -1;
    }
  } 
  return -1;
}
