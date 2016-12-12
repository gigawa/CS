//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Listing 19-1.

/** A class of nodes for a Red-Black tree.
 @file RedBlackNode.h */
 
#ifndef RED_BLACK_NODE_
#define RED_BLACK_NODE_
#include <memory>

enum Color {RED, BLACK};

template<class ItemType>
class RedBlackNode
{
private:
	ItemType                              item;          // Data portion
	td::shared_ptr<RedBlackNode<ItemType>> parentPtr;  // Pointer to parent
   	std::shared_ptr<RedBlackNode<ItemType>> leftChildPtr;  // Pointer to left child
   	std::shared_ptr<RedBlackNode<ItemType>> rightChildPtr; // Pointer to right child
	Color color;
   
public:
	RedBlackNode();
	RedBlackNode(ItemType & anItem);

	void setItem(const ItemType& anItem);
   	ItemType getItem() const;
   
  	bool isLeaf() const;
   
	auto getParentPtr() const;
   	auto getLeftChildPtr() const;
   	auto getRightChildPtr() const;
   
	void setParentPtr(std::shared_ptr<RedBlackNode<ItemType>> parent);
   	void setLeftChildPtr(std::shared_ptr<RedBlackNode<ItemType>> leftPtr);
   	void setRightChildPtr(std::shared_ptr<RedBlackNode<ItemType>> rightPtr);

	void setColor(const Color & color);
	void setLeftColor(const Color & color);
	void setRightColor(const Color & color);
	
	Color getColor() const;
	Color getLeftColor() const;
	Color getRightColor() const;

}; // end RedBlackNode
#include "RedBlackNode.cpp"
#endif
