/**************************************************************
 * File:    HashedSplays.h
 * Project: CMSC 341 - Project 3 - Word Frequency
 * Author : Neh Patel
 * Date   : 04-November-2014
 * Section: Lecture-02
 * E-mail:  npatel10@umbc.edu
 *
 * HashedSplays header class. Also contains the implementations of the function
 * The program takes in the file and reads all the words, filters them and 
 * adds the words as a node into the correct tree that exists in the vector 
 * of trees(tables)
 *
 *************************************************************/
#ifndef HASHED_SPLAYS_H
#define HASHED_SPLAYS_H
#include "Node.h"
#include "SplayTree.h"
#include "Exceptions.h"
#include <vector> 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

/*-------------------------------------------------------------------------
  HASHED SPLAYS
     constrcutor. intializes the table with empty splay trees. takes in a 
     number and makes that size of a vector of splay trees
    
  --------------------------------------------------------------------------*/
class HashedSplays{
 public:
  HashedSplays(int size){ 
    for(int i = 0; i < size; i++){
      // need to make a new splay tree to insert in the hash table 
      SplayTree<Node> splay;
      // need to insert the the node before we insert the tree into the 
      // vector 
      table.push_back(splay);
    }
  }

  /*-------------------------------------------------------------------------    ~HASHED SPLAYS                          
       destrctor. used just to output that all my results are in the file 
  --------------------------------------------------------------------------*/
  ~HashedSplays(){
    cout << "The results are in the Results.txt" << endl;
    table.clear();
  }

  /*------------------------------------------------------------------------- 
  FILE READER 
      reads the file of the filename that is passed in. reads the words, then 
      filters it and inserts it inot a tree according to the first alphabet 
  --------------------------------------------------------------------------*/
  void FileReader(char* filename){
    ifstream infile;
    infile.open(filename,ios_base::in);
    if(infile.fail()){
      cout << "failed to open the file" << endl;
      exit(1);
    }
    string word;
    // read in every word 
    while(infile >> word){
      // filter the word
      word = Util::Strip(word);
      // go through the table and find the tree to insert in 
      for(int i = 0; i < signed(table.size()); i++){
	char alphachar = static_cast<char>(i + 97);
	// casting the char to a string                                     
	string tempWord(1,alphachar);
    	// compare the initial word. so you know which splay to insert in
	string tempStr = Util::Lower(word);
	// SOMETHING WRONG HERE 
	// lowercase it so the upper case words are included as well 
	if(tempWord[0] == tempStr[0]){
	  Node insertWord(word,1);
	  // if the word already exists in the tree. increment the frequency  
	  if(table[i].contains(insertWord)){
	    // get the pointer to that node 
	    Node* tempNode = &table[i].GetRootNode();
	    tempNode->IncrementFrequency();
	  }else{
	    // if not in the tree. insert that word 
	    table[i].insert(insertWord);
	  }
	}
      }
    }
    infile.close();
  }

  /*-------------------------------------------------------------------------    PRINT HASH COUNT RESULTS                                            
       writes the root node of the splay tree to a file.
       Every splay tree in table       
  ------------------------------------------------------------------------*/
  void PrintHashCountResults(){
    // use ofstream so when writing to it when program restarts. the results 
    // starts over fresh
    ofstream outfile;
    outfile.open("Results.txt"); 
    // print all root nodes 
    for(int i = 0; i < signed(table.size()); i++){
      if(table[i].isEmpty()){
	outfile << "This tree has no nodes" << endl;
      }else{
      outfile << "This tree starts with ";
      // creating a node to print 
      Node temporary = table[i].GetRootNode();
      outfile << temporary << " and has " << table[i].GetSize() << " nodes" << endl;
      }
    }
    outfile.close();
  }
  
 /*-------------------------------------------------------------------------  
  PRINT TREE(INT)
     takes in an int, and then the int is used as a index to write the tree 
     at that index, to a file
  --------------------------------------------------------------------------*/
  void PrintTree(int index){
    // use ftream to add onto the results file 
    fstream outfile;
    outfile.open("Results.txt", fstream::in | fstream::out | fstream::app);
    table[index].writeTree();
    // PRINTING FOR TESTING 
    outfile << "This tree has " << table[index].GetSplayCount() << " splays."<< endl;
    outfile.close();
  }
  
  /*------------------------------------------------------------------------- 
  PRINT TREE(STRING) 
      takes in a string of an uppercase alphabet. Matches with the root word
      with every tree. and if does match then that tree is wrote to a output
      file
  --------------------------------------------------------------------------*/
  void PrintTree(string word){
    // same fstream concept here 
    fstream outfile;
    outfile.open("Results.txt", fstream::in | fstream::out | fstream::app);
    for(int i = 0; i < signed(table.size()); i++){
      char alphachar = static_cast<char>(i + 65);
      // casting the char to a string                                         
      string tempWord(1,alphachar);
      Node tempNode(tempWord, 0);
      // compare the initial word. so you know which splay to print  in  
      if(tempWord[0] == word[0]){
        table[i].writeTree();
	// if we find it earlier just break off so we save some run time 
	if(!table[i].isEmpty()){
	  outfile << "This tree has " << table[i].GetSplayCount() << " splays."<<  endl;
	}
	break;
      }
    }
    outfile.close();
  }
  
  /*-------------------------------------------------------------------------  
  FIND ALL                                                      
       takes in a certain word. And if that word is in any of the tree.
       It prints out that node. 
  --------------------------------------------------------------------------*/
  void FindAll(string find){
    SplayTree<Node> tempTree;
    Node tempNode(find, 0);
    // fstream concept 
    fstream outfile;
    outfile.open("Results.txt", fstream::in | fstream::out | fstream::app);
    outfile << "Printing the results of the nodes that start with \'" << find << "\'" << endl;

    for(int i = 0; i < signed(table.size()); i++){  
      // check if the word is in the file
      char alphachar = static_cast<char>(i + 97);
      // casting the char to a string                    
      string tempWord(1,alphachar);
      // compare the initial word. so you know which splay to print  in
      find = Util::Lower(find);
      if(tempWord[0] == find[0]){
	table[i].FindAll(tempNode);
      }
    }
    //tempTree.FindAll(tempNode);
    /*
    // tempTree.printTree();
    // now we have a cloned tree with the node being in here
    if(tempTree.contains(tempNode)){
      cout << "it is in there alright" << endl;                               
      // we can use root node as it was splayed and now is at the root        
      // of the tree                                                          
      outfile << tempTree.GetRootNode() << endl;   
    }*/
    outfile.close();
  }
  
 private:
  vector< SplayTree<Node> >  table;
};

#endif 
