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
		return nullptr;
	}else if (treePtr->getItem() == target) {
		return treePtr;
	} else if (subTreePtr->getItem() > target) {
		return findNode(treePtr->getLeftChildPtr(), target);
	}else {
		return findNode(treePtr->getRightChildPtr(), target);
	}
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException) {
	if(findNode(rootPtr, anEntry) == nullptr) {
		std::string message = "Item Not Found";
      		throw(NotFoundException(message));
	}else {
		  return findNode(rootPtr, anEntry)->getItem();
	}
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                    const ItemType target,
                    bool& isSuccessful) override {
	if(subTreePtr == nullptr) {
		isSuccessful = false;
	} else if(subTreePtr->getItem() == target) {
		subTreePtr = removeNode(subTreePtr)
		isSuccessful = true;
	}else if(subTreePtr->getItem > target) {
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
		subTreePtr->setLeftChildPtr(tempPtr);
	}else {
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
		subTreePtr->setRightChildPtr(tempPtr);
	}
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr) {
	if(nodePtr->isLeaf()) {
		return nodePtr;
	}else if(nodePtr->getLeftChildPtr == nullptr || nodePtr->getRightChildPtr == nullptr) {
		std::shared_ptr<BinaryNode<ItemType>> nodeToConnectPtr;
		if(nodePtr->getLeftChildPtr == nullptr) {
			nodeToConnectPtr = nodePtr->getRightChildPtr;
		}else {
			nodeToConnectPtr = nodePtr->getLeftChildPtr;
		}
		return nodeToConnectPtr;
	}else {
		ItemType newNodeValue;
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeLeftMostNode(nodePtr->getRightChildPtr(), newNodeValue)
		nodePtr->setRightChildPtr(tempPtr);
		nodePtr->setItem(newNodeValue);
	}
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>>subTreePtr,
                           ItemType& inorderSuccessor) {
	if(nodePtr->getLeftChildPtr() == nullptr) {
		inorderSuccessor = nodePtr->getItem();
		return removeNode(nodePtr);
	}else {
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeLeftMostNode(nodePtr->getLeftChildPtr(), inorderSuccessor);
		nodePtr->setLeftChildPtr(tempPtr);
		return nodePtr;
	}
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target) {
	bool isSuccessful = false;
	rootPtr = removeValue(rootPtr, target, isSuccessful);
	return isSuccessful;
}
