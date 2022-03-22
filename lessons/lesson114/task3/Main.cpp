#include <array>
#include <cassert>
#include <iostream>

class Stack {
private:
  std::array<int, 10> myElements;
  size_t mySize;

public:
  Stack() : myElements{}, mySize{} {}

  ~Stack() {}

  void print() {
    std::cout << "( ";

    for (size_t i = 0; i < mySize; ++i) {
      std::cout << myElements[i] << ' ';
    }

    std::cout << ")\n";
  }

  void reset() {
    myElements.fill(0);
    mySize = 0;
  }

  bool push(int element) {
    if (myElements.size() == mySize) {
      return false;
    }

    myElements[mySize] = element;
    ++mySize;
    return true;
  }

  int pop() {
    assert(mySize != 0);
    return myElements[--mySize];
  }
};

int main() {
  Stack stack;

  stack.reset();
  stack.print();

  stack.push(3);
  stack.push(7);
  stack.push(5);
  stack.print();

  stack.pop();
  stack.print();

  stack.pop();
  stack.pop();
  stack.print();
  return 0;
}