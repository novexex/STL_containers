#include "s21_array.h"

using namespace s21;

//default construct
template <typename T, std::size_t S>
Array<T, S>::Array() {
    this->size_ = S;
    this->array_ = new T[this->size_]();
}

//copy construct
template <typename T, std::size_t S>
Array<T, S>::Array(const Array &a) : Array<T, S>() {
    this->size_ = a.size_;
    for (size_t i = 0; i < this->size_; i++ )
        *(this->array_ + i) = *(a.array_ + i);
}

//move construct
template <typename T, std::size_t S>
Array<T, S>::Array(Array &&a) : Array<T, S>(a) {
    a.deleteArray();
}

//init list construct
template <typename T, std::size_t S>
Array<T, S>::Array(std::initializer_list<value_type> const &items) {
    this->array_ = new T[S]();
    this->size_ = items.size();

    for (auto i = 0, it = items.begin(); it != items.end(); ++it)
        this->array_[i++] = *it;
}

//destructor
template <typename T, std::size_t S>
Array<T, S>::~Array() {
    this->deleteArray();
}

template <typename T, std::size_t S>
Array<T, S>& Array<T, S>::operator=(Array<T, S> &a) {
    this->array_ = new T[a.size_]();
    memcpy(this->array_, a.array_, a.size_ * sizeof(T));
    this->size_ = a.size_;
    return *this;
}

template <typename T, std::size_t S>
typename Array<T, S>::reference Array<T, S>::operator[](size_type pos) {
    return this->at(pos);
}

template <typename T, std::size_t S>
typename Array<T, S>::const_reference Array<T, S>::front() {
    return *(this->array_);
}

template <typename T, std::size_t S>
typename Array<T, S>::const_reference Array<T, S>::back() {
    return *(this->array_ + (S-1));
}

template <typename T, std::size_t S>
typename Array<T, S>::iterator Array<T, S>::data() {
    return this->array_;
}

template <typename T, std::size_t S>
typename Array<T, S>::iterator Array<T, S>::begin() {
    return this->array_;
}

template <typename T, std::size_t S>
typename Array<T, S>::iterator Array<T, S>::end() {
    return this->array_ + (S-1);
}

template <typename T, std::size_t S>
bool Array<T, S>::empty() {
    return this->size_ == 0;
}

template <typename T, std::size_t S>
typename Array<T, S>::size_type Array<T, S>::size() {
    return this->size_;
}

template <typename T, std::size_t S>
typename Array<T, S>::size_type Array<T, S>::max_size() {
    return S;
}

template <typename T, std::size_t S>
void Array<T, S>::fill(const_reference value) {
    for (size_t i = 0; i < this->size_; i++)
        this->array_[i] = value;
}

template <typename T, std::size_t S>
typename Array<T, S>::reference Array<T, S>::at(size_type pos) {
    if (pos >= this->size_) 
        throw std::range_error("Incorrect position");
    return this->array_[pos];
}

template <typename T, std::size_t S>
void Array<T, S>::swap(reference a) {
    Array<T, S> tmp(*this);
    *this = a;
    a = tmp;
}

template <typename T, std::size_t S>
void Array<T, S>::deleteArray() {
    delete[] this->array_;
    this->size_ = 0;
    this->size_ = 0;
    this->array_ = nullptr;
}
