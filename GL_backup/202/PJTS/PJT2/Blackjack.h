/****************************************************************
 * File:    Blackjack.h
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  John Park
 * Date:    3/10/14
 * Section: all
 * E-mail:  park@umbc.edu 
 *
 *   This file contains the declaration for the Blackjack class.
 *   The class manages and implements the mechanics for a multi-player
 *   version of the Blackjack/21 program, including bets.
 *
 ****************************************************************/

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <vector>
#include "Player.h"
#include "Hand.h"
#include "Deck.h"

class Blackjack {
 public:
  /*
   * default (no-arg) constructor: sets up a game with one player:
   *   "Jane", starting with $100
   */
  Blackjack();

  /*
   * Standard constructor: sets up a game with a collection of players,
   *   number specified by numPlayers, with given names.
   *   Each player is given a default $100
   */
  Blackjack(char *names[], int numPlayers);

  /****************************************************************
   * GetNumPlayers:
   * Preconditions: none.
   * Postconditions:
   *   Returns: the number of players registered for the game
   ****************************************************************/
  int GetNumPlayers();

  /****************************************************************
   * GetPlayerName:
   * Preconditions:
   *   player -- the index of the requested player
   * Postconditions:
   *   Returns: the given player's name
   ****************************************************************/
  char *GetPlayerName(int player);

  /****************************************************************
   * GetPlayerFunds
   *   Return the given player's pool of available funds
   * Preconditions:
   *   player -- the index of the requested player
   * Postconditions:
   *   Returns: The amount of funds the player currently has remaining
   ****************************************************************/ 

  int GetPlayerFunds(int player);

  /*
   * Set the given player's pool of funds available for betting
   */
  void SetPlayerFunds(int player, int amt);

  /*
   * Set how much the player wants to bet in current round.
   * This must be compared against available funds, and rejected
   * if funds are insufficient.
   * Postconditions:
   *   amount of bet is recorded for the player
   *   returns true if bet is valid; false if insufficient funds.
   */
  bool SetPlayerBet(int player, int amt);

  /*
   * Create a fresh Deck, shuffle it, and deal out 2 cards
   * to each player and the dealer, going around the circle
   * one card at a time, like most card games.
   */
  void NewDeal();

  /*
   * Display the player's hand
   */
  void OutputPlayerHand(int player);


  /****************************************************************
   * OutputDealerHand:
   *   Displays dealer's hand.
   * Preconditions: none.
   * Postconditions:
   *   Output the dealer's hand to cout, hiding the hole card (the
   *   second card).  So, it should display something like:
   *   "Ace of Spades, [hidden card]"
   *   Note: just display cards; no label at start, no endl at end.
   ****************************************************************/
  /*
   * Parameters: none.
   */
  void OutputDealerHand();

  /*
   * Deal the player another card.
   * Preconditions:
   *   Player must not have gone bust earlier; this is a precondition
   *   you are required to check for!
   * Postconditions:
   *   returns true if player is busted due to new card; false otherwise.
   *   (HINT: it would probably be helpful to record that the player went
   *    bust in some object.)
   */
  bool HitPlayer(int player);

  /*
   * Deal to the Dealer's hand until she stops (because she has
   * 17 or higher).
   * Postconditions:
   *   Dealer might have gone bust, or might have blackjack (in which
   *   case no cards were taken.)
   */
  void DealerPlay();

  /*
   * At end of game, settle bet for given player:
   *   Compare player's hand to
   */
  int SettlePlayerBet(int player);



 private:

  /*
   * ADD YOUR DATA MEMBERS HERE
   * The following are just examples; feel free to modify or delete
   */

  std::vector<Player> players;
  Deck m_deck;
  Player m_dealer;
  int Hit(Player &player);
  int m_intPlayers;
  int m_handValue;
};

#endif 
