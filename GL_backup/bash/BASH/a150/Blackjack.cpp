/****************************************************************
 * File:    Blackjack.cpp
 * Project: CMSC 202 Project 2, Fall 2014
 * Author:  Anh Ho
 * Date:    10/19/14
 * Section: 03
 * E-mail:  a150@umbc.edu 
 *
 *   This file contains the definitions for the Blackjack class.
 *
 ****************************************************************/

#include <iostream>
using namespace std;

#include "Blackjack.h"
#include "Player.h"
#include "Hand.h"

Blackjack::Blackjack(){

	m_players.push_back(Player('Jane', 100));

}


Blackjack::Blackjack(char *names[], int numPlayers){

	for(int counter = 0; counter < numPlayers; counter ++){
		m_players.push_back(Player(*names[counter], 100));
	}

}

int Blackjack::GetNumPlayers(){
	
	return m_players.size();

}

char* Blackjack::GetPlayerName(int player){

	return m_players[player].PlayerName();
}

int Blackjack::GetPlayerFunds(int player){

	return m_players[player].PlayerFunds();
}

void Blackjack::SetPlayerFunds(int player, int amt){

	m_players[player].SetFunds(amt);

}

bool Blackjack::SetPlayerBet(int player, int amt){

	int currentFunds = m_players[player].PlayerFunds();

	if(currentFunds > amt){
		m_players[player].SetBet(amt);
		return true;
	}

	else{
		return false;
	}

}

void Blackjack::NewDeal(){

	m_deck = Deck();
	m_deck.Shuffle();

	int roundCounter = 0;

	while(roundCounter < 2){

		for(int counter = 0; counter < int(m_players.size()); counter ++){
			m_players[counter].AddCard(m_deck.DealCard());
		}

		m_dealer.AddCard(m_deck.DealCard());

	}

}

void Blackjack::OutputPlayerHand(int player){

	m_players[player].DisplayPlayer();

}

void Blackjack::OutputDealerHand(){
	m_dealer.DisplayDealer();

}

bool Blackjack::HitPlayer(int player){
	return true;

}

void Blackjack::DealerPlay(){

}

int Blackjack::SettlePlayerBet(int player){
	return 1;

}
