#include "ItemNode.h"

// Constructor
ItemNode::ItemNode() {
    item = "";
    nextNodeRef = NULL;
}

// Constructor                                                                                     
ItemNode::ItemNode(string itemInit) {
    item = itemInit;
    nextNodeRef = NULL;
}

// Constructor        
ItemNode::ItemNode(string itemInit, ItemNode *nextLoc) {
    item = itemInit;
    nextNodeRef = nextLoc;
}

// Insert node after this node.     
void ItemNode::InsertAfter(ItemNode &nodeLoc) {
    ItemNode* tmpNext;
    
    tmpNext = nextNodeRef;
    nextNodeRef = &nodeLoc;
    nodeLoc.nextNodeRef = tmpNext;
}

// TODO: Define the InsertAtEnd() member function that inserts a parameter ItemNode
//       to the end of the linked list
void ItemNode::InsertAtEnd(ItemNode* nodeLoc) {
    
    nextNodeRef = nodeLoc;
    nodeLoc->nextNodeRef = nullptr;
}

// Get location pointed by nextNodeRef                                                             
ItemNode* ItemNode::GetNext() {
    return nextNodeRef;
}

// Print data of this node
void ItemNode::PrintNodeData() {
    cout << item << endl;
}

// Get data of this node
string ItemNode::GetNodeItem() {
    return item;
}