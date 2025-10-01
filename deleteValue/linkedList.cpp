#include <iostream>
#include "linkedList.h"

LinkedList::LinkedList(int cap) : 
  head(-1), freeListHead(0), size(0), capacity(cap) {
  for (int i = 0; i < capacity - 1; i++) {
    nodes[i][1] = i+1;
  }
  nodes[capacity-1][1] = -1; // the end of the free list
}

void LinkedList::deleteValue(int value) {
    for (int i = 0; i < size; i++)
    {
        if (nodes[i][0] == value)
        {
            // Move all the nodes afterwards back
            for (int j = i; j < size - 1; j++)
            {
                nodes[j][0] = nodes[j + 1][0];
                //nodes[j][1] = nodes[j + 1][1] - 1; // Be sure to decrement the next pointers
            }

            int saveHead = nodes[head][1];
            nodes[head][1] = freeListHead;
            freeListHead = head;
            head = saveHead;
            size--;
            break;
        }
    }
}

void LinkedList::doJosephus(int m) {
  if (isEmpty()) {
    std::cout << "List is empty" << std::endl;
    return;
  }
  int currentNode = head;
  printList();

  while (size > 1) {
    for (int i = 0; i < m-1; ++i) {
      if ( nodes[currentNode][1] == -1 ) {
        currentNode = head;
      }
      else {
        currentNode = nodes[currentNode][1];
      }
    }
    std::cout << nodes[currentNode][0] << "  ";
    int nextNode = nodes[currentNode][1];
    // You must write this function as part of Project #1
    deleteValue(nodes[currentNode][0]);
    if (nextNode == -1) {
		nextNode = head;
	}
    currentNode = nextNode;
  }
  std::cout << std::endl;
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

