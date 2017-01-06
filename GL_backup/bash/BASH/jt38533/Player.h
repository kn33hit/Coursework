//File: Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"

class Player
{
 public:
  /****************************************************************
   * Name:Player
   *   default no arguments
   * Preconditions: none
   * Postconditions:
   *   Returns: the given player's name
   ****************************************************************/
  Player(); 
  /****************************************************************
   * Name: Player
   *   Standard Constructor
   * Preconditions:
   *   playerName - name of player
   * Postconditions:
   *   Create a player object with default funds of $100 and player
   *   name
   ****************************************************************/
  Player(char *playerName);
  /****************************************************************
   * Name: GetName
   * Preconditions: none
   * Postconditions:
   *   Returns: the given player's name
   ****************************************************************/
  char *GetName();
    /****************************************************************
   * Name: GetFunds
   * Preconditions: none
   * Postconditions:
   *   Returns: the fund of the specific player
   ****************************************************************/
  int GetFunds();
    /****************************************************************
   * Name: SetFunds
   * Preconditions: 
   *   amt- the amount of funds the player is given
   * Postconditions:
   *   Set the player's fund 
   ****************************************************************/
  int SetFunds(int amt);
    /****************************************************************
   * Name: GetBet
   * Preconditions: none
   * Postconditions:
   *   Returns: the given player's bet
   ****************************************************************/
  int GetBet();
    /****************************************************************
   * Name: SetBet
   * Preconditions: 
   *   amt- the amount of bet the player wishes to bet
   * Postconditions:
   *   Sets the player's bet with the new bet 
   ****************************************************************/
  void SetBet(int amt);
    /****************************************************************
   * Name: takeCard
   * Preconditions: 
   *   Card- A Card class object is pass through
   *   and is going through Hand class to add card to 
   *   a Hand vector holding the cards
   * Postconditions:
   *   The card is added to the player's hand
   ****************************************************************/
  void takeCard(Card card);
    /****************************************************************
   * Name: CurrentHand
   * Preconditions: none
   * Postconditions:
   *   Displays the player's hand of cards
   ****************************************************************/
  void CurrentHand();
  void GetCard();
    /****************************************************************
   * Name: GetDealerHand
   * Preconditions: none
   * Postconditions:
   *   Returns: the given player's name
   ****************************************************************/
  char GetDealerHand();
  /****************************************************************
   * Name: GetBust
   * Preconditions: none
   * Postconditions:
   *   Returns: the bool value of bust
   *	if the player went bust the value would be false
   ****************************************************************/
  bool GetBust();
  /****************************************************************
   * Name: SetBust
   * Preconditions: none
   * Postconditions:
   *   Returns: Set member m_bust to be true or false
   ****************************************************************/
  void SetBust();
  /****************************************************************
   * Name: GetHand
   * Preconditions: none
   * Postconditions:
   *   Returns: the size of the hand which holds the cards
   ****************************************************************/
  int GetHand();
  /****************************************************************
   * Name: GetValue
   * Preconditions: none
   * Postconditions:
   *   Returns:
   ****************************************************************/
  int GetValue();
  /****************************************************************
   * Name: Clear
   * Preconditions: none
   * Postconditions:
   *   Clear hands for the next game
   ****************************************************************/
 // void Clear();
  
 private:
  char *m_playerName;
  int m_funds;
  int m_bet;
  bool m_bust;
  Hand m_currentHand;	
};
#endif
