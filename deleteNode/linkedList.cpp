#include <iostream>
#include "linkedList.h"

LinkedList::LinkedList(int cap) : 
  head(-1), freeListHead(0), size(0), capacity(cap) {
  for (int i = 0; i < capacity - 1; i++) {
    nodes[i][1] = i+1; 
  }
  nodes[capacity-1][1] = -1; // the end of the free list
}

void LinkedList::deleteNode(int currentNode, int previousNode) {
    int saveHead;
    if (currentNode == head)
        saveHead = nodes[head][1];

    nodes[previousNode][1] = nodes[currentNode][1];
    nodes[currentNode][1] = freeListHead;
    freeListHead = currentNode;
    if (currentNode == head)
        head = saveHead;
    size--;
}

void LinkedList::doJosephus(int m) {
  if (isEmpty()) {
    std::cout << "List is empty" << std::endl;
    return;
  }
  int currentNode = head;
  int previousNode = 0; // If current is head, the node "before" head will always be the 0th node in this case
  printList();

  while (size > 1) {
    for (int i = 0; i < m-1; ++i) {
      if ( nodes[currentNode][1] == -1 ) {
        currentNode = head;
      }
      else {
        currentNode = nodes[currentNode][1];
      }

      if ( nodes[previousNode][1] == -1 ) {
        previousNode = head;
      }
      else {
        previousNode = nodes[previousNode][1];
      }
    }
    std::cout << nodes[currentNode][0] << "  ";
    int nextNode = nodes[currentNode][1];
    // You must write this function as part of Project #1
    deleteNode(currentNode, previousNode);
    if (nextNode == -1) {
		nextNode = head;
	}
    currentNode = nextNode;
  }
  std::cout << std::endl;
  nodes[currentNode][1] = -1;
}

void LinkedList::insertFront(int value) {
  if ( isFull() ) {
    std::cout << "list is full, cannot insert: " << value << std::endl;
    return;
  }
  int saveHead = head;
  head = freeListHead;
  freeListHead = nodes[freeListHead][1];
  nodes[head][0] = value;
  nodes[head][1] = saveHead;
  size++;
}

void LinkedList::printList() const {
  int currentNode = head;
  while (currentNode != -1) {
    std::cout << nodes[currentNode][0] << " ";
    currentNode = nodes[currentNode][1];
  }
  std::cout << std::endl;
}

void LinkedList::printWholeArray() const {
  std::cout << "--------------------------------------------------"
            << std::endl;
  std::cout << "head: " << head << "\tfreeListHead: " << freeListHead
            << std::endl;
  std::cout << "The 2D Array looks like this: " << std::endl;
  std::cout << "index\tvalues:\tnextPtr" << std::endl;
  for (int i = 0; i < capacity; ++i) {
    std::cout << i << "\t    "
              << nodes[i][0] << "\t   " 
              << nodes[i][1] << std::endl;
  }
  std::cout << "--------------------------------------------------"
            << std::endl;
}

