/****************************************************************
* File:    Blackjack.cpp
* Project: CMSC 202 Project 2, Spring 2014
* Author:  Jacob Lutz
* Date:    3/28/14
* Section: 08
* E-mail:  jlutz1@umbc.edu
*
*   This file contains the implementation of the Blackjack class.
*   The class manages and implements the mechanics for a multi-player
*   version of the Blackjack/21 program, including bets.
*
****************************************************************/

#include "Blackjack.h"
#include <iostream>
#include <string>
using namespace std;

// Blackjack
// Default Constructor
Blackjack::Blackjack()
{
    char player[5] = "Jane";
    m_players.push_back(Player(player, 100));
}

// Blackjack
// Standard Constructor
Blackjack::Blackjack(char *names[], int numPlayers)
{
    for (int player = 0; player < numPlayers; player++)
        m_players.push_back(Player(names[player], 100));
}

// GetNumPlayers
// Returns the number of players during the current round
int Blackjack::GetNumPlayers()
{
    return static_cast<int>(m_players.size());
}

// GetPlayerName
// Returns the current player's name
char *Blackjack::GetPlayerName(int player)
{
    return m_players[player].GetName();
}

// GetPlayerFunds
// Returns the current player's funds
int Blackjack::GetPlayerFunds(int player)
{
    return m_players[player].GetFunds();
}

// SetPlayerFunds
// Sets the player's money available to bet
void Blackjack::SetPlayerFunds(int player, int amt)
{
    m_players[player].SetFunds(amt);
}

// SetPlayerBet
// Sets the player's bet for the round
bool Blackjack::SetPlayerBet(int player, int amt)
{
    bool betIsValid = m_players[player].SetCurrentBet(amt);
    if (betIsValid)
        return true;
    else
        return false;
}

// NewDeal
// Creates a new deck, shuffles, and deal out the cards
void Blackjack::NewDeal()
{
    // create and shuffle new deck
    m_deck = Deck();
    m_deck.Shuffle();
    
    // deal new cards to each player, then to dealer; repeat
    for (int deal = 0; deal < 2; deal++) {
        for (unsigned int player = 0; player < m_players.size(); player++)
            m_players[player].AddCardToHand(m_deck.DealCard());
        m_dealer.AddCardToHand(m_deck.DealCard());
    }
}

// OutputPlayerHand
// Prints the current player's hand
void Blackjack::OutputPlayerHand(int player)
{
    m_players[player].OutputHand(false);
}

// OutputDealerHand
// Prints the dealer's hand
void Blackjack::OutputDealerHand()
{
    m_dealer.OutputHand(true);
}

// HitPlayer
// Deals the player another card and checks if player is now bust
bool Blackjack::HitPlayer(int player)
{
    // first, check if player has already bust
    // if false, deal a new card
    if (m_players[player].IsBust() == false) {
        m_players[player].AddCardToHand(m_deck.DealCard());

        // print out new card
        m_players[player].OutputNewCard();
        cout << endl;

        // now check if player has gone bust due to new card
        if (m_players[player].IsBust())
            return true;
        else
            return false;
    }
    // if function reaches this point, above statement did not execute
    // most likely means the player already went bust
    return false;
}

// DealerPlay
// Loops until the dealer has 17 or higher, or busts
void Blackjack::DealerPlay()
{
    cout << ">>Dealer's turn:" << endl;

    //reveal hidden card
    cout << "Hand: ";
    m_dealer.OutputHand(false);
    cout << endl;

    // loop only while the dealer's hand value is less than 17
    do {
        // determine if the dealer has bust
        // if not, print dealer's next move
        if (m_dealer.IsBust())
            cout << "Busted!";
        else {
            if (m_dealer.GetHandValue() < DEALER_STAY) {
                cout << "Dealer's move: hit" << endl << endl;

                // give the dealer a new card
                m_dealer.AddCardToHand(m_deck.DealCard());

                // print the dealer's new card and hand
                m_dealer.OutputNewCard();
                cout << endl << "Hand: ";
                m_dealer.OutputHand(false);
                cout << endl;
            }
        }
    } while (m_dealer.GetHandValue() < DEALER_STAY);

    // check dealer's final standing
    if (m_dealer.IsBust())
        cout << "Busted!" << endl << endl;
    else
        cout << "Dealer's move: stay" << endl << endl;

    // print dealer's hand value
    if (m_dealer.GetHandValue() == BLACKJACK)
        cout << "Dealer has blackjack" << endl;
    else if (m_dealer.GetHandValue() > BLACKJACK)
        cout << "Dealer has busted" << endl;
    else
        cout << "Dealer has " << m_dealer.GetHandValue() << endl;
}

// SettlePlayerBet
// Compares player and dealer's hands
// and determines whether player wins or loses
int Blackjack::SettlePlayerBet(int player)
{
    cout << m_players[player].GetName();

    // determine whether to display blackjack, bust, or hand value
    if (m_players[player].GetHandValue() == BLACKJACK)
        cout << " has blackjack--";
    else if (m_players[player].GetHandValue() > BLACKJACK)
        cout << " has busted--";
    else
        cout << " has " << m_players[player].GetHandValue() << "--";

    // determine the winner
    if ((m_players[player].GetHandValue() > m_dealer.GetHandValue() || m_dealer.IsBust()) && m_players[player].IsBust() != true) {
        // player has won
        cout << m_players[player].GetName() << " wins" << endl;
        m_players[player].WinGame();
    }
    else if (m_players[player].GetHandValue() == m_dealer.GetHandValue()) {
        // tie game
        cout << "tie" << endl;
        m_players[player].TieGame();
    }
    else {
        // dealer has won
        cout << "Dealer wins" << endl;
        m_players[player].Reset();
    }

    // if final comparison has been made, clear dealer's hand
    if (player == (static_cast<int>(m_players.size() - 1)))
        m_dealer.Reset();

    return 0;
}
