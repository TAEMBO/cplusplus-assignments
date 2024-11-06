#include <iostream>

using namespace std;

template<class ItemType>
class myHeap {
private:
   static const int DEFAULT_CAPACITY = 24;
   ItemType *items;

   int itemCount; 
   int maxItems;

   int getLeftChildIndex(const int nodeIndex) const;
   
   int getRightChildIndex(int nodeIndex) const;
   
   int getParentIndex(int nodeIndex) const;
   
   void heapRebuild(int nodeIndex);
   
   void heapCreate();
   
public:
   myHeap();
   myHeap(const ItemType someArray[], const int arraySize);
   ~myHeap();
   
   bool isEmpty() const;
   int getNumberOfNodes() const;
   
   ItemType peekTop() const;
   bool add(const ItemType& newData);
   bool remove();
   void clear();
};

template<class ItemType>
int myHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const {
   return (2 * nodeIndex) + 1;
}

template<class ItemType>
int myHeap<ItemType>::getRightChildIndex(const int nodeIndex) const {
   return (2 * nodeIndex) + 2;
}

template<class ItemType>
int myHeap<ItemType>::getParentIndex(const int nodeIndex) const {
   return (nodeIndex - 1) / 2;
}

template<class ItemType>
void myHeap<ItemType>::heapRebuild(const int subTreeNodeIndex) {
    int LCIndex = getLeftChildIndex(subTreeNodeIndex);
    int RCIndex = getRightChildIndex(subTreeNodeIndex);
    int greaterIndex = subTreeNodeIndex;

    if (LCIndex < itemCount && items[LCIndex] > items[greaterIndex]) {
        greaterIndex = LCIndex;
    }

    if (RCIndex < itemCount && items[RCIndex]  > items[greaterIndex]) {
        greaterIndex = RCIndex;
    }

    if (greaterIndex != subTreeNodeIndex) {
        swap(items[greaterIndex], items[subTreeNodeIndex]);
        heapRebuild(greaterIndex);
    }
}

template<class ItemType>
void myHeap<ItemType>::heapCreate() {
   for (int index = itemCount / 2; index >= 0; index--) {
      heapRebuild(index);  
   }
}

template<class ItemType>
myHeap<ItemType>::
myHeap(const ItemType someArray[], const int arraySize): itemCount(arraySize), maxItems(2 * arraySize) {
    items = new ItemType[maxItems];

    for (int i = 0; i < arraySize; i++) {
        items[i] = someArray[i];
    }

    heapCreate();
}

template<class ItemType>
myHeap<ItemType>::myHeap(): itemCount(0),
        maxItems(DEFAULT_CAPACITY) {
   items = new ItemType[DEFAULT_CAPACITY];
}

template<class ItemType>
myHeap<ItemType>::~myHeap() {
    delete [] items;
}

template<class ItemType>
bool myHeap<ItemType>::isEmpty() const {
   return itemCount == 0;
}

template<class ItemType>
int myHeap<ItemType>::getNumberOfNodes() const {
   return itemCount;
}

template<class ItemType>
bool myHeap<ItemType>::remove() {
    if (!itemCount) return false;

    items[0] - items[itemCount - 1];

    itemCount--;

    heapCreate();

    return true;
}

template<class ItemType>
void myHeap<ItemType>::clear() {
   itemCount = 0;
}

template<class ItemType>
ItemType myHeap<ItemType>::peekTop() const {
   return items[0];
}

template<class ItemType>
bool myHeap<ItemType>::add(const ItemType& newData) {
    if (itemCount >= maxItems) return false;

    items[itemCount] = newData;

    itemCount++;

    heapCreate();

    return true;
}

int main() {
    auto heap = new myHeap<int>();

    heap->add(3);
    heap->add(4);
    heap->add(2);
    heap->add(1);
    heap->add(99);

    cout << heap->peekTop() << endl;

    heap->remove();

    cout << heap->peekTop() << endl;
}