//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

template<class ItemType>
SortedListIsA<ItemType>::SortedListIsA()
{
}  // end default constructor

template<class ItemType>
SortedListIsA<ItemType>::SortedListIsA(const SortedListIsA<ItemType>& sList)
	                                          : LinkedList<ItemType>(sList)
{
}  // end copy constructor

template<class ItemType>
SortedListIsA<ItemType>::~SortedListIsA()
{
}  // end destructor

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

template<class ItemType>
bool SortedListIsA<ItemType>::insertSorted(const ItemType& newEntry)
{
   int newPosition = std::abs(getPosition(newEntry));
   // We need to call the LinkedList version of insert, since the
   // SortedListIsA version does nothing but return false
   return LinkedList<ItemType>::insert(newPosition, newEntry);
}  // end insertSorted

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

template<class ItemType>
bool SortedListIsA<ItemType>::removeSorted(int position)
{
   bool ableToRemove = position > 0;
   
   if (ableToRemove)
      ableToRemove = LinkedList<ItemType>::remove(position);
   
   return ableToRemove;
}  // end removeSorted

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

template<class ItemType>
int SortedListIsA<ItemType>::getPosition(const ItemType& anEntry) const
{
   int position = 1;
   int length = LinkedList<ItemType>::getLength();
   
   while ( (position <= length) &&
           (anEntry > LinkedList<ItemType>::getEntry(position)) )
   {
      position++;
   }  // end while
   
   if ( (position > length) ||
        (anEntry != LinkedList<ItemType>::getEntry(position)) )
   {
      position = -position;
   }  // end if
   
   return position;
}  // end getPosition

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

template<class ItemType>
bool SortedListIsA<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   return false;
}  // end insert

template<class ItemType>
void SortedListIsA<ItemType>::replace(int position, const ItemType& newEntry)
        throw(PrecondViolatedExcept)
{
}
