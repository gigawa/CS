template<class ItemType>
auto RedBlackTree<ItemType>::leftRotate(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> x) {

	if(x->getRightChildPtr() == nullptr) {
		return root;
	}else {
		auto y = x->getRightChildPtr();
		if(y->getLeftChildPtr() != nullptr) {
			x->setRightChildPtr(y->getLeftChildPtr());
			y->getLeftChildPtr()->setParentPtr(x);
		} else {
			x->setRightChildPtr(nullptr);
		}
		if(x->getParentPtr() != nullptr) {
			y->setParentPtr(x->getParentPtr());
			if(x == x->getParentPtr()->getLeftChildPtr()) {
				x->getParentPtr()->setLeftChildPtr(y);
			}else {
				x->getParentPtr()->setRightChildPtr(y);
			}
			y->setLeftChildPtr(x);
			x->setParentPtr(y);  
		} else {
			root = y;
		}

		return root;
	}
}

template<class ItemType>
auto RedBlackTree<ItemType>::rightRotate(std::shared_ptr<RedBlackNode<ItemType>> root, std::shared_ptr<RedBlackNode<ItemType>> x) {
	
	if(x->getLeftChildPtr() == nullptr) {
		return root;
	}else {
		auto y = x->getLeftChildPtr();
		if(y->getRightChildPtr() != nullptr) {
			x->setLeftChildPtr(y->getRightChildPtr());
			y->getRightChildPtr()->setParentPtr(x);
		} else {
			x->setLeftChildPtr(nullptr);
		}
		if(x->getParentPtr() != nullptr) {
			y->setParentPtr(x->getParentPtr());
			if(x == x->getParentPtr()->getLeftChildPtr()) {
				x->getParentPtr()->setLeftChildPtr(y);
			}else {
				x->getParentPtr()->setRightChildPtr(y);
			}
			y->setRightChildPtr(x);
			x->setParentPtr(y);  
		} else {
			root = y;
		}

		return root;
	}
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
	x->setColor(RED);
	while(x != root && x->getParentPtr()->getColor() == RED && x->getParentPtr() != root) {
		if(x->getParentPtr()->getParentPtr()->getLeftChildPtr() == x->getParentPtr()) {
			auto y = x->getParentPtr()->getParentPtr()->getRightChildPtr();
			if(y == nullptr || y->getColor() == RED) {
				if(y != nullptr) {
					y->setColor(BLACK);
				}
				x->getParentPtr()->setColor(BLACK);
				x->getParentPtr()->getParentPtr()->setColor(BLACK);
				x = x->getParentPtr()->getParentPtr();
			} else if(y->getColor() == BLACK){
				if(x->getParentPtr()->getRightChildPtr() == x) {
					x = x->getParentPtr();
					root = leftRotate(root, x);
				}
				x->getParentPtr()->setColor(BLACK);
				x->getParentPtr()->getParentPtr()->setColor(RED);
				root = rightRotate(root, x->getParentPtr()->getParentPtr());
			}
		} else {
			auto y = x->getParentPtr()->getParentPtr()->getLeftChildPtr();
			if(y == nullptr || y->getColor() == RED) {
				if(y != nullptr) {
					y->setColor(BLACK);
				}
				x->getParentPtr()->setColor(BLACK);
				x->getParentPtr()->getParentPtr()->setColor(BLACK);
				x = x->getParentPtr()->getParentPtr();
			} else if(y->getColor() == BLACK){
				if(x->getParentPtr()->getLeftChildPtr() == x) {
					x = x->getParentPtr();
					root = rightRotate(root, x);
				}
				x->getParentPtr()->setColor(BLACK);
				x->getParentPtr()->getParentPtr()->setColor(RED);
				root = leftRotate(root, x->getParentPtr()->getParentPtr());
			}
		}
	}
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
   if (treePtr != nullptr)
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
