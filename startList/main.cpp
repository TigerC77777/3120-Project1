#include <string>
#include <chrono>
#include "linkedList.h"

void printList(const std::string& msg, const LinkedList& l) {
  std::cout << msg;
  l.printList();
  std::cout << std::endl;
}

int main() {
  LinkedList myList;
  for (int i = LIST_SIZE; i > 0; --i) {
    myList.pushFront(i);
  }
  printList("List: ", myList);

  auto start_time = std::chrono::steady_clock::now();
  myList.doJosephus(4);
  auto end_time = std::chrono::steady_clock::now();
  auto elapsed_duration = end_time - start_time;
  auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(elapsed_duration);
  std::cout << "Elapsed time: " << elapsed_ms.count() << " microseconds" << std::endl;

  printList("List: ", myList);
  return 0;
}
