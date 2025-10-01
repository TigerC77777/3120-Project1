#include "linkedList.h"

void LinkedList::pushFront(int value) {
  head = new Node(value, head);
  ++size;
}

void LinkedList::printList() const {
  Node* temp = head;
  while (temp != nullptr) {
    std::cout << temp->getData() << "  ";
    temp = temp->getNext();
  }
}

void LinkedList::deleteFront() {
  if (isEmpty()) {
    std::cout << "list is empty" << std::endl;
    return;
  }
  Node* temp = head;
  head = head->getNext();
  delete temp;
  --size;
}

void LinkedList::deleteNode(Node* previousNode, Node* nodeToDelete) {
    previousNode->setNext(nodeToDelete->getNext());
    if (nodeToDelete == head)
        head = nodeToDelete->getNext();

    delete nodeToDelete;
    --size;
}

void LinkedList::doJosephus(int m)
{
    if (isEmpty())
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    
    Node* currentNode = head;
    Node* previousNode = nullptr;
    printList();

    while (size > 1)
    {
        for (int i = 0; i < m - 1; ++i)
        {
            if (currentNode->getNext() == nullptr)
                currentNode = head;
            else
                currentNode = currentNode->getNext();

            if (previousNode == nullptr || previousNode->getNext() == nullptr)
                previousNode = head;
            else
                previousNode = previousNode->getNext();
        }

        //std::cout << currentNode->getData() << " ";
        Node* nextNode = currentNode->getNext();
        deleteNode(previousNode, currentNode);
        if (nextNode == nullptr)
            nextNode = head;
        currentNode = nextNode;
    }
    std::cout << std::endl;
    currentNode->setNext(nullptr);
}

