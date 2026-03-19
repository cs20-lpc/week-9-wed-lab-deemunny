#pragma once
#include "ArrayQueue.hpp"

template <typename T>
ArrayQueue<T>::ArrayQueue(int i) : maxSize(i), frontIndex(0), backIndex(maxSize - 1) {
    // TODO
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    if (isEmpty()) throw string("Queue is empty, nothing in back.");
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    if (isEmpty()) throw string("Queue is empty, nothing to remove");
    cout << "Removing value " << front();
    ++frontIndex % maxSize;  // auto "loops" around if front would overflow
    --this->length;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if (isFull()) {  
        int newSize = maxSize * 2 + 1;
        T* newBuffer = new T[newSize];
        for (int i = 0; i < this->length; ++i) {
            newBuffer[i] = front();
            dequeue();
        }        
        clear();
        buffer = newBuffer;
        maxSize = newSize;
    } 
    buffer[++backIndex % maxSize] = elem;
    ++this->length;        
}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    if (isEmpty()) throw string("Queue is empty, nothing in front");
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
