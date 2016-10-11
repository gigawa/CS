#include <iostream>
#include "node.h"

using namespace std;

template<class ItemType>
class Stack{
        public:
                Stack(int = 0);
                Stack(const Stack<ItemType>&);
                ~Stack();
                Stack& operator=(const Stack<ItemType>&);
                bool push(ItemType);
                bool pop(ItemType&);
                bool empty() const;
                bool full() const;
                bool clear();
		bool operator==(const Stack<ItemType>&) const;
                friend ostream& operator<<(ostream&, const Stack<ItemType>&);
        private:
		Node * top;
};
