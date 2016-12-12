template<class ItemType>
auto RedBlackTree<ItemType>::leftRotate(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> x) {
	std::cout << "Rotate Left" << endl;	
	auto y = x->getRightChildPtr();
	x->getRightChildPtr() = y->getLeftChildPtr();
	if(y->getLeftChildPtr() != nullptr) {
		y->getLeftChildPtr()->setParentPtr(x);
	}
	y->setParentPtr(x->getParentPtr());
	if(x->getParentPtr() == nullptr) {
		root = y;
	}else if(x == x->getParentPtr()->getLeftChildPtr()) {
		x->getParentPtr()->setLeftChildPtr(y);
	}else {
		x->getParentPtr()->setRightChildPtr(y);
	}
	y->setLeftChildPtr(x);
	x->setParentPtr(y);

	return root;
}

template<class ItemType>
auto RedBlackTree<ItemType>::rightRotate(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> y) {
	std::cout << "Rotate Right" << endl;
	auto x = y->getLeftChildPtr();
	y->getLeftChildPtr() = x->getRightChildPtr();
	if(x->getRightChildPtr() != nullptr) {
		x->getRightChildPtr()->setParentPtr(y);
	}
	x->setParentPtr(y->getParentPtr());
	if(y->getParentPtr() == nullptr) {
		root = x;
	}else if(y == y->getParentPtr()->getRightChildPtr()) {
		y->getParentPtr()->setRightChildPtr(x);
	}else {
		y->getParentPtr()->setLeftChildPtr(x);
	}
	x->setRightChildPtr(y);
	y->setParentPtr(x);

	return root;
}

template<class ItemType>
bool RedBlackTree<ItemType>::isEmpty() {
	if(rootPtr == nullptr) {
		return true;
	} else {
		return false;
	}
}

template<class ItemType>
auto RedBlackTree<ItemType>::insert(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> x) {
	root = treeInsert(root, x);
	std::cout << "Start Insert" << endl;
	std::cout << x->getItem() << endl;
	x->setColor(RED);
	while(x != nullptr && x->getParentPtr() != nullptr && x->getParentPtr()->getColor() == RED) {
		std::cout << "In While" << endl;
		if(x->getParentPtr()->getParentPtr()->getLeftChildPtr() == x->getParentPtr()->getParentPtr()) {
			std::cout << "IF" << endl;
			auto y = x->getParentPtr()->getParentPtr()->getRightChildPtr();
			if(y->getColor() == RED) {
				std::cout << "Case 1" << endl;
				y->setColor(BLACK);
				x->getParentPtr()->setColor(BLACK);
				x->getParentPtr()->getParentPtr()->setColor(BLACK);
				x = x->getParentPtr()->getParentPtr();
			} else {
				std::cout << "Case 2" << endl;
				if(x->getParentPtr()->getRightChildPtr() == x) {
					x = x->getParentPtr();
					root = leftRotate(root, x);
				}
				x->getParentPtr()->setColor(BLACK);
				x->getParentPtr()->getParentPtr()->setColor(RED);
				rightRotate(root, x->getParentPtr()->getParentPtr());
			}
		} else {
			std::cout << "ELSE" << endl;
			auto y = x->getParentPtr()->getParentPtr()->getLeftChildPtr();
			std::cout << "got parent" << endl;
			std::cout << y->getColor() << endl;
			if(y->getColor() == RED) {
				std::cout << "Case 3" << endl;
				y->setColor(BLACK);
				x->getParentPtr()->setColor(BLACK);
				x->getParentPtr()->getParentPtr()->setColor(BLACK);
				x = x->getParentPtr()->getParentPtr();
			} else {
				std::cout << "Case 4" << endl;
				if(x->getParentPtr()->getLeftChildPtr() == x) {
					x = x->getParentPtr();
					root = rightRotate(root, x);
				}
				x->getParentPtr()->setColor(BLACK);
				x->getParentPtr()->getParentPtr()->setColor(RED);
				leftRotate(root, x->getParentPtr()->getParentPtr());
			}
		}
	}
	std::cout << "end While" << endl;
	root->setColor(BLACK);
	return root;
}

template<class ItemType>
auto RedBlackTree<ItemType>::treeInsert(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> z) {
	auto y = root;
	auto x = root;

	while(x != nullptr) {
		y = x;
		if(z->getItem() < x->getItem()) {
			x = x->getLeftChildPtr();
		} else {
			x = x->getRightChildPtr();
		}
	}
	z->setParentPtr(y);
	if(y == nullptr) {
		root = z;
	}else if(z->getItem() < y->getItem()){
		y->setLeftChildPtr(z);
	} else {
		y->setRightChildPtr(z);
	}
	return root;
}

template<class ItemType>
void RedBlackTree<ItemType>::add(const ItemType & item) {
	auto newNode = std::make_shared<RedBlackNode<ItemType>>(item);
	rootPtr = insert(rootPtr, newNode);
}

template<class ItemType>
int RedBlackTree<ItemType>::
    getHeightHelper(std::shared_ptr<RedBlackNode<ItemType>> subTreePtr) const
{
   if (subTreePtr == nullptr)
      return 0;
   else
      return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                     getHeightHelper(subTreePtr->getRightChildPtr()));
}  // end getHeightHelper

template<class ItemType>
void RedBlackTree<ItemType>::
     destroyTree(std::shared_ptr<RedBlackNode<ItemType>> subTreePtr)
{
   if (subTreePtr != nullptr)
   {
      destroyTree(subTreePtr->getLeftChildPtr());
      destroyTree(subTreePtr->getRightChildPtr());
      subTreePtr.reset(); // Decrement reference count to node
   }  // end if
}  // end destroyTree

template<class ItemType>
void RedBlackTree<ItemType>::
     inorder(void visit(ItemType&),
             std::shared_ptr<RedBlackNode<ItemType>> treePtr) const
{
   if (!isEmpty())
   {
      inorder(visit, treePtr->getLeftChildPtr());
      ItemType theItem = treePtr->getItem();
      visit(theItem);
      inorder(visit, treePtr->getRightChildPtr());
   }  // end if
}  // end inorder

template<class ItemType>
int RedBlackTree<ItemType>::getHeight() const {
	return getHeightHelper(rootPtr);
}

template<class ItemType>
void RedBlackTree<ItemType>::clear() {
	destroyTree(rootPtr);
	rootPtr.reset();
}

template<class ItemType>
void RedBlackTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
	inorder(visit, rootPtr);
}
