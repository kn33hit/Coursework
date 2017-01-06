/****************************************************************
 * File:    Player.cpp
 * Project: CMSC 202 Project 2, Fall 2014
 * Author:  Anh Ho
 * Date:    10/19/14
 * Section: 03
 * E-mail:  a150@umbc.edu 
 *
 *   This file contains the definitions for the Player class.
 *
 ****************************************************************/
#include <iostream>
using namespace std;
#include <string>
#include "Player.h"
#include "Hand.h"

Player::Player(){
	m_name = NULL;
}

Player::Player(char player, int amount){

	m_name = player;
	m_funds = amount;
}

char* Player::PlayerName(){

	return &m_name;

}

int Player::PlayerFunds(){

	return m_funds;
}

void Player::SetFunds(int amount){

	m_funds = amount;

}

void Player::SetBet(int amount){
	m_currentBet = amount;
}

void Player::AddCard(Card card){
	m_hand.NewCard(card);
}

void Player::DisplayPlayer(){
	m_hand.DisplayPlayerCards();
}

void Player::DisplayDealer(){
	m_hand.DisplayDealerCards();
}