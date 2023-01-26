#ifndef SRC_S21_ARRAY_H_
#define SRC_S21_ARRAY_H_

#include <initializer_list>
#include <cstddef>
#include <stdexcept>

namespace s21 {
    template <class T, std::size_t S>
    class Array {
        public:
            //внутриклассовые переопределения типов
            using value_type      = T;
            using reference       = T&;
            using const_reference = const T&;
            using iterator        = T*;
            using const_iterator  = const T*;
            using size_type       = size_t;

            //конструкторы
            Array(); //default
            Array(std::initializer_list<value_type> const &items); //init list construct
            Array(const Array &a); //copy construct
            Array(Array &&a); //move construct
            ~Array();

            //операторы
            Array<T, S> &operator=(Array &a);
            reference operator[](size_type pos);

            //публичные методы для доступа к элементам класса
            reference at(size_type pos);
            const_reference front();
            const_reference back();
            iterator data();

            //публичные методы для итерирования по элементам класса
            iterator begin();
            iterator end();

            //публичные методы для доступа к информации о наполнении контейнера
            bool empty();
            size_type size();
            size_type max_size();

            //публичные методы для изменения контейнера
            void swap(reference);
            void fill(const_reference value);
            void deleteArray();

        private:
            value_type* array_;
            size_type size_;
    };
}; // namespace s21

#include "s21_array.cc"

#endif  // SRC_S21_ARRAY_H_
