/****************************************************************
 * File:    Hand.cpp
 * Project: CMSC 202 Project 2, Fall 2014
 * Author:  Anh Ho
 * Date:    10/19/14
 * Section: 03
 * E-mail:  a150@umbc.edu 
 *
 *   This file contains the definitions for the Hand class.
 *
 ****************************************************************/

#include <iostream>
using namespace std;

#include "Hand.h"

Hand::Hand(){
	
}

void Hand::NewCard(Card card){
	m_cards.push_back(card);
}

void Hand::DisplayPlayerCards(){
	for(int counter = 0; counter < int(m_cards.size()); counter ++){
		m_cards[counter].OutputCard();
	}
}

void Hand::DisplayDealerCards(){
	m_cards[0].OutputCard();
	cout << "[Hidden Card]";

	for(int counter = 2; counter < int(m_cards.size()); counter ++){
		m_cards[counter].OutputCard();
	}
}