//This is the Hand class
//Christopher Turner
//ft93935
//10/19/2014


#include "Hand.h"
using namespace std;
Hand::Hand(){
}
void Hand::AddCard(Card card){
  m_cards.push_back(card);
}
Card Hand::GetCard(int card){
  return m_cards[card];
}
int Hand::Size(){
  return m_cards.size();
}
void Hand::Clear(){
  m_cards.clear();
}
