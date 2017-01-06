#include "Hand.h"

void Hand::PrintHand()
{
  // gets amount of card
  int amt = m_card.size();
  // loops thro all card
  for(int x = 0; x < amt;x++)
    {
      // get the Card
      Card thisCard = m_card[x];
      // display card
      thisCard.OutputCard();
    }
}

int Hand::TotalValue()
{
  // bool to figure out if there is an ace 1 or11
  bool haveAce = false;

  // keeps track of total value
  int total = 0;

  // for loop each card
  for(int x = 0; m_card.size() > x; x++)
    {
      // get card valure from card class
      // adds them up
      total += value;
      if(card == ACE)
	{
	  haveAce = true;
	  // adds 10 to makeace value 11
	  total += 10;
	}
    }// end for loop

  // if there was an ACE and the hand busted then 
  // converts the ACE value back to one by subtracting 10
  if(total > 21 && haveAce)
    {
      total -= 10;
    }

  // returns that total
  return total;
}

void Hand::AddCard(Card card)
{
  m_card.push_bacck(card);
}

