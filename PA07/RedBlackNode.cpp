#include "RedBlackNode.h"

using namespace std;

template<class ItemType>
RedBlackNode<ItemType>::RedBlackNode() {
	parentPtr = nullptr;
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;
	color = BLACK;
}

template<class ItemType>
RedBlackNode<ItemType>::RedBlackNode(const ItemType& anItem) {
	item = anItem;
	parentPtr = nullptr;
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;
	color = BLACK;
}

template<class ItemType>
void RedBlackNode<ItemType>::setColor(const Color & theColor) {
	color = theColor;
}

template<class ItemType>
void RedBlackNode<ItemType>::setLeftColor(const Color & theColor) {
	getLeftChildPtr->color = theColor;
}

template<class ItemType>
void RedBlackNode<ItemType>::setRightColor(const Color & theColor) {
	getRightChildPtr->color = theColor;
}

template<class ItemType>
Color RedBlackNode<ItemType>::getColor() const {
	return color;
}
	
template<class ItemType>
Color RedBlackNode<ItemType>::getLeftColor() const {
	return getLeftChildPtr->color;
}

template<class ItemType>
Color RedBlackNode<ItemType>::getRightColor() const {
	return getRightChildPtr->color;
}

template<class ItemType>
void RedBlackNode<ItemType>::setItem(const ItemType & anItem) {
	item = anItem;
}

template<class ItemType>
ItemType RedBlackNode<ItemType>::getItem() const {
	return item;
}

template<class ItemType>
bool RedBlackNode<ItemType>::isLeaf() const {
	if(leftChildPtr == nullptr && rightChildPtr == nullptr) {
		return true;
	}else {
		return false;
	}
}

template<class ItemType>
auto RedBlackNode<ItemType>::getParentPtr() const {
	return parentPtr;
}

template<class ItemType>
auto RedBlackNode<ItemType>::getLeftChildPtr() const {
	return leftChildPtr;
}

template<class ItemType>
auto RedBlackNode<ItemType>::getRightChildPtr() const {
	return rightChildPtr;
}

template<class ItemType>
void RedBlackNode<ItemType>::setParentPtr(std::shared_ptr<RedBlackNode<ItemType>> parent) {
	parentPtr = parent;
}

template<class ItemType>
void RedBlackNode<ItemType>::setLeftChildPtr(std::shared_ptr<RedBlackNode<ItemType>> leftPtr) {
	leftChildPtr = leftPtr;
}

template<class ItemType>
void RedBlackNode<ItemType>::setRightChildPtr(std::shared_ptr<RedBlackNode<ItemType>> rightPtr) {
	rightChildPtr = rightPtr;
}
