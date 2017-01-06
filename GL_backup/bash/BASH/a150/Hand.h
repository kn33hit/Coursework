/****************************************************************
 * File:    Hand.h
 * Project: CMSC 202 Project 2, Fall 2014
 * Author:  Anh Ho
 * Date:    10/19/14
 * Section: 03
 * E-mail:  a150@umbc.edu 
 *
 *   This file contains the declarations for the Hand class.
 *
 ****************************************************************/

#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector> 

class Hand{

public:

	Hand();
	void NewCard(Card card);
	void DisplayPlayerCards();
	void DisplayDealerCards();

private:
	std::vector<Card> m_cards;

};

#endif
