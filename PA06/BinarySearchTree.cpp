template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr) {

}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType & newData) {
	auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
	rootPtr = placeNode(rootPtr, newNodePtr);

	return true;
}

template<class ItemType>
void BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                  std::shared_ptr<BinaryNode<ItemType>> newNode) {
	if(subTreePtr == nullptr) {
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

auto BinarySearchTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                 const ItemType& target) const {
	if(treePtr == nullptr) {
		return nullptr;
	}else if (treePtr->getItem() == target) {
		return treePtr;
	} else if (subTreePtr->getItem() > target) {
		return findNode(treePtr->getLeftChildPtr(), target);
	}else {
		return findNode(treePtr->getRightChildPtr(), target);
	}
}

ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException) {
	if(findNode(rootPtr, anEntry) == nullptr) {
		std::string message = "Item Not Found";
      		throw(NotFoundException(message));
	}else {
		  return findNode(rootPtr, anEntry)->getItem();
	}
}


