//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Listing 15-1.

/** Interface for the ADT binary tree.
 @file BinaryTreeInterface.h */
#ifndef BINARY_TREE_INTERFACE_
#define BINARY_TREE_INTERFACE_
#include "NotFoundException.h"

template<class ItemType>
class BinaryTreeInterface
{
public:
   /** Tests whether this binary tree is empty.
    @return  True if the binary tree is empty, or false if not. */
   virtual bool isEmpty() const = 0;
   
   /** Gets the height of this binary tree.
    @return  The height of the binary tree. */
   virtual int getHeight() const = 0;
   
   /** Gets the number of nodes in this binary tree.
    @return  The number of nodes in the binary tree. */
   virtual int getNumberOfNodes() const = 0;
   
   /** Adds the given data to this binary tree.
    @param newData  The data to add to the binary tree.
    @post  The binary tree contains the new data.
    @return  True if the addition is successful, or false if not. */
   virtual bool add(const ItemType& newData) = 0;
   
   /** Removes the specified data from this binary tree.
    @param target  The data to remove from the binary tree.
    @return  True if the removal is successful, or false if not. */
   virtual bool remove(const ItemType& target) = 0;
   
   /** Removes all data from this binary tree. */
   virtual void clear() = 0;
   
   /** Retrieves the specified data from this binary tree.
    @post  The desired data has been returned, and the binary tree
       is unchanged. If no such data was found, an exception is thrown.
    @param target  The data to locate.
    @return  The data in the binary tree that matches the given data.*/
   virtual ItemType getEntry(const ItemType& target) const = 0;
   
   /** Traverses this binary tree in preorder (inorder, postorder) and
       calls the function visit once for each node.
    @param visit  A client-defined function that performs an operation on
       either each visited node or its data. */
   virtual void preorderTraverse(void visit(ItemType&)) const = 0;
   virtual void inorderTraverse(void visit(ItemType&)) const = 0;
   virtual void postorderTraverse(void visit(ItemType&)) const = 0;
   
   /** Destroys this tree and frees its assigned memory. */
   virtual ~BinaryTreeInterface() { }
}; // end BinaryTreeInterface
#endif
