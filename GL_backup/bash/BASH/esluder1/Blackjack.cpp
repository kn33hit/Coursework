/****************************************************************              
 * File:    Blackjack.cpp
 * Project: CMSC 202 Project 2, Fall 2014
 * Author:  Eric Sluder
 * Date:    10/11/14
 * Section: 1112 - Lecture, 1113 - Discussion
 * E-mail:  esluder1@umbc.edu
 *
 *   This file contains the workings for the Blackjack class.               
 *   The class manages and implements the mechanics for a multi-player         
 *   version of the Blackjack/21 program, including bets.                      
 *                                                                             
 ****************************************************************/

#include "Blackjack.h"

//default constructor - set up game with one player "Jane", with $100
//assigns default name and default amount and creates a Player object
//adds the "default Player" to the vector of players
Blackjack::Blackjack() {
   char *defaultName = "Jane";
   int defaultAmount = 100;
   Player defaultPlayer(defaultName, defaultAmount);
   m_players.push_back(defaultPlayer);
}

//constructor to set up game with specified players - default $100 funds
//creates Player objects for each input player from command line, adds
//them to the player vector
Blackjack::Blackjack(char *names[], int numPlayers) {
   int defaultFunds = 100;
   for(int i = 0; i < numPlayers; i++){
      Player tempPlayer(names[i], defaultFunds);
      m_players.push_back(tempPlayer);
   }
}

//returns the number of Players - the size of the Players vector
int Blackjack::GetNumPlayers(){
   return m_players.size();
}

//returns the name of a Player at a specific place in the Players vector
char* Blackjack::GetPlayerName(int player){
   return m_players.at(player).GetPlayerName();
}

//returns the amount of money the desired Player has
int Blackjack::GetPlayerFunds(int player){
   return m_players.at(player).GetPlayerFunds();
}

//sets the amount of money a player has
void Blackjack::SetPlayerFunds(int player, int amt){
   m_players.at(player).SetPlayerFunds(amt);
}

//sets the amount of money a player is betting
bool Blackjack::SetPlayerBet(int player, int amt){
   m_validBet = m_players.at(player).SetPlayerBet(amt);
   return m_validBet;
}

//creates a "new deal", essentially a new game instance
void Blackjack::NewDeal(){
//creates and shuffles a new deck
   m_deck = Deck();
   m_deck.Shuffle();
   
//resets all players' hands and "bust" checks
   for(int i = 0; i < m_players.size(); i++){
      m_players.at(i).ResetHand();
      m_dealer.ResetHand();
      m_playerBust = 0;
      m_dealerBust = 0;
      m_isBust = 0;
   }

//deals two cards to each player's hand
   for(int i = 0; i < (2*m_players.size()); i++){
      m_tempCard = m_deck.DealCard();
      m_players.at(i % m_players.size()).AddToHand(m_tempCard);
      
      //adds a card to dealer's hand after all players have received cards
      if((i % m_players.size()) == 0){
	 m_tempCard = m_deck.DealCard();
	 m_dealer.AddToHand(m_tempCard);
      }
   }
}

//outputs the player's hand
void Blackjack::OutputPlayerHand(int player){
   m_players.at(player).OutputPlayerHand();
}

//outputs the dealer's hand (this function is different than for players,
//because it needs to hide the hole card for the dealer
void Blackjack::OutputDealerHand(){
   m_dealer.OutputDealerHand();
}

//gives a player a new card and checks if the player busts, returns the bust
//check
bool Blackjack::HitPlayer(int player){
   m_isBust = m_players.at(player).HitPlayer(m_deck);
   return m_isBust;
}

//main dealer play logic -- hits until hand value is 17 or greater, or bust
void Blackjack::DealerPlay(){
   //defaults busted check to false, print formatting to match player format
   m_isBust = 0;
   cout << endl << ">>Dealer's Turn:" << endl << "Hand: ";
   m_dealer.OutputPlayerHand();

   //dealer hits until they reach 17 or greater or bust
   while(m_dealer.ReturnHandValue() < 17 && !m_isBust){
      cout << endl << "Dealer's play: ";
      cout << "hit" << endl << endl;
      m_isBust = m_dealer.HitPlayer(m_deck);

      //only print dealer hand if the dealer hasn't busted
      if(!m_isBust){
	 cout << "Hand: ";
	 m_dealer.OutputPlayerHand();
      }
   }

   //dealer stays if they are over 17, prints out proper format
   if(m_dealer.ReturnHandValue() >= 17 && !m_isBust){
      cout << endl << "Dealer's play: stay" << endl << endl << endl;
      cout << "Dealer has: " << m_dealer.ReturnHandValue() << endl;  
   }

   //prints out appropriate dealer busted message
   else if(m_isBust){
      cout << "Busted!" << endl;
      cout << endl << "Dealer has: " << m_dealer.ReturnHandValue() << endl;
      cout << "Dealer busted" << endl;
      }
}

