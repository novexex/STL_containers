#include "s21_list.h"

#define MAX_SIZE_LIST 384307168202282325

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
    return this->iter_;
}

template <typename value_type>
bool List<value_type>::empty() {
    return (this->size_ == 0);
}

template <typename value_type>
typename List<value_type>::size_type List<value_type>::size() {
    return this->size_;
}

template <typename value_type>
typename List<value_type>::size_type List<value_type>::max_size() {
    return MAX_SIZE_LIST;
}

template <typename value_type>
void List<value_type>::clear() {
    size_type const_size = this->size_;
    for (size_type i = 0; i < const_size; i++)
        this->erase(this->begin());
}

template<class value_type>
typename List<value_type>::iterator List<value_type>::insert(iterator pos, const_reference value) {
    if (pos == this->begin()) {
        this->push_front(value);
    } else if (pos == this->end()) {
        this->push_back(value);
    } else {
        Node* node_by_pos = get_node_by_pos(pos);
        Node* node_before_pos = node_by_pos->back;
        Node* new_node = new Node(value, node_by_pos, node_before_pos);
        node_by_pos->back = node_before_pos->next = new_node;
        this->size_++;
    }
    return --pos;
}

template<class value_type>
void List<value_type>::erase(iterator pos) {
    if (pos == this->end() || this->empty())
        throw std::out_of_range("Error: Iterator is out of range");
    Node* node = this->get_node_by_pos(pos);
    Node* node_next = node->next;
    Node* node_back = node->back;
    if (this->size_ > 1 && node_next != this->iter_)
        node_next->back = node_back;
    if (this->size_ > 1 && node_back != this->iter_)
        node_back->next = node_next;
    if (pos == this->begin())
        this->head_ = node_next;
    if (pos == --end())
        this->tail_ = node_back;
    this->size_--;
    this->set_iter((this->size_ == 0) ? value_type() : node->data);
    delete node;
}

template<class value_type>
void List<value_type>::push_back(const_reference value) {
    Node *temp = new Node(value, nullptr, this->tail_);
    if (this->tail_ != nullptr)
        this->tail_->next = temp;
    if (this->size_ == 0)
        this->head_ = this->tail_ = temp;
    else
        this->tail_ = temp;
    this->size_++;
    this->set_iter(this->size_);
}

template<class value_type>
void List<value_type>::pop_back() {
    if (this->empty())
        throw std::out_of_range("Error: List is empty");
    this->erase(--end());
}

template<class value_type>
void List<value_type>::push_front(const_reference value) {
    Node *temp = new Node(value, this->head_, nullptr);
    if (this->head_ != nullptr)
        this->head_-> back = temp;
    if (this->size_ == 0)
        this->head_ = this->tail_ = temp;
    else
        this->head_ = temp;
    this->size_++;
    this->set_iter(this->size_);
}

template<class value_type>
void List<value_type>::pop_front() {
    if (this->empty())
        throw std::out_of_range("Error: List is empty");
    this->erase(begin());
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