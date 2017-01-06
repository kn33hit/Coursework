/****************************************************************
* File:    Player.h
* Project: CMSC 202 Project 2, Spring 2014
* Author:  Jacob Lutz
* Date:    3/28/14
* Section: 08
* E-mail:  jlutz1@umbc.edu
*
*   This file contains the implementation of the Player class.
*   The class manages the statistics for a given player, including
*   the player's name, funds, and current bet.
*
****************************************************************/

#include "Player.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

// Player
// Default Constructor
Player::Player()
{
    strcpy(m_name, "A lone wanderer");
    m_funds = 0;
    m_currentBet = 0;
}

// Player
// Standard Constructor
Player::Player(char name[])
{
    strcpy(m_name, name);
    m_funds = 0;
    m_currentBet = 0;
}

// Player
// Standard Constructor
Player::Player(char name[], int funds)
{
    strcpy(m_name, name);
    m_funds = funds;
    m_currentBet = 0;
}

// GetName
// Returns the player's name
char* Player::GetName()
{
    return m_name;
}

// GetFunds
// Returns the player's available money
int Player::GetFunds()
{
    return m_funds;
}

// GetCurrentBet
// Returns the player's current bet
int Player::GetCurrentBet()
{
    return m_currentBet;
}

// GetHandValue
// Accesses the player's hand's blackjack value
int Player::GetHandValue()
{
    return m_playerHand.GetHandValue();
}

// IsBust
// Determines if the player has lost
bool Player::IsBust()
{
    if (m_playerHand.GetHandValue() > 21)
        //player is bust
        return true;
    else
        return false;
}

// IncreaseFunds
// Increases the player's money by the specified amount
void Player::SetFunds(int amt)
{
    m_funds = amt;
}

// SetCurrentBet
// Takes money out of player's funds and uses it as the current bet
bool Player::SetCurrentBet(int amt)
{
    if (m_funds >= amt) {
        //player has enough money
        m_funds -= amt;
        m_currentBet = amt;
        return true;
    }
    else
        //player can't afford bet
        return false;
}

// WinGame
// Payout if player wins the game
void Player::WinGame()
{
    m_funds += (m_currentBet * 2);
    m_currentBet = 0;
    m_playerHand.ClearHand();
}

// LoseGame
// Dealer takes the player's bet
void Player::Reset()
{
    m_currentBet = 0;
    m_playerHand.ClearHand();
}

// TieGame
// Returns if player ties the game
void Player::TieGame()
{
    m_funds += m_currentBet;
    m_currentBet = 0;
    m_playerHand.ClearHand();
}

// OutputHand
// Prints to the screen the player's current hand
void Player::OutputHand(bool isDealer)
{
    if (isDealer)
        //print the dealer's hand
        m_playerHand.PrintDealerHand();
    else
        //print the player's hand
        m_playerHand.PrintHand();
}

//OutputNewCard
// Prints the newest card to the screen
void Player::OutputNewCard()
{
    m_playerHand.PrintNewCard();
}

// AddCardToHand
// Adds the card to the player's hand
void Player::AddCardToHand(Card cardToAdd)
{
    m_playerHand.AddCard(cardToAdd);
}
