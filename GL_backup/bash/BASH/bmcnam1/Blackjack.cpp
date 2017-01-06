/****************************************************************
 * File:    Blackjack.cpp
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Bernard McNamee
 * Date:    3/19/14
 * Section: all
 * E-mail:  bmcnam1@umbc.edu
 *
 *   This file contains the implementations for the methods defined
 *   in the Blackjack.h file
 *
 ****************************************************************/
#include <vector>
#include "Player.h"
#include "Blackjack.h"
#include <iostream>
using namespace std;
  /*
   *Blackjack
   * default (no-arg) constructor: Creates a player by calling 
   * the defualt player constructor to set the name to "Jane" with funds of 100 dollars
   */
Blackjack:: Blackjack(){
  Player p;
  p=Player();
  m_players.push_back(p);
}

  /*
   *Blackjack
   * Standard constructor: sets up a game with a collection of players,
   *   number specified by numPlayers, with given names.
   *   Each player is given a default $100
   */
Blackjack::Blackjack(char *names[], int numPlayers){
  cout<<"Number of players = "<<numPlayers<<endl;
  //if no players were entered then call default constructor
  if(numPlayers == 0){
    numPlayers=1;
    Blackjack();
  }
  for(int i =0; i < numPlayers; i++){
    Player p;
    //default 100 dollars
    p=Player(names[i], 100);
    m_players.push_back(p);
  }
  //  PrintPlayerList(numPlayers);
  
    
}


  /*
   * GetNumPlayers
   * no arguments.
   * Return the number of registered players
   */
int Blackjack::GetNumPlayers(){
  return m_players.size();
}

  /*
   *GetPlayerName
   * Return the given player's name. no args
   */
char *Blackjack::GetPlayerName(int player){
  
  return (m_players[player].GetName());
}

  /*
   *GetPlayerFunds
   * Return the given player's pool of available funds
   */
int Blackjack::GetPlayerFunds(int player){
  return m_players[player].GetFund();
}

  /*
   *SetPlayerFunds
   *Given the player index in the vector and the amount to set the funds to
   * Sets the given player's pool of funds available for betting
   */
void Blackjack::SetPlayerFunds(int player, int amt){
  m_players[player].SetFund(amt);
  
 
}
 /*
   *SetPlayerBet
   *Given the player index in the vector and the amount to bet
   * Set how much the player wants to bet in current round.
   * This must be compared against available funds, and rejected
   * if funds are insufficient.
   * Postconditions:
   *   amount of bet is recorded for the player
   *   returns true if bet is valid; false if insufficient funds.
   */
bool Blackjack::SetPlayerBet(int player, int amt){
  if(amt<=m_players[player].GetFund()){
    m_players[player].SetBetAmount(amt); 
    return true;
  }else{
    //not enough money left to bet
    return false;
  }  
}

  /*
   *NewDeal
   * Create a fresh Deck, shuffle it, and deal out 2 cards
   * to each player and the dealer, going around the circle
   * one card at a time, like most card games.
   */
void Blackjack::NewDeal(){
  //starts each round by make shure the dealer's hand is clear
  m_dealer.ClearHand();
  m_deck = Deck();
  //puts a new deck in randome order
  m_deck.Shuffle();
  //each player gets two cards
  for(int j =0;j<2;j++){  
    for(int i =0;i<(int)m_players.size();i++){
      //Will not deal cards if there are none left
      if(m_deck.CardsLeft()<=0){
	cout<<"Error: No more cards left"<<endl;
      }else{
	//add card to the hand
         m_players[i].AddToHand(m_deck.DealCard());
      } 
    }
  }
  //deal to the dealer
  if(m_deck.CardsLeft()>0){ 
    m_dealer.AddToHand(m_deck.DealCard());
  }else{
    cout<<"Error: No more cards left"<< endl;
  }
  

}

  /*
   *OutputPlayerHand
   *given the index player vector value
   * Display the player's hand
   * Note: just display cards; no label at start, no endl at end.
   */
void Blackjack::OutputPlayerHand(int player){
  //if there are no cards left it will not dispaly hand
  if(m_deck.CardsLeft()>0){
    m_players[player].PrintPlayerHand();
  }
}
  /*
   *OutputDealerHand
   * Display the dealer's hand, hiding the hole card (the second card)
   * So, it should display something like "Ace of Spades, [hidden card]"
   * Note: just display cards; no label at start, no endl at end.
   */
void Blackjack::OutputDealerHand(){
  //will print the first card, then adds the second in order to display "hidden card"
  m_dealer.PrintPlayerHand();
  //will not work if no more cards left
  if(m_deck.CardsLeft()>0){
    m_dealer.AddToHand(m_deck.DealCard());
    cout<<"[hidden card]";
  }else{
    cout<<"Error no more cards Left"<<endl;
  }
}
  /*
   * HitPlayer
   * Deal the player another card.
   * Preconditions: Given the idex value for the player vector
   *   Player must not have gone bust earlier; this is a precondition
   *   you are required to check for!
   * Postconditions:
   *   returns true if player is busted due to new card; false otherwise.
   *   (HINT: it would probably be helpful to record that the player went
   *    bust in some object.)
   */
