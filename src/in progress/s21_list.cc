#include "s21_list.h"

using namespace s21;

template <typename value_type>
List<value_type>::List() {
    this->front_ = nullptr;
    this->rear_ = nullptr;
    this->size_ = 0;
}

template <typename value_type>
List<value_type>::List(size_type n) : List() {
    for (size_type i = 0; i < n; i++)
        this->push_back(value_type());
}

template <typename value_type>
List<value_type>::List(std::initializer_list<value_type> const &items) : List() {
    for (auto it = items.begin(); it != items.end(); ++it)
        this->push(*it);
}

template <typename value_type>
List<value_type>::List(const List &other) : List() {
    this->copy(other);
}

template <typename value_type>
List<value_type>::List(List &&other) : List(other) {
    other.clear();
}

template <typename value_type>
List<value_type>::~List() {
    this->clear();
}

template <typename value_type>
List<value_type>& List<value_type>::operator=(List<value_type> &&other) {
    this->copy(other);
    return *this;
}

template <typename value_type>
typename List<value_type>::const_reference List<value_type>::front() {
    if (this->front_ == nullptr)
        throw std::out_of_range("List is empty");
    return this->front_->data;
}

template <typename value_type>
typename List<value_type>::const_reference List<value_type>::back() {
    if (this->front_ == nullptr)
        throw std::out_of_range("List is empty");
    return this->rear_->data;
}

template <typename value_type>
typename List<value_type>::iterator begin() {
    return 
}

template <typename value_type>
typename List<value_type>::iterator end() {

}

template <typename value_type>
bool List<value_type>::empty() {

}

template <typename value_type>
typename List<value_type>::size_type List<value_type>::size() {

}

template <typename value_type>
typename List<value_type>::size_type List<value_type>::max_size() {

}

template <typename value_type>
void List<value_type>::clear() {

}

template<class value_type>
typename List<value_type>::iterator List<value_type>::insert(iterator pos, const_reference value) {

}

template<class value_type>
void List<value_type>::erase(iterator pos) {

}

template<class value_type>
void List<value_type>::push_back(const_reference value) {

}

template<class value_type>
void List<value_type>::pop_back() {

}

template<class value_type>
void List<value_type>::push_front(const_reference value) {

}

template<class value_type>
void List<value_type>::pop_front() {

}

template<class value_type>
void List<value_type>::swap(List& other) {

}

template<class value_type>
void List<value_type>::merge(List& other) {

}

template<class value_type>
void List<value_type>::splice(const_iterator pos, List& other) {

}

template<class value_type>
void List<value_type>::reverse() {

}

template<class value_type>
void List<value_type>::unique() {

}

template<class value_type>
void List<value_type>::sort() {

}