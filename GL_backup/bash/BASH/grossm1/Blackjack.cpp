/*****************************************
** File: Blackjack.cpp
** Project: CMSC 202 Project 2, Fall 2014
** Author: Gregory Rossman ** Date: 10/19/14
** Section: 12
** E-mail: grossm1@umbc.edu
**
** This file contains the implementation of Blackjack class for
** Proj2 program to use.  It defines a blackjack game with methods
** to handle the main logic of the game.
**
**
***********************************************/






#include "Blackjack.h"
#include <iostream>
#include <stdlib.h>

using namespace std;



// Blackjack (default constructor)
// instantiate with dealer and just one player, funds $100, name
// points to defaultPlayerName class data member (Jane)
Blackjack::Blackjack()
{
    // Add dealer, input dummy amount funds
    char m_dealerName[7] = "Dealer"; //name of dealer for m_dealer object
    m_dealer = Player(&m_dealerName[0], m_dealerFunds);

    // Just add 1 player with default name (Jane) and funds ($100)
    m_numPlayers = 1;
    char m_defaultPlayerName[5] = "Jane"; // Default name when player
                                          // instantiated with no name
    m_players.push_back(Player(&m_defaultPlayerName[0], m_defaultFunds));
}


// Blackjack (standard constructor)
// instantiate with dealer and with <numPlayers> players with names
// as given in array of pointers *names[], default funds ($100)
Blackjack::Blackjack(char *names[], int numPlayers)
    :m_numPlayers(numPlayers)
{
    // Add dealer
    char m_dealerName[7] = "Dealer"; //name of dealer for m_dealer object
    m_dealer = Player(&m_dealerName[0], m_dealerFunds);

    // Add all players to vector m_players
    // in same order as they appeared in argv to main
    m_players.reserve(m_numPlayers);
    for(int i = 0; i < m_numPlayers; i++)
	m_players.push_back(Player(names[i], m_defaultFunds));
}


// GetNumPlayers
// return num of players in game
int Blackjack::GetNumPlayers()
{
    return m_numPlayers;
}


// GetPlayerName
// returns name of player at given index in array of players
// remember player names in main's *argv[] and Player objects
// are indexed similarly
char *Blackjack::GetPlayerName(int player)
{
    return m_players[player].GetName();
}



// GetPlayerFunds
// return funds remaining for player at given index
int Blackjack::GetPlayerFunds(int player)
{
    return m_players[player].GetFunds();
}


// SetPlayerFunds
// set funds of player at given index to new, given integer value
void Blackjack::SetPlayerFunds(int player, int amt)
{
    m_players[player].SetFunds(amt);
}



// SetPlayerBet
// set player-at-given-index's bet amt for this round for this
// round to the given int value if this exceeds player funds,
// return false, otherwise true
bool Blackjack::SetPlayerBet(int player, int amt)
{
    return m_players[player].SetBet(amt);
}


// NewDeal
// create and shuffle a fresh deck, deal 1 card to each player in
// order, then dealer. As you do this, before dealing, empty player's old
// hand. then deal one more card to each player in order, then dealer
// again. If no cards left, error message printed and program exits!
void Blackjack::NewDeal()
{
    // get a fresh deck of cards
    m_deck = Deck();
    m_deck.Shuffle();
    bool displayCard = false; // none of cards dealt to be displayed yet

    // Go around table twice
    for(int i = 0; i < 2; i++)
    {
	// Go through each player in order
	for(int j = 0; j < m_numPlayers; j++)
	{
            // if this is first time around table, clear player's hand
	    if(i == 0)
		m_players[j].ClearHand();

	    // if cards left in deck, deal to player
	    if(m_deck.CardsLeft() <= 0)
	    {
		std::cout << "Error - No cards left in deck.\n\n";
		exit(1);
	    }

	    // impossible to bust first 2 cards, so ignore return value:
            (void) m_players[j].AddCardToHand(m_deck.DealCard(), displayCard);
     	}

	// if this is first time around table, clear dealer's old hand
	if(i == 0)
	    m_dealer.ClearHand();

	// Deal card to dealer if cards left in deck
	if(m_deck.CardsLeft() <0)
	{
	    std::cout << "Error - No cards left in deck.\n\n";
	    exit(1);
	}
	// impossible to bust first 2 cards, so ignore return value:
	(void) m_dealer.AddCardToHand(m_deck.DealCard(), displayCard);
    }

}











// OutputPlayerHand
// display given indexed player's hand to screen, neatly/appropriately
void Blackjack::OutputPlayerHand(int player)
{
    m_players[player].OutputHand();
}




// OutputDealerHand
// display dealer's hand to screen, neatly/appropriately,
// but hide second card
void Blackjack::OutputDealerHand()
{
    m_dealer.OutputHandExceptSecondCard();
}




// HitPlayer
// if already bust, do nothing, return true, otherwise, deal new card
// to given indexed player and print out new card dealt. Return true
// if player busts from new card, otherwise false
bool Blackjack::HitPlayer(int player)
{
    // if already bust, do nothing
    if(m_players[player].GetBustedValue())
	return true;

    // deal new card and cout card
    bool displayCard = true;
    if(m_deck.CardsLeft() <= 0)
    {
	std::cout << "Error - No cards left in deck.\n\n";
	exit(1);
    }
    bool busted = m_players[player].AddCardToHand(m_deck.DealCard(), displayCard);

    return busted;
}





