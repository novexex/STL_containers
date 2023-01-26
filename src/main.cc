
#include "s21_stack.h"
#include <iostream>

using namespace s21;

int main() {
    Stack<int> *node = new Stack<int>(std::initializer_list<int> ({1, 3, 4, 5, 6}));
    Stack<int> *copyNode = new Stack<int>(*node);

    std::cout << copyNode->empty() << std::endl;
    std::cout << copyNode->size() << std::endl;
}