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
    return this->front_;
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
    List<value_type> new_list(other);
    other = *this;
    *this = new_list;
}

template<class value_type>
void List<value_type>::merge(List& other) {
    iterator it_this = this->begin();
    value_type prev_value = other.front();
    for (auto it_other = other.begin(); it_other != other.end(); prev_value = *it_other) {
        if (*it_other < prev_value || *it_this > *it_other) {
            this->insert(it_this, *it_other);
            ++it_other;
        } else {
            ++it_this;
        }
    }
    other.clear();
}

template<class value_type>
void List<value_type>::splice(const_iterator pos, List& other) {
    iterator this_it = this->begin();
    for (; this_it != pos; ++this_it) {;}
    for (auto it = other.begin(); it != other.end(); ++it)
        insert(this_it, *it);
    other.clear();
}

template<class value_type>
void List<value_type>::reverse() {
    List<value_type> reverse_list;
    for (auto it = this->begin(); it != this->end(); ++it)
        reverse_list.push_front(*it);
    *this = reverse_list;
}

template<class value_type>
void List<value_type>::unique() {
   iterator it_next = ++(this->begin());
    for (auto it = this->begin(); it_next != this->end(); ++it_next) {
        if (*it == *it_next)
            this->erase(it_next);
        else
            ++it;
    }
}

template<class value_type>
void List<value_type>::sort() {
    if (!this->empty())
        this->quick_sort(0, this->size_ - 1);
}

// Convenience methods

template<class value_type>
void List<value_type>::quick_sort(size_type first_node, size_type last_node) {
    size_type start = first_node, end = last_node;
    size_type size = (start == 0) ? end - start + 1 : start + end;
    value_type middle = move_to_index(size / 2)->data;
    do {
        while (move_to_index(start)->data < middle) start++;
        while (move_to_index(end)->data > middle) end--;
        if (start <= end) {
            value_type temp = move_to_index(start)->data;
            move_to_index(start)->data = move_to_index(end)->data;
            move_to_index(end)->data = temp;
            start++;
            end--;
        }
    } while (start <= end);
    if (end > first_node)
        quick_sort(0, end++);
    if (start < last_node)
        quick_sort(start, this->size_ - 1);
}