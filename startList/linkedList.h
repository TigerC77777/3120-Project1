#include "node.h"
const int LIST_SIZE = 10;

class LinkedList {
public:
  LinkedList() : head(nullptr), size(0) {}
  void pushFront(int value);
  void printList() const;
  void deleteFront();
  void deleteValue(int);
  void deleteNode(Node*, Node*);
  void doJosephus(int m);
  bool isEmpty() const { return head == nullptr; }
private:
  Node* head;
  int size;
};
