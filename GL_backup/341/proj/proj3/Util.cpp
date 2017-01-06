/**************************************************************            
 * File:    Util.cpp
 * Project: CMSC 341 - Project 3 - Word Frequency                              
 * Author : Neh Patel                                                          
 * Date   : 04-November-2014                                                  
 * Section: Lecture-02                                                         
 * E-mail:  npatel10@umbc.edu                                                  
 *                                                                    
 *  This is the source file of Util. It contains the implementations of the 
 *  fucntions 
 *                                                                             
 *************************************************************/
#include "Util.h"
#include <algorithm>
#include <cctype>

/*=======================================================================
  LOWER
     takes in a string and then lowercases it, returns the lowercased string 
     =======================================================================*/
string Util::Lower(string word){
    // to lowercase and get rid of extra things                              
    transform(word.begin(), word.end(), word.begin(), (int (*)(int))tolower);
    return word;
  }

/*=======================================================================      
  STRIP                                                                       
     strips of non-alpha characters from the string. unless they are - or 
     '. 
  =======================================================================*/ 
string Util::Strip(string inString){
    string temp = inString;
    inString = "";
    for(int i=0; i <signed(temp.length()); i++){
      // taking out everything except the -,', and obviously the alphabets  
      if (isalpha(temp[i]) || temp[i] == '-' || temp[i] == '\''){
	// if oky add it onto the string 
	inString += temp[i];
      }
    }
    return inString;
  }
  
