/****************************************************************
 * File:    Blackjack.cpp
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Chandler Deppe
 * UMBC ID: OQ44374
 * Date:    3/22/14
 * Section: 05
 * E-mail:  cdeppe1@umbc.edu
 *
 *   This file contains the implementation for the Blackjack class
 *   which was mostly written by John Park.
 *
 ****************************************************************/

#include <iostream>
#include "Blackjack.h"

using namespace std;

//Blackjack
//default constructor, sets up one player "Jane" with 100 dollars
Blackjack::Blackjack() {
   m_numPlayers = 1;
   Player player((char *)"Jane");
   m_players.push_back(player);
}

//Blackjack
//standard constructor, sets up the a number of players and adds them to
//  the game with their respective names
Blackjack::Blackjack(char *names[], int numPlayers) {
   m_numPlayers = numPlayers;
   for(int i = 0; i < numPlayers; i++) {
      Player player(names[i]);
      m_players.push_back(player);
   }
}

//GetNumPlayers
//returns the number of players in the game
int Blackjack::GetNumPlayers() {
   return m_numPlayers;
}

//GetPlayerName
//returns the player's name at the specified index--player
char* Blackjack::GetPlayerName(int player) {
   return m_players[player].GetName();
}

//GetPlayerFunds
//returns the player's funds at the specified index--player
int Blackjack::GetPlayerFunds(int player) {
   return m_players[player].GetFunds();
}

//SetPlayerFunds
//set the player's funds at the specified amount
void Blackjack::SetPlayerFunds(int player, int amt) {
   m_players[player].SetFunds(amt);
}

//SetPlayerBet
//sets the player's bet, but validates it beforehand by comparing
//  it to their current funds. If it's valid then true is returned,
//  false otherwise
bool Blackjack::SetPlayerBet(int player, int amt) {
   return m_players[player].SetBet(amt);
}

//NewDeal
//creates a new deck, shuffles, and then deals cards round robin
//  to every player
void Blackjack::NewDeal() {
   m_deck = Deck();
   m_deck.Shuffle();

   //a double for loop to deal round robin
   for(int i = 0; i < 2; i++) {
      for(int j = 0; j < m_numPlayers; j++) {
	 //validate that cards are left in the deck
	 if(m_deck.CardsLeft() > 0)
	    m_players[j].ModifyHand(m_deck.DealCard());
      }
      //validate that cards are left in the deck
      if(m_deck.CardsLeft() > 0)
	m_dealer.ModifyHand(m_deck.DealCard());
   }   
}

//OutputPlayerHand
//displays the player's hand to the terminal
void Blackjack::OutputPlayerHand(int player) {
   //the false is so that the 2nd card is not hidden
   m_players[player].ShowHand(false);
}

//OututDealerHand
//displays the dealer's hand with the second card hidden
void Blackjack::OutputDealerHand() {
   //the true is so that the 2nd card is hidden
   m_dealer.ShowHand(true);
}

//HitPlayer
//hit's the player with a card which is outputted and then returns whether
//  the player has busted from that card.
bool Blackjack::HitPlayer(int player) {
   if(m_players[player].GetBusted() == false) {
      //deal and output card
      Card card = m_deck.DealCard();

      card.OutputCard();
      cout << "\n";

      //add the card to the players hand
      m_players[player].ModifyHand(card);

      //check if they busted and then set their busted status accordingly
      m_players[player].SetBusted(m_players[player].CheckBusted());
   }

   //return whether the player busted or not
   return m_players[player].GetBusted();
}

