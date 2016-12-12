template<class ItemType>
void RedBlackTree<ItemType>::leftRotate(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> x) {
	auto y = x->getRightPtr();
	x->getRightPtr() = y->getLeftPtr();
	if(y->getLeftPtr() != nullptr) {
		y->getLeftPtr()->setParentPtr(x);
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
}

template<class ItemType>
void RedBlackTree<ItemType>::rightRotate(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> y) {
	auto x = y->getLeftPtr();
	y->getLeftPtr() = x->getRightPtr();
	if(x->getRightPtr() != nullptr) {
		x->getRightPtr()->setParentPtr(y);
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
}

template<class ItemType>
void RedBlackTree<ItemType>::insert(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> x) {
	treeInsert(root, x);
	x->setColor(RED);
	while(x != nullptr && x->getParent()->getColor() == RED) {
		if(x->getParent()->getParent()->getLeftChild() == x->getParent()->getParent()) {
			auto y = x->getParent()->getParent()->getRightChild();
			if(y->getColor() == RED) {
				y->setColor(BLACK);
				x->getParent()->setColor(BLACK);
				x->getParent()->getParent()->setColor(BLACK);
				x = x->getParent()->getParent();
			} else {
				if(x->getParent()->getRightChild() == x) {
					x = x->getParent();
					leftRotate(root, x);
				}
				x->getParent()->setColor(BLACK);
				x->getParent()->getParent()->setColor(RED);
				rightRotate(root, x->getParent()->getParent();
			}
		} else {
			auto y = x->getParent()->getParent()->getLeftChild();
			if(y->getColor() == RED) {
				y->setColor(BLACK);
				x->getParent()->setColor(BLACK);
				x->getParent()->getParent()->setColor(BLACK);
				x = x->getParent()->getParent();
			} else {
				if(x->getParent()->getLeftChild() == x) {
					x = x->getParent();
					rightRotate(root, x);
				}
				x->getParent()->setColor(BLACK);
				x->getParent()->getParent()->setColor(RED);
				leftRotate(root, x->getParent()->getParent();
			}
		}
	}
	root->setColor(BLACK);
}

template<class ItemType>
void RedBlackTree<ItemType>::treeInsert(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> z) {
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
	z->setParent(y);
	if(y == nullptr) {
		root = z;
	}else {
		y->setLeftChildPtr(z);
	} else {
		y->setRightChildPtr(z);
	}
}

template<class ItemType>
void RedBlackTree<ItemType>::add(ItemType & item) {
	auto newNode = std::make_shared<RedBlackNode<ItemType>>(item);
	insert(rootPtr, newNode);
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
	std::cout << "Not Null" << endl;
      inorder(visit, treePtr->getLeftChildPtr());
      ItemType theItem = treePtr->getItem();
	std::cout<<theItem;
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
