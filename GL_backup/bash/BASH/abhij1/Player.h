#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include <vector>
class Player
{
 public:
  Player(); //default constructor
  void SetName(char* name); //sets the player name
  void SetBet(int bet); //sets the player bet
  void SetFund(int fund); //sets the player fund
  char* GetName(); //gets the player name.
  int GetFund(); //gets gets the player's fund
  void GetHand(); //gets the player hand.
  void HandHit(Card card); //Hitting the hand
  void FundIncrease(); //increasing the fund for winning.
  void PrintHand(); //prints the player hand
  void DealerPrintHand(); //prints the print hand
  bool PlayerBust(); //checks if player bust
  void FundDecrease(); //decrease the fund
  void Push(); //pushs the fund
  int GetTotal(); //gets the hand total
  void SetBust(bool bust); //sets if player bust
  void ClearHand(); //clears the hand of all values.
  void DealerHit(Card dcard); //hits the dealer hand.
  bool HasBlackjack(); //checks if the player is blackjack
  //Player(vector<Player> m_player, char*names[]);
  /*player(int money, Hand hand)
    {
    }
  
    In addition to the Blackjack class, you are required to create a Player class, and a Hand class. The Player will keep track of the information about a single player: their name, their pool of betting funds, their bet on the current game, etc.
  */

 private:
  Hand m_hand; //the hand
  char*  m_playerName; 
  int m_playerFund;
  int m_currentBet;
  int m_numberOfPlayers;
  

};
#endif 