//DealerPlay
//the function which runs the dealers turn
void Blackjack::DealerPlay() {
   //set the dealer's score, which should be what the
   //  dealer has in his/her hand
   int score = m_dealer.GetScore();

   //inform the user of the dealer's turn and show
   //  the dealers hand
   cout << ">>Dealer's turn:" << endl;
   cout << "Hand: "; 
   m_dealer.ShowHand(false);
   cout << endl;

   //dealer must have atleast a 17 to stay
   while(score <= 17) {
      cout << "Dealer's play: hit" << endl << endl;

      //deal the card and output
      Card card = m_deck.DealCard();
      card.OutputCard();
      cout << endl;

      //add the card to the dealer's hand, and get his score
      m_dealer.ModifyHand(card);
      score = m_dealer.GetScore();

      //show the hand
      cout << "Hand: ";
      m_dealer.ShowHand(false);

      cout << endl << endl;
   }

   //output dealer's status
   if(score <=21 && score >=17)
      cout << "Dealers play: stay" << endl << endl;

   m_dealer.DetermineBlackjack();

   if(m_dealer.GetBlackjack())
      cout << "Dealer has blackjack" << endl;
   else if (m_dealer.CheckBusted())
      cout << "Dealer has busted" << endl;
   else
      cout << "Dealer has " << score << endl;
}

int Blackjack::SettlePlayerBet(int player) {
   //m_playCount is used to keep track of when to clear the
   //  dealer's hand, which is after the dealer has been compared
   //  to every player
   m_playCount++;

   m_players[player].DetermineBlackjack();

   //set up all bools which are used for comparison
   //blackjack status
   bool pBlackjack = m_players[player].GetBlackjack();
   bool dBlackjack = m_dealer.GetBlackjack();

   //busted status
   bool pBusted = m_players[player].GetBusted();
   bool dBusted = m_dealer.GetBusted();

   //win and push status
   bool pWin = false, push = false;

   //score
   int pScore = m_players[player].GetScore(), dScore = m_dealer.GetScore();

   char *name = m_players[player].GetName();
   
   //first condition tested is if the player busted in which they
   //  automatically lose or if the dealer busted and the player
   //  has not in which the player wins
   if((pBusted && !dBusted) || (pBusted && dBusted))
      m_players[player].ModifyFunds(pWin);

   else if(!pBusted && dBusted) {
      pWin = true;
      m_players[player].ModifyFunds(pWin);
   }

   //next the scores are compared and the players win status is set
   //  accordingly
   else {
      if(pScore < dScore)
	 m_players[player].ModifyFunds(pWin);

      else if(pScore > dScore) {
	 pWin = true;
         m_players[player].ModifyFunds(pWin);
      }

      //finally if the scores are the same then the players blackjack
      //  status is compared, where the bool push comes into play if
      //  both the dealer and player have blackjack or don't have
      //  blackjack. otherwise their individual blackjack statuses
      //  are compared to determine a winner
      else {
         if((!pBlackjack && !dBlackjack) || (pBlackjack && dBlackjack))
	    push = true;

	 else if(dBlackjack && !pBlackjack)
	    m_players[player].ModifyFunds(pWin);

	 else {
	    pWin = true;
	    m_players[player].ModifyFunds(pWin);
	 }
      }
   }

   //if a tie
   if(push) {
      if(pBlackjack)
	 cout << name << " has blackjack--tie\n";
      else
         cout << name << " has " << pScore << "--tie\n";
   }

   //if the player wins
   else if(pWin) {
      if(pBlackjack)
	 cout << name << " has blackjack--" << name << " wins\n";
      else
	 cout << name << " has " << pScore << "--" << name << " wins\n";
   }

   //if the player busted or lost normally
   else {
     if(pBusted)
       cout << name << " has busted--dealer wins\n";
     else
       cout << name << " has " << pScore << "--dealer wins\n";
   }

   //reset the player bet, busted status, and clears their hand
   m_players[player].SetBet(0);
   ResetPlayer(m_players[player]);

   //once all players have been compared the dealer is reset and
   //  m_playCount is reset to 0
   if(m_playCount == m_numPlayers) {
      ResetPlayer(m_dealer);
      m_playCount = 0;
   }

   return 0;
}

//ResetPlayer (private)
//  reset the player's busted status and clears their hands
void Blackjack::ResetPlayer(Player &player) {
   player.SetBusted(false);
   player.ClearHand();
}

//m_playCount
int Blackjack::m_playCount = 0;
