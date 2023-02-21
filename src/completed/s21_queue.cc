#include "s21_queue.h"

using namespace s21;

template <typename value_type>
Queue<value_type>::Queue() {
    this->front_ = nullptr;
    this->rear_ = nullptr;
    this->size_ = 0;
}

template <typename value_type>
Queue<value_type>::Queue(std::initializer_list<value_type> const &items) : Queue() {
    for (auto it = items.begin(); it != items.end(); ++it)
        this->push(*it);
}

template <typename value_type>
Queue<value_type>::Queue(const Queue &other) : Queue() {
    this->copy(other);
}

template <typename value_type>
Queue<value_type>::Queue(Queue &&other) : Queue(other) {
    other.clear();
}

template <typename value_type>
Queue<value_type>::~Queue() {
    this->clear();
}

template <typename value_type>
Queue<value_type>& Queue<value_type>::operator=(Queue<value_type> &&other) {
    this->copy(other);
    return *this;
}

template <typename value_type>
typename Queue<value_type>::const_reference Queue<value_type>::front() {
    if (this->front_ == nullptr)
        throw std::out_of_range("Queue is empty");
    return this->front_->data;
}

template <typename value_type>
typename Queue<value_type>::const_reference Queue<value_type>::back() {
    if (this->front_ == nullptr)
        throw std::out_of_range("Queue is empty");
    return this->rear_->data;
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
    Node* node = new Node(value);
    if (this->empty())
        this->front_ = node;
    if (this->rear_ != nullptr)
        this->rear_->next = node;
    this->rear_ = node;
    this->size_++;
}

template <typename value_type>
void Queue<value_type>::pop() {
    if (!this->empty()) {
        Node* node = this->front_->next;
        delete this->front_;
        this->front_ = node;
        size_--;
    }
}

template <typename value_type>
void Queue<value_type>::swap(Queue& other) {
    Queue<value_type> replacement(other);
    other = *this;
    *this = replacement;
}

template <typename value_type>
void Queue<value_type>::clear() {
    while (this->size())
        this->pop();
}

template <typename value_type>
void Queue<value_type>::copy(const Queue &other) {
    this->clear();
    Node* tmp = other.front_; 
    for (int i = 0; i < other.size_; ++i) {
        this->push(tmp->data);
        tmp = tmp->next;
    }
}