bool Blackjack::HitPlayer(int player){
  //will not do anything if there are no more cards left
  if(m_deck.CardsLeft()>0){
    Card c = m_deck.DealCard();
    c.OutputCard();
    cout<<endl;
    m_players[player].AddToHand(c);
  
    if(m_players[player].GetTotalHand()<21){    
      return false;
    }else if(m_players[player].GetTotalHand()==21){
      cout<<"PLAYER GOT 21!!"<<endl;
      return false;
    }else{
      return true;
    }
  }else{
    cout<<"Error no more Cards Left"<<endl;
    return true;
  }
}
  /*
   *DealerPlay
   * Deal to the Dealer's hand until she stops (because she has
   * 17 or higher).
   * Postconditions:
   *   Dealer might have gone bust, or might have blackjack (in which
   *   case no cards were taken.)
   */
void Blackjack::DealerPlay(){
  //Checks to see if there are cards left before contiuing
  if(m_deck.CardsLeft()>0){
    cout<<"Dealer's Turn: "<<endl;
    cout<<"Hand: ";
    m_dealer.PrintPlayerHand();
    cout<<endl;
    Card c;
    //checks if cards left
    if(m_deck.CardsLeft()>0){
      //contiues to deale until they get 17 or higher
      while(m_dealer.GetTotalHand()<17){
        cout<<endl;
        c = m_deck.DealCard();
        cout<<"Dealer's play: hit"<<endl;
        m_dealer.AddToHand(c);
        m_dealer.PrintPlayerHand();
      }
    }else{
      cout<<"Error no more cards left"<<endl;
    }
    //displayer what the dealer has
    cout<<endl;
    if(m_dealer.GetTotalHand()>21){
      cout<<"Dealer is BUSTED "<<endl;
    }else{
    cout<<"Dealer's play: Stay"<<endl;
    }
    cout<<endl;
    if(m_dealer.HasBlackjack()){
      cout<<"Dealer has Blackjack" <<endl;
    }else if(m_dealer.GetTotalHand()>21){
      cout<<"Dealer has Busted!"<<endl;
    }else{
      cout<<"Dealer has "<<m_dealer.GetTotalHand()<<endl;
    }
  }
}
  /*
   *SettlePlayerBet
   *Given the index value of the player vector
   * At end of game, settle bet for given player:
   *   Compare player's hand to
   *Finds the winner of the match, then adjusts every player's funds accordingly
   */
int Blackjack::SettlePlayerBet(int player){
  //nothing happens if there were no more cards
  if(m_deck.CardsLeft()>0){
    int total =0;
    int playerCount =m_players[player].GetTotalHand();
    int dealerCount = m_dealer.GetTotalHand();
    //both have blackjack
    if(m_players[player].HasBlackjack() && m_dealer.HasBlackjack()){
      cout<<m_players[player].GetName()<<" Has Blackjack -- Tie Game"<<endl;      
      total = m_players[player].GetFund();
      m_players[player].ClearHand();
      return total;
      //player has blackjack
    }else if(m_players[player].HasBlackjack() && !m_dealer.HasBlackjack()){
      cout<<m_players[player].GetName()<<" has Blackjack! -- Dealer Loses"<<endl;
      total = m_players[player].GetFund() + m_players[player].GetBetAmount();
      m_players[player].SetFund(total);
      m_players[player].ClearHand();
      return total;
      //dealer has blackjack
    }else if(m_dealer.HasBlackjack() && !m_players[player].HasBlackjack()){
      cout<<m_players[player].GetName()<<" has "<<playerCount<<"-- Dealer Wins"<<endl;
      total = m_players[player].GetFund() - m_players[player].GetBetAmount();
      m_players[player].SetFund(total);
      m_players[player].ClearHand();
      return total;
      //player is busted
    }else if(playerCount>21){
      cout<<m_players[player].GetName()<<" has busted-- Dealer Wins"<<endl;
      total = m_players[player].GetFund() - m_players[player].GetBetAmount();
      m_players[player].SetFund(total);
      m_players[player].ClearHand();
      return total;
      //dealer is busted and player is not
    }else if((dealerCount>21) && (playerCount <= 21)){
      cout<<m_players[player].GetName()<<" has "<<playerCount<<"-- Dealer Loses"<<endl;
      total = m_players[player].GetFund() + m_players[player].GetBetAmount();
      m_players[player].SetFund(total);
      m_players[player].ClearHand();
      return total;
      //player beats dealer- normal
    }else if(playerCount > dealerCount){
      cout<<m_players[player].GetName()<<" has "<<playerCount<<"-- Dealer Loses"<<endl;
      total = m_players[player].GetFund() + m_players[player].GetBetAmount();
      m_players[player].SetFund(total);
      m_players[player].ClearHand();
      return total;
      //dealer beats player- normal
    }else if(dealerCount> playerCount){
      cout<<m_players[player].GetName()<<" has "<<playerCount<<"-- Dealer Wins"<<endl;
      total = m_players[player].GetFund() - m_players[player].GetBetAmount();
      m_players[player].SetFund(total);
      m_players[player].ClearHand();
      return total;
      //its a tie
    }else{
      cout<<m_players[player].GetName()<<" has "<<playerCount<<"-- Tie Game"<<endl;
      total = m_players[player].GetFund();
      m_players[player].ClearHand();
      return total;
    }
  }else{
    return 0;
  }
}
