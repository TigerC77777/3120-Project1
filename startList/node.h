#include <iostream>

// Conform to the Rule of Zero:
//   No copy constructor, destructor, assignment operator
// Use initialization lists (in constructors, of course!) Item #4
// Use const everywhere! Item #3
class Node {
public:
  Node() : data(0), next(nullptr) {}
  Node(int d, Node* const n) : data(d), next(n) {}

  void setNext(Node* nextPtr) { next = nextPtr; }
  int getData() const { return data; }
  Node* getNext() const { return next; }
  Node* getNext() { return next; }
private:
  int data;
  Node* next;
};
