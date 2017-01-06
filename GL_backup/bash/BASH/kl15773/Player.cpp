#include "Player.h"

/*
 * Constructors
 */

// defualt: no arguments
Player::Player()
{
  m_Name = "UNREGISTERED";
  m_MoneyFund = 0;
}

// with a name and initial money
Player::Player(char name, int money)
{
  m_Name = name;
  m_MoneyFund = money;
}


/*
 * Methods Functions
 */

// changes current bet of the user
void Player::SetBet(int money)
{
  m_CurrentBet =  money;
}

// returns current player's bet
int Player::GetBet()
{
  return m_CurrentBet;
}

// returns the total money they have
int Player::GetFunds()
{
  return m_MoneyFund;
}

//gets the funds of the player
void Player::SetFunds(int money)
{
  m_MoneyFund = money;
}

// (adds) puts money into the money fund
void Player::DepositMoney(int money)
{
  m_MoneyFund += money;
}

// (minus) takes money from money fund
void Player::WithdrawMoney(int money)
{
  m_MoneyFund -= money;
}

// returns the name of the player
char Player::GetName()
{
  return m_Name;
}

// checks if busted 
// true if bust false if not
bool Player::IsBust()
{
  return m_bust;
}

// makes m_bust true
void Player::GotBusted()
{
  m_bust = true;
}

//gets the players Hand
Hand Player::GetHand()
{
  return m_hand;
}
