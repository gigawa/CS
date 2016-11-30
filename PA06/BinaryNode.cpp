#include "BinaryNode.h"

using namespace std;

template<class ItemType>
BinaryNode<ItemType>::BinaryNode() {
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem) {
	leftChildPtr = NULL;
	rightChildPtr = NULL;
	item = anItem;
}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
              std::shared_ptr<BinaryNode<ItemType>> leftPtr,
              std::shared_ptr<BinaryNode<ItemType>> rightPtr) {
	rightChildPtr = rightPtr;
	leftChildPtr = leftPtr;
	item = anItem;
}

template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType & anItem) {
	item = anItem;
}

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
	return item;
}

template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const {
	if(leftChildPtr == nullptr && rightChildPtr == nullptr) {
		return true;
	}else {
		return false;
	}
}

template<class ItemType>
auto BinaryNode<ItemType>::getLeftChildPtr() const {
	return leftChildPtr;
}

template<class ItemType>
auto BinaryNode<ItemType>::getRightChildPtr() const {
	return rightChildPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr) {
	leftChildPtr = leftPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr) {
	rightChildPtr = rightPtr;
}
