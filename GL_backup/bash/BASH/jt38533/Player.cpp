#include <iostream>
#include <cstdlib>
#include "Player.h"
//This is the Players class 
//which will keep track of player's information
using namespace std;

Player::Player()
{
}

Player::Player(char *playerName)
{
  m_bet = 0;
  m_funds = 100;
  m_playerName = playerName;
}

char *Player::GetName()
{
  return m_playerName;
}

int Player::GetFunds()
{
  return m_funds;
}

int Player::SetFunds(int amt)
{
  m_funds = amt;
  return m_funds;
}

int Player::GetBet()
{
  return m_bet;
}
void Player::SetBet(int amt)
{
  m_bet = amt;
}

void Player::takeCard(Card card)
{
  m_currentHand.addCard(card);
}

void Player::CurrentHand()
{
  m_currentHand.DisplayCards();
}

void Player::GetCard()
{
  m_currentHand.CurrentCard();
}

char Player::GetDealerHand()
{
  m_currentHand.DealerCard();
}
bool Player::GetBust()
{
	return m_bust;
}
void Player::SetBust()
{
  m_bust = false;
}
int Player::GetHand()
{
  return m_currentHand.sizeOfHand();
}
int Player::GetValue()
{
  return m_currentHand.TotalValue();
}
/*void Player::Clear()
{
  m_currentHand.clear();
}
*/