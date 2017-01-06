/**************************************************************
 * File:    Indexer.h
 * Project: CMSC 341 - Project 2 - Index Creator
 * Author : Neh Patel
 * Date   : October 16th
 * Section: 02
 * E-mail:  npatel10@umbc.edu
 *
 *  Main project header file. An object that runs the entire
 *  project. Two files are read, one is filtered words(stop words) file,
 *  another is the data file with text. Then the words are counted and
 *  line occurence is stored. The main purpose of this project is learn
 *  Binary Search Tree and use recursion. Run time no greater than O(n).
 *
 *************************************************************/
#ifndef INDEXER_H
#define INDEXER_H
#include <string>
#include "dsexceptions.h"
#include "Exceptions.h"
#include "Word.h"
#include "BST.h"
using namespace std;

class Indexer{
 public: 
  Indexer(string filterFile,string DataFile);
  void DoIndex();
  bool FileExists(string filename);
  void FileFilterReader();
  void FileWordReader();
  void OutputResults();

 private:
  string dataFile, filterFile;
  BinarySearchTree<string> filteredBST;
  BinarySearchTree<Word> indexedBST;
;
};

#endif