//player win-loss logic -- compares individual player hands (if not busted) to
//delaer hand. If busted, player loses bet, if player beats dealer, player wins
//bet (added to previous funds), if player ties dealer, player keeps bet (keeps
//original funds)
int Blackjack::SettlePlayerBet(int player){

   //initializes the necessary variable -- names and functions
   //are self-explanatory. Player variable access the appropriate Player class
   //variables for the individual player.
   m_playerHandValue = m_players.at(player).ReturnHandValue();
   m_dealerHandValue = m_dealer.ReturnHandValue();
   m_playerHandSize = m_players.at(player).ReturnHandSize();
   m_dealerHandSize = m_dealer.ReturnHandSize();
   m_playerBust = m_players.at(player).IsBust();
   m_dealerBust = m_dealer.IsBust();
   m_blackjackHandValue = 21;
   m_blackjackHandSize = 2;

   //resets the lose and tie checks to zero -- if the program gets to this
   //point, it is a new deal and loss/tie conditions need to be redetermined
   m_playerLose = 0;
   m_playerTie = 0;

   
   if(m_playerBust){
      m_playerLose = 1;
   }
   else if(m_playerHandValue < m_dealerHandValue && !m_dealerBust
	   && !m_playerBust){
      m_playerLose = 1;
   }
   else if(m_playerHandValue == m_dealerHandValue &&
	   m_playerHandValue == m_blackjackHandValue &&
	   m_dealerHandSize == m_blackjackHandSize &&
	   m_playerHandSize > m_blackjackHandSize){
      m_playerLose = 1;
   }
   else if(m_playerHandValue == m_dealerHandValue &&
	   m_playerHandValue < m_blackjackHandValue){
      m_playerTie = 1;
   }
   
   //temporary print statement for loss/tie checks -- irrelevant to game
   //cout << "Lose: " << m_playerLose << " Tie: " << m_playerTie << " ";

   //depending on loss/tie conditions, change the fund for the current player
   m_players.at(player).AlterFunds(m_playerLose, m_playerTie);

   //print statements for win/loss/tie -- value of hand and round outcome for
   //current player (individual)
   if(m_playerBust){
      cout << m_players.at(player).GetPlayerName() 
	   << " has busted--Dealer Wins" << endl;
   }
   else if(!m_playerBust && m_playerLose){
      cout << m_players.at(player).GetPlayerName() << " has "
	   << m_players.at(player).ReturnHandValue() << "--Dealer wins"
	   << endl;
   }
   else if(!m_playerBust && !m_playerLose && !m_playerTie &&
	   m_playerHandValue <= m_blackjackHandValue &&
	   m_playerHandSize > m_blackjackHandSize){
      cout << m_players.at(player).GetPlayerName() << " has "
	   << m_players.at(player).ReturnHandValue() << "--"
	   << m_players.at(player).GetPlayerName() << " wins" << endl;
   }
   else if(!m_playerBust && !m_playerLose && !m_playerTie &&
	   m_playerHandValue < m_blackjackHandValue &&
	   m_playerHandSize == m_blackjackHandSize){
      cout << m_players.at(player).GetPlayerName() << " has "
	   << m_players.at(player).ReturnHandValue() << "--"
	   << m_players.at(player).GetPlayerName() << " wins" << endl;
   }
   else if(!m_playerBust && !m_playerLose && !m_playerTie &&
	   m_playerHandValue == m_blackjackHandValue &&
	   m_playerHandSize == m_blackjackHandSize){
      cout << m_players.at(player).GetPlayerName() << " has "
	   << "blackjack--" << m_players.at(player).GetPlayerName() << " wins"
	   << endl;
   }
   else if(m_playerTie && m_playerHandValue != m_blackjackHandValue){
      cout << m_players.at(player).GetPlayerName() << " has "
	   << m_players.at(player).ReturnHandValue() << "--tie" << endl;
   }
   else if(m_playerTie && m_playerHandValue == m_blackjackHandValue &&
	   m_playerHandSize < m_blackjackHandSize){
      cout << m_players.at(player).GetPlayerName() << " has "
	   << m_players.at(player).ReturnHandValue() << "--tie" << endl;
   }
   else if(m_playerTie && m_playerHandValue == m_blackjackHandValue &&
	   m_playerHandSize == m_blackjackHandSize){
      cout << m_players.at(player).GetPlayerName() << " has "
	   << "blackjack--tie" << endl;
   }
      
   //resets the player's bet for next round
   m_players.at(player).ResetBet();

   //return 0 to main -- needed for proper functioning in main()
   return 0;
}



