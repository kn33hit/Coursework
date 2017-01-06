#include <vector>
#include "Hand.h"
class Player
{
 public:
  // constructors
  Player();
  Player(char name, int money);

  void SetBet(int money);
  int GetBet();

  void SetFunds(int money);
  int GetFunds();

  void DepositMoney(int money);// add money to funds
  void WithdrawMoney(int money);// take money from funds

  char GetName();

  Hand GetHand();

  void GotBusted();// make the player busted
  bool IsBust();// get bust

 private:
  int m_CurrentBet;
  int m_MoneyFund;
  char m_Name;
  std::vector<Hand> m_hand;
  bool m_bust;
};
