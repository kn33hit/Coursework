/****************************************************************
 * File:    Player.h
 * Project: CMSC 202 Project 2, Spring 2014
 * Author:  Denmark Luceriaga
 * Date:    3/18/14
 * Section: 
 * E-mail:  dlu1@umbc.edu 
 *
 *   This file contains the declaration for the Player class.
 *   This class will keep track of the information about a 
 *   single player: their name, their pool of betting funds, 
 *   their bet on the current game, etc.
 *
 ****************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Hand.h"
#include "Deck.h"
#include "Card.h"
#include <string>


class Player {
 public:

  Player();
  /****************************************************************
   * UpdateFunds:
   *     Updates player's funds as part of end-of-round bet-settling  
   * Preconditions: none.
   * Postconditions: Sets up one player: "Jane", starting with $100
   ****************************************************************/
  void UpdateFunds(int, int, bool);

  /****************************************************************
   * SetPlayerName:
   *     Assigns name to char* m_name
   * Preconditions: char* is a player's name
   * Postconditions: m_name is player's name
   ****************************************************************/
  void SetPlayerName(char*);

  /****************************************************************
   * GetPlayerName:
   *     Retrieves player's name
   * Preconditions: none.
   * Postconditions: Returns m_name
   ****************************************************************/
  char* GetPlayerName();

  /****************************************************************
   * GetPlayerFunds:
   *     Retrieves player's funds
   * Preconditions: none.
   * Postconditions: Return's m_funds
   ****************************************************************/
  int GetPlayerFunds();

  /****************************************************************
   * GetPlayerBet:
   *     Retrieves player's bet
   * Preconditions: none.
   * Postconditions: Returns m_bet
   ****************************************************************/
  int GetPlayerBet();

  /****************************************************************
   * GetPlayerBust:
   *     Retrieves player's status of bust
   * Preconditions: none.
   * Postconditions: Returns m_bust
   ****************************************************************/
  bool GetPlayerBust();

  /****************************************************************
   * SetPlayerFunds:
   *     Stores value of player's funds
   * Preconditions: Funds must be int
   * Postconditions: Assigns int to m_funds
   ****************************************************************/ 
  void SetPlayerFunds(int);

  /****************************************************************
   * SetPlayerBet:
   *     Stores value of player's bet
   * Preconditions: Bet must be int
   * Postconditions: Assigns into to m_bet
   ****************************************************************/
  void SetPlayerBet(int);

  /****************************************************************
   * SetPlayerBust:
   *     Stores player's status of bust
   * Preconditions: bool must be false if player hasn't busted
   * Postconditions: Assigns bool to m_bust
   ****************************************************************/
  void SetPlayerBust(bool);

  /****************************************************************
   * TakeCard:
   *     Gets card ready to be placed in player's hand
   * Preconditions: Card must be top card from game deck
   * Postconditions: Card is passed into PutCardIntoHand()
   ****************************************************************/
  void TakeCard(Card);

  /****************************************************************
   * LookAtHand:
   *     Looks at hand to get ready to get number of cards in hand
   * Preconditions:
   * Postconditions: GetSizeOfHand() is called
   ****************************************************************/
  int LookAtHand();

  /****************************************************************
   * LookAtHand:
   *     Looks at hand to get ready to output a card
   * Preconditions: int is index of card
   * Postconditions: int is passed into LookAtCards()
   ****************************************************************/
  void LookAtHand(int);

  /****************************************************************
   * ClearPlayerHand:
   *     Gets ready to empty player's hand
   * Preconditions: none.
   * Postconditions: Player's m_cards vector is cleared
   ****************************************************************/
  void ClearPlayerHand();

  /****************************************************************
   * GetHandValueAccess:
   *     Gets access to hand so hand value can be computed
   * Preconditions: none.
   * Postconditions: Hand object's GetHandValue() is returned
   ****************************************************************/
  int GetHandValueAccess();

  /****************************************************************
   * GetPlayerBJHandAccess:
   *      Gets access to hand
   * Preconditions: none.
   * Postconditions: GetBJHand()is called and returned
   ****************************************************************/
  bool GetPlayerBJHandAccess();

 private:
  char* m_name;
  int m_funds;
  int m_bet;
  bool m_bust;

  Hand m_hand;
};

#endif //PLAYER_H
