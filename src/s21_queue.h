#ifndef SRC_S21_STACK_H_
#define SRC_S21_STACK_H_

#include <initializer_list>
#include <stdexcept>

namespace s21 {
    template <class T>
    class Queue {
        public:
            // Member type
            using value_type      = T;
            using reference       = T&;
            using const_reference = const T&;
            using size_type       = size_t;

            // Member functions
            Queue();
            Queue(std::initializer_list<value_type> const &items);
            Queue(const Queue &q);
            Queue(Queue &&q);
            ~Queue();

            // Operators
            Queue<value_type>& operator=(Queue &&q);

            // Element access
            const_reference front();
            const_reference back();

            // Capacity
            bool empty();
            size_type size();

            // Modifiers
            void push(const_reference value);
            void pop();
            void swap(Queue& other);

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

            Node *first_, *last_;
            size_t size_;
    };
}; // namespace s21

#include "s21_queue.cc"

#endif  // SRC_S21_STACK_H_
