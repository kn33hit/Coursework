#include <iostream>
#include <cstdlib>
#include "Hand.h"
//This is the Hands Class
//which will keep track of the cards from a single player
using namespace std;

Hand::Hand()
{
}
//***********************
void Hand::DisplayCards()
{
  for (int i = 0; i < int(m_currentCards.size());i++)
    {
     m_currentCards[i].OutputCard();
	cout<<", ";
   }
}

void Hand::DealerCard()
{
  m_currentCards[0].OutputCard();
}

void Hand::addCard(Card card)
{
  m_currentCards.push_back(card);
}

void Hand::GetDealerValue()
{
  for (int i = 0; i < int(m_currentCards.size()); i++)
    {
      m_currentCards[i].OutputCard();
    }
}

int Hand::sizeOfHand()
{
  int handSize = m_currentCards.size();
  return handSize;
}

void Hand::CurrentCard()
{
  Card tempCard = m_currentCards.back();
  tempCard.OutputCard();
}
int Hand::TotalValue()
{
  int value = 0;
  for (int i = 0; i < int(m_currentCards.size()); i++)
    {
      value = value + m_currentCards[i].GetBlackjackValue();
    }
  return value;
}
