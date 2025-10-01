const int SMALL_SIZE = 1000000;

class LinkedList {
public:
  LinkedList(int cap);

  bool isEmpty()  const { return head == -1; }
  bool isFull()   const { return freeListHead == -1; }
  int  getSize()  const { return size; }

  void doJosephus(int);
  void insertFront(int value);
  void deleteNode(int currentNode, int previousNode);

  void printList() const;
  void printWholeArray() const;
private:
  int head;            // index of first element
  int freeListHead;    // index of first free node
  int size;
  int capacity;        
  int nodes[SMALL_SIZE][2];
};
