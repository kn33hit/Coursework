/****************************************************************
 * File:    Player.h
 * Project: CMSC 202 Project 2, Fall 2014
 * Author:  Anh Ho
 * Date:    10/19/14
 * Section: 03
 * E-mail:  a150@umbc.edu 
 *
 *   This file contains the declarations for the Player class.
 *
 ****************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Card.h"

class Player{

public:

	Player();
	Player(char player, int amount);
	char* PlayerName();
	int PlayerFunds();
	void SetFunds(int amount);
	void SetBet(int amount);
	void AddCard(Card card);
	void DisplayPlayer();
	void DisplayDealer();

private:
	char m_name;
	int m_funds;
	int m_currentBet;
	Hand m_hand;

};

#endif
