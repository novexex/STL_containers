#include "s21_stack.h"

using namespace s21;

template <typename value_type>
Stack<value_type>::Stack() {
    this->top_ = nullptr;
    this->size_ = 0;
}

template <typename value_type>
Stack<value_type>::Stack(std::initializer_list<value_type> const &items) : Stack() {
    for (auto it = items.begin(); it != items.end(); ++it)
        this->push(*it);
}

template <typename value_type>
Stack<value_type>::Stack(const Stack &other) : Stack() {
    this->copy(other);
}

template <typename value_type>
Stack<value_type>::Stack(Stack &&other) : Stack(other) {
    other.clear();
}

template <typename value_type>
Stack<value_type>::~Stack() {
    this->clear();
}

template <typename value_type>
Stack<value_type>& Stack<value_type>::operator=(Stack<value_type> &&other) {
    this->copy(other);
    return *this;
}

template <typename value_type>
typename Stack<value_type>::const_reference Stack<value_type>::top() {
    return this->top_;
}

template <typename value_type>
bool Stack<value_type>::empty() {
    return this->size_ == 0;
}

template <typename value_type>
typename Stack<value_type>::size_type Stack<value_type>::size() {
    return this->size_;
}

template <typename value_type>
void Stack<value_type>::push(const_reference value) {
    Node* element = new Node(value, this->top_);
    this->top_ = element;
    this->size_++;
}

template <typename value_type>
void Stack<value_type>::pop() {
    if (this->top_ != nullptr) {
        Node* element = this->top_->next;
        delete this->top_;
        this->top_ = element;
        this->size_--;
    }
}

template <typename value_type>
void Stack<value_type>::swap(Stack& other) {
    Stack<value_type> replacement(other);
    other = *this;
    *this = replacement;
}

template <typename value_type>
void Stack<value_type>::clear() {
    for (int i = 0; i < this->size_; ++i) {
        this->pop();
    }
}

template <typename value_type>
void Stack<value_type>::copy(const Stack &other) {
    Node* tmp = other.top_; 
    for (int i = 0; i < other.size_; ++i) {
        this->push(tmp->data);
        tmp = tmp->next;
    }
}
