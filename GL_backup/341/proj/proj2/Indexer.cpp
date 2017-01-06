/**************************************************************
 * File:    Indexer.cpp
 * Project: CMSC 341 - Project 2 - Index Creator
 * Author : Neh Patel
 * Date   : October 16th
 * Section: 02
 * E-mail:  npatel10@umbc.edu
 *
 *  Main project source file. An object that runs the entire 
 *  project. Two files are read, one is filtered words(stop words) file,
 *  another is the data file with text. Then the words are counted and 
 *  line occurence is stored. The main purpose of this project is learn 
 *  Binary Search Tree and use recursion. Run time no greater than O(n).
 *
 *************************************************************/
#include "Indexer.h"
#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

/*----------------------------------------------------------------           
                                                             
  CONSTRUCTOR                                                       
     creates the object.
     have to pass in two string which are the names of the files 
     filterFile is the stop words file.
     dataFile is the text file.

----------------------------------------------------------------*/
Indexer::Indexer(string filter, string data){
  filterFile = filter;
  dataFile = data;
}

/*----------------------------------------------------------------              
  DO INDEX                                                 
     main core function which will call other functions to run the 
     program.

----------------------------------------------------------------*/
void Indexer::DoIndex(){
  bool flagFilter = false;
  bool flagData = false;
  // checking for both files to be easy to open
  flagFilter = FileExists(filterFile);
  flagData = FileExists(dataFile);
  if(flagFilter && flagData){
    // intialization of Filter words(stop words) happens in this 
    // functions
    FileFilterReader();
    // headache in here. make the indexedBST. using filtered BST
    FileWordReader();
    //output finals results into a file
    OutputResults();
  }else{ // if file opening fails
    if(flagData){
      cout << "An error occured in opening " << filterFile << endl;
    }else{
      cout << "An error occured in opening " << dataFile << endl;
    }
  }
}

/*----------------------------------------------------------------        
                                                                  
  FILE EXISTS                                           
     opens a filel and reads it. 
     a single file name is passed in. It opens the file, if a 
     problem occurs in opening the file. Returns false and the 
     program is never ran.

----------------------------------------------------------------*/
bool Indexer::FileExists(string filename){;
  
  ifstream infile;
  infile.open(filename.c_str(),ios_base::in);
  // just to be on a safer side if the file does not open properly

  if(infile.fail()){
    infile.close();
    // return false if opening the file fails
    return false;
  }
  infile.close();
  return true;
}

/*----------------------------------------------------------------                                                                          
  FILE FILTER READER

----------------------------------------------------------------*/
void Indexer::FileFilterReader(){
  ifstream infile;
  infile.open(filterFile.c_str(),ios_base::in);
  string word;
  // easy to make
  while(infile >> word){
    filteredBST.insert(word);
  }
  infile.close();
}                                               

/*----------------------------------------------------------------
                                                                                 
  FILE WORD READER
     takes the file and formats the words to lowercase and gets rid 
     of non-alphabetical characters. Then adds those words into the BST.
     Then using the Filtered BST, make the indexed. Indexed BST uses the 
     overloaded insert to create the tree. as it would update it along the
     way.
                                                                              
----------------------------------------------------------------*/
void Indexer::FileWordReader(){
  ifstream infile;
  infile.open(dataFile.c_str(),ios_base::in);
  string line,word;
  int lineNum =1;
  // would've used lineNum and line to account for the lines and 
  // push it in, but dont have time 
  while(getline(infile,line)){
    // doing this to format the words
      Word lineobj(line);
      // function for Word object. lowercase and formatting
      lineobj.proper();
      string properLine = lineobj.getWord();
      stringstream ss(properLine);
      while(ss >> word){
	Word wordObj(word,lineNum);
	// if not in the filtered, include that word 
	if(filteredBST.contains(word)){
	indexedBST.insert(wordObj,lineNum);
	}
      }
      lineNum++;
    }
  infile.close();
}

/*----------------------------------------------------------------        
                                                                               
  OUTPUTRESULTS
      Uses one of the BST functions to recursively write to a file 
      Trees must not be empty for you to write in the file.

-----------------------------------------------------------------*/
void Indexer::OutputResults(){
  // writes to a file called output.txt(indexedBST)
  indexedBST.outFile("output.txt");
  cout << "The results of indexed BST is in output.txt" << endl;
  //writes to a file calles filterResults.txt(stop words file)
  filteredBST.outFile("filterResults.txt");
  cout << "The results of filtered BST is in filterResults.txt" << endl;
}
