#ifndef SRC_S21_LIST_H_
#define SRC_S21_LIST_H_

#include <initializer_list>
#include <stdexcept>

namespace s21 {
    template <class T>
    class List {
        public:
            // Member type
            using value_type      = T;
            using reference       = T&;
            using const_reference = const T&;
            using iterator        = ListIterator<T>;
            using const_iterator  = ListConstIterator<T>;
            using size_type       = size_t;

            // Member functions
            List();
            List(size_type n);
            List(std::initializer_list<value_type> const &items);
            List(const List &l);
            List(List &&l);
            ~List();
            
            // Operators
            List<value_type>& operator=(List &&s);

            // Element access
            const_reference front();
            const_reference back();

            // Iterators
            iterator begin();
            iterator end();

            // Capacity
            bool empty();
            size_type size();
            size_type max_size();

            // Modifiers
            void clear();
            iterator insert(iterator pos, const_reference value);
            void erase(iterator pos);
            void push_back(const_reference value);
            void pop_back();
            void push_front(const_reference value);
            void pop_front();
            void swap(List& other);
            void merge(List& other);
            void splice(const_iterator pos, List& other);
            void reverse();
            void unique();
            void sort();

            // Convenience methods

        private:
            class Node {
                public:
                    Node *next, *prev;
                    T data;

                    Node(T data = T(), Node *next = nullptr, Node *prev = nullptr) {
                        this->next = next;
                        this->back = prev;
                        this->data = data;
                    }
            };

            Node *top_;
            size_t size_;
    };
}; // namespace s21

#include "s21_list.cc"

#endif  // SRC_S21_ARRAY_H_
