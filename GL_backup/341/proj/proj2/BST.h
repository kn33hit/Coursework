#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <fstream>
#include "dsexceptions.h"
#include "Word.h"
#include <iostream>    // For NULL
using namespace std;

// BinarySearchTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted


// NEWLY ADDED
// an overloaded insert 
// a find function
// an outfile function
template <typename Comparable>
class BinarySearchTree
{
 public:
 BinarySearchTree( ) :root( NULL )
    {
    }

 BinarySearchTree( const BinarySearchTree & rhs ) : root( NULL )
    {
      *this = rhs;
    }

  /**
   * Destructor for the tree
   */
  ~BinarySearchTree( )
    {
      makeEmpty( );
    }

  /**
   * Find the smallest item in the tree.
   * Throw UnderflowException if empty.
   */
  const Comparable & findMin( ) const
  {
    if( isEmpty( ) )
      throw UnderflowException( );
    return findMin( root )->element;
  }

  /**
   * Find the largest item in the tree.
   * Throw UnderflowException if empty.
   */
  const Comparable & findMax( ) const
  {
    if( isEmpty( ) )
      throw UnderflowException( );
    return findMax( root )->element;
  }

  /**
   * Returns true if x is found in the tree.
   */
  bool contains( const Comparable & x ) const
  {
    return contains( x, root );
  }

  /**
   * Test if the tree is logically empty.
   * Return true if empty, false otherwise.
   */
  bool isEmpty( ) const
  {
    return root == NULL;
  }

  /**
   * Print the tree contents in sorted order.
   */
  void printTree( ostream & out = cout ) const
  {
    if( isEmpty( ) )
      out << "Empty tree" << endl;
    else
      printTree( root, out );
  }

  /**
   * Make the tree logically empty.
   */
  void makeEmpty( )
  {
    makeEmpty( root );
  }

  /**
   * Insert x into the tree; duplicates are ignored.
   */
  void insert( const Comparable & x ,int lineNum)
  {
    //added lineNum to it so when duplication occurs it
    //chenages the count
    insert( x,lineNum, root );
  }

  void insert( const Comparable & x )
  {                                                       
    insert( x, root );
  }

  /**
   * Remove x from the tree. Nothing is done if x is not found.
   */
  void remove( const Comparable & x )
  {
    remove( x, root );
  }

  /**
   * Deep copy.
   */
  const BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
      if( this != &rhs )
        {
	  makeEmpty( );
	  root = clone( rhs.root );
        }
      return *this;
    }
  //--------------------------------------------------------------------
  

 /*-----------------------------------------------------------------

  OUTFILE(bootstrap)
     this is to write in a file instead of outputting everything

 -------------------------------------------------------------------*/

  void outFile(string filename){
    ofstream outfile;
    outfile.open(filename.c_str());
    outFile(outfile,root);
    outfile.close();
  }

/*-----------------------------------------------------------------
      
  FIND(bootstrap)
    to find a given data and return that data 

-------------------------------------------------------------------*/
  Comparable* find( const Comparable& x)
  {
    if( isEmpty( ) ){
      // if empty throw an error
      throw UnderflowException( );
    }
    else{
	return find( x,root )->element;    }
  }

  
 private:
    struct BinaryNode
    {
      Comparable element;
      BinaryNode *left;
      BinaryNode *right;

      BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode 
		  *rt )
      : element( theElement ), left( lt ), right( rt ) { }
    };
 
    BinaryNode *root;


    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, BinaryNode * & t )
    {
      if( t == NULL )
	t = new BinaryNode( x, NULL, NULL );
      else if( x < t->element )
	insert( x, t->left );
      else if( t->element < x )
	insert( x, t->right );
      else
	;  // Duplicate; do nothing
    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( const Comparable & x, BinaryNode * & t )
    {
      if( t == NULL )
	return;   // Item not found; do nothing
      if( x < t->element )
	remove( x, t->left );
      else if( t->element < x )
	remove( x, t->right );
      else if( t->left != NULL && t->right != NULL ) // Two children
        {
	  t->element = findMin( t->right )->element;
	  remove( t->element, t->right );
        }
      else
        {
	  BinaryNode *oldNode = t;
	  t = ( t->left != NULL ) ? t->left : t->right;
	  delete oldNode;
        }
    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode * findMin( BinaryNode *t ) const
    {
      if( t == NULL )
	return NULL;
      if( t->left == NULL )
	return t;
      return findMin( t->left );
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item
	}*/
    BinaryNode * findMax( BinaryNode *t ) const
    {
      if( t != NULL ){
	while( t->right != NULL ){
	  t = t->right;
	}
      }
      return t;
    }


    /**
    * Internal method to test if an item is in a subtree.
    * x********/
     bool contains( const Comparable & x ,BinaryNode *t) const
     {
       if(t==NULL){
	 return false;
       }else if(x < t->element){
	 return contains(x, t->left);
       }else if(t->element < x){
	 return contains(x, t->right);
       }else{
	 return true;
       }
     }

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( BinaryNode * & t )
    {
      if( t != NULL )
        {
	  makeEmpty( t->left );
	  makeEmpty( t->right );
	  delete t;
        }
      t = NULL;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( BinaryNode *t, ostream & out ) const
    {
      if( t != NULL )
        {
	  printTree( t->left, out );
	  out << t->element << endl;
	  printTree( t->right, out );
        }
    }

    /**
     * Internal method to clone subtree.
     */
    BinaryNode * clone( BinaryNode *t ) const
    {
      if( t == NULL )
	return NULL;
      else
	return new BinaryNode( t->element, clone( t->left ), clone(t->right));
    }
    

    //----------------------------------------------------------------------
    //----------------------------------------------------------------------

    /** 
     *	internal method to find a node in the subtree rooted at t
    */
    BinaryNode* find( const Comparable& x, BinaryNode *t ) 
    {
      // basically the same as contains but it returns a pointer 
      // top the node it is trying to find 
      if(t!=NULL){
	if(x < t->element){
	  return find(x ,t->left);
	}else if(t->element < x){
	  return find(x, t->right);
	}else{
	  // here we have where it is neither greater or less, so equal 
	  // t here is basically what we want 
	  return t;
	}
      }
    }

    /**
     *  internal method to write to a file
     */

    void outFile(ofstream& writeFile, BinaryNode *t){
      // check for empty tree or node with no children 
      if( t != NULL )
	{
	  // do left   (L)
	  outFile( writeFile,t->left);
	  // write     (P)
	  writeFile << t->element << endl;
	  // do right  (R)
	  outFile( writeFile, t->right );
	}
    }


    /*-------------------------------------------------------------------
     OVERLOADED INSERT 
       it needs an extra argument than regular insert 
       lineNum is passed in so when the two datas are similar
       it calls the CountWord() and adds the line number to the queue
       
    /-----------------------------------------------------------------*/

    void insert( const Comparable & x,int lineNum, BinaryNode * & t )
    {
      if( t == NULL )
        t = new BinaryNode( x, NULL, NULL );
      else if( x < t->element )
        insert( x,lineNum, t->left );
      else if( t->element < x )
        insert( x,lineNum, t->right );
      else
        t->element.CountWord(lineNum);  // increment by one                
      
    }

    //--------------------------------------------------------------------
    //--------------------------------------------------------------------
};


#endif
