/** Red-Black tree
 @file RedBlackTree.h */
 
#ifndef RED_BLACK_TREE_
#define RED_BLACK_TREE_
#include <memory>
#include "RedBlackNode.h"


template<class ItemType>
class RedBlackTree
{
private:
   	std::shared_ptr<RedBlackNode<ItemType>> rootPtr;

	/** allows recursive calculation of the height of the tree */
	int getHeightHelper(std::shared_ptr<RedBlackNode<ItemType>> subTreePtr) const;

	/** destroys the tree */
	void destroyTree(std::shared_ptr<RedBlackNode<ItemType>> subTreePtr);

	/** rotates the tree left and right to correctly position the nodes in the tree */
	auto leftRotate(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> x);
	auto rightRotate(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> y);

	/** inserts a node into the tree */
	auto treeInsert(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> z);

	/** inserts a node into the tree in the correct position*/
	auto insert(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> x);

	/** allows for recursive traversal */
	void inorder(void visit(ItemType&), std::shared_ptr<RedBlackNode<ItemType>> treePtr) const;
   
public:
	/** Tests whether this binary tree is empty.
    	@return  True if the binary tree is empty, or false if not. */
	bool isEmpty();
	
	/** Adds the given data to this binary tree.
   	@param newData  The data to add to the binary tree.
    	@post  The binary tree contains the new data.*/
	void add(const ItemType & item);

	/** Gets the height of this binary tree.
    	@return  The height of the binary tree. */
	int getHeight() const;

	/** Traverses this binary tree in inorder and
       	calls the function visit once for each node.
    	@param visit  A client-defined function that performs an operation on
       	either each visited node or its data. */
	void inorderTraverse(void visit(ItemType&)) const;

	 /** Removes all data from this binary tree. */
	void clear();
};

#include "RedBlackTree.cpp"
#endif
