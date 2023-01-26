#ifndef SRC_S21_STACK_H_
#define SRC_S21_STACK_H_

#include <initializer_list>
#include <stdexcept>

namespace s21 {
    template <class T>
    class Stack {
        public:
            // Member type
            using value_type      = T;
            using reference       = T&;
            using const_reference = const T&;
            using size_type       = size_t;

            // Member functions
            Stack();
            Stack(std::initializer_list<value_type> const &items);
            Stack(const Stack &s);
            Stack(Stack &&s);
            ~Stack();
            
            // Operators
            Stack<value_type>& operator=(Stack &&s);

            // Element access
            const_reference top();

            // Capacity
            bool empty();
            size_type size();

            // Modifiers
            void push(const_reference value);
            void pop();
            void swap(Stack& other);

            // Custom
            void clear();
            void copy(const Stack &s);

        private:
            class Node {
                public:
                    Node *next;
                    T data;

                    Node(T data = T(), Node *next = nullptr) {
                        this->data = data;
                        this->next = next;
                    }
            };

            Node *top_;
            size_t size_;
    };
}; // namespace s21

#include "s21_stack.cc"

#endif  // SRC_S21_STACK_H_
