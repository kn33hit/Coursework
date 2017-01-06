/**************************************************************
 * File:    Word.h
 * Project: CMSC 341 - Project 2 - Index Creator
 * Author : Neh Patel
 * Date   : October 16th
 * Section: 02
 * E-mail:  npatel10@umbc.edu
 *
 *  Word object header file. This object is only used to make things 
 *  easier to store the number of occurences of the number and the 
 *  lines that they occur in. Also uses queues to store at what line 
 *  occur in. 
 *  4 operators overloaded: =, <, ==< and <<
 *************************************************************/
#ifndef WORD_H
#define WORD_H
#include <queue>
#include <string>
using namespace std;

class Word{
 public:
  Word(string word);
  Word(string word,int j);
  void CountWord(int lineNum);
  string getWord() const;
  int getWordCount() const;
  queue<int> getQueue() const;
  void setWord(string word);
  void setWordCount(int wordCount);
  void setQueue(queue<int> lineNumer);
  Word& operator=(const Word& rhs);
  bool operator<(const Word& rhs) const;
  bool operator==(const Word& rhs) const;
  void proper();
  friend ostream& operator<<(ostream& os, const Word& obj);
 
 private:
  string word;
  int wordCount;
  queue<int> lineNumber;
};
#endif 
