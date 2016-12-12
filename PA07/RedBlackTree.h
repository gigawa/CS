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

	int getHeightHelper(std::shared_ptr<RedBlackNode<ItemType>> subTreePtr) const;
	void destroyTree(std::shared_ptr<RedBlackNode<ItemType>> subTreePtr);

	void leftRotate(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> x);
	void rightRotate(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> y);
	void treeInsert(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> z);
	void insert(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> x);

	void inorder(void visit(ItemType&), std::shared_ptr<RedBlackNode<ItemType>> treePtr) const;
   
public:
	void add(ItemType & item);
	int getHeight() const;
	void inorderTraverse(void visit(ItemType&)) const;
	void clear();
};

#include "RedBlackTree.cpp"
#endif
