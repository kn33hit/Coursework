#include "Player.h"
#include <vector>
#include <iostream>

using namespace std;

//default constructor.
Player::Player()
{
}

//Output:none
//input: name 
//description: sets the player name 
void Player::SetName(char* name)
{
  m_playerName = name;
}
//Output:none
//input: bet
//description: sets the player bet 
void Player::SetBet(int bet)
{
  m_currentBet = bet;
}
//Output:none
//input: fund
//description: sets the player fund 
void Player::SetFund(int fund)
{
  m_playerFund = fund;
}
//Output: player name
//input: none
//description: gets the player name 
char* Player::GetName()
{
  return m_playerName;
}
//Output: player fund
//input: none
//description: gets the player fund 
int Player::GetFund()
{
  return m_playerFund;
}
//Output: none
//input: card
//description: sends card to hand. 
void Player::HandHit(Card card)
{
  m_hand.AddCard(card);
}
//Output: none
//input: card
//description: sends the card to dealer hand 
void Player::DealerHit(Card dcard)
{
  m_hand.Dealer(dcard);
}

//output: none
//input: none
//description: increases player fund
void Player::FundIncrease()
{
  
  m_playerFund = m_playerFund+(2*m_currentBet);
}
//output: none
//input: none
//description: decrease player fund
void Player::FundDecrease()
{
    m_playerFund = m_playerFund-m_currentBet;
}
//output: none
//input: none
//description: returns player fund
void Player::Push()
{
  m_playerFund = m_playerFund+m_currentBet;
}
//output: none
//input: none
//description: tells hands to print card
void Player::PrintHand()
{
  m_hand.PrintCard();
}
//output: none
//input: none
//description: tells hands to print 
void Player::DealerPrintHand()
{
  m_hand.DealerPrintHand();
}
//output: true or false
//input: none
//description: tells hands is bust 
bool Player::PlayerBust()
{
  if(m_hand.Bust() == true)
    return true;
  else
    return false;
}
//output: total value
//input: none
//description: gets the hand total
int Player::GetTotal()
{
  return m_hand.FindTotal();
}
//output: none
//input: bust
//description: sets bust making total equal zero
void Player::SetBust(bool bust)
{
  int total = 0;
}
//output: none
//input: none
//description: makes a new hand
void Player::ClearHand()
{
  //m_hand.DeleteTotal();
  m_hand = Hand();
}
//output: true or false
//input: none
//description: see if player is blackjack 
bool Player::HasBlackjack()
{

  if(m_hand.NumCards() == 2 && GetTotal() == 21)
    return true;
  else
    return false;
}
