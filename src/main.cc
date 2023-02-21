
#include "s21_queue.h"
#include <iostream>

using namespace s21;

int main() {
    s21::Queue<int> abc;
    abc.push(23);
    abc.push(43);
    abc.push(443);
    abc.push(431);
    abc.push(423);
    abc.clear();
}