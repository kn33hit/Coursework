#include <iostream>
#include "Hand.h"
using namespace std;



Hand::Hand() {
  
}



int Hand::SizeOf() {
  return m_cards.size();
}




void Hand::SetCard(Card card) {
  m_cards.push_back(card);
}




void Hand::OutputCard(int card) {
  m_cards[card].OutputCard();
}



int Hand::ValueOf(int card) {
  int value;
  value = m_cards[card].GetBlackjackValue();
  return value;
}
