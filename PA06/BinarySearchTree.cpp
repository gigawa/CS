#include "NotFoundException.h"

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr) {

}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree(){

}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType & newData) {
	auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
	rootPtr = placeNode(rootPtr, newNodePtr);

	return true;
}

template<class ItemType>
auto BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr) {
	if(subTreePtr == nullptr) {
		return newNodePtr;
	} else if(subTreePtr->getItem() > newNodePtr->getItem()) {
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
		subTreePtr->setLeftChildPtr(tempPtr);
	} else {
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
		subTreePtr->setRightChildPtr(tempPtr);
	}
	return subTreePtr;
}

template<class ItemType>
auto BinarySearchTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                 const ItemType& target) const {
	if(treePtr == nullptr) {
		return treePtr;
	}else if (treePtr->getItem() == target) {
		return treePtr;
	} else if (treePtr->getItem() > target) {
		return findNode(treePtr->getLeftChildPtr(), target);
	}else {
		return findNode(treePtr->getRightChildPtr(), target);
	}
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException) {
	if(findNode(rootPtr, anEntry) == nullptr) {
		std::string message = "Item Not Found or ";
		message = message + "does not exist";
      		throw(NotFoundException(message));
	}else {
		  return findNode(rootPtr, anEntry)->getItem();
	}
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                    const ItemType target,
                    bool& isSuccessful) {
	if(subTreePtr == nullptr) {
		isSuccessful = false;
		return subTreePtr;
	} else if(subTreePtr->getItem() == target) {
		subTreePtr = removeNode(subTreePtr);
		isSuccessful = true;
	}else if(subTreePtr->getItem() > target) {
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
		subTreePtr->setLeftChildPtr(tempPtr);
	}else {
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
		subTreePtr->setRightChildPtr(tempPtr);
	}

	return subTreePtr;
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr) {
	if(nodePtr->isLeaf()) {
		nodePtr.reset();
		return nodePtr;
	}else if(nodePtr->getLeftChildPtr() == nullptr || nodePtr->getRightChildPtr() == nullptr) {
		std::shared_ptr<BinaryNode<ItemType>> nodeToConnectPtr;
		if(nodePtr->getLeftChildPtr() == nullptr) {
			nodeToConnectPtr = nodePtr->getRightChildPtr();
		}else {
			nodeToConnectPtr = nodePtr->getLeftChildPtr();
		}
		nodePtr.reset();
		return nodeToConnectPtr;
	}else {
		ItemType newNodeValue;
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
		nodePtr->setRightChildPtr(tempPtr);
		nodePtr->setItem(newNodeValue);
		return nodePtr;
	}
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                           ItemType& inorderSuccessor) {
	if(subTreePtr->getLeftChildPtr() == nullptr) {
		inorderSuccessor = subTreePtr->getItem();
		return removeNode(subTreePtr);
	}else {
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor);
		subTreePtr->setLeftChildPtr(tempPtr);
		return subTreePtr;
	}
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target) {
	bool isSuccessful = false;
	rootPtr = removeValue(rootPtr, target, isSuccessful);
	return isSuccessful;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {
	if(rootPtr == nullptr) {
		return true;
	}else {
		return false;
	}
}

template<class ItemType>
void BinarySearchTree<ItemType>::
     inorder(void visit(ItemType&),
             std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
   if (treePtr != nullptr)
   {
      inorder(visit, treePtr->getLeftChildPtr());
      ItemType theItem = treePtr->getItem();
      visit(theItem);
      inorder(visit, treePtr->getRightChildPtr());
   }  // end if
}  // end inorder

template<class ItemType>
void BinarySearchTree<ItemType>::
     preorder(void visit(ItemType&),
             std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
   if (treePtr != nullptr)
   {
      ItemType theItem = treePtr->getItem();
      visit(theItem);
      inorder(visit, treePtr->getLeftChildPtr());
      inorder(visit, treePtr->getRightChildPtr());
   }  // end if
}  // end preorder

template<class ItemType>
void BinarySearchTree<ItemType>::
     postorder(void visit(ItemType&),
             std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
   if (treePtr != nullptr)
   {
      inorder(visit, treePtr->getLeftChildPtr());
      inorder(visit, treePtr->getRightChildPtr());
      ItemType theItem = treePtr->getItem();
      visit(theItem);
   }  // end if
}  // end preorder

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
	inorder(visit, rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const {
	preorder(visit, rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const {
	postorder(visit, rootPtr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
	return getHeightHelper(rootPtr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
	return getNumberOfNodesHelper(rootPtr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::
    getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
   if (subTreePtr == nullptr)
      return 0;
   else
      return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                     getHeightHelper(subTreePtr->getRightChildPtr()));
}  // end getHeightHelper

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const {
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear() {
	destroyTree(rootPtr);
	rootPtr.reset();
}

template<class ItemType>
void BinarySearchTree<ItemType>::
     destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
   if (subTreePtr != nullptr)
   {
      destroyTree(subTreePtr->getLeftChildPtr());
      destroyTree(subTreePtr->getRightChildPtr());
      subTreePtr.reset(); // Decrement reference count to node
   }  // end if
}  // end destroyTree
