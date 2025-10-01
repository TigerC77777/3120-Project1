#include <iostream>
#include <chrono>
#include "linkedList.h"

int main() {
  LinkedList myList(SMALL_SIZE);
  for (int i = SMALL_SIZE; i > 0; --i) {
    myList.insertFront(i);
  }
  myList.printWholeArray();
  myList.printList();

  auto start_time = std::chrono::steady_clock::now();
  myList.doJosephus(4);
  auto end_time = std::chrono::steady_clock::now();
  auto elapsed_duration = end_time - start_time;
  auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_duration);
  std::cout << "Elapsed time: " << elapsed_ms.count() << " microseconds" << std::endl;

  //myList.printWholeArray();
  myList.printList();
  return 0;
}
