//this is the Player.h file 
//ft93935
//this will have all of the initializations for the player class
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <stdbool.h>
 
class Player{
public:
  //this will be the default constructor
  Player();
  //this is the non default constructor
  Player(char *name, int funds);
  //these are the getters and setters for the player class
  int GetFunds();
  int GetBet();
  void SetHasBusted(bool bustorno);
  bool HasBusted();
  char *GetName();
  void SetName(char *name);
  void SetBet(int bet);
  void HitPlayer(Card card);
  Hand& GetHand();
  void SetFunds(int funds);
private:
  //these will be the values held in the player class
  int m_funds;
  int m_bet;
  bool m_hasBusted;
  Hand m_hand;
  char *m_name;
  //std::vector<Card> hand;
};
#endif
