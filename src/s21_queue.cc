#include "s21_queue.h"

using namespace s21;

template <typename value_type>
Queue<value_type>::Queue() {
    this->first_ = nullptr;
    this->last_ = nullptr;
    this->size_ = 0;
}

template <typename value_type>
Queue<value_type>::Queue(std::initializer_list<value_type> const &items) : Queue() {
    for (auto it = items.begin(); it != items.end(); ++it)
        this->push(*it);
}

template <typename value_type>
Queue<value_type>::Queue(const Queue &q) : Queue() {
    this->copy(q);
}

template <typename value_type>
Queue<value_type>::Queue(Queue &&q) : Queue(q) {
    s.clear();
}

template <typename value_type>
Queue<value_type>::~Queue() {
    this->clear();
}

template <typename value_type>
Queue<value_type>& Queue<value_type>::operator=(Queue<value_type> &&q) {
    this->copy(q);
    return *this;
}

template <typename value_type>
Queue<value_type>::const_reference Queue<value_type>::front() {
    if (this->first_ == nullptr)
        throw std::out_of_range("Queue is empty");
    return this->first_->data;
}

template <typename value_type>
Queue<value_type>::const_reference Queue<value_type>::back() {
    if (this->first_ == nullptr)
        throw std::out_of_range("Queue is empty");
    return this->last_->data;
}

template <typename value_type>
bool Queue<value_type>::empty() {
    return this->size_ == 0;
}

template <typename value_type>
typename Queue<value_type>::size_type Queue<value_type>::size() {
    return this->size_;
}

template <typename value_type>
void Queue<value_type>::push(const_reference value) {
    Node* node = new Node(value, nullptr);
    if (this->first_ == nullptr)
        this->first_ = node;
    if (this->last_ != nullptr)
        this->last_->next = node;
    this->last_ = node;
    this->size_++;
}

template <typename value_type>
void Queue<value_type>::pop() {
    if (this->first_ != nullptr) {
        Node* element = this->first_->next;
        delete this->first_;
        this->first_ = element;
        this->size_--;
    }
}

template <typename value_type>
void Queue<value_type>::swap(Queue& other) {
    Queue<value_type> replacement(other);
    other = *this;
    *this = replacement;
}

// template <typename value_type>
// void Queue<value_type>::clear() {
//     for (int i = 0; i < this->size_; ++i) {
//         this->pop();
//     }
// }

// template <typename value_type>
// void Queue<value_type>::copy(const Queue &s) {
//     Node* tmp = s.first_; 
//     for (int i = 0; i < s.size_; ++i) {
//         this->push(tmp->data);
//         tmp = tmp->next;
//     }
// }