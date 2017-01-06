#include "Hand.h"
#include <vector>
#include <iostream>

using namespace std;
//default construstor
Hand::Hand()
{
}

//Output:nothing
//Input: card
//Description: this function adds cards to the m_card vector
void Hand::AddCard(Card card)
{
  m_card.push_back(card);
  m_numCards++;
}
//Output:nothing
//Input: nothing
//Description: this function prints the player hand.
void Hand::PrintCard()
{
  for(int i = 0; i < m_numCards; i++)
    {
      m_card[i].OutputCard();
      if(i != m_numCards - 1)
	{
	  std::cout << " , ";
	}
    }
}
//Output: nothing
//Input: nothing
//Description: this function prints dealer hand.
void Hand::DealerPrintHand()
{
  for(int i = 0; i < m_card.capacity(); i++)
    {
      if(i == 0)
	{
	  m_card[i].OutputCard();
	  std::cout << " , ";
	}
      else
	{
	  //m_card[1].OutputCard();
	  std::cout << "[hidden card] ";
	}
    }
}
//Output: nothing
//Input: nothing
//Description: this function clears all the cads.
void Hand::DeleteTotal()
{
  m_total = 0;
  m_card.clear();
}
//Output: the total value
//Input: nothing
//Description: this function finds the total value of each hand.
int Hand::FindTotal()
{
  int total = 0;
  bool ace = false;
  int numAces(0);
  for(int i = 0; i < m_numCards; i++)
    {
      if(m_card[i].GetBlackjackValue() == 1)
	{
	  ace = true;
	  numAces++;
	}
      total += m_card[i].GetBlackjackValue();     
	
    }
  for(int i = 0; i < numAces; i++)
    {
      total += 10;
      if(total > TWENTYONE)
	{
	  total -= 10;
	}
    }
  
  m_total = total;
  return total;
}
//Output: nothing
//Input: card
//Description: this function adds cards to the m_card vector
void Hand::Dealer(Card dCard)
{
  
  if(FindTotal() < SOFT_SEVENTEEN)
    {
      m_card.push_back(dCard);
    }
 
}
//Output: true or false
//Input: nothing
//Description: this function checks if the hand is bust.
bool Hand::Bust()
{
  
  if(FindTotal() > TWENTYONE)
    {
      return true;
    }
  else
    {
      return false;
    }
  
}
int Hand::NumCards()
{

  return m_card.capacity();
}