// DealerPlay
// deal cards to dealer repeatedly until hand is 17 or higher
// display each dealt card and display resulting hand each time as
// done in main
void Blackjack::DealerPlay()
{
    // display start of dealer's turn and her hand
    std::cout << "Dealer's turn:\nHand: ";
    m_dealer.OutputHand();




/*
    // if player is going to keep hitting, output will be dealt with
    // in while loop below, but if they are going to stay now, the
    // while loop will never be entered, so we need to say now they
    // are staying...
    // So, if player has hand of 16, 17, 18, 19, 20, 21, or blackjack...
    if(m_dealer.GetHandValue() > 16 || m_dealer.GetHandValue() == 0)
    {
	    std::cout << "Dealer's play: stay\n\n";
    }
*/





    // If applicable, start hitting dealer
    bool displayCard = true; // all cards dealt will be displayed

    // while dealer's hand under 17 and is non-zero (not blackjack), she must hit
    while(m_dealer.GetHandValue() < 17 && m_dealer.GetHandValue() != 0)
    {
	// if no cards left in deck, display error, exit program
        if(m_deck.CardsLeft() <= 0)
	{
	    std::cout << "Error - No cards left in deck.\n\n";
	    exit(1);
	}

	// hit dealer
	std::cout << "\nDealer's play: hit\n\n";
        m_dealer.AddCardToHand(m_deck.DealCard(), displayCard);
    

	// if dealer busted...
	if(m_dealer.GetBustedValue())
	{
	    std::cout << "Busted!\n\n";  
	}
    
	// if dealer has blackjack...
	else if(m_dealer.GetHandValue() == 0)
	{
	    std::cout << "Hand: ";
	    // neatly print hand
	    m_dealer.OutputHand();
	    std::cout << "\nDealer's play: stay\n\n";
	}

	// otherwise, dealer has numbered hand to display...
	else
	{
	    std::cout << "Hand: ";
	    // neatly print hand
	    m_dealer.OutputHand();
	}
    }

    // now that dealer is done hitting, display outcome
    if(m_dealer.GetBustedValue())
    {
        std::cout << "Dealer has busted\n";
    }
    else if(m_dealer.GetHandValue() == 0)
    {
	std::cout << "Dealer has blackjack\n";	
    }
    else
    {
	std::cout << "\nDealer's play: stay\n\n";
	std::cout << "Dealer has " << m_dealer.GetHandValue() << endl;
    }

}






// SettlePlayerBet
// compare given indexed player's hand to dealer's, update player's
// funds to reflect win/lose, output results, zero-out player's bet
// for start of next round, return 0
int Blackjack::SettlePlayerBet(int player)
{
    int bet = m_players[player].GetAndResetBet(); // get bet value and
                                                  // reset zero-out bet
    int playerTotal = m_players[player].GetHandValue();
    int dealerTotal = m_dealer.GetHandValue();
    const char *playerName = m_players[player].GetName();


    // if player has blackjack...
    if(playerTotal == 0)
    {
	// if both player and dealer have blackjack, it's a blackjack tie
	if(dealerTotal == 0)
	{
	    // no change in money, declare blackjack tie
	    std::cout << playerName << " has blackjack--tie\n";
       	}

	// if player has blackjack and dealer has non-blackjack,  player wins
	if(dealerTotal != 0)
	{
	    m_players[player].IncreaseFundsBy(bet); // increase funds
	    std::cout << playerName <<  " has blackjack--";
	    std::cout << playerName << " wins\n";
	}
    }
    // else if player has busted...
    else if(m_players[player].GetBustedValue())
    {
	// if player busted, dealer wins, no matter if dealer had blackjack, busted, or normal
	m_players[player].IncreaseFundsBy(-bet); // decrease funds
	std::cout << playerName <<  " has busted--Dealer wins\n";
    }
    // else if player has no blackjack and hasn't busted (normal hand)
    else
    {
	// if, additionally, the dealer's hand is equal to players (meaning
	// dealer's hand is also non-busted, non-blackjack), they normal tie
	if(dealerTotal == playerTotal)
	{
	    // no change in money, declare tie
	    std::cout << playerName << " has " << playerTotal << "--tie\n";
	}

	// if, additionally, the dealer's hand is lower and non-zero
	// (non-blackjack), the player wins
	if(dealerTotal < playerTotal && dealerTotal != 0)
	{
	    m_players[player].IncreaseFundsBy(bet); // increase funds
	    std::cout << playerName <<  " has " << playerTotal << "--";
	    std::cout << playerName << " wins\n";
	}


	// if, additionally, the dealer's hand is non-busted and higher or
	// dealer's hand is a zero (blackjack) the dealer wins
	if((!m_dealer.GetBustedValue() && dealerTotal > playerTotal)  ||  (dealerTotal == 0) )
	{
	    m_players[player].IncreaseFundsBy(-bet); // decrease funds
	    std::cout << playerName <<  " has " << playerTotal << "--";
	    std::cout << "Dealer wins\n";
	}


	// if, additionally, the dealer is busted, the player wins
	if(m_dealer.GetBustedValue())
	{
	    m_players[player].IncreaseFundsBy(bet); // increase funds
	    std::cout << playerName <<  " has " << playerTotal << "--";
	    std::cout << playerName << " wins\n";
	}
    }




    return 0;
}




