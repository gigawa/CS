template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType & newData) {
	auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
	rootPtr = placeNode(rootPtr, newNodePtr);

	return true;
}

void BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                  std::shared_ptr<BinaryNode<ItemType>> newNode) {
	if(subTreePtr == NULL) {
		return newNodePtr;
	} else if(subTreePtr->getItem() > newNodePtr->getItem()) {
		tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
		subTreePtr->setLeftChildPtr(tempPtr);
	} else {
		tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
		subTreePtr->setRightChildPtr(tempPtr);
	}
	return subTreePtr;
}
