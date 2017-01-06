#include <iostream>
#include "Hand.h"

using namespace std;

Hand::Hand(){
}
void Hand::addCard(Card newCard){
  m_cards.insert(m_cards.end(), newCard);
}
void Hand::printCards(){
  for(int i = 0; i < m_cards.size(); i++){
    m_cards[i].OutputCard();
    if(i != m_cards.size()-1)
      cout << ", ";
  }
}

void Hand::printDealerCards(){
  for(int i = 0; i < m_cards.size()-1; i++){
    m_cards[i].OutputCard();
    if(i != m_cards.size()-2)
      cout << ", ";
  }
  cout << " [hidden card]";
}
int Hand::handValue(){
  int sum = 0;
  bool ace = false;
  for(int i = 0; i < m_cards.size(); i++){
    sum = sum + m_cards[i].GetBlackjackValue();
    if(m_cards[i].GetBlackjackValue() == 1)
      ace = true;
  }
  if(sum + 10 <= 21)
    return sum +10;
  else
    return sum;
}
