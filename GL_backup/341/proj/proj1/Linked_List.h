/**************************************************************             
 * File:    Linked_List.h                                             
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation                    
 * Author : Neh N. Patel                                                       
 * Date   : Sept 29                                                            
 * Section: 2                                                                  
 * E-mail:  npatel10@umbc.edu                                                  
 *                                                                            
 * Linked List class. an object that is a list that is made by 
 * object pointing to another same type of object. the type would be         
 * vehicles for this. the linked list is used to dispplay results 
 *                                                                            
 *************************************************************/

#include "Vehicle.h"
#ifndef LINKED_LIST_H
#define LINKED_LIST_H


class Node{
  Vehicle m_data;
  Node* next;
};

// List is a linked list of ints
class Linked_List
{
 public:
  // Creates a default empty list
  Linked_List();

  // Insert "data" into the list
  void insert(Vehicle data);

  // Returns the size of the list
  unsigned int size() const;

 private:
  Node* head;
  Node* front;
  Node* rear;
  

};

#endif 

