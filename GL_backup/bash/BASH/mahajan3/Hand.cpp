#include <iostream>
#include "Hand.h"
#include "Card.h"
using namespace std;

Hand :: Hand(){
}

void Hand :: InsertCard(Card card){
  m_cards.push_back(card);
}

void Hand :: PrintHand(){
  for(int i = 0; i < m_cards.size(); i++){
    m_cards[i].OutputCard();
    cout << " ";
  }
}

void Hand :: ClearHand(){
  m_cards.clear();
}

int Hand :: GetSum(){
  return m_sum;
}

int Hand :: SumOfCards(){
  for(int i = 0; i < m_cards.size(); i++){
    int temp = m_cards[i].GetBlackjackValue();
    if(temp == 1){
      temp = 11;
    }
    m_sum = m_sum + temp;
  }
  if(m_sum > 21){
    m_sum = 0;
    for(int i = 0; i < m_cards.size(); i++){
      int temp = m_cards[i].GetBlackjackValue();
      m_sum = m_sum + temp;
    }
  }
  return m_sum;
}
