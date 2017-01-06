
#include "List.h"
#include <iostream>

using namespace std;

Node::Node(int data)
   : m_data(data)
{
   next = NULL;
}

List::List()
   : m_head(new Node(0))
{ /* No code */ }

List::List(const List &rhs)
   : m_head(new Node(0))
{
   // Assign RHS into this List
   (*this) = rhs;
}

List::~List()
{
   clear();

   delete m_head;
}

const List& List::operator=(const List &rhs)
{
   // check for self-assignment
   if(this == &rhs) return *this;

   // we are going to be overwriting, so delete our old stuff
   clear();
 
   Node* rhs_current = rhs.m_head;
   Node* current = m_head;

   while(rhs_current->next != NULL) {
      current->next = new Node(rhs_current->next->m_data);

      current = current->next;
      rhs_current = rhs_current->next;
   }

   return *this;
}

void List::insert(int data)
{
   Node* current = m_head;
   
   // traverse linked list
   while(current->next != NULL) {
      if(current->next->m_data > data) {
         // found place to insert
         // insert a new node inbetween current and
         // the current current->next
         // now:   [CURRENT] -> [CURRENT NEXT]
         // after: [CURRENT] -> [NEW NODE] -> [OLD CURRENT NEXT]
         // PUT CODE HERE:
	Node* newCurrent = new Node(data);
	Node* temp = current->next;
	current->next = newCurrent;
	newCurrent->next = temp;

         // exit the function
         return;
      }

      current = current->next;
   }

   // insert at the end of the list
   // this will only get here if the node is the last one to insert
   current->next = new Node(data);
}


bool List::remove(int data)
{
   Node* current = m_head;

   // traverse the linked list and find the element
   while(current->next != NULL) {
      if(current->next->m_data == data) {
         // found place to delete

         // delete current's next and reassign current's next
         // now:   [CURRENT] -> [CURRENT NEXT] -> [CURRENT NEXT NEXT]
         // after: [CURRENT] -> [OLD CURRENT NEXT NEXT]
         // PUT CODE HERE:
  
       	Node* temp = current->next;
	current->next = current->next->next;
	delete temp;
	temp = NULL;
	

         // exit the function
         return true;
      }

      current = current->next;
   }

   return false;
}

void List::Print() const
{
   Node* current = m_head;

   while(current->next != NULL) {
      cout << current->next->m_data << ' ';
      current = current->next;
   }
}

void List::clear()
{
   // it's empty already!
   if(m_head->next == NULL) return;

   Node* previous = m_head->next;
   Node* current = m_head->next->next;

   m_head->next = NULL;

   while(current != NULL) {
      delete previous;

      previous = current;
      current = current->next;
   }
}

unsigned int List::size() const
{
   // traverse linked list with a while loop and count the number of
   // elements.
   // PUT CODE HERE:
  Node* current = m_head->next;
   int count=0;
   while(current->next != NULL) {
     count++;
     current = current->next;
   }
   

   // REPLACE ZERO WITH CORRECT NUMBER:
   return count;
}


