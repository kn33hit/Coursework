/****************************************************************              
 * File:    Player.cpp
 * Project: CMSC 202 Project 2, Fall 2014
 * Author:  Eric Sluder
 * Date:    10/11/14
 * Section: 1112 - Lecture, 1113 - Discussion
 * E-mail:  esluder1@umbc.edu
 *  
 *   This file contains the workings for the Player class.
 *   The class manages and implements the players in a given instance of
 *   the Blackjack/21 program.
 *
 ****************************************************************/

#include "Player.h"

//constructors

//default (no-arg) constructor -- used to create dealer
//all other player creations use another constructor -- saves some space
Player::Player(){
   //create dealer player -- sets name, funds and bust check set to 0
   m_name = "Dealer";
   m_funds = 0;
   m_isBust = 0;
}

//general constructor -- takes in the input name and funds from the
//command line arg list and assigns them to the proper class variables
Player::Player(char *m_InputName, int m_InputFund){
   m_name = m_InputName;
   m_funds = m_InputFund;
   m_isBust = 0;
}


//accessors

//returns the player's name
char *Player::GetPlayerName(){
   return m_name;
}

//returns the player's funds
int Player::GetPlayerFunds(){
   return m_funds;
}

//calls Hand (and Card, internally) class functions to display the hand of the
//current player 
void Player::OutputPlayerHand(){
   m_hand.OutputPlayerHand();
}

//outputs the dealer's hand using Hand (and Card) calls, as above. Keeps the
//second card hidden. Only used for the first "showing" of hands.
void Player::OutputDealerHand(){
   m_hand.OutputDealerHand();
}

//returns if the player has busted
bool Player::IsBust(){
   return m_isBust;
}


//mutators

//sets the funds to the desired amount
void Player::SetPlayerFunds(int m_inputAmt){
   m_funds = m_inputAmt;
}

//checks if the desired bet is within available funds. If so, changes bet to
//that amount. If not, sets it to 0.
bool Player::SetPlayerBet(int m_inputBet){
   if(m_inputBet <= m_funds){
      m_bet = m_inputBet;
      m_validBet = 1;
   }
   else if(m_inputBet > m_funds){
      m_bet = 0;
      m_validBet = 0;
   }
   return m_validBet;
}   

//adds desired card to the player's hand, using the Hand class function
void Player::AddToHand(Card m_inputCard){
   m_hand.AddToHand(m_inputCard);
}

//hits the player if they haven't busted. Deals the next card from the deck,
//using the Deck class function. Adds the dealt card to the player's hand,
//calling the internal function. Returns the new (or original) bust check
bool Player::HitPlayer(Deck &m_deck){
   if(!m_isBust){
      if(m_deck.CardsLeft() > 0){
	 m_newCard = m_deck.DealCard();
	 m_newCard.OutputCard();
	 AddToHand(m_newCard);
	 cout << endl;
      }
      else{
         cout << "No more cards left in deck." << endl;
      }
      
      //if the new card makes the user bust, change the check to true
      m_handValue = m_hand.ReturnHandValue();
      if(m_handValue > 21){
	 m_isBust = 1;
      }
   }

   return m_isBust;
}

//changes the player's funds to reflect the outcome of the game with the user's
//bet
void Player::AlterFunds(bool m_playerLose, bool m_playerTie){
   if(m_playerLose){
      m_funds -= m_bet;
   }
   else if(!m_playerLose && !m_playerTie){
      m_funds += m_bet;
   }
}

//calls the Hand class function to return the value of the player's hand
int Player::ReturnHandValue(){
   m_handValue = m_hand.ReturnHandValue();
   return m_handValue;
}

//calls the Hand class function to return the size of the player's hand
int Player::ReturnHandSize(){
   m_handSize = m_hand.ReturnHandSize();
   return m_handSize;
}

//resets the player's bet to 0 for new round
void Player::ResetBet(){
   m_bet = 0;
}

//resets the player's hand and bust check to null-vector for new round
void Player::ResetHand(){
   m_hand.ResetHand();
   m_isBust = 0;
   ReturnHandValue();
}
