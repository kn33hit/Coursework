/**************************************************************
 * File:    Word.h
 * Project: CMSC 341 - Project 2 - Index Creator
 * Author : Neh Patel
 * Date   : October 16th
 * Section: 02
 * E-mail:  npatel10@umbc.edu
 *
 *  Word object source file. This object is only used to make things
 *  easier to store the number of occurences of the number and the
 *  lines that they occur in. Also uses queues to store at what line
 *  occur in.
 *  4 operators overloaded: =, <, ==< and <<
 *************************************************************/
#include "Word.h"
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

/*----------------------------------------------------------------

  CONSTRUCTOR
     creating the object. Initializes the word data as the word that  
     will be passed in

----------------------------------------------------------------*/

Word::Word(string wordGiven){
  word = wordGiven;
  wordCount = 1;
}

Word::Word(string wordGiven, int lineNum){
  word = wordGiven;
  wordCount = 1;
  lineNumber.push(lineNum);
}


/*----------------------------------------------------------------
                                                                        
  COUNT WORD                                                              
     counts the occurence of words everytime it is called 
     needs a line number to be passed in which is stored in the queue

----------------------------------------------------------------*/
void Word::CountWord(int lineNum){
  
  // have to add THIS-> so it knows to change the pointer values 
  // in the actual tree
  // incrementing by one 
  this->wordCount++;
  // taking care of seg fault by mkaing sure we check for an 
  // empty queue
  // if the line number is the same as the last one
  // it will not be added in the queue
  if((lineNumber.empty()) || (lineNum != lineNumber.back())){
    this->lineNumber.push(lineNum);
  }
}

/*----------------------------------------------------------------             
                                                                               
  GET WORD                                                                 
     it is an accessor.
     helps non-class  access this data member

----------------------------------------------------------------*/
string Word::getWord() const{
  return word;
}

/*----------------------------------------------------------------             
                                                                              
  GET WORD COUNT                                                           
     it is an accessor.                                                   
     helps non-class  access this data member                                 
                                                    
----------------------------------------------------------------*/
int Word::getWordCount() const{
  return wordCount;
}

/*----------------------------------------------------------------             
                                                                               
  GET QUEUE                                                               
     it is an accessor.                                               
     helps non-class  access this data member                                                                                               
 ----------------------------------------------------------------*/
queue<int> Word::getQueue() const{
  return lineNumber;
}

/*----------------------------------------------------------------             
                                                                               
  SET WORD                                         
     it is a mutator.                                                        
     helps non-class mutate this data member                                  
                                                    
--------------------------------------------------------------*/
void Word::setWord(string wordGiven){
  word = wordGiven;
}

/*----------------------------------------------------------------             
                                                                               
  SET WORD COUNT                                                               
     it is a mutator.                                                          
     helps non-class mutate this data member                                                                             
----------------------------------------------------------------*/
void Word::setWordCount(int count){
  wordCount = count;
}

/*----------------------------------------------------------------             
                                                                               
  SET QUEUE                                                        
     it is a mutator.                           
     helps non-class mutate this data member 

----------------------------------------------------------------*/
void Word::setQueue(queue<int> lineNum){
  lineNumber = lineNum;
}

/*----------------------------------------------------------------             
                                                                               
  OPERATOR =                                                          
     an operator overloading function. (=)
     helps you make another object that has the same data members 

----------------------------------------------------------------*/
Word& Word::operator=(const Word& rhs){
  word = rhs.word;
  return *this;
}

/*----------------------------------------------------------------             
                                                                               
  OPERATOR <                                                               
    an operator overloading function. (<)                                      
    an operatore that helps you compare the two word data members 
       and returns a boolean 
 
----------------------------------------------------------------*/
bool Word::operator<(const Word& rhs)const{
  if(word < rhs.word){
    return true;
  }else{
    return false;
  }
}

/*----------------------------------------------------------------             
                                                                               
  OPERATOR ==
    an operator overloading function. (==)                   
    checks to see if the two words are identical or not and returns
       a boolean accordingly 
                                                                               
----------------------------------------------------------------*/
bool Word::operator==(const Word& rhs) const{
  if(word == rhs.word){
    return true;
  }else{
    return false;
  }
}

/*----------------------------------------------------------------             
                                                                               
  OPERATOR <<                                                             
     an operator overloading function. (<<) 
     helps you output the object. Formatable the way you want it
 
----------------------------------------------------------------*/
ostream& operator<<(ostream& os, const Word& obj){
  //output format
  string dots = "......................";
  dots = obj.word + dots.substr(obj.word.size());
  // just output the string with ... and the count 
  os << dots << obj.wordCount << ": ";
  // make a copy of queue because we dont want to lose our original one 
  queue<int> lineNum = obj.getQueue();
  while(!lineNum.empty())
    {
      os << lineNum.front() << "   ";
      lineNum.pop();
    }
  // so we go to next line 
  cout << endl;
  return os;
}


/*----------------------------------------------------------------             
  PROPER 
     lower cases the string passed in and gets rid of extra syntax
     around it.

----------------------------------------------------------------*/
void Word::proper(){
  // to lowercase and get rid of extra things
  transform(word.begin(), word.end(), word.begin(), (int (*)(int))tolower);
  // since word has the string we need a temporary variable
  string temp = word;
  word = "";
  for(int i=0; i <signed(temp.length()); i++){
    // taking out everything except the spaces and obviously the alphabets 
    if (isalpha(temp[i]) || temp[i] == ' '){
      word += temp[i];
    }
  }
}
