//This will be the hand class file header
//Christopher Turner
//ft93935
#ifndef HAND_H
#define HAND_H
#include "Card.h"
#include <iostream>
#include <vector>
using namespace std; 
class Hand{
public:
  Hand();
  void AddCard(Card card);
  Card GetCard(int card);
  void Clear();
  int Size();
private:
  std::vector<Card> m_cards;
  //int Score;
  //int NumHits;
  //int IsBlackJack;
};
#endif
