/*****************************************
** File: Player.cpp
** Project: CMSC 202 Project 2, Fall 2014
** Author: Gregory Rossman ** Date: 10/19/14
** Section: 12
** E-mail: grossm1@umbc.edu
**
** This file contains the implementation of Player class for Blackjack
** class in Proj2 program to use.  The class defines players in a
** blackjack game, who have hands (of cards), current funds and bet
** levels, and names (or rather pointers to names).  Class also handles
** indirectly the outputting of hand info.
**
**
***********************************************/





#include "Player.h"

#include <vector>


// Player constructor default
// instantiate a dummy player
Player::Player()
{
}


// Player constructor standard
// instantiate player with name given by char pointer and with
// given funds
Player::Player(char *name, int funds)
    :m_name(name), m_funds(funds)
{
}


// GetName
// return pointer to player name
char *Player::GetName() const
{
    return m_name;
}



// GetFunds
// return current funds
int Player::GetFunds() const
{
    return m_funds;
}


// SetFunds
// set player's funds to  new given int value
void Player::SetFunds(int newFunds)
{
    m_funds = newFunds;
}



// SetBet
// set player's bet amt for this round to given int value
// if this exceeds player funds, return false, otherwise true
bool Player::SetBet(int amt)
{
    m_betThisRound = amt;
    if(m_betThisRound > m_funds)
    {
	return false;
    }
    return true;
}


// AddCardToHand
// adds given card to player's Hand
bool Player::AddCardToHand(Card card, bool displayCard)
{
    return  m_hand.AddCard(card, displayCard);
}




// OutputHand
// cout all cards currently in hand, neatly listed per instructions
void Player::OutputHand()
{
    m_hand.OutputHand();
}


// OutputHandExceptSecondCard
// cout all cards currently in hand, neatly listed per instructions,
// but hide second card with "[hidden card]"
void Player::OutputHandExceptSecondCard()
{
    m_hand.OutputHandExceptSecondCard();
}




// GetBustedValue
// return true if player busted, else false
bool Player::GetBustedValue() const
{
    return m_hand.GetBustedValue();
}




// GetHandValue
// get highest possible value of hand without busting, if it's
// impossible to not bust,then give lowest possible value of hand,
// Except: if hand is blackjack, return zero
int Player::GetHandValue()
{
    return m_hand.GetHandValue();
}






// IncreaseFundsBy
// increase player's funds by given int (or if int is negative, decrease)
// by absolute value of that int, and reset hand for next round
void Player::IncreaseFundsBy(int increase)
{
    m_funds += increase;
}



// GetAndResetBet
// return what the player was going to be this round, and reset
// m_betThisRound to zero
int Player::GetAndResetBet()
{
    int temp = m_betThisRound;
    m_betThisRound = 0;
    return temp;
}



// ClearHand
// empty player's hand / reinitialize it
void Player::ClearHand()
{
    m_hand = Hand();
}
