/**************************************************************                
 * File:    Util.h                                                   
 * Project: CMSC 341 - Project 3 - Word Frequency                              
 * Author : Neh Patel                                                          
 * Date   : 04-November-2014                                                   
 * Section: Lecture-02                                                         
 * E-mail:  npatel10@umbc.edu                                                  
 *                                                                             
 * Util class header file. No constructor. Just a couple fucntions to 
 * be used in the project to filter the words read from the file 
 *                                                                             
 *************************************************************/

#ifndef UTIL_H
#define UTIL_H
#include <string>
using namespace std;
class Util{
 public: 
  static string Lower(string word);
  static string Strip(string word);
};

#endif
